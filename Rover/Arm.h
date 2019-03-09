#ifndef Arm_h
#define Arm_h

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Arm{
  public:
    Arm(int initialPos);
    ~Arm();

    // Methods
    void moveBase(uint8_t degrees);
    void moveShoulder(uint8_t degrees);
    void moveElbow(uint8_t degrees);
    void moveWrist(uint8_t degrees);

    // claw
    void rotateClaw(uint8_t degrees);
    void hClaw();
    void vClaw();
    void openClaw();
    void closeClaw();
    
    void startingPos();
	void init();

  private:
    int _initialPos;

};
#endif
