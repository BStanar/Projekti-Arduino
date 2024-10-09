#include <Arduino.h>

#define pinLed 3
#define pinbtn 2

void upaliDiodu();
unsigned long prethodnoVrijeme = 0;
bool stanjePrekidaca = false;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinbtn, INPUT);
  //Brzine koje arduino koristi su: 300, 600, 1200, 2400, 4800, 9600, 19200
  Serial.begin(9600);
  //Pravim interrupt za taster
  attachInterrupt(0, upaliDiodu, CHANGE);
}

void loop() {
 
}

void upaliDiodu(){
  unsigned long trenutnoVrijeme = millis();
  //uslov koristim radi debouncing-a
  if(trenutnoVrijeme - prethodnoVrijeme > 200){
    stanjePrekidaca = !stanjePrekidaca;
    prethodnoVrijeme = trenutnoVrijeme;
    digitalWrite(pinLed, stanjePrekidaca);
    //Ispis na vrtualni terminal
    Serial.print("Stanje prekidaca: ");
    Serial.println(stanjePrekidaca? "Upaljen\n":"Ugasen\n");
  }
}