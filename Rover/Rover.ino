#ifndef DEBUG
#define DEBUG
#endif

#include <RFComm.h>



RFComm comm(8, 53);

uint8_t command[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len;

void setup(){
  Serial.begin(9600);
  while (!Serial)
    ;
    comm.init();

}
 
void loop(){
  if(comm.available()){
    //Serial.println("connected!");
    if(comm.hasMessage()){
      comm.getMessage(command, &len);

      #ifdef DEBUG
      Serial.print("got request: ");
      Serial.println((char*)command);
      #endif
      
    }
  }
  else
  {
    //Serial.println("Not Connected!");
  }
}

void Parser(char* command){
  
}
