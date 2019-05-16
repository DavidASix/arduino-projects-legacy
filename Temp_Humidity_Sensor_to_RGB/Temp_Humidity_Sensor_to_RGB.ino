// Author: David Anderson Six //
// www.dave6.com //

/*
  This script Reads the DHT11 Humidity & Temperature sensor.
  The sensor data is printed in the serial monitor.
  Sensor data is interpolated via ledColor() to return a value of 0-255.
  Code was written after 30 hours of no sleep, try not to judge too harshly.

  DEPENDENCIES
    dht.h
*/

// DHT11 Humidity & Temperature sensor used
#include "dht.h"
#define dataPin 7

dht DHT; //create DHT object

const int red = 11;
const int green = 10;
const int blue = 9;

void setup() {
  Serial.begin(9600);
  delay(1000); // Delay allows system to begin serial //

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

int ledColor(int led, float temp) {
    // Temperature: 0C - 25C : blue - green;
    // Temperature: 25C - 50C : green - red;
    // Mid point for color should probably be just below room temperature, roughly 18C,
    // May revist later.

    // As LED's are current sinking a higher value (ie 240) means a dimmer bulb
    // to make things easier the value is inverted at the end of func (255-val)
    int val = 255;
    int tempStep = 0;
    switch (led) {
      case red:
        if (temp > 25) {
          tempStep = 256/25;
          val = tempStep * (50 - temp);
        }
        break;
      case green:
        if (temp > 12.5 && temp <= 25) {
          tempStep = 256/25;
          val = 255 - (tempStep * (temp - 12.5));
        } else if (temp > 25 && temp <= 37.5) {
          tempStep = 256/25;
          val = tempStep * (temp - 12.5);
        }
        break;
      case blue:
        if (temp < 25) {
          tempStep = 256/25;
          val = tempStep * temp;
        }
        break;
      default:
        Serial.print("Err - LED not recognized");
        break;
    }
    // Print value of LED
    Serial.print("LED ");
    Serial.print(led);
    Serial.print(" Brightness is: ");
    Serial.println(255-val);
    return val;
  }

void loop() {
  int readData = DHT.read11(dataPin);

  if (readData == 0) {
    float temp = DHT.temperature;
    float humi = DHT.humidity;
    Serial.println("");
    Serial.print("It is currently ");
    Serial.print(temp);
    Serial.println("°C");
    Serial.print("The humidity is ");
    Serial.print(humi);
    Serial.println("%");
    Serial.println("");
    analogWrite(red, ledColor(red, temp));
    analogWrite(green, ledColor(green, temp));
    analogWrite(blue, ledColor(blue, temp));
  } else {
    Serial.println("Error Reading Sensor");

    // Reset LED's //
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  delay(2000);
}
