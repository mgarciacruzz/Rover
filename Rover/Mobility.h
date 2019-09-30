#ifndef Mobility_h
#define Mobility_h

#include <Wire.h>
#include<AFMotor.h>

class Mobility{
  public:
    Mobility(uint8_t rightMotorPos, uint8_t leftMotorPos);
    ~Mobility();

    // Methods
    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
    void init();
    void stop();
    
  private:
    AF_DCMotor *rightMotor;
    AF_DCMotor *leftMotor;

};
#endif
