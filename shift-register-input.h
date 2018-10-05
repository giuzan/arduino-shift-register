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

#ifndef SHIFT_REGISTER_INPUT_H_INCLUDED
#define SHIFT_REGISTER_INPUT_H_INCLUDED

#include <string>

using namespace std;

class ShiftRegisterInput
{
    private:
        bool data;
        bool latch;
        bool clock;
        bool notOutputEnable;
        bool notMasterReset;
    public:
        ShiftRegisterInput();
        bool getData();
        bool getLatch();
        bool getClock();
        bool getNotOutputEnable();
        bool getNotMasterReset();
        void setData(bool);
        void setLatch(bool);
        void setClock(bool);
        void setNotOutputEnable(bool);
        void setNotMasterReset(bool);
        string toString();
};

#endif
