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
#include "shift-register-input.h"

ShiftRegisterInput::ShiftRegisterInput()
{
    this->data = false;
    this->latch = false;
    this->clock = false;
    this->notOutputEnable = false;
    this->notMasterReset = true;
}

bool ShiftRegisterInput::getData()
{
    return this->data;
}

bool ShiftRegisterInput::getLatch()
{
    return this->latch;
}

bool ShiftRegisterInput::getClock()
{
    return this->clock;
}

bool ShiftRegisterInput::getNotOutputEnable()
{
    return this->notOutputEnable;
}

bool ShiftRegisterInput::getNotMasterReset()
{
    return this->notMasterReset;
}

void ShiftRegisterInput::setData(bool status)
{
    this->data = status;
}

void ShiftRegisterInput::setLatch(bool status)
{
    this->latch = status;
}

void ShiftRegisterInput::setClock(bool status)
{
    this->clock = status;
}

void ShiftRegisterInput::setNotOutputEnable(bool status)
{
    this->notOutputEnable = status;
}

void ShiftRegisterInput::setNotMasterReset(bool status)
{
    this->notMasterReset = status;
}

string toString()
{
    string s = "Input:\n";

    s += "  Data (DS):\t\t\t" + to_string(this->data) + "\n";
    s += "  Latch (ST_CP):\t\t" + to_string(this->latch) + "\n";
    // TODO
    s += "  Clock (SH_CP):\t\t" + to_string(this->inputClock) + "\n";
    s += "  Not Output Enable (/OE):\t" + to_string(this->inputNotOutputEnable)
            + "\n";
    s += "  Not Master Reset (/MR):\t" + to_string(this->inputNotMasterReset)
            + "\n";
}
