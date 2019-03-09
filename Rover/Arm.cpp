// Rover Communication System

#include "Arm.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


// Servo Position Limits
#define BASE_SERVOMIN  150 
#define BASE_SERVOMAX  600 

#define SHOULDER_SERVOMIN  150 
#define SHOULDER_SERVOMAX  600 

#define ELBOW_SERVOMIN  150 
#define ELBOW_SERVOMAX  600 

#define WRIST_SERVOMIN  150 
#define WRIST_SERVOMAX  600 

#define CLAW_ROTATE_SERVOMIN  150 
#define CLAW_ROTATE_SERVOMAX  600 

#define CLAW_SERVOMIN  150 
#define CLAW_SERVOMAX  600 

// servo Positions offset
#define BASE_POS 0
#define SHOULDER_POS 1
#define ELBOW_POS 2
#define WRIST_POS 3
#define CLAW_ROTATE_POS 4
#define CLAW_POS 5
// Constructor
Arm::Arm(int initialPos){
  _initialPos = initialPos;

}

// Destructor
Arm::~Arm(){/* Nothing to destruct*/}

// Methods
void Arm::init(){
	pwm.begin();
  
	pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

	delay(10);
}

void Arm::moveBase(uint8_t degrees){
	uint16_t pulselength = map(degrees, 0, 180, BASE_SERVOMIN, BASE_SERVOMAX);
  Serial.println(pulselength);
  pwm.setPWM(_initialPos + BASE_POS, 0, pulselength);
}

void Arm::moveShoulder(uint8_t degrees){
  uint16_t pulselength = map(degrees, 0, 180, SHOULDER_SERVOMIN, SHOULDER_SERVOMAX);
  Serial.println(pulselength);
  pwm.setPWM(_initialPos + SHOULDER_POS, 0, pulselength);
}

void Arm::moveElbow(uint8_t degrees){
  degrees = 90 - degrees;
  uint16_t pulselength = map(degrees, 0, 180, ELBOW_SERVOMIN, ELBOW_SERVOMAX);
  Serial.println(pulselength);
  pwm.setPWM(_initialPos + ELBOW_POS, 0, pulselength);
}

void Arm::moveWrist(uint8_t degrees){
  degrees = 90 - degrees;
  uint16_t pulselength = map(degrees, 0, 180, WRIST_SERVOMIN, WRIST_SERVOMAX);
  Serial.println(pulselength);
  pwm.setPWM(_initialPos + WRIST_POS, 0, pulselength);
}

void Arm::rotateClaw(uint8_t degrees){
  uint16_t pulselength = map(degrees, 0, 180, CLAW_ROTATE_SERVOMIN, CLAW_ROTATE_SERVOMAX);
  Serial.println(pulselength);
  pwm.setPWM(_initialPos + CLAW_ROTATE_POS, 0, pulselength);
}

void Arm::openClaw(){
  uint16_t pulselength = map(20, 0, 180, CLAW_SERVOMIN, CLAW_SERVOMAX);
  pwm.setPWM(_initialPos + CLAW_POS, 0, pulselength);
}

void Arm::closeClaw(){
  uint16_t pulselength = map(85, 0, 180, CLAW_SERVOMIN, CLAW_SERVOMAX);
  pwm.setPWM(_initialPos + CLAW_POS, 0, pulselength);  
}
void Arm::hClaw(){
  rotateClaw(60);
}

void Arm::vClaw(){
  rotateClaw(0);
}

void Arm::startingPos(){
  moveBase(70);
  moveShoulder(90);
  moveElbow(90);
  moveWrist(90);
  openClaw();
  hClaw();
}
