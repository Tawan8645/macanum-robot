#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <geometry_msgs/msg/twist.h>
#include <ESP32Servo.h>  // Include the Servo library

// Micro-ROS variables
rcl_allocator_t allocator;
rclc_support_t support;
rclc_executor_t executor;
rcl_node_t node;
rcl_subscription_t motorsub;
geometry_msgs__msg__Twist msg;

// Servo variables
float linear_velocity_x;
Servo esc;
Servo servo;

void cmd_vel_callback(const void* msgin) {
  const geometry_msgs__msg__Twist* twist_msg = (const geometry_msgs__msg__Twist*)msgin;

  // Extract linear velocity in the x direction
  linear_velocity_x = twist_msg->linear.x;

  // Map the linear velocity to a range for the servo (you can adjust this as needed)
  if (linear_velocity_x > 0.4) {
    // Forward motion (positive linear velocity)
    esc.writeMicroseconds(2000);  // Full speed
    delay(50);
    servo.write(10);  // Move servo to 14 degrees
  } else if (linear_velocity_x == -0.0) {
    // Reverse motion (negative linear velocity)
    esc.writeMicroseconds(1000);  // Stop motor
    servo.write(90);  // Move servo to 70 degrees (example reverse position)
  }
}


void setup() {
  // Initialize Micro-ROS
  set_microros_transports();  // Initialize Micro-ROS transports (serial by default)
  Serial.begin(115200);  // Start serial communication for debugging

  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "motor_node", "", &support);
  rclc_subscription_init_default(
    &motorsub,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel");

  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(
    &executor,
    &motorsub,
    &msg,
    &cmd_vel_callback,
    ON_NEW_DATA);

  // Attach the ESC and servo to the specified pins
  esc.attach(19);    // ESC connected to pin 19
  servo.attach(21);  // Servo connected to pin 21
  esc.writeMicroseconds(1000);  // Stop motor
  servo.write(90);   // Set servo to neutral position (90 degrees)
}

void loop() {
  // Process Micro-ROS messages
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}
