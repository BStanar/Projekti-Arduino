Ovaj repozitorij sadrži male zadatke za Arduino, koji se koriste za učenje i testiranje različitih funkcionalnosti Arduina i njegovih senzora. Projekti se razvijaju i simuliraju koristeći Proteus za simulaciju, dok se za pisanje i implementaciju koda koristi Visual Studio Code sa PlatformIO ekstenzijom.
Postavka okruženja

    Visual Studio Code: Koristi se kao IDE za pisanje i uređivanje koda.
        PlatformIO ekstenzija: Omogućava rad sa Arduinom unutar Visual Studio Code-a.
    Proteus: Koristi se za simulaciju Arduino projekata i testiranje funkcionalnosti.
        Svi projekti su simulirani u Proteusu, gdje su modeli senzora, displeja i ostalih komponenti povezani sa Arduinom.

Projekti
Projekat 1: LED Kontrola sa Tasterom

    Koristi se taster za kontrolu LED diode.

Projekat 2: Prikaz Brojeva na Sedmosegmentnom Displeju

    Pritiskom na taster prikazuje se sljedeći broj na sedmosegmentnom displeju.

Projekat 3: Sat sa Odbrojavanjem Sekundi

    Prikazuje sekunde koje su prošle od paljenja Arduina na LCD displeju.

Projekat 4: Kontrola Prekidača i Prikaz na Virtuelnom Terminalu

    Stanje tastera se prikazuje na virtuelnom terminalu, dok taster kontroliše LED diodu.

Projekat 5: Ultrazvučni Senzor za Mjerenje Udaljenosti

    Korištenje ultrazvučnog senzora za mjerenje udaljenosti, a podaci se ispisuju na LCD displeju.

Projekat 6: Parking Senzor

    Parking senzor koristi ultrazvučni senzor i prikazuje udaljenost na LCD-u.

Projekat 7: I2C Komunikacija

    Koristi se I2C protokol za komunikaciju sa LCD displejem i DS1621 temperaturnim senzorom.

Projekat 8: RTC Sat sa DS1307

    Prikazivanje tačnog vremena koristeći DS1307 RTC modul koji pamti vrijeme čak i kada je Arduino isključen.

Projekat 9: Multipleksiranje Sedmosegmentnih Displeja

    Prikaz brojeva na više sedmosegmentnih displeja koristeći tehniku multipleksiranja.

Projekat 10: Serijska Komunikacija sa Računarom

    Komunikacija između Arduina i računara preko virtuelnog COM porta. Koristi se program Hercules za prikaz rezultata.

Kako koristiti

    Pisanje Koda: Svi zadaci se pišu unutar Visual Studio Code-a koristeći PlatformIO. Kodovi za svaki projekat su strukturirani u odgovarajuće fajlove.

    Simulacija u Proteusu: Za simulaciju, otvorite odgovarajući Proteus fajl i povežite komponente kako je opisano u projektima. Pokrenite simulaciju i testirajte funkcionalnost.

Potrebni alati

    Arduino
    Visual Studio Code sa PlatformIO ekstenzijom
    Proteus za simulaciju
    Komponente: LCD displeji, sedmosegmentni displeji, senzori, tranzistori, ultrazvučni senzori, DS1307 RTC modul, itd.