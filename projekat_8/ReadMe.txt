U ovom projektu koristi se I2C komunikacija za kontrolu LCD displeja i očitavanje temperature preko DS1621 senzora.

Koraci:

    LCD displej preko I2C: Umjesto 6 pinova za kontrolu LCD-a, putem I2C koristite samo 2 pina (SDA i SCL). Za ovo vam treba PCF8574 čip.
        Adresa I2C za LCD je 0x20.
        Konstruktor za LCD sa I2C komunikacijom izgleda ovako: LiquidCrystal_I2C lcd(0x20,20,2);.

    Mjerenje temperature pomoću DS1621 senzora: Ovaj senzor koristi I2C za komunikaciju, a njegova adresa je 0x48 (ako su A0, A1, i A2 pinovi uzemljeni).

Prednosti I2C: Koriste se samo dva pina za kontrolu više uređaja, što štedi prostor i pojednostavljuje ožičenje.Potrebne komponente:
1. ARDUINO
2. RES
3. LCD (20X2)
4. PCF8574 (CIP ZA I2C KOMUNIKACIJU)
5. DS1621 (TERMOMETAR)

