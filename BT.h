
#ifndef BT_H
#define BT_H

#include <SoftwareSerial.h>//Libreria para nuevo puerto serial para el bluetooth



#define RX_PIN 2
#define TX_PIN 3

class BT
{
  private:
  SoftwareSerial Bluetooth; // RX, TX

  public:
  BT(int TX, int RX): Bluetooth(TX,RX){}
  void Bluetooth_inits(void);
  char Bluetooth_read(void);
  void Bluetooth_sent(char Data);
  void Bluetooth_sent_float(float Data);


};




#endif
