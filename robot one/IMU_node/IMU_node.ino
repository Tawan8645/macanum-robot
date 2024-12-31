#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
  Serial.println("MPU6050 connected");
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // Send sensor data over serial
  Serial.print("ax: ");
  Serial.print(ax);
  Serial.print(", ay: ");
  Serial.print(ay);
  Serial.print(", az: ");
  Serial.print(az);
  Serial.print(", gx: ");
  Serial.print(gx);
  Serial.print(", gy: ");
  Serial.print(gy);
  Serial.print(", gz: ");
  Serial.println(gz);

  delay(100);  // Small delay
}
