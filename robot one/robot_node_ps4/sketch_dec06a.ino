#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <geometry_msgs/msg/twist.h>

rcl_allocator_t allocator;
rclc_support_t support;
rclc_executor_t executor;
rcl_node_t node;
rcl_subscription_t motorsub;
geometry_msgs__msg__Twist msg;

//#### Motor Driver Pins ####
int INA1 = 12;
int INB1 = 14;
int PWM1 = 27;
int INA2 = 25;
int INB2 = 33;
int PWM2 = 32;
int INA3 = 15;
int INB3 = 2;
int PWM3 = 0;
int INA4 = 5;
int INB4 = 18;
int PWM4 = 19;

//#### Speed Variables ####
int speed1 = 130;
int speed2 = 130;
int speed3 = 130;
int speed4 = 130;

float linear_velocity_x = 0.0;
float linear_velocity_y = 0.0;
float linear_velocity_z = 0.0;
float angular_velocity_x = 0.0;
float angular_velocity_y = 0.0;
float angular_velocity_z = 0.0;

void cmd_vel_callback(const void* msgin) {
  const geometry_msgs__msg__Twist* twist_msg = (const geometry_msgs__msg__Twist*)msgin;
  ///////////////////linear_velocity/////////////////
  linear_velocity_x = twist_msg->linear.x;
  linear_velocity_y = twist_msg->linear.y;
  linear_velocity_z = twist_msg->linear.z;
  ///////////////////angular_velocity////////////////
  angular_velocity_x = twist_msg->angular.x;
  angular_velocity_y = twist_msg->angular.y;
  angular_velocity_z = twist_msg->angular.z;
}

void move_robot() {
  if (angular_velocity_y > 0.7) {
    forword();
  } else if (angular_velocity_y < -0.7) {
    backword();
  } else if (linear_velocity_y > 0.5) {
    turnLeft();
  } else if (linear_velocity_y < -0.5) {
    turnRight();
  } else if ((angular_velocity_y > 0.0) && (angular_velocity_z < 0.0)) {
    forwordRight();
  } else if ((angular_velocity_y > 0.0) && (angular_velocity_z > 0.0)) {
    forwordLeft();
  } else if ((angular_velocity_y < 0.0) && (angular_velocity_z < 0.0)) {
    backwordRight();
  } else if ((angular_velocity_y < 0.0) && (angular_velocity_z > 0.0)) {
    backwordLeft();
  } else {
    stopbot();
  }

  // Example for turning with angular velocity
  if (angular_velocity_z > 0.7) {
    slideLeft();
  } else if (angular_velocity_z < -0.7) {
    slideRight();
  }
}

void setup() {
  set_microros_transports();
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INA3, OUTPUT);
  pinMode(INB3, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(INA4, OUTPUT);
  pinMode(INB4, OUTPUT);
  pinMode(PWM4, OUTPUT);

  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "motor_node", "", &support);
  rclc_subscription_init_default(
    &motorsub,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel"); // หัวข้อที่สมัครรับข้อมูล

  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(
    &executor,
    &motorsub,
    &msg,
    &cmd_vel_callback,
    ON_NEW_DATA);
}

void loop() {
  move_robot();
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}

void forword() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 1);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 1);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 1);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 1);
  analogWrite(PWM4, speed4);
}
/////////////////////////////////////////////
void backword() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 1);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 1);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 1);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, speed4);
}
//////////////////////////////////////////////
void turnRight() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 1);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, 100);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, 100);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 1);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, 100);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 1);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, 100);
}
//////////////////////////////////////////////
void turnLeft() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 1);
  analogWrite(PWM1, 100);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 1);
  analogWrite(PWM2, 100);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 1);
  analogWrite(PWM3, 100);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 1);
  analogWrite(PWM4, 100);
}
/////////////////////////////////////////////
void slideRight() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 1);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 1);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 1);
  analogWrite(PWM4, speed4);
}
///////////////////////////////////////////
void slideLeft() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 1);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 1);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 1);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 1);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, speed4);
}
///////////////////////////////////////
void forwordRight() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 1);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 1);
  analogWrite(PWM4, speed4);
}
//////////////////////////////////////
void forwordLeft() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 1);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 1);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, speed4);
}
///////////////////////////////////
void backwordRight() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 0);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 1);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 0);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, speed4);
}
////////////////////////////////////////
void backwordLeft() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 1);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 0);
  analogWrite(PWM2, speed2);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, 0);
  digitalWrite(INB3, 0);
  analogWrite(PWM3, speed3);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, 1);
  digitalWrite(INB4, 0);
  analogWrite(PWM4, speed4);
}
//////////////////////////////////////
void stopbot() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, LOW);
  analogWrite(PWM1, 0);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, LOW);
  digitalWrite(INB2, LOW);
  analogWrite(PWM2, 0);
  //#### Motor Driver 3 ####
  digitalWrite(INA3, LOW);
  digitalWrite(INB3, LOW);
  analogWrite(PWM3, 0);
  //#### Motor Driver 4 ####
  digitalWrite(INA4, LOW);
  digitalWrite(INB4, LOW);
  analogWrite(PWM4, 0);
}
/////////////////////////////////
