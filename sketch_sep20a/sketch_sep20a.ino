#include <Wire.h>


const int MPU6050_ADDRESS = 0x68;
unsigned long previousTime = 0;

int16_t readSensorValue(byte regAddress) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(regAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 2);
  byte highByte = Wire.read();
  byte lowByte = Wire.read();
  return (highByte <<8)|lowByte;

void setup() {
  // put your setup code here, to run once:
 Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1A);
  Wire.write(0x03);
  Wire.endTransmission();

}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currentTime = millis(); 
    unsigned long elapsedTime = currentTime - previousTime;


  previousTime = currentTime;

  int16_t rawYaw = readSensorValue(0x47);
  float yawAngle = rawYaw / 131.0; 
  float theta1 = yawAngle * (elapsedTime/1000.0);
 float theta =+ theta1;
  Serial.print("Yaw angle: ");
  Serial.println(yawAngle);
  Serial.println(elapsedTime);
  Serial.println(theta);

  delay(100);
}



