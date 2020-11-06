#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include <SoftwareSerial.h>//Libreria para nuevo puerto serial para el bluetooth
#include "BT.h"

#define RX 2
#define TX 3

extern SoftwareSerial mySerial(RX,TX); // RX, TX

void Bluetooth_inits(void)
{

    mySerial.begin(9600);//Iniciar la comunicacion a 9600
}

char Bluetooth_read(void)
{
  char Data;
  if (mySerial.available() > 0)
      {
        Data = mySerial.read();
      }
  return Data;
}

void Bluetooth_sent(char Data)
{
  if (mySerial.available() > 0)
      {
       mySerial.write( Data );
      }
}
