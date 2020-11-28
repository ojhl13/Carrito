#ifndef AddressedUart_H
#define AddressedUart_H

//#include <WProgram.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

class AddressedUart {
  private:
    byte _RX;
    byte _TX;
    int _ADDRESS;
    int _UARTBAUD;
    SoftwareSerial UART;
  public:
    AddressedUart(byte RX, byte TX, int Address);
    void begin(int UARTBAUD);
};

#endif
