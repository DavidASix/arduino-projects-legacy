// Author: David Anderson Six //
// www.dave6.com //


/*
  This script is a basic example of how to use the Optrex IM50240 LCD (Marked PWB50240)
  This is a 4 digit 7 segment display with displays saying CLEAR and SECURE.
  My best guess is that it was used for a safe.
  The script turns the clear and secure displays on then
  Loops through writing an Unsigned Int, a signed int, and a hexidecimal char set every 500ms

  DEPENDENCIES
    OptexLCD.h (https://playground.arduino.cc/uploads/Code/OptrexLCD/index.zip)
        MSTimer2 (https://playground.arduino.cc/uploads/Main/MsTimer2/index.zip)

*/

#include "OptrexLCD.h"


const int delayTime = 500;

void setup() {
// 4 Pins are used, related LCD pins shown in comments //

// 50% duty cycle clock (M), Pin 4 on LCD PCB //
  OptrexLCD::set_M_pin(4);
// Shift Clock, Pin 3 on LCD PCB //
  OptrexLCD::set_Shift_pin(3);
// Latch Clock, Pin 2 on LCD PCB //
  OptrexLCD::set_Latch_pin(5);
// Input Data, Pin 1 on LCD PCB //
  OptrexLCD::set_Din_pin(6);
// Initialize LCD //
  OptrexLCD::initialize();

}

void loop() {

  // Clear and Secure display, takes BOOL //
  OptrexLCD::set_clear(true);
  OptrexLCD::set_secure(true);

  // Loop forever
  for(;;) {

    // Write Unsigned Int with leading 0's //
    // Supports 0000 - 9999 //
    OptrexLCD::write_uint(6500);
    OptrexLCD::wait_latched();

    delay(delayTime);

    // Write Signed Int with leading 0's //
    // Supports -999 - 9999 //
    OptrexLCD::write_int(-600);
    OptrexLCD::wait_latched();

    delay(delayTime);

    // Write 4 Char with trailing _'s //
    // Supports Hex Chars - 0-F //
    OptrexLCD::write("DA6");
    OptrexLCD::wait_latched();

    delay(delayTime);

  }
}
