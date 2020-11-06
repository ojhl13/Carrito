
#ifndef BT_H
#define BT_H

#include <SoftwareSerial.h>//Libreria para nuevo puerto serial para el bluetooth
#include "Base_Robot.h"
class BT
{
  private:
  SoftwareSerial Bluetooth; // RX, TX

  public:
  Robot_BT(int TX, int RX): Bluetooth(TX,RX){}
  void Inicializar();
  char Leer_BT();

};




#endif
