# PostureCorrectingDevice
This project will help you in keeping up your posture.

You can find proof of concept images under "Images" folder.

The pitch presentation included(supressing some slides)

# DESCRIPTION
We are now living in work from home era(at least from more than one year). Most of us are working sitting in front of monitors/screens for long hours. During these long hours we unintentionally ignore our sitting habits.
By sitting habits I mean sitting properly, ignorance of which gives rise to health issue. To be specific back pain.
I also went through the same issue, and decided to make a device which alert me whenever my posture is wrong.
And this will definitely improve productivity and helps in providing a healthy life.

# Concept of the device:
Whenever a person with the device leans forward the device alert by sending a signal to a buzzer/vibration sensor, and as soon as the person becomes straight it stops sending signal to the buzzer/vibration sensor.
Planning to use a microcontroller, a gyroscope sensor and buzzer/vibration sensor and obviously a small battery to power it up.
Also I want to make it tiny to be like wearable electronics.

# DETAILS
 This section can be used to explain everything about your project.
So here we will be discussing the main components used and then working of the whole project and more stuff in detail.

The main component of this project is microcontroller ATTINY85 and MPU6050 - the Gyro/accelerometer sensor. Then we have other components like vibration motor/sensor, battery and switches.

# Component Description
## 1> ATTINY85 microcontroller
The main reason for using it is because it is one of the smallest uc, having 8K FLASH which is sufficient for programming, 512B RAM and it supports SPI interfacing which is required to wirk with the MPU6050 Accelerometer/gyro sensor. It has 6 no. of I/O's which is enough for interfacing with other components.

ATTINY can be operated with 2.7V to 5.5V so easy to use with 3.7V rechargable batteries.

pin details-

![ATtiny85-Microcontroller](https://user-images.githubusercontent.com/30037314/168246885-1db9f4cb-c223-4aa3-a61e-50ae13126756.jpg)


pin configurations-
![ATtiny85-Pinout](https://user-images.githubusercontent.com/30037314/168247028-5a035e67-c276-4e25-bf5f-261847bc75ab.png)


## 2> MPU6050 Accelerometer and Gyroscope Module
The MPU6050 is a Micro Electro-Mechanical Systems (MEMS) which consists of a 3-axis Accelerometer and 3-axis Gyroscope inside it. This helps us to measure acceleration, velocity, orientation, displacement and many other motion related parameter of a system or object. This module also has a (DMP) Digital Motion Processor inside it which is powerful enough to perform complex calculation and thus free up the work for Microcontroller. It also supports I2C Communication protocol.

It`s working voltage range is 3V to 5V.

![MPU6050-Module-Gyroscope-Axis](https://user-images.githubusercontent.com/30037314/168247599-9c459490-adc0-437c-9585-3a65526e414d.jpg)



## 3> Viberation Motor
It`s used for feedback/alert purpose. It has operating voltage of 3.0V
![Vibro_motor_30109531-01](https://user-images.githubusercontent.com/30037314/168247770-fde6c503-fd77-4a77-80ad-ab35d128b279.jpg)


## 4> Battery 3.7V
 Lipo Rechargeable Battery
![3 7v-lipo-battery-2-300x259](https://user-images.githubusercontent.com/30037314/168248470-1f2615ef-1fab-42bf-9cea-cba7191df6a3.jpg)


## 5> TP4056  
Lithium Battery Charger Module having Input interface as Micro USB

![tp4056-1a-charging-with-current-protection](https://user-images.githubusercontent.com/30037314/168248743-5a2812d6-395c-4589-9c10-41b02735612a.jpg)

# Working

![BlockDiagramPostureCorrectingDevice](https://user-images.githubusercontent.com/30037314/168249075-f8dcb229-7f82-44e7-a9b0-6525d1fd626d.jpg)

First while programming the microcontroller we define the cutoff for the Accelerometer /Gyroscope sensor. By cutoff I mean the value where it triggers and activates the vibration motor/sensor.

So Accelerometer/Gyroscope tracks the cutoff value ---> if value crossed ----> sends signal to microcontroller ----> microcontroller activates(or deactivates) the vibration motor/sensor(or LED in case for prototype circuit, which is used for optical fedback for human eyes, the LED may be removed in final make of the device.)

Thus it alerts the user for correcting his/her posture.

