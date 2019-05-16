// Author: David Anderson Six //
// www.dave6.com //


/*
  This script is a basic example of how to use the LiquidCrystal library.
  This library works with any LCD using a similar architecture to the Hitachi HD44780 driver.
  Below I have included the pin layouts for 2 seemingly less common LCD boards:
  LMB162NFC & Optrex DMC-50037C

  DEPENDENCIES
    LiquidCrystal.h
*/


// LCD Display LMB162NFC Example //
// Pins: Bottom Left: 1, Bottom Right: 2, continue //
// 1: 5V Power (LCD) //
// 2: Ground (LCD) //
// 3: Variable 5V contrast of LCD (Potentionmeter) //
// 4: Register Select, controls where to store memory //
//    HIGH: Transfering display data //
//    LOW: Transfering instruction data //
// 5: Read / Write mode control, HIGH: Read, LOW: Write //
//    HIGH: Read Mode: Reading data from screen //
//    LOW: Write Mode: Writing to the screen //
// 6: Data Enable, Enables writing to the LCD (connect to digitalPin) //
// 7-14: Data pins //
//    8bit Mode: DB0[pin7]-DB7[pin14] are used //
//    4bit Mode: DB4[pin11]-DB7[pin14] are used (DB0[pin7]-DB4[pin10] are open) //
// 15: 5V Power (Backlight) //
// 16: Ground (Backlight) //

// LCD Display DMC-50037C Example //
// 1: Ground (LCD) //
// 2: 5V Power (LCD) //
// 3: Variable 5V contrast of LCD (Potentionmeter) //
// 4: Register Select, controls where to store memory //
//    HIGH: Transfering display data //
//    LOW: Transfering instruction data //
// 5: Read / Write mode control, HIGH: Read, LOW: Write //
//    HIGH: Read Mode: Reading data from screen //
//    LOW: Write Mode: Writing to the screen //
// 6: Data Enable, Enables writing to the LCD (connect to digitalPin) //
// 7-14: Data pins //
//    8bit Mode: DB0[pin7]-DB7[pin14] are used //
//    4bit Mode: DB4[pin11]-DB7[pin14] are used (DB0[pin7]-DB4[pin10] are open) //

#include <LiquidCrystal.h>

const int
  registerSelect = 12,
  enableData = 13,
  dB0 = 2,
  dB1 = 3,
  dB2 = 4,
  dB3 = 5,
  dB4 = 6,
  dB5 = 7,
  dB6 = 8,
  dB7 = 9
;

LiquidCrystal lcd(
  registerSelect,
  enableData,
  dB0,
  dB1,
  dB2,
  dB3,
  dB4,
  dB5,
  dB6,
  dB7
);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(40, 2);
  // Print a message to the LCD.
  lcd.print("Hello World!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(1, 20);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  //lcd.print("Hi!");
}
