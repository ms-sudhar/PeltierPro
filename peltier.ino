// Pre-setup code
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_MAX31855.h"

// LCD and thermocouple setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define MAXDO   8
#define MAXCS   9
#define MAXCLK  10
#define RELAY1  7

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

void setup() {
  // LCD setup
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("    Cooler");
  delay(1000);

  // Thermocouple setup
  Serial.begin(9600);
  while (!Serial) delay(1);
  Serial.println("Initializing sensor...");
  if (!thermocouple.begin()) {
    Serial.println("Thermocouple Error");
    while (1) delay(10);
  }

  // Relay setup
  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1, HIGH);

  Serial.println("Setup Done.");
}

void loop() {
  // Read temperature
  double c = thermocouple.readCelsius();

  // Display temperature on LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("Cooler: ");
  lcd.setCursor(0,1);
  lcd.write("Temp (C): ");
  lcd.print(c);

  // Control relay based on temperature
  int relayStatus = (c >= 30) ? LOW : HIGH;
  if (c >= 30) {
      digitalWrite(RELAY1, LOW); 
      lcd.setCursor(0,0);
  lcd.write("Peltier: on"); // Relay on
      
    } 
  else {
      digitalWrite(RELAY1, HIGH); // Relay off
      lcd.setCursor(0,0);
  lcd.write("Peltier: off");
      
    }

  // Output temperature and relay status to Serial
  Serial.print("temperature:");
  Serial.print(c);
  Serial.print(",relay:");
  Serial.println(relayStatus);

  delay(2000);
}

 