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

#include "Arduino.h"
#include "Multiplexer14051.h"

Multiplexer::Multiplexer(int powerPin, int inhibitPin, int dataPinA, int dataPinB, int dataPinC)
{
  pinMode(powerPin, OUTPUT);
  pinMode(inhibitPin, OUTPUT);
  pinMode(dataPinA, OUTPUT);
  pinMode(dataPinB, OUTPUT);
  pinMode(dataPinC, OUTPUT);
  pinMode(dataPinC, OUTPUT);

  _inhibit = inhibitPin;
  _pinA = dataPinA;
  _pinB = dataPinB;
  _pinC = dataPinC;
  analogWrite(powerPin, 255);
}

void Multiplexer::writePin(int pinNum) {
    int pins[8][3] = {
    //{ pinA, pinB, pinC }
      { LOW, LOW, LOW }, // X0
      { HIGH, LOW, LOW }, // X1
      { LOW, HIGH, LOW }, // X2
      { HIGH, HIGH, LOW }, // X3
      { LOW, LOW, HIGH }, // X4
      { HIGH, LOW, HIGH }, // X5
      { LOW, HIGH, HIGH }, // X6
      { HIGH, HIGH, HIGH } // X7
    };

    // -1 as pin number returns all pins dark
    if (pinNum == -1) {
      digitalWrite(_inhibit, HIGH);
    } else {
      digitalWrite(_inhibit, LOW);
      digitalWrite(_pinA, pins[pinNum][0]);
      digitalWrite(_pinB, pins[pinNum][1]);
      digitalWrite(_pinC, pins[pinNum][2]);
    }
}
