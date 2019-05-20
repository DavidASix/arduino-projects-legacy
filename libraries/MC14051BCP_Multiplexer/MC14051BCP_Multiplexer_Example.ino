// Author: David Anderson Six //
// www.dave6.com //


/*
  This script contains an example for the MC14051B Multiplexer.
  // See PDF in containing folder for truth table and pin layout
  DEPENDENCIES
*/
const int
  powerPin = A5, //Pin for output power
  dataPinA = 2,
  dataPinB = 3,
  dataPinC = 4,
  inhibit = 7
  ;

const int waitTime = 500;

void setup() {
  pinMode(dataPinA, OUTPUT);
  pinMode(dataPinB, OUTPUT);
  pinMode(dataPinC, OUTPUT);
  pinMode(inhibit, OUTPUT);
  analogWrite(powerPin, 255); //Value of outputing pin

}

void writePin(int pinNum) {
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

  digitalWrite(dataPinA, pins[pinNum][0]);
  digitalWrite(dataPinB, pins[pinNum][1]);
  digitalWrite(dataPinC, pins[pinNum][2]);
}

void loop() {
  writePin(0);
  delay(waitTime); // Pin X0
  writePin(1);
  delay(waitTime); // Pin X1
  writePin(2);
  delay(waitTime); // Pin X2
  //...ETC
}
