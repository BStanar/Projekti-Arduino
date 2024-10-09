#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define pinRs 12
#define pinE 11
#define pinD7 5
#define pinD6 4
#define pinD5 3
#define pinD4 2
#define pinVee 8

LiquidCrystal lcd(pinRs, pinE, pinD4, pinD5, pinD6, pinD7, pinVee, POSITIVE );
int sekunde;
int minute;
int sati;
unsigned long prethodnoVrijeme = 0;
void ocitajVrijeme();
void prikaziVrijeme();

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  //Potrebno je omoguciti I2C komunikaciju
  Wire.begin();
}

void loop() {
  unsigned long trenutnoVrijeme = millis();
  if (trenutnoVrijeme - prethodnoVrijeme > 500){
    prethodnoVrijeme = trenutnoVrijeme;
    prikaziVrijeme();
  }
}

void ocitajVrijeme(){
  Wire.beginTransmission(0x68);
  //Citam iz prvog registra (ondosno iz registra za sekunde)
  Wire.write(1);
  //resetujem komunikaciju
  Wire.endTransmission(false);
  //Zahtjeva transmisiju sa naseg modula i cita tri podatka (za sec, min i h)
  Wire.requestFrom(0x68,2);

  //Kad smo dobili podatke vrsimo citanje
  sekunde = Wire.read();
  minute = Wire.read();
  sati = Wire.read();
}

void prikaziVrijeme(){
    ocitajVrijeme();
    sekunde = (sekunde >> 4) * 10 + (sekunde & 0x0F);
    minute = (minute >> 4) * 10 + (minute & 0x0F);
    sati = (sati >> 4) * 10 + (sati & 0x0F);

    lcd.setCursor(0, 0);
    lcd.print("Vrijeme: " + String(sekunde) + ":" + String(minute) + ":" + String(sati));
    Serial.print("Vrijeme: " + String(sekunde) + ":" + String(minute) + ":" + String(sati) + "\n");
}

