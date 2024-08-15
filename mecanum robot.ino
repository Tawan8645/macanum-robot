//############################ mecanum robot by Tawan ATG ROBOT SHOP ################################ 
//#### Motor Driver 1 ####
int INA1 = 2;
int INB1 = 3;
int PWM1 = 4;
//#### Motor Driver 2 ####
int INA2 = 5;
int INB2 = 6;
int PWM2 = 7;
//#### Motor Driver 3 ####
int INA3 = 8;
int INB3 = 9;
int PWM3 = 10;
//#### Motor Driver 4 ####
int INA4 = 11;
int INB4 = 12;
int PWM4 = 13;


//#### speed bord ####
int speed1 = 255 ; 
int speed2 = 255 ; 
int speed3 = 255 ; 
int speed4 = 255 ; 


void setup() {
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
}

void loop() {
 forword();
 delay(3000);
 backword();
 delay(3000);
 turnRight();
 delay(3000);
 turnLeft();
 delay(3000);
 slideRight();
 delay(3000);
 slideLeft();
 delay(3000);
 forwordRight();
 delay(3000);
 forwordLeft();
 delay(3000);
 backwordRight();
 delay(3000);
 backwordLeft();
 delay(3000);
 stopbot();
 delay(3000);
}


///////////////////////////////////////////////
void forword() {
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
void backword() {
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
/////////////////////////////////////////
void forwordRight() {
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
void forwordLeft() {
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
///////////////////////////////////////
void backwordRight() {
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
void backwordLeft() {
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
