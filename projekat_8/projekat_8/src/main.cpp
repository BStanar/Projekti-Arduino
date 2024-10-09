#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
float get_temperature();
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};

void setup()
{
  //Inicijalizacija LCD displeja
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Temperatura je: " + String(get_temperature()));
  lcd.setCursor(0, 1);
  lcd.print("by Boris");
  //*********************

  //Startovanje I2c konekcije koja je potrebna za DS1621 senzor
  Wire.begin();       // join i2c bus
  // initialize DS1621 sensor
  Wire.beginTransmission(0x48);    // ako pinovi A0, A1, A2 nisu spojeni adresa je: 0x48
  Wire.write(0xAC);               // send configuration register address (Access Config)
  Wire.write(0);                 // perform continuous conversion
  Wire.beginTransmission(0x48); // send repeated start condition
  Wire.write(0xEE);            // send start temperature conversion command
  Wire.endTransmission();
  //************************
  //Otvaranje konekcije za virtualni terminal
  Serial.begin(9600);
}

void loop()
{
  //Ispis temperature na virtualni terminal
  Serial.println("Temperatura je: " + String(get_temperature()));
  lcd.setCursor(0, 0);
  lcd.print("Temperatura je: " + String(get_temperature()));
  delay(1000);
}

float get_temperature() {
  Wire.beginTransmission(0x48); // ako pinovi A0, A1, A2 nisu spojeni adresa je: 0x48
  Wire.write(0xAA);                       // read temperature command
  Wire.endTransmission(false);            // send repeated start condition
  Wire.requestFrom(0x48, 2);    // request 2 bytes from DS1621 and release I2C bus at end of reading
  uint8_t t_msb = Wire.read();            // read temperature MSB register
  uint8_t t_lsb = Wire.read();            // read temperature LSB register
 
  // calculate full temperature (raw value)
  int16_t raw_t = (int8_t)t_msb << 1 | t_lsb >> 7;
  // convert raw temperature value to tenths °C
  raw_t = raw_t * 10/2;
  //Ovdje sam podijelio sa 10 i vracam u float tipu 
  return raw_t/10.0;
}