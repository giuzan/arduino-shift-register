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

#include <iostream>
#include "shift-register.h"
#include "shift-register-output.h"

using namespace std;

int main()
{
    system("clear");

    cout << "********************************" << endl;
    cout << "*  ShiftRegister Testing Tool  *" << endl;
    cout << "********************************" << endl << endl;

    ShiftRegister sr;
    ShiftRegisterOutput& o = sr.getOutput();

    bool value;

    cout << "> Data (DS): ";
    cin >> value;
    sr.setInputData(value);

    cout << "> Latch (ST_CP): ";
    cin >> value;
    sr.setInputLatch(value);

    cout << "> Data (SH_CP): ";
    cin >> value;
    sr.setInputClock(value);

    cout << "> Not Output Enable (/OE): ";
    cin >> value;
    sr.setInputNotOutputEnable(value);

    cout << "> Not Master Reset (/MR): ";
    cin >> value;
    sr.setInputNotMasterReset(value);

    for (int i=0; i<ShiftRegisterOutput::DIMENSION; i++) {
        cout << "> Pin " << i << ": (Q" << i << "): ";
        cin >> value;
        o.setPin(i, value);
    }

    cout << endl;

    cout << sr.toString() << endl;
}
