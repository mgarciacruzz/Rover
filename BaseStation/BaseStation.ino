#include <RFComm.h>

RFComm comm(8, 10);

uint8_t message[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len;

char receivedChars[RH_NRF24_MAX_MESSAGE_LEN]; // an array to store the received data
boolean newData = false;

void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only

  Serial.println("Base station v0.1.0");
  comm.init();
}


void loop()
{
  recvWithEndMarker();
  sendData();
  Serial.flush();
}

void recvWithEndMarker() {
 static byte ndx = 0;
 char endMarker = '\n';
 char rc;
 
 // if (Serial.available() > 0) {
  while (Serial.available() > 0 && newData == false) {
  rc = Serial.read();

    if (rc != endMarker) {
     receivedChars[ndx] = rc;
     ndx++;
     if (ndx >= RH_NRF24_MAX_MESSAGE_LEN) {
      ndx = RH_NRF24_MAX_MESSAGE_LEN - 1;
     }
    }
   else {
     receivedChars[ndx] = '\0'; // terminate the string
     ndx = 0;
     newData = true;
    }
  }
}

void sendData() {
  if (newData == true) {
    Serial.print("echo: ");
    Serial.println(receivedChars);
    comm.sendMessage((uint8_t*)receivedChars, RH_NRF24_MAX_MESSAGE_LEN);
    newData = false;
  }
}
