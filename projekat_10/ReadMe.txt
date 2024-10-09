U ovom projektu koristite DS1307 modul, koji je RTC (Real Time Clock) uređaj, za precizno praćenje vremena. Modul radi nezavisno od Arduina zahvaljujući svojoj bateriji, što omogućava da vrijeme bude tačno čak i kada je Arduino isključen.

Koraci:

    RTC biblioteka: Uključite RTC biblioteku za rad sa DS1307. Biblioteka omogućava lako podešavanje i čitanje vremena.
    Kristalni kvarc: DS1307 koristi kristalni oscilator frekvencije 32.768 kHz za precizno mjerenje vremena.
    I2C komunikacija: Adresa modula je 0x68, a komunikacija se uspostavlja pomoću Wire.beginTransmission(0x68);.

Prednost RTC modula: Za razliku od računanja vremena unutar loop() funkcije, RTC moduli su mnogo precizniji i mogu nastaviti praćenje vremena čak i kada Arduino nije napajan.


Potrebne komponente:
1. ARDUINO
2. DS1307 (sluzi za pamcenje vremena)
3. CRYSTAL (kristalni oscilator)
