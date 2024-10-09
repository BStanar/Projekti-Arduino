#include <Arduino.h>

//definicija segmenata koji se nalaze na sedmosegmentnom displeju
#define pinSegmentA 7
#define pinSegmentB 6
#define pinSegmentC 5
#define pinSegmentD 4
#define pinSegmentE 3
#define pinSegmentF 1
#define pinSegmentG 0
//definisanje dugmeta na pinu 2 koji ce nam sluziti kao interrupt
#define pinBtn 2

//funkcija koja prikazuje odredjeni broj na displeju
void upaliBroj(int broj);
void pritisakTastera();
unsigned long staroVrijeme;
int i = 1;

void setup() {
    pinMode(pinSegmentA, OUTPUT);
    pinMode(pinSegmentB, OUTPUT);
    pinMode(pinSegmentC, OUTPUT);
    pinMode(pinSegmentD, OUTPUT);
    pinMode(pinSegmentE, OUTPUT);
    pinMode(pinSegmentF, OUTPUT);
    pinMode(pinSegmentG, OUTPUT);
    //Pri paljenju arduina neka bude prikazana nula
    upaliBroj(0);

    pinMode(pinBtn, INPUT);
    attachInterrupt(0,pritisakTastera, CHANGE);  
}

void loop() {

}

void pritisakTastera(){
   unsigned long trenutnoVrijeme = millis();
  if(trenutnoVrijeme - staroVrijeme > 200){
    staroVrijeme = trenutnoVrijeme;
    upaliBroj(i);
    i = i != 9? ++i : 0;
    staroVrijeme = trenutnoVrijeme;
  }
}

void upaliBroj(int broj){
  switch (broj)
  {
  case 1:
    digitalWrite(pinSegmentA, HIGH);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, HIGH);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, HIGH);
    digitalWrite(pinSegmentG, HIGH);
    break;
    case 2:
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentC, HIGH);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, LOW);
    digitalWrite(pinSegmentF, HIGH);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 3:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, HIGH);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 4:
    digitalWrite(pinSegmentA, HIGH);
    digitalWrite(pinSegmentB, HIGH);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, HIGH);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 5:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, HIGH);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 6:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, HIGH);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, LOW);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 7:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, HIGH);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, HIGH);
    digitalWrite(pinSegmentG, HIGH);
    break;
    case 8:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, LOW);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, LOW);
    break;
    case 9:
    digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, HIGH);
    digitalWrite(pinSegmentE, HIGH);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, LOW);
    break;
  default:
  digitalWrite(pinSegmentA, LOW);
    digitalWrite(pinSegmentB, LOW);
    digitalWrite(pinSegmentC, LOW);
    digitalWrite(pinSegmentD, LOW);
    digitalWrite(pinSegmentE, LOW);
    digitalWrite(pinSegmentF, LOW);
    digitalWrite(pinSegmentG, HIGH);
    break;
  }
}