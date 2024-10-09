Projekat 11 – Prvi dio: U ovom dijelu se koristi multipleksiranje za upravljanje više sedmosegmentnih displeja. 
Pošto ne možemo istovremeno slati signale na oba ekrana, displeji se naizmjenično pale i gase pri velikoj brzini. 
Na taj način, korisnik ne primjećuje da se ekrani pale jedan po jedan. Kontrola displeja se vrši pomoću tranzistora, 
koji omogućavaju brzo prebacivanje između ekrana.

Projekat 11 – Drugi dio: U drugom dijelu projekta pravite komunikaciju između Arduina i računara preko virtualnog COM porta. 
Koristite COMPIM modul u Proteusu za simulaciju serijske komunikacije, postavljajući fizičku i virtuelnu baud brzinu na 9600 bps. 
COMPIM se povezuje na pinove 0 i 1 Arduina. Da bi komunikacija funkcionisala, 
morate virtuelno napraviti dva povezana COM porta pomoću aplikacije, a serijsku komunikaciju pokrenuti linijom Serial.begin(9600);. 
Korištenje programa Hercules omogućava ispisivanje podataka sa Arduina na računar.


Potrebne komponente;
1. ARDUINO
2. 2 X 7SEG DISPLAY
3. VIRTUAL TERMINAL
4. NPN
5. RES
6. COMPIM (ZA VEZU SA APLIKACIJOM)
