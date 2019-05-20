/*
  Author: David Anderson Six
  Date: 05/20/2019
  License: Released into the public domain.
  Contact: www.dave6.com
*/

/*
  This library creates an easy wrapper for the MC14051B Multiplexer.

  // See PDF in containing folder for truth table and pin layout //
*/

#ifndef Multiplexer_h
#define Multiplexer_h

  #include "Arduino.h"

  class Multiplexer
  {
    public:
      Multiplexer(int powerPin, int inhibitPin, int dataPinA, int dataPinB, int dataPinC);
      void writePin(int pinNum);
    private:
      int powerPin;
      int _inhibit;
      int _pinA;
      int _pinB;
      int _pinC;
  };

#endif
