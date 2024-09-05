// int ch1 = 14;
// int ch2 = 15;
// int ch3 = 16;
// int ch4 = 17;
// int ch5 = 18;
// //value
// int value1;
// int value2;
// int value3;
// int value4;
// int value5;

//#### Motor Driver 1 ####
int INA1 = 12;
int INB1 = 14;
int PWM1 = 27;
//#### Motor Driver 2 ####
int INA2 = 25;
int INB2 = 33;
int PWM2 = 32;
//#### Motor Driver 3 ####
int INA3 = 15;
int INB3 = 2;
int PWM3 = 0;
//#### Motor Driver 4 ####
int INA4 = 5;
int INB4 = 18;
int PWM4 = 19;


//#### speed bord ####
int speed1 = 100;
int speed2 = 100;
int speed3 = 100;
int speed4 = 100;

void setup() {
  // pinMode(ch1, INPUT);
  // pinMode(ch2, INPUT);
  // pinMode(ch3, INPUT);
  // pinMode(ch4, INPUT);
  // pinMode(ch5, INPUT);
  //#### Motor Driver 1 ####
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  //#### Motor Driver 2 ####
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  //#### Motor Driver 3 ####
  pinMode(INA3, OUTPUT);
  pinMode(INB3, OUTPUT);
  pinMode(PWM3, OUTPUT);
  //#### Motor Driver 4 ####
  pinMode(INA4, OUTPUT);
  pinMode(INB4, OUTPUT);
  pinMode(PWM4, OUTPUT);


  Serial.begin(9600);
}

void loop() {

  // value1 = pulseIn(ch1, HIGH);  // อ่านค่าความกว้างของสัญญาณของแต่ละ Channel
  // value2 = pulseIn(ch2, HIGH);
  // value3 = pulseIn(ch3, HIGH);
  // value4 = pulseIn(ch4, HIGH);
  // value5 = pulseIn(ch5, HIGH);


  // Serial.print("Channel 1:");
  // Serial.println(value1);

  // Serial.print("Channel 2:");
  // Serial.println(value2);
  // Serial.print("Channel 3:");
  // Serial.println(value3);
  // Serial.print("Channel 4:");
  // Serial.println(value4);
  // Serial.print("Channel 5:");
  // Serial.println(value5);


  // if (value2 < 1100) {
  //   Serial.println("เดินหน้า");
  //   backword();

  // } else if (value2 > 1900) {
  //   Serial.println("ถอยหลัง");
  //   forword();
  // } else if (value1 > 1900) {
  //   Serial.println("ขวา");
  //   slideRight();
  // } else if (value1 < 1100) {
  //   Serial.println("ซ้าย");
  //   slideLeft();
  // } else if (value4 > 1900) {
  //   Serial.println("ขวา");
  //   turnRight();
  // } else if (value4 < 1100) {
  //   Serial.println("ซ้าย");
  //   turnLeft();
  // } else if ((value2 > 1600) && (value1 > 1600)) {
  //   Serial.println("เดินหน้าขวา");
  //   forwordRight();

  // } else if ((value2 > 1600) && (value1 < 1400)) {
  //   Serial.println("เดินหน้าซ้้าย");
  //   forwordLeft();

  // } else if ((value2 < 1400) && (value1 > 1600)) {
  //   Serial.println("เดินหน้าซ้้าย");
  //   backwordRight();

  // } else if ((value2 < 1400) && (value1 < 1400)) {
  //   Serial.println("เดินหน้าซ้้าย");
  //   backwordLeft();

  // }



  // else {
  //   Serial.println("หยุด");
  //   stopbot();
  // }
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
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 0);
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
//////////////////////////////////////////////
void turnLeft() {
  //#### Motor Driver 1 ####
  digitalWrite(INA1, 0);
  digitalWrite(INB1, 1);
  analogWrite(PWM1, speed1);
  //#### Motor Driver 2 ####
  digitalWrite(INA2, 0);
  digitalWrite(INB2, 1);
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
