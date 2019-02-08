// Rover Communication System

#include "RFComm.h"

//RH_NRF24 nrf24(8, 53); // Arduino Mega

// Constructor
RFComm::RFComm(uint8_t chipEnablePin, uint8_t slaveSelectPin){
  nrf24 = new RH_NRF24(chipEnablePin, slaveSelectPin);
}

void RFComm::init(){
  (*nrf24).init();
  (*nrf24).setChannel(1);
  (*nrf24).setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm);
}
// Destructor
RFComm::~RFComm(){/* Nothing to destruct*/}

bool RFComm::available(){
  return (*nrf24).available();
}

bool RFComm::hasMessage(){
  len = sizeof(buf);
  bool value = (*nrf24).recv(buf, &len);
  return value;
}

void RFComm::getMessage(uint8_t* message, uint8_t* length){
  memcpy(message, buf, sizeof(uint8_t)*len);
  (*length) = len; 
}

void RFComm::sendMessage(uint8_t* message, uint8_t length){
  (*nrf24).send(message, length);
  (*nrf24).waitPacketSent();
}
