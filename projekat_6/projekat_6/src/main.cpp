#include <Arduino.h>
//Moram ukljuciti ovu biblioteku jer LiqidCrystal zahtjeva
#include <Wire.h>
#include <LiquidCrystal.h>

//Za lcd definicija pinova
#define pinRs 12
#define pinEn 11
#define pinD4 5
#define pinD5 4
#define pinD6 3
#define pinD7 2
//Za ultrazvucni senzor
#define pinTr 10
#define pinEcho 9

//za custom karakter --> Pravim crni pravugaonik
byte crniPravugaonik[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

LiquidCrystal lcd(pinRs, pinEn, pinD4, pinD5, pinD6, pinD7);
void ispisNaLcd(int broj);

void setup() {
  //Podesavam broj kolona i redova
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  pinMode(pinTr, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
  lcd.createChar(0, crniPravugaonik);
  lcd.setCursor(0, 0);
  
}

void loop() {
  //Racunanje udaljenosti za ultrazvucni senzor
  digitalWrite(pinTr, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTr, LOW);
  long trajanje = pulseIn(pinEcho, HIGH);
  int udaljenost = trajanje * 0.034/2;

  ispisNaLcd(udaljenost);
  Serial.println("Udaljenost je " + String(udaljenost));
  delay(500);
} 

//funkcija koja na osnovu primljenog broja ispisuje na lcd odredjeni broj karaktera
void ispisNaLcd(int broj){
  if(broj > 50){
    //Cisti sve karaktere sa lcd-a
    lcd.clear();
    //Postavlja kursor na pocetak ekrana
    lcd.setCursor(0, 0);
    lcd.print("Nema prepreka");
  }else if (broj >= 49){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0)); 
  }else if (broj >= 46){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
  }else if(broj >= 43){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0)); 
  }else if (broj >= 39){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if(broj >= 36){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if(broj >= 33){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if (broj >= 29){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if(broj >= 26){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if(broj >= 23){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }else if(broj > 19){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0)); 
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
    lcd.write(byte(0));
  }
}
