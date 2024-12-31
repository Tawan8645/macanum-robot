#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>
#include <sensor_msgs/msg/joy.h>

// Node and related variables
rcl_subscription_t joy_subscription;
rcl_publisher_t command_publisher;
rclc_executor_t executor;
rcl_node_t node;
std_msgs__msg__String command_msg;

// Constants
const float DEADZONE = 0.1;  // Joystick deadzone to avoid small movements
const size_t MAX_COMMAND_LENGTH = 100;  // Maximum command length

// Function to process joystick input and generate command
void process_joy_input(const sensor_msgs__msg__Joy *msg) {
    // Access the buttons and axes data from the sequence
    int32_t* buttons = msg->buttons.data;  // Array of int32 values for button states
    float* axes = msg->axes.data;          // Array of float32 values for axes positions

    // Initialize default command to "Stop"
    command_msg.data.data = "Stop";

    // Priority-based processing of joystick buttons
    if (buttons[0]) {
        command_msg.data.data = "Move Forward";
    } else if (buttons[1]) {
        command_msg.data.data = "Move Backward";
    } else if (buttons[2]) {
        command_msg.data.data = "Turn Left";
    } else if (buttons[3]) {
        command_msg.data.data = "Turn Right";
    } else if (buttons[4]) {
        command_msg.data.data = "Increase Speed";
    } else if (buttons[5]) {
        command_msg.data.data = "Decrease Speed";
    } else if (buttons[6]) {
        command_msg.data.data = "Activate Mode A";
    } else if (buttons[7]) {
        command_msg.data.data = "Activate Mode B";
    }

    // Processing joystick axes with Deadzone consideration
    if (axes[0] > DEADZONE) {
        command_msg.data.data = "Turn Slightly Right";
    } else if (axes[0] < -DEADZONE) {
        command_msg.data.data = "Turn Slightly Left";
    } else if (axes[1] > DEADZONE) {
        command_msg.data.data = "Move Slightly Forward";
    } else if (axes[1] < -DEADZONE) {
        command_msg.data.data = "Move Slightly Backward";
    }

    // Set the size of the command string
    command_msg.data.size = strlen(command_msg.data.data);
}

// Callback function for processing joystick data
void joy_callback(const void *msgin) {
    const sensor_msgs__msg__Joy *msg = (const sensor_msgs__msg__Joy *)msgin;

    // Extract header data (for debugging)
    std_msgs__msg__Header header = msg->header;
    uint32_t seq = header.seq;
    int32_t stamp_sec = header.stamp.sec;
    int32_t stamp_nanosec = header.stamp.nanosec;
    const char* frame_id = header.frame_id.data;

    // Print header info (for debugging)
    printf("Header Info:\n");
    printf("Sequence: %u, Timestamp: %d.%d, Frame ID: %s\n", seq, stamp_sec, stamp_nanosec, frame_id);

    // Process joystick input to generate the appropriate command
    process_joy_input(msg);

    // Publish the command
    rcl_publish(&command_publisher, &command_msg, NULL);
}

// Function to initialize ROS 2 node and components with error handling
rcl_ret_t initialize_ros() {
    rcl_allocator_t allocator = rcl_get_default_allocator();
    rclc_support_t support;
    if (rclc_support_init(&support, 0, NULL, &allocator) != RCL_RET_OK) {
        printf("Failed to initialize ROS 2 support.\n");
        return RCL_RET_ERROR;
    }

    // Initialize node
    if (rclc_node_init_default(&node, "esp32_robot_controller", "", &support) != RCL_RET_OK) {
        printf("Failed to initialize ROS 2 node.\n");
        return RCL_RET_ERROR;
    }

    // Initialize subscription to /joy topic
    if (rclc_subscription_init_default(&joy_subscription, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Joy), "/joy") != RCL_RET_OK) {
        printf("Failed to initialize subscription to /joy.\n");
        return RCL_RET_ERROR;
    }

    // Initialize publisher to /robot_cmd topic
    if (rclc_publisher_init_default(&command_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "/robot_cmd") != RCL_RET_OK) {
        printf("Failed to initialize publisher to /robot_cmd.\n");
        return RCL_RET_ERROR;
    }

    // Initialize executor
    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_subscription(&executor, &joy_subscription, NULL, joy_callback, ON_NEW_DATA);

    return RCL_RET_OK;
}

// Main function to execute the application
void appMain(void *arg) {
    // Initialize ROS 2
    if (initialize_ros() != RCL_RET_OK) {
        return;
    }

    // Allocate memory for the command message (using stack allocation for improved performance)
    command_msg.data.data = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
    if (command_msg.data.data == NULL) {
        printf("Failed to allocate memory for command message.\n");
        return;
    }
    command_msg.data.capacity = MAX_COMMAND_LENGTH;

    // Main loop
    while (1) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));  // Process incoming messages
        vTaskDelay(pdMS_TO_TICKS(100));  // Yield control to other tasks
    }

    // Cleanup (not reached in the current infinite loop)
    free(command_msg.data.data);
    rclc_publisher_fini(&command_publisher, &node);
    rclc_subscription_fini(&joy_subscription, &node);
    rcl_node_fini(&node);
}
