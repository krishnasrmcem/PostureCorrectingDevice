/*
by krishna.mohan.ec@gmail.com

For posture corrector Connection For Digispark & Attiny 85: 
Digispark--> MPU6050(P0-SDA, P2-SCL, VCC & GND accordingly)
DIGISPARK-->LED/Vibrator motor (PIN1 Or PIN3 One is forward active and another is backward movment active, 
can be used according to placement of mpu6050)

To operate with attiny85 just change PIN1 with 6 and PIN3 with 2, which are pin no of attiny85
Only AcZ(Accelerometer Z axis) is enough for the operation.

*/

#include <Wire.h>
//#include <TinyWireM.h>

const int ledPin1   = 6;
const int ledPin3   = 2; // optional

const int MPU=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ;

void setup() {
   
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  Wire.begin();
  Wire.beginTransmission(MPU); // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B); // Talk to the register 6B
  Wire.write(0x00); // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);  //end the transmission
   
}

void loop() {
  // measure because we may woop
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACC_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,6); // we need to read all 6 registers, really!

  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();

  if (AcZ > 0) {
   digitalWrite(ledPin1, HIGH);     
   digitalWrite(ledPin3, LOW);
  }
  
  else if (AcZ < 0){
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin1, LOW); 
      }
  
}
