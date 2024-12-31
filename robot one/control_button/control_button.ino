#include <Arduino.h>
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/float32.h>
#include <ESP32Servo.h>  // Include the Servo library

// กำหนดขา GPIO สำหรับควบคุมมอเตอร์ (เปลี่ยนให้เหมาะกับ ESP32-C3)
Servo esc;
Servo servo;

// ตัวแปรเพื่อเชื่อมต่อกับ ROS2
rcl_publisher_t motor_publisher;
std_msgs__msg__Float32 motor_speed_msg;
rcl_subscription_t subscription;

// ประกาศตัวแปร executor ภายนอก
rclc_executor_t executor;

// ฟังก์ชั่น callback ที่จะทำงานเมื่อมีการรับข้อมูลจาก ROS2
void motor_speed_callback(const void * msgin)
{
  const std_msgs__msg__Float32 * msg = (const std_msgs__msg__Float32 *)msgin;

  // การควบคุมมอเตอร์ตามค่าที่รับมาจาก ROS2
  if (msg->data == 1) {
    esc.writeMicroseconds(2000);  // Full speed
    delay(50);
    servo.write(10);  // Move servo to 14 degrees
  }
  else if (msg->data == 2) {
    esc.writeMicroseconds(2000);  // Full speed
  }
  else if (msg->data == 0) {
    esc.writeMicroseconds(1000);  // Full speed
    servo.write(90);  // Move servo to 70 degrees (example
  }
}

void setup() {
  // เริ่มต้นการเชื่อมต่อกับ Micro-ROS
  set_microros_transports();
  
  // เริ่มต้น Micro-ROS Client
  rclc_support_t support;
  rcl_allocator_t allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);

  // เริ่มต้น Node
  rcl_node_t node;
  rclc_node_init_default(&node, "esp32_motor_control", "", &support);

  // เริ่มต้น Subscriber สำหรับ topic 'motor_speed'
  rclc_subscription_init_default(&subscription, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), "motor_speed");

  // เริ่มต้น Executor
  rclc_executor_init(&executor, &support.context, 1, &allocator);

  // เพิ่ม subscriber ใน executor
  rclc_executor_add_subscription(&executor, &subscription, &motor_speed_msg, &motor_speed_callback, ON_NEW_DATA);
  
  // Attach the ESC and servo to the specified pins
  esc.attach(19);    // ESC connected to GPIO 2 (ESP32-C3)
  servo.attach(23);  // Servo connected to GPIO 3 (ESP32-C3)
  esc.writeMicroseconds(1000);  // Stop motor
  servo.write(90);   // Set servo to neutral position (90 degrees)
}

void loop() {
  // รอให้มีข้อมูลใหม่จาก ROS2
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1));

}
