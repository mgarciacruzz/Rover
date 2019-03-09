#ifndef DEBUG
#define DEBUG
#endif

#include <stdio.h>
#include <string.h>

#include <RFComm.h>
#include <Lights.h>
#include "Arm.h"

Lights lights(13, 10);
RFComm comm(8, 53);
Arm arm(8);

uint8_t command[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len;

void setup(){
  Serial.begin(9600);
  while (!Serial)
    ;
    
    comm.init();
    arm.init();

    arm.startingPos();
}
 
void loop(){
  if(comm.available()){
    //Serial.println("connected!");
    if(comm.hasMessage()){
      comm.getMessage(command, &len);
      
      // Parsing command
      Parser(command);
    } // End reading command
  } // Command available

  Serial.flush();
}

void Parser(char* command){
  char* tokens[5];
  char* temp;
  
  int i = 0;
  temp = strtok (command," ");
  while (temp != NULL)
  {
    tokens[i++] = temp;  
    temp = strtok (NULL, " ");
  }

  // if command does not exists return
  if(i == 0)
    return;

  if(strcmp (tokens[0],"lights") == 0){
    #ifdef DEBUG
    Serial.println("Debug: Lights command");
    #endif

    lightsCommand(tokens, i);
  }
  else if(strcmp (tokens[0],"arm") == 0){
    #ifdef DEBUG
    Serial.println("Debug: Arm command");
    #endif

    armCommand(tokens, i);
  }
  else{
    #ifdef DEBUG
    Serial.println("Invalid Command");
    #endif
  }
}

void lightsCommand(char* tokens[], int i){
  // exit if it didnt find 3 parameters
    if(i < 2)
      return;

    // Wrong light section
    if(strcmp (tokens[1],"front") != 0)
      return;
    
    if(strcmp (tokens[2],"on") == 0)
      lights.frontLightsOn();
    else if(strcmp (tokens[2],"off") == 0)
      lights.frontLightsOff();
}

void armCommand(char* tokens[], int i){
  // exit if it didnt find 3 parameters
  if(i < 2)
    return;

  if(strcmp (tokens[1],"base") == 0){
    int deg = atoi(tokens[2]);
    if(deg >= 0)
      arm.moveBase(deg);
  }
  else if(strcmp (tokens[1],"shoulder") == 0){
    int deg = atoi(tokens[2]);
    if(deg >= 0)
      arm.moveShoulder(deg);
  }
  else if(strcmp (tokens[1],"elbow") == 0){
    int deg = atoi(tokens[2]);
    if(deg >= 0)
      arm.moveElbow(deg);
  }
  else if(strcmp (tokens[1],"wrist") == 0){
    int deg = atoi(tokens[2]);
    if(deg >= 0)
      arm.moveWrist(deg);
  }
   else if(strcmp (tokens[1],"rotateclaw") == 0){
    int deg = atoi(tokens[2]);
    if(deg >= 0)
      arm.rotateClaw(deg);
  }
  else if(strcmp (tokens[1],"claw") == 0){
    if(strcmp (tokens[2],"h") == 0)
      arm.hClaw();
    else if(strcmp (tokens[2],"v") == 0)
      arm.vClaw();
    else if(strcmp (tokens[2],"open") == 0)
      arm.openClaw();
    else if(strcmp (tokens[2],"close") == 0)
      arm.closeClaw();
  }
  
      
}
