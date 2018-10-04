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

#include <string>
#include "shift-register-output.h"

using namespace std;

ShiftRegisterOutput::ShiftRegisterOutput()
{
    for (int i=0; i<ShiftRegisterOutput::DIMENSION; i++) {
        this->pins[i] = false;
    }
}

bool ShiftRegisterOutput::getPin(int index)
{
    return this->pins[index];
}

void ShiftRegisterOutput::setPin(int index, bool status)
{
    this->pins[index] = status;
}

string ShiftRegisterOutput::toString()
{
    string s = "Output:\n";

    for (int i=0; i<ShiftRegisterOutput::DIMENSION; i++) {
        s += "  Pin " + to_string(i) + " (Q" + to_string(i) + "):\t"
            + to_string(this->pins[i]) + "\n";
    }

    return s;
}
