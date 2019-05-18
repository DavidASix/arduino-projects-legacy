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

void lightSegment(int digit, int seg, int delayValue=1) {
  // Matrix goes Digit, segment, [anode#, cathode2 value,] //
  int digiSegments[3][7][3] = {
    {  // D2, A-G
      {4, 0 }, {2, 0 }, {3, 0 }, {3, 1 }, {1, 1 }, {4, 1 }, {2, 1 }
    },
    { //D3, A-G
      {5, 1 }, {6, 1 }, {7, 1 }, {7, 0 }, {8, 0 }, {5, 0 }, {6, 0 }
    },
    { //D4 A-G
      {11, 0 }, {9, 0 }, {10, 0 }, {10, 1 }, {8, 1 }, {11, 1 }, {9, 1 }
    }
  };

  int anodes[11] = {
    anode1, anode2, anode3, anode4, anode5,
    anode6, anode7, anode8, anode9, anode10,
    anode11,
  };

  // Set Cathode values

  if (digiSegments[digit][seg][1] == 1) {
    digitalWrite(cathode2, HIGH);
    digitalWrite(cathode1, LOW);
  } else {
    digitalWrite(cathode2, LOW);
    digitalWrite(cathode1, HIGH);
  }

  digitalWrite(anodes[digiSegments[digit][seg][0] - 1], HIGH);
  delay(delayValue);
  digitalWrite(anodes[digiSegments[digit][seg][0] - 1], LOW);
}

void lightNumber(int numChar, int digit=0) {
  // numChar = Number to be displayed
  // digit = digit position for numChar to showup
  // First element of each array is the length minus 1
  int numbers[10][8] {
    {6, 0, 1, 2, 3, 4, 5 }, // 0
    {2, 1, 2 }, // 1
    {5, 0, 1, 6, 4, 3 }, // 2
    {5, 0, 1, 6, 2, 3 }, // 3
    {4, 1, 2, 6, 5 }, // 4
    {5, 0, 5, 6, 2, 3 }, // 5
    {6, 0, 5, 4, 3, 2, 6 }, // 6
    {3, 0, 1, 2 }, // 7
    {7, 0, 1, 2, 3, 4, 5, 6 }, //8
    {5, 0, 1, 2, 6, 5 } // 9
  };

  // Light up each segement in the specified array //
  for (int i=0; i < numbers[numChar][0]; i++) {
    lightSegment(digit, numbers[numChar][i + 1]);
  }
}

void loop() {
  int sec = millis() / 1000;
  // Minutes Passed //
  lightNumber(floor(sec / 60), 0);
  // 10's of seconds pased //
  lightNumber(floor((sec % 60) / 10), 1);
  // 1's of seconds passed //
  lightNumber(sec % 10, 2);
}
