#include <Arduino.h>

//definisanje pinova da ne bi morali da radimo sa brojevima
#define pinLed1 7
#define pinLed2 6
#define pinLed3 5
#define pinLed4 4
#define pinLed5 3
#define pinSw 2

unsigned long curentMillis;
unsigned long lastSync;
bool ledBlink = true;
int led = 1;
bool swstate;

void turnOnLed(int number);
//Ova funkcija se pokrece nakon paljenja arduina ili nakon resetovanja arduina
void setup() {
  //OUTPUT daje napon tome pinu (HIGH), ili mu ne daje napon (LOW)
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);

  //INPUT --> mjeri vrijednost na tome pinu.
  //Ako je vrijednost blizu VDD-a onda vraca HIGH, a ako nije vraca LOW.
  //Ovu vrijednost citam preko funkcije digitalRead().
  pinMode(pinSw, INPUT);
}

//ova funkcija(petlja) radi citavo vrijeme dok je arduino upaljen
void loop() {
  //millis() --> fukcija koja vraca vrijeme koje je proslo od paljenja mikrokontrolera 
  curentMillis = millis();
  swstate = digitalRead(pinSw);
  if(swstate && (curentMillis - lastSync > 100)){
    lastSync = curentMillis;
    turnOnLed(led);

    if(led < 6){
      led++;
    }else{
      digitalWrite(pinLed1, LOW);
      digitalWrite(pinLed2, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
      led = 1;
    }
  }
}

//funkcija koja prima broj diode koja ce biti upaljena
void turnOnLed(int number){
  switch (number)
  {
  case 1:
  digitalWrite(pinLed1, HIGH);
    break;
    case 2:
  digitalWrite(pinLed2, HIGH);
    break;
    case 3:
  digitalWrite(pinLed3, HIGH);
    break;
    case 4:
  digitalWrite(pinLed4, HIGH);
    break;
    case 5:
  digitalWrite(pinLed5, HIGH);
    break;
  default:
    break;
  }
}