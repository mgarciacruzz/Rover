// Rover Communication System

#include "Lights.h"

// Constructor
Lights::Lights(int leftLightPin, int rightLightPin){
  _leftLightPin = leftLightPin;
  _rightLightPin = rightLightPin;
  
  pinMode(_leftLightPin, OUTPUT);
  pinMode(_leftLightPin, OUTPUT);
  
}

// Destructor
Lights::~Lights(){/* Nothing to destruct*/}

// Methods
void Lights::frontLightsOn(){
	digitalWrite(_leftLightPin, HIGH);
	digitalWrite(_rightLightPin, HIGH);
}

void Lights::frontLightsOff(){
	digitalWrite(_leftLightPin, LOW);
	digitalWrite(_rightLightPin, LOW);
}
