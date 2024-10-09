#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define pinRs 12
#define pinE 11
//Koristim ga za pozadinsko osvjetljenje (on je totalno nebitan)
#define pinVee 8
#define pinD4 5
#define pinD5 4
#define pinD6 3
#define pinD7 2

LiquidCrystal lcd(pinRs, pinE, pinD4, pinD5, pinD6, pinD7, pinVee, POSITIVE );
unsigned long prethodnoVrijeme = 0;
int sekunde = 0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Sekunde: ");
  lcd.setCursor(0,1);
  lcd.print("by Boris");
  Serial.begin(9600);
}

void loop() {
  unsigned long trenutnoVrijeme = millis();
  if(trenutnoVrijeme - prethodnoVrijeme > 1000){
    prethodnoVrijeme = trenutnoVrijeme;
    sekunde++;
    lcd.setCursor(9,0);
    lcd.print(String(sekunde));
    Serial.println("Sekunda: " + String(sekunde));
  }
}