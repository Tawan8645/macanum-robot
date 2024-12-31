#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <geometry_msgs/msg/twist.h>
#include <ESP32Servo.h>  // Include the Servo library

rcl_allocator_t allocator;
rclc_support_t support;
rclc_executor_t executor;
rcl_node_t node;
rcl_subscription_t motorsub;
geometry_msgs__msg__Twist msg;

float linear_velocity_x;
Servo myServo;  // Create a Servo object
int servoAngle = 0;

// Pin for servo control
const int servoPin = 13;  // Connect your servo signal wire to pin 9

void cmd_vel_callback(const void* msgin) {
  const geometry_msgs__msg__Twist* twist_msg = (const geometry_msgs__msg__Twist*)msgin;
  ///////////////////linear_velocity/////////////////
  linear_velocity_x = twist_msg->linear.x;
  
  // Map the linear velocity to servo angle (adjust range as needed)
  
}


void servo() {
  servoAngle = map(linear_velocity_x, -1.0, 1.0, 20, 160);  // Mapping -1 to 1 to 0 to 180 degrees
  myServo.write(servoAngle);  // Set the servo position
}

void setup() {
  set_microros_transports();
  
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
  
  // Attach the servo to the specified pin
  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  servo();
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}
