#ifndef BLACKBOX_H
#define BLACKBOX_H
#include "Arduino.h" //Permite utilizar los comandos de Arduino

class Blackbox
{
   private:

   public:
      Blackbox():
      void Start_system(void);
      void test (void);
      float read_speed(void);
}

#endif
