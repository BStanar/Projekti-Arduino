#include <Arduino.h>

#define pinE1 12
#define pinE2 11
#define segA 8
#define segB 7
#define segC 6
#define segD 5
#define segE 4
#define segF 3
#define segG 2

void ispisiBroj(int broj);
int broj = 0;
int jedinice;
int desetice;
bool stanje = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(pinE1, OUTPUT);
  pinMode(pinE2, OUTPUT);
  //Virtualni terminal
  Serial.begin(9600);
  Serial.println("Arduino pokrenut\nby Boris");
  digitalWrite(pinE1, HIGH);
}

void loop() {
  //Razdvajam jedinice i desetice od broja
  jedinice = broj%10;
  desetice = (broj%100)/10;
  //************************
  //Ispisujemo u nasu Hercules aplikaciju preko virtuelnog COM porta
  Serial.println("Broj je: " + String(broj));

  if(broj < 10){
    digitalWrite(pinE2, LOW);
    digitalWrite(pinE1, HIGH);
    ispisiBroj(jedinice);
  }else{
    digitalWrite(pinE2, HIGH);
    digitalWrite(pinE1, LOW);
    ispisiBroj(desetice);
  }
  

  broj++;
  //Provjeravamo da li imamo primljenih podataka iz aplikacije
  if(Serial.available()){
    //Citamo podatke poslate iz aplikacije
    String primljeniPodatak = Serial.readString();
    //Ispis u aplikaciju
    Serial.println("Primljeni podatak: " + primljeniPodatak);
    broj = primljeniPodatak.toInt();
    if(broj < 10){
      ispisiBroj(broj);
    }
  }
  delay(10);
}

void ispisiBroj(int broj){
  switch (broj)
  {
  case 1:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
    case 2:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
    case 3:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
    case 4:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
    case 5:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
    case 6:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
    case 7:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
    case 8:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
    case 9:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
    default:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;
  }
}