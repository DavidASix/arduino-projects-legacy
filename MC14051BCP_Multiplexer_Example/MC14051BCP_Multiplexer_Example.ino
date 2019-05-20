// Author: David Anderson Six //
// www.dave6.com //


/*
  This script contains an example for using my MC14051B Multiplexer library.

  DEPENDENCIES
    Multiplexer14051
*/

#include <Multiplexer14051.h>

// powerPin, inhibitor pin, dataPinA, dataPinB, dataPinC //
Multiplexer multiplexer(A5, 7, 2, 3, 4);

const int waitTime = 500;

void setup() {}

void loop() {
  // writePin requires 1 argument from -1 - 7 (-1 = no pins, 0-7 = respective pins) //
  multiplexer.writePin(0);
  delay(waitTime); // Pin X0
  multiplexer.writePin(1);
  delay(waitTime); // Pin X1
  multiplexer.writePin(2);
  delay(waitTime); // Pin X2
  multiplexer.writePin(-1);
  delay(waitTime); // Pins off
  //...ETC
}
