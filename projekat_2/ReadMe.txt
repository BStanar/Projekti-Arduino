
Ova šema koristi prekid (interrupt) za detekciju pritiska tastera, 
čime se LED uključuje ili isključuje. Kada se pritisne taster, 
aktivira se prekid, a funkcija "pin_ISR" čita stanje tastera i pali/gasi LED. 
Problem višestrukih detekcija zbog odskakanja tastera može se riješiti softverski pomoću millis(), 
koja ignoriše prekide unutar kratkog vremenskog perioda.