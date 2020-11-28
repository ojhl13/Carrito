#include "AddressedUart.h"

//<<constructor>> setup the LED, make pin 13 an OUTPUT
AddressedUart::AddressedUart(byte RX, byte TX, int Address){
  _RX = RX;
  _TX = TX;
  _ADDRESS = Address;
}

//turn the LED on
void AddressedUart::begin(int UARTBAUD){
  _UARTBAUD = UARTBAUD;
  UART.begin(_UARTBAUD);
}
