// Author: David Anderson Six //
// www.dave6.com //


/*
  This script is an attempt to run the parts from a scrapped alarm clock.
  AlarmClock: Curtis - CR1274
  4 digit 7Seg display: LY6052S

  DEPENDENCIES
*/

/*
  DigitToLight (digit layman name): { pinName(pinNumberOnLcd) }

  // Digits assume all unspecified cathodes are HIGH and all unspecified anodes are LOW
  DIGITS:
  {
    L1 (Top Dot): { cathode1(1): LOW },
    L2 (Bottom Dot): { cathode3(3): LOW },
    L3/L4 (Colon): { cathode1(1): LOW },
    D1 (FirstDigit): {
      A:
      B: { cathode2(2): LOW },
      C: { anode1(9): HIGH, cathode2(2): LOW, cathode3(3): HIGH },

    },
    D2 (SecondDigit): {
      A: { anode4(13): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      B: { anode2(10): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      C: { anode3(12): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      D: { anode3(12): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      E: { anode1(9): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      F: { anode4(13): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      G: { anode2(10): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
    },
    D3 (Third Digit): {
      A: { anode5(15): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      B: { anode6(16): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      C: { anode7(17): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      D: { anode7(17): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      E: { anode8(18): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      F: { anode5(15): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      G: { anode6(16): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
    },
    D4 (Fourth Digit): {
      A: { anode11(21): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      B: { anode9(19): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      C: { anode10(20): HIGH, cathode2(2): LOW, cathode1(1): HIGH },
      D: { anode10(20): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      E: { anode8(18): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      F: { anode11(21): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
      G: { anode9(19): HIGH, cathode2(2): HIGH, cathode1(1): LOW },
    },
}

  }
*/
const int
  delayTime = 2,
  cathode1 = A0, //LCDPin 1
  cathode2 = A1, //LCDPin 2
  cathode3 = A2, //LCDPin 3
  anode1 = 13, //LCDPin 9
  anode2 = 12, //LCDPin 10
  anode3 = 11, //LCDPin 12
  anode4 = 10, //LCDPin 13
  anode5 = 9, //LCDPin 15
  anode6 = 8, //LCDPin 16
  anode7 = 7, //LCDPin 17
  anode8 = 6, //LCDPin 18
  anode9 = 5, //LCDPin 19
  anode10 = 4, //LCDPin 20
  anode11 = 3 //LCDPin 21
;

// For each digit if both cathodes are off on a pin only one iterneeded

void setup() {
  // put your setup code here, to run once:
  pinMode(cathode1, OUTPUT);
  pinMode(cathode2, OUTPUT);
  pinMode(cathode3, OUTPUT);
  pinMode(anode1, OUTPUT);
  pinMode(anode2, OUTPUT);
  pinMode(anode3, OUTPUT);
  pinMode(anode4, OUTPUT);
  pinMode(anode5, OUTPUT);
  pinMode(anode6, OUTPUT);
  pinMode(anode7, OUTPUT);
  pinMode(anode8, OUTPUT);
  pinMode(anode9, OUTPUT);
  pinMode(anode10, OUTPUT);
  pinMode(anode11, OUTPUT);
}

void loop() {
  // Second Digit - B, C, E, F, G //
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode2, HIGH);
  delay(delayTime);
  digitalWrite(anode2, LOW);

  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode2, HIGH);
  delay(delayTime);
  digitalWrite(anode2, LOW);

  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode1, HIGH);
  delay(delayTime);
  digitalWrite(anode1, LOW);

  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode3, HIGH);
  delay(delayTime);
  digitalWrite(anode3, LOW);

  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode4, HIGH);
  delay(delayTime);
  digitalWrite(anode4, LOW);

  // Third Digit //
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode5, HIGH);
  delay(delayTime);
  digitalWrite(anode5, LOW);

  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode6, HIGH);
  delay(delayTime);
  digitalWrite(anode6, LOW);

  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode6, HIGH);
  delay(delayTime);
  digitalWrite(anode6, LOW);

  //D3 C
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode7, HIGH);
  delay(delayTime);
  digitalWrite(anode7, LOW);

  //D3 E
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode8, HIGH);
  delay(delayTime);
  digitalWrite(anode8, LOW);

  // Fourth Digit //
  //D4 B
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode9, HIGH);
  delay(delayTime);
  digitalWrite(anode9, LOW);

  //D4 C
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode10, HIGH);
  delay(delayTime);
  digitalWrite(anode10, LOW);

  //D4 G
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode9, HIGH);
  delay(delayTime);
  digitalWrite(anode9, LOW);

  //D4 E
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode8, HIGH);
  delay(delayTime);
  digitalWrite(anode8, LOW);

  //D4 F
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  digitalWrite(cathode3, HIGH);
  digitalWrite(anode11, HIGH);
  delay(delayTime);
  digitalWrite(anode11, LOW);
}
