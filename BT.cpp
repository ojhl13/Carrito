#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "BT.h"


void BT::Bluetooth_inits(void)
{

    Bluetooth.begin(9600);//Iniciar la comunicacion a 9600
}

char BT::Bluetooth_read(void)
{
  char Data_readed;
  Data_readed=0;
  if (Bluetooth.available())
      {
        Data_readed= Bluetooth.read();
      }
  return Data_readed;
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
