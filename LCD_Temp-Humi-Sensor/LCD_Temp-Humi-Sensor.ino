// Author: David Anderson Six //
// www.dave6.com //

/*
  This script reads the Temperature & Humidity sensor every 2500ms
  The T&H are displayed on an Optrex DMC50037N 40X2 LCD
  If the Sensor cannot be read display an error

  DEPENDENCIES
    LiquidCrystal.h (LCD)
    dht.h (T&H sensor)
*/

#include <LiquidCrystal.h>

#include "dht.h"
#define dataPin 11

dht DHT; //create DHT object

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
  Serial.begin(9600);
  delay(1000); // Delay allows system to begin serial //

  // set up the LCD's number of columns and rows:
  lcd.begin(40, 2);
}

void loop() {

  int readData = DHT.read11(dataPin);
  lcd.clear();

  if (readData == 0) {

    float temp = DHT.temperature;
    float humi = DHT.humidity;
    lcd.setCursor(0, 0);

    lcd.print("Temperature:");
    lcd.setCursor(14, 0);
    lcd.print(temp);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity:");
    lcd.setCursor(14, 1);
    lcd.print(humi);
    lcd.print("%");
  } else {
    lcd.setCursor(5, 1);
    lcd.print("Error, cannot read sensor");
  }
  delay(2500);
}
