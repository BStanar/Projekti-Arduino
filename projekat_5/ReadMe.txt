U ovom projektu koristi se ultrazvučni senzor za mjerenje udaljenosti. 
Senzor radi tako što šalje zvučni talas koji se odbija od objekta i vraća natrag do senzora.

Koraci u programu:

    Definišite TrigPin i EchoPin povezane na Arduino (npr. EchoPin na D2, TrigPin na D3).
    Postavite TrigPin na LOW stanje na 2 mikrosekunde kako biste ga očistili.
    Postavite TrigPin na HIGH stanje na 10 mikrosekundi da biste generisali ultrazvučni talas.
    Koristite funkciju pulseIn() da biste izmjerili trajanje povratnog impulsa i stavili tu vrijednost u varijablu "duration".
        Funkcija pulseIn() čeka da EchoPin pređe iz HIGH u LOW, što označava početak i kraj trajanja zvučnog talasa.
    Izračunajte udaljenost pomoću formule:

distance=duration×0.0342
distance=2duration×0.034​

Primjer: Ako je objekat udaljen 20 cm, vrijeme putovanja zvuka će biti oko 588 mikrosekundi. Vrijednost dobijena sa Echo pina biće duplo veća jer zvučni talas putuje do objekta i nazad, pa je potrebno podijeliti taj rezultat sa 2.
