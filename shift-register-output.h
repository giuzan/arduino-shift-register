/*
  74HC595
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

#ifndef SHIFT_REGISTER_OUTPUT_H_INCLUDED
#define SHIFT_REGISTER_OUTPUT_H_INCLUDED

#include <string>

using namespace std;

class ShiftRegisterOutput
{
    private:
        bool pins[8];
    public:
        static const int DIMENSION = 8;
        ShiftRegisterOutput();
        bool getPin(int);
        void setPin(int, bool);
        string toString();
};

#endif
