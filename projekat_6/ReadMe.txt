Za ovaj projekat parking senzora koristi se ultrazvučni senzor za mjerenje udaljenosti, dok se rezultati prikazuju na LCD displeju.

Koraci za dodavanje biblioteke u PlatformIO

    Preuzimanje biblioteke Prvo skinete odgovarajuću biblioteku za LCD.
    Ubacivanje biblioteke Kopirate preuzetu biblioteku u lib folder vašeg projekta.
    Podešavanje u PlatformIO
        Otvorite PlatformIO i pronađete vaš projekat.
        Otvorite platformio.ini fajl unutar projekta.
        Dodate liniju lib_extra_dirs = lib, koja govori PlatformIO-u gdje da traži dodatne biblioteke.

Nastavak projekta 5 Koristite kod iz Projekta 5 (ultrazvučni senzor) za mjerenje udaljenosti, 
dok će ispisivanje izmjerenih vrijednosti ići na LCD ekran umjesto na Serial Monitor.