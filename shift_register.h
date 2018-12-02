/*
  74HC595 (only one)
         _____
   Q1  -|°    |-  VCC
   Q2  -|     |-  Q0
   Q3  -|     |-  DS    (data pin)
   Q4  -|     |-  /OE
   Q5  -|     |-  ST_CP (latch pin)
   Q6  -|     |-  SH_CP (clock pin)
   Q7  -|     |-  /MR (master reset pin)
  GND  -|_____|-  Q7'
*/

/*
  74HC595 (two or more)

         _____
   Q1  -|°    |-  VCC
   Q2  -|     |-  Q0
   Q3  -|     |-  DS (data pin)
   Q4  -|     |-  /OE <--> /OE(2)
   Q5  -|     |-  ST_CP (latch pin) <--> ST_CP(2)
   Q6  -|     |-  SH_CP (clock pin) <--> SH_CP(2)
   Q7  -|     |-  /MR (master reset pin) <--> /MR(2)
  GND  -|_____|-  Q7' <--> DS(2)

         _____
   Q1  -|°    |-  VCC
   Q2  -|     |-  Q0
   Q3  -|     |-  DS <--> Q7'(1)
   Q4  -|     |-  /OE <--> /OE(1)
   Q5  -|     |-  ST_CP <--> ST_CP(1)
   Q6  -|     |-  SH_CP <--> SH_CP(1)
   Q7  -|     |-  /MR <--> /MR(1)
  GND  -|_____|-  Q7'
*/

#ifndef SHIFT_REGISTER_INCLUDED_H
#define SHIFT_REGISTER_INCLUDED_H

#include "Arduino.h"

class ShiftRegister
{
    private:
        int dimension;
        int dataPin;
        int latchPin;
        int clockPin;
        int masterResetPin;
        int outputEnablePin;

    public:
        ShiftRegister();
        ShiftRegister(int, int, int, int, int, int);
        void init();
        void setOutputPins(bool*);
        void disableOutput();
        void enableOutput();
        int getDimension() const;
};

#endif
