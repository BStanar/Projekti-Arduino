#include <Arduino.h>
//Definicija pinova koje koristim u projektu
#define pinLed1 7
#define pinLed2 6
#define pinLed3 5
#define pinLed4 4
#define pinLed5 3
#define pinBtn 2

int8_t trenutnadioda = 1;
void tasterPritisnut();
unsigned long posljednjiInterrupt = 0;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);

  pinMode(pinBtn, INPUT);
  //Definisanje Interrupta-a. Arduino Uno ima dva pina za Interrupt (pin2 i pin3). 0 je za pin2, 1 je za pin3
  attachInterrupt(0,tasterPritisnut,CHANGE);
}

void loop() {
 
}
//Funkcija koja sluzi za ukljucivanje diode u zavisnosti koji joj je broj proslijedjen.
void  ukljuciDiodu(int broj){

  switch (broj)
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

//Funkcija koja se poziva kada se taster pritisne. Nju sam ubacio u Interrupt.
void tasterPritisnut(){
  //Zna se dogoditi da Interrupt ocita nekad da je taster vise puta pritisnut (zbog prelaznih procesa i neidealnih prekidaca)
  //Zato pravim ispitivam da li je proslo 0.2 sekunde od proslog pritiskanja tastera (Ovaj proces se naziva Debounce)
    unsigned long trenutniInterrupt = millis();
    if(trenutniInterrupt - posljednjiInterrupt > 200){

    if(trenutnadioda <= 5){
      ukljuciDiodu(trenutnadioda);
      trenutnadioda++;
    }else{
      trenutnadioda = 1;
      digitalWrite(pinLed2, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed5, LOW);
    }
    }
    posljednjiInterrupt = trenutniInterrupt;
}