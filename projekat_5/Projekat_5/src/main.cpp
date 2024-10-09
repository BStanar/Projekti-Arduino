#include <Arduino.h>

#define pinTr 3
#define pinEcho 2
long trajanje;
long udaljenost;

void setup() {
  pinMode(pinTr, OUTPUT);
  pinMode(pinEcho, INPUT);

  Serial.begin(9600);
}

void loop() {
  //Posaljem signal na trig pin
  digitalWrite(pinTr, HIGH);
  //Sacekam deset mili sekundi
  delayMicroseconds(10);
  //Ugasim napon na trig pinu
  digitalWrite(pinTr, LOW);
  //Mjerim vrijeme koje je potrebno da se signal vrati ultrasonicnom senzoru
  trajanje = pulseIn(pinEcho, HIGH);

  //Mjerim udaljenost
  udaljenost = trajanje * 0.034/2;
  //Ispis na virtualni terminal
  Serial.print("Udaljenost je: ");
  Serial.println(udaljenost);
  delayMicroseconds(2000);
}