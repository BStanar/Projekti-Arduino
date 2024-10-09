Ovaj projekat uključuje paljenje diode pritiskom na taster, dok se stanje tastera ispisuje na virtuelni terminal.

    Virtuelni terminal: Otvara se preko opcije desni klik -> plac -> virtual instrument -> virtual terminal.
    Brzina prenosa: 	Arduino podržava brzine od 300 do 19200 bps. Standardna brzina za ovaj projekat je 9600 bps, 
			uspostavljena pomoću Serial.begin(9600);.
    Ispis na terminal: 	Pomoću Serial.print("Hello world"); ispisujete podatke na virtuelni terminal, kao što je stanje tastera.