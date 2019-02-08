#ifndef RFComm_H
#define RFComm_H

#include <SPI.h>
#include <RH_NRF24.h>

class RFComm{
  public:
    RFComm(uint8_t chipEnablePin, uint8_t slaveSelectPin);
    ~RFComm();
    bool available();
    bool hasMessage();
    void getMessage(uint8_t* message, uint8_t* length);
    void sendMessage(uint8_t* messsage, uint8_t length);  
    void init();
    
  private:
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len;
    RH_NRF24 *nrf24;
};
#endif
