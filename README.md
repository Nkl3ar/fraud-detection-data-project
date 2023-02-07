# fraud-detection-data-project

# Korištene strukture i spremanje podataka
Korištene su strukture Map i multimap gdje je key stupac nad kojim vršimo zadanu radnju (pretraživanje, min, max) a value je cijeli red spremljen u ručno napisanu strukturu fraud_data. Svi su podatci spremljeni u što smislenijem obliku, izuzev vremena koji je spremljen kao string.

Odabrao sam ID, cc_num i city_pop stupce radi jednostavnosti pisanja i kopiranja koda.

Svaki od ta tri stupca ima svoj map/multimap.

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

Kompleksnost dohvaćanja iteratora je konstantna.

Također samo mogao koristiti operator [] ali prvo sam se sjetio korištenja iteratora.

# Operacije traženja podataka

Samo koristimo find metodu iz (multi)mapa. To je najbrži i najbolji način.

Ako tražimo N podataka samo spremimo tih N podataka u neku vrstu arraya (najbolje vektor radi jednostavnosti), te napravimo petlju.

Tijekom pisanja koda nisam bio siguran moramo li vratiti sami podatak ili možemo li samo vratiti je li pretraživanje bilo uspješno. Na kraju sam se odlučio za vraćanje boola, te samo napravio odvojenu funkciju get koja vraća sami podatak.

Kompleksnost je log n.

# Dodavanje

Pri dodavanju moramo provjeriti postoji li već element/podatak koji ima isti ID.

Ukoliko postoji odmah otkazujemo cijelu radnju kako bi održali jedinstvenost IDa.

Ako ne postoji, dodajemo ih u sve tri strukture.

Tu nam uvelike pomaže to što nam je value cijeli red jer možemo iz njega izvući potrebne podatake.

# Brisanje

Drugi najbolniji dio ovog projekta.

Brisanje kod obične mape je veoma jednostavno jer se nema duplikata keya.

Problem nastaje kod multimape jer moramo biti jako oprezni da slučajno ne obrišemo krivi podatak.

Stoga moramo raditi provjere je li value koji je povezan uz ključ kojeg brišemo iz jedne strukture isti kao value iz druge strukture.

# Učitavanje samog dataseta

Najbolniji dio projekta.

Postoje tri ključna problema kod učitavanja csva.

Header koji opisuje podatke, neki podatci sadrže zareze (iako zarez razdvaja stupce) te to što ne postoji funkcija koja omogućuje vađenje substringa od mjesta a do mjesta b.

Headera se lako riješimo, samo ignoriramo prvo liniju koju pročitamo.

Za substring:

imamo varijablu begin koja sprema mjesto zadnjeg zareza.

Zatim radimo begin+1, da dobijemo mjesto nakon zareza

find da nađem zarez koji se nalazi nakon tog mjesta(begin+1)

pošto find vraća vrijednost mjesta, moramo tog finda oduzeti begin+1 kako bi dobili broj znakova

te begin+1 i tu duljinu šaljemo metodu substring kako bi dobili željeni podataka


Za zareze:

na sreću ti podatci su unutar navodnika

stoga radimo na principu ako je idući char (begin+1) navodnik

tražimo idući navodnik koji se nalazi nakon trenutacanChar+1og mjesta

i onda tražimo zarez koji se nalazi nakon tog navodnika

