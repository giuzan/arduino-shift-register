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

#ifndef SHIFT_REGISTER_H_INCLUDED
#define SHIFT_REGISTER_H_INCLUDED

#include <string>
#include "shift-register-input.h"
#include "shift-register-output.h"

using namespace std;

class ShiftRegister
{
    private:
        bool inputData;
        bool inputLatch;
        bool inputClock;
        bool inputNotOutputEnable;
        bool inputNotMasterReset;
        ShiftRegisterOutput* output;
        ShiftRegisterInput* input;

    public:
        ShiftRegister();
        bool getInputData();
        bool getInputLatch();
        bool getInputClock();
        bool getInputNotOutputEnable();
        bool getInputNotMasterReset();
        ShiftRegisterOutput& getOutput();
        ShiftRegisterInput& getInput();
        void setInputData(bool);
        void setInputLatch(bool);
        void setInputClock(bool);
        void setInputNotOutputEnable(bool);
        void setInputNotMasterReset(bool);
        void setOutput(ShiftRegisterOutput&);
        void setInput(ShiftRegisterInput&);
        string toString();
};

#endif
