#ifndef Lights_h
#define Lights_h

#include <Arduino.h>

class Lights{
  public:
    Lights(int leftLightPin, int rightLightPin);
    ~Lights();

    // Methods
    void frontLightsOn();
    void frontLightsOff();
    
  private:
    int _leftLightPin;
	  int _rightLightPin;
};
#endif
