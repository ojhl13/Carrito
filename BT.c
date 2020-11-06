#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "BT.h"


void BT::Bluetooth_inits(void)
{

    mySerial.begin(9600);//Iniciar la comunicacion a 9600
}

char BT::Bluetooth_read(void)
{
  char Data;
  if (mySerial.available() > 0)
      {
        Data = mySerial.read();
      }
  return Data;
}

void BT::Bluetooth_sent(char Data)
{
  if (mySerial.available() > 0)
      {
       mySerial.write( Data );
      }
}
