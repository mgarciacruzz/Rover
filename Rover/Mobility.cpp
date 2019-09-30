// Rover Communication System

#include "Mobility.h"

// Constructor
Mobility::Mobility(uint8_t rightMotorPos, uint8_t leftMotorPos){
  leftMotor = new AF_DCMotor(leftMotorPos);
  rightMotor = new AF_DCMotor(rightMotorPos);
}

// Destructor
Mobility::~Mobility(){/* Nothing to destruct*/}

void Mobility::init(){
  (*leftMotor).setSpeed(255);
  (*rightMotor).setSpeed(255);
}

// Methods
void Mobility::moveForward(){
  (*rightMotor).run(FORWARD);
  (*leftMotor).run(FORWARD);
}

void Mobility::moveBack(){
  (*rightMotor).run(BACKWARD);
  (*leftMotor).run(BACKWARD);
}

void Mobility::moveLeft(){

}

void Mobility::moveRight(){

}

void Mobility::stop(){
  (*rightMotor).run(RELEASE);
  (*leftMotor).run(RELEASE);
}
