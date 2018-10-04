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
    this->inputData = false;
    this->inputLatch = false;
    this->inputClock = false;
    this->inputNotOutputEnable = false;
    this->inputNotMasterReset = true;
    this->output = new ShiftRegisterOutput();
}

bool ShiftRegister::getInputData()
{
    return this->inputData;
}

bool ShiftRegister::getInputLatch()
{
    return this->inputLatch;
}

bool ShiftRegister::getInputClock()
{
    return this->inputClock;
}

bool ShiftRegister::getInputNotOutputEnable()
{
    return this->inputNotOutputEnable;
}

bool ShiftRegister::getInputNotMasterReset()
{
    return this->inputNotMasterReset;
}

ShiftRegisterOutput *ShiftRegister::getOutput()
{
    return this->output;
}

void ShiftRegister::setInputData(bool status)
{
    this->inputData = status;
}

void ShiftRegister::setInputLatch(bool status)
{
    this->inputLatch = status;
}

void ShiftRegister::setInputClock(bool status)
{
    this->inputClock = status;
}

void ShiftRegister::setInputNotOutputEnable(bool status)
{
    this->inputNotOutputEnable = status;
}

void ShiftRegister::setInputNotMasterReset(bool status)
{
    this->inputNotMasterReset = status;
}

void ShiftRegister::setOutput(ShiftRegisterOutput *output)
{
    this->output = output;
}

string ShiftRegister::toString()
{
    string s = "Input:\n";

    s += "  Data (DS):\t\t\t" + to_string(this->inputData) + "\n";
    s += "  Latch (ST_CP):\t\t" + to_string(this->inputLatch) + "\n";
    s += "  Clock (SH_CP):\t\t" + to_string(this->inputClock) + "\n";
    s += "  Not Output Enable (/OE):\t" + to_string(this->inputNotOutputEnable)
            + "\n";
    s += "  Not Master Reset (/MR):\t" + to_string(this->inputNotMasterReset)
            + "\n";

    s += this->output->toString();

    return s;
}
