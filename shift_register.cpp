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

#include "Arduino.h"
#include "shift_register.h"

ShiftRegister::ShiftRegister()
{
    this->dimension = 8;
    this->dataPin = 0;
    this->latchPin = 0;
    this->clockPin = 0;
    this->masterResetPin = 0;
    this->outputEnablePin = 0;
}

ShiftRegister::ShiftRegister(
    int dimension,
    int dataPin,
    int latchPin,
    int clockPin,
    int masterResetPin,
    int outputEnablePin
)
{
    this->dimension = dimension;
    this->dataPin = dataPin;
    this->latchPin = latchPin;
    this->clockPin = clockPin;
    this->masterResetPin = masterResetPin;
    this->outputEnablePin = outputEnablePin;
}

void ShiftRegister::init()
{
    pinMode(this->latchPin, OUTPUT);
    pinMode(this->clockPin, OUTPUT);
    pinMode(this->dataPin, OUTPUT);
    pinMode(this->masterResetPin, OUTPUT);
    pinMode(this->outputEnablePin, OUTPUT);
}

void ShiftRegister::setOutputPins(bool* outputPins)
{
    digitalWrite(this->masterResetPin, LOW);
    digitalWrite(this->masterResetPin, HIGH);

    for (int i=this->dimension-1; i>=0; i--) {
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->latchPin, LOW);
        digitalWrite(this->dataPin, LOW);

        if (outputPins[i]) {
            digitalWrite(this->dataPin, HIGH);
        } else {
            digitalWrite(this->dataPin, LOW);
        }

        digitalWrite(this->clockPin, HIGH);
        digitalWrite(this->dataPin, LOW);
        digitalWrite(this->clockPin, LOW);
    }

    digitalWrite(this->latchPin, HIGH);
    digitalWrite(this->latchPin, LOW);
}

void ShiftRegister::disableOutput()
{
    digitalWrite(this->outputEnablePin, HIGH);
}

void ShiftRegister::enableOutput()
{
    digitalWrite(this->outputEnablePin, LOW);
}

int ShiftRegister::getDimension() const
{
    return this->dimension;
}
