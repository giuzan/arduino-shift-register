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

#ifndef SHIFT_REGISTER_MANAGER_INCLUDED_H
#define SHIFT_REGISTER_MANAGER_INCLUDED_H

class ShiftRegisterManager
{
    private:
        ShiftRegister* shiftRegister;
        int dataPin;
        int latchPin;
        int clockPin;
        int masterResetPin;
        int outputEnablePin;

    public:
        ShiftRegisterManager();
        ShiftRegisterManager(int, int, int, int, int);
        ShiftRegister& getShiftRegister();
        void init();
        void setOutputPins(bool*);
};

#endif
