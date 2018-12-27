/*
  74HC595
         _____
   Q1  -|°    |-  VCC
   Q2  -|     |-  Q0
   Q3  -|     |-  DS    (data pin)
   Q4  -|     |-  /OE
   Q5  -|     |-  ST_CP (latch pin)
   Q6  -|     |-  SH_CP (clock pin)
   Q7  -|     |-  /MR
  GND  -|_____|-  Q7'
*/

#include <shift_register.h>

int dimension = 8; // Number of output pins
int dataPin = 8; // Pin connected to Data Pin (DS)
int latchPin = 9; // Pin connected to Latch Pin (ST_CP)
int clockPin = 10; // Pin connected to Clock Pin (SH_CP)
int masterResetPin = 11; // Pin connected to Master Reset Pin (/MR)
int outputEnablePin = 12; // Pin connected to Output Enable Pin (/OE)

ShiftRegister sr = ShiftRegister(
  dimension,
  dataPin,
  latchPin,
  clockPin,
  masterResetPin,
  outputEnablePin
);

int count = 0;

void setup()
{
  Serial.begin(9600);
  sr.init();
}

void loop()
{
  bool output[dimension][dimension] = {
    { true, false, false, false, false, false, false, false,},
    {false,  true, false, false, false, false, false, false,},
    {false, false,  true, false, false, false, false, false,},
    {false, false, false,  true, false, false, false, false,},
    {false, false, false, false,  true, false, false, false,},
    {false, false, false, false, false,  true, false, false,},
    {false, false, false, false, false, false,  true, false,},
    {false, false, false, false, false, false, false,  true,},
  };

  Serial.print(count);
  Serial.print("\n\r");

  sr.setOutputPins(output[count]);

  count = (count + 1) % dimension;

  delay(10000);
}
