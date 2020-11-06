#include "motor.h"
#include "BT.h"

#define RX 2
#define TX 3

SoftwareSerial mySerial(RX,TX); // RX, TX


void setup() {
  // put your setup code here, to run once:
  Start_motors();


}

void loop() {
  // put your main code here, to run repeatedly:

}
