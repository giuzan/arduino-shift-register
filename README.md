<html>
<h1>Shift Register 74HC595 Driver</h1>
  <h2>Introduction</h2>
  <p>This Arduino library allows to drive one ore more 74HC595 shift registers in order to increase the output pins. Every <em>loop</em> you can set the values the output pins should have.</p>
  
  <h2>Single Shift Register</h2>
  <h3>Wiring</h3>
  <p><img src="https://github.com/giuzan/arduino-shift-register/blob/master/doc/files/circuit_single_shift_register.svg"></p>
  <h3>Code</h3>
  <pre>

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

  </pre>
  <p>You can find the example project file <a href="https://github.com/giuzan/arduino-shift-register/blob/master/doc/example_sketches/single_shift_register_example.ino">here</a></p>
  
  <h2>Multiple Shift Registers</h2>
  <p>TODO</p>
</html>
