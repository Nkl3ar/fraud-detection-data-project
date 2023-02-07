# fraud-detection-data-project

# Korištene strukture i spremanje podataka
Korištene su strukture Map i multimap gdje je key stupac nad kojim vršimo zadanu radnju (pretraživanje, min, max) a value je cijeli red spremljen u ručno napisanu strukturu fraud_data. Svi su podatci spremljeni u što smislenijem obliku, izuzev vremena koji je spremljen kao string.
Odabrao sam ID, cc_num i city_pop stupce radi jednostavnosti pisanja i kopiranja koda.
Jednom kada sam napravio sve funkcije za ID lako sam ih mogao izmijeniti da budu funkcije za stupac cc_num/city_num.
Također to su sve numerički stupci što olakšava min i max radnje.

# Razlog odabir strukture

Map je korišten radi brzog pretraživanja, lakog dolaska do minimalne i maksimalne vrijednosti te relativno brzog ubacivanja i brisanja.
U C++ map je implementiran kao red-black tree.
Multimap je korišten kod stupaca cc_num i city_pop jer se neki podatci ponavljaju (u slučaju cc_num do 500 puta).

# Operacije vraćanja min i maxa

Za max dovoljno je samo dohvatiti rbegin iterator, dok je za min dovoljno je samo dohvatiti begin iterator.
Razlog toga je to što je map već sortiran.
Ako želimo dohvatiti n-ti podatak, samo dohvatimo (r)begin iterator te ga inkrementiramo n-1 puta preko neke vrste petlje jer ne možemo samo napisati rbegin+(n-1)/begin+(n-1).

# Operacije traženja podataka

Samo koristimo find metodu iz (multi)mapa. To je najbrži i najbolji način.
Ako tražimo N podataka samo spremimo tih N podataka u neku vrstu arraya (najbolje vektor radi jednostavnosti), te napravimo petlju.
Tijekom pisanja koda nisam bio siguran moramo li vratiti sami podatak ili možemo li samo vratiti je li pretraživanje bilo uspješno. Na kraju sam se odlučio za vraćanje boola, te samo napravio odvojenu funkciju find koja vraća podatak.