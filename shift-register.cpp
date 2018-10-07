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
#include "shift-register.h"

using namespace std;

ShiftRegister::ShiftRegister()
{
    this->output = new ShiftRegisterOutput();
    this->input = new ShiftRegisterInput();
}

ShiftRegisterOutput& ShiftRegister::getOutput()
{
    return *(this->output);
}

ShiftRegisterInput& ShiftRegister::getInput()
{
    return *(this->input);
}

string ShiftRegister::toString()
{
    string s = "Input:\n";

    s += this->input->toString();
    s += this->output->toString();

    return s;
}
