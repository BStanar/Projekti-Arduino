#include <Arduino.h>

#define pinLed1 2
#define pinLed2 3
#define pinLed3 4
#define pinLed4 5
#define pinLed5 6

#define pinTr 8
#define pinEcho 9

void upaliDiode(int udaljenost);

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);

  pinMode(pinTr, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
}
void loop() 
{

  digitalWrite(pinTr, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTr, LOW);
  long vrijeme = pulseIn(pinEcho, HIGH);
  long udaljenost =  vrijeme * 0.034/2;

  Serial.println(udaljenost);
  upaliDiode((int)udaljenost);
  delayMicroseconds(300);
}


//Funkcija koja pali odredjene diode u zavisnosti od udaljnosti
void upaliDiode(int udaljenost){
    if(udaljenost < 10){
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed5, HIGH);
    }else if(udaljenost < 20){
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed5, LOW);
    }else if (udaljenost < 30){
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
    }else if(udaljenost < 40){
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
    }else if(udaljenost < 50){
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed2, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
    }else{
      digitalWrite(pinLed1, LOW);
      digitalWrite(pinLed2, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
    }
}