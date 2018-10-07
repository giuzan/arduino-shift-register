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

#include "shift-register.h"
#include "shift-register-manager.h"

ShiftRegisterManager::ShiftRegisterManager()
{
    this->shiftRegister = new ShiftRegister();

    this->dataPin = 0;
    this->latchPin = 0;
    this->clockPin = 0;
    this->masterResetPin = 0;
    this->outputEnablePin = 0;
}

ShiftRegisterManager::ShiftRegisterManager(
    int dataPin,
    int latchPin,
    int clockPin,
    int masterResetPin,
    int outputEnablePin
)
{
    this->shiftRegister = new ShiftRegister();

    this->dataPin = dataPin;
    this->latchPin = latchPin;
    this->clockPin = clockPin;
    this->masterResetPin = masterResetPin;
    this->outputEnablePin = outputEnablePin;
}

ShiftRegister& ShiftRegisterManager::getShiftRegister()
{
    return *(this->shiftRegister);
}

void ShiftRegisterManager::init()
{
    // TODO if there is at least a pin = 0, throw an exception.
}

void ShiftRegisterManager::setOutputPins(bool*)
{}
