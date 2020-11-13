#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "BT.h"


void BT::Bluetooth_inits(void)
{

    Bluetooth.begin(9600);//Iniciar la comunicacion a 9600
}

char BT::Bluetooth_read(void)
{
  char Data;
  if (Bluetooth.available())
      {
        Data = Bluetooth.read();
      }
  return Data;
}

void BT::Bluetooth_sent(char Data)
{
  if (Bluetooth.available())
      {
       Bluetooth.write( Data );
      }
}


void BT::Bluetooth_sent_float(float Data)
{
  if (Bluetooth.available())
      {
       Bluetooth.write( Data );
      }
}