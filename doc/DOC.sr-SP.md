# Dokumentacija za RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · **Srpski** · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Prvi koraci](#prvi-koraci)
- [Glavni prozor](#glavni-prozor)
- [Dodavanje torenata](#dodavanje-torenata)
- [Upravljanje torentima](#upravljanje-torentima)
- [Oznake](#oznake)
- [Filteri i konzola](#filteri-i-konzola)
- [Pravljenje torenata](#pravljenje-torenata)
- [Podešavanja](#podešavanja)
- [Prelazak sa PicoTorrenta ili qBittorrenta](#prelazak-sa-picotorrenta-ili-qbittorrenta)
- [Ažuriranja](#ažuriranja)
- [Prečice na tastaturi](#prečice-na-tastaturi)
- [Datoteke i komandna linija](#datoteke-i-komandna-linija)


## Prvi koraci

Preuzmite zip za svoj Windows sa
[stranice izdanja](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` za 64-bitni Windows, `arm64` za Windows na ARM-u, `x86` za 32-bitni
Windows. Raspakujte ga u bilo koju fasciklu u koju možete da pišete i
pokrenite `RePicoTorrent.exe`. Ništa se ne instalira: podešavanja, spisak
torenata i dnevnici čuvaju se pored exe datoteke, pa se fascikla može
premestiti ili kopirati na USB fleš.

Svaka fascikla je zasebna kopija programa. Dve kopije u različitim
fasciklama mogu da rade istovremeno ako koriste različite portove.


## Glavni prozor

![Glavni prozor](images/en-US/main.png)

Gore je spisak torenata. Svaka kolona se sortira klikom na njeno
zaglavlje; desnim klikom na zaglavlja prikazujete ili skrivate kolone.

- **Napredak** i **Done**: koliko je željenih podataka preuzeto.
- **Preostalo**, **Preuzimanje**, **Slanje**: preostalo vreme, brzina preuzimanja i
  slanja.
- **Dostupnost**: koliko potpunih kopija zajedno imaju povezani
  peerovi.
- **Sejači**, **Kolege**, **Leechers**: povezani, a u zagradi broj u
  celom roju prema trekerima.

Dole su detalji izabranog torenta:

- **Pregled**: naziv, heševi (v1 i v2), veličina, fascikla, komentar i
  zbirovi. Linkovi u komentaru otvaraju se u pregledaču. Traka na vrhu
  prikazuje delove: svaki preuzeti deo obojen je tamo gde se nalazi u
  torentu. Delovi se preuzimaju van redosleda (najređi prvo), pa
  nezavršeni torent ima praznine.
- **Datoteke**: datoteke i fascikle sa napretkom. Desni klik postavlja
  prioritet ili preskače datoteku; dvoklik otvara preuzetu datoteku.
- **Kolege**: povezani peerovi sa zemljom, klijentom, brzinama i
  oznakama veze ispisanim rečima.
- **Tragači**: stanje trekera, prijavljeni sideri i ličeri i sledeća
  najava. Desni klik za dodavanje, uklanjanje ili ponovnu najavu.

Statusna traka prikazuje broj torenata, DHT čvorove, trenutne brzine, da
li je IP filter uključen i koliko je preneto u ovoj sesiji. Meni
**Izgled** skriva ili prikazuje panel sa detaljima, statusnu traku i
konzolu.


## Dodavanje torenata

- **Datoteka > Dodaj torrent** (Ctrl+O): izaberite jednu ili više
  `.torrent` datoteka.
- **Datoteka > Dodaj magnet link(ove)** (Ctrl+U): nalepite magnet
  linkove, jedan po redu.
- Otvorite `.torrent` datoteku ili magnet link pomoću `RePicoTorrent.exe`;
  ako program iz te fascikle već radi, torent se predaje njemu.

Pre dodavanja možete izabrati fasciklu, željene datoteke i oznaku. Da bi
se torenti odmah dodavali sa podrazumevanim podešavanjima, uključite
**Preskočite 'Dodaj torent' dijalog** u podešavanjima.


## Upravljanje torentima

Desni klik na jedan ili više torenata:

- **Nastavi**, **Nastavi (prisilno)** (zanemaruje red), **Pauziraj**.
- **Forsiraj najavu**, **Ponovo proveri** (proverava podatke na
  disku).
- **Sekvencijalno preuzimanje**: preuzimanje delova redom, korisno za gledanje
  videa dok se preuzima.
- **Etiketa**: dodeliti oznaku.
- **Izvezi**: magnet link ili `.torrent` datoteka.
- **Premesti**: premestiti podatke u drugu fasciklu.
- **Ukloni**: ukloniti torent (Del) ili torent sa datotekama
  (Shift+Del).
- **Čekanje u redu**: gore ili dole u redu preuzimanja.
- **Kopiraj info heš**, **Otvori u Explorer-u**.


## Oznake

Oznake grupišu torente. Prave se u **Podešavanja > Etikete**:

- **Boja**: boja oznake; uz uključeno
  **Koristi boju etikete za pozadinu u listi torenta** (**General**)
  redovi se boje njome.
- **Putanja čuvanja**: torenti sa ovom oznakom čuvaju se ovde.
- **Primeni filter**: regularni izraz; novi torent čiji mu naziv odgovara
  automatski dobija ovu oznaku. Primer: `ubuntu|debian|fedora`.

**Izgled > Etikete** prikazuje samo torente sa jednom oznakom.


## Filteri i konzola

U **Izgled > Filter** su sačuvani filteri, na primer torenti
koji se upravo preuzimaju. **Izgled > Konzola** otvara red
ispod spiska: upišite upit i pritisnite Enter da ostanu samo odgovarajući
torenti; ispraznite ga da se ponovo prikažu svi.

| Polje | Tip | Značenje |
|---|---|---|
| `name` | tekst | naziv torenta |
| `label` | tekst | naziv oznake |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | broj | procenat završenosti |
| `size` | veličina | željena veličina: `b` (podrazumevano), `kb`, `mb`, `gb` |
| `dl`, `ul` | brzina | bajtova u sekundi (podrazumevano), `kbps`, `mbps`, `gbps` |

Operatori: `=`, `<`, `<=`, `>`, `>=` i `~` (sadrži, bez obzira na velika i
mala slova), povezani sa `and` i `or`. Tekst se piše u dvostrukim
navodnicima, jedinice malim slovima.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Pravljenje torenata

**Datoteka > Napravi torent**:

![Pravljenje torenta](images/en-US/create-torrent.png)

- Izaberite datoteku ili fasciklu.
- **Mod**: v1, v2 ili hibrid v1 + v2. Hibrid radi sa svim klijentima
  i podrazumevani je izbor.
- **Komentar** i **Kreator** nisu obavezni.
- **Privatna**: peerovi dolaze samo od trekera, ne preko DHT-a, PeX-a ni
  lokalnog otkrivanja.
- **Dodaj u sesiju**: odmah početi deljenje novog torenta.
- **Trackers (jedan u liniji)**: svaki treker ide u svoj nivo; nivoi se
  isprobavaju redom.
- **URL sejači (jedan u liniji)**: veb serveri sa istim podacima. Za
  fasciklu adresa mora da pokazuje na fasciklu koja je sadrži.


## Podešavanja

**Izgled > Podešavanja**. **Vrati podrazumevane vrednosti** vraća sva
podešavanja. Neke promene (jezik, tema, portovi) traže ponovno pokretanje;
program ga nudi.

### General

![Opšte](images/en-US/preferences-general.png)

- **Jezik** i **Theme** (sistemska ili svetla; tamna tema prati
  podešavanje Windowsa).
- **Preskočite 'Dodaj torent' dijalog**, **Pokrenite RePicoTorrent sa Windows-om**,
  **Početna pozicija** prozora.
- **Prikažite RePicoTorrent u polju za obaveštenja** i da li ga minimizovanje ili
  zatvaranje prozora skriva tamo.

### Preuzimanja

![Preuzimanja](images/en-US/preferences-downloads.png)

- **Putanja čuvanja**, **Premesti završena preuzimanja** u drugu fasciklu.
- **Pauziraj kada nema dovoljno prostora na disku**.
- **Ograničenja**: ograničenja preuzimanja i slanja u KB/s, koliko torenata
  sme da bude aktivno istovremeno i ukupan broj veza.

### Etikete

![Oznake](images/en-US/preferences-labels.png)

Pogledajte [Oznake](#oznake).

### Konekcija

![Veza](images/en-US/preferences-connection.png)

- **Interfejs osluškivanja**: adrese i portovi za dolazne veze. `0.0.0.0` i
  `[::]` znače sve IPv4 i IPv6 adrese.
- **Enkripcija**: zahtevati šifrovanje dolaznih ili odlaznih veza.
- **Privatnost**: DHT, lokalno otkrivanje peerova (LSD), razmena peerova
  (PeX), WebTorrent i kolona sa zemljom peera. Baza zemalja (DB-IP Lite)
  preuzima se jednom mesečno dok je kolona uključena.
- **IP filter**: blokirati adrese iz filtera u eMule formatu u zip
  datoteci, na primer sa emule-security.org.

### Proxy

![Proksi](images/en-US/preferences-proxy.png)

HTTP ili SOCKS4/5 proksi, sa lozinkom ili bez nje, i šta ide kroz njega:
razrešavanje imena, veze sa peerovima i trekerima.

### Napredno

![Napredno](images/en-US/preferences-advanced.png)

Sva podešavanja libtorrenta. Izaberite jedno da ispod spiska pročitate
njegov opis. Menjajte ih samo ako znate šta rade; **Vrati podrazumevane vrednosti**
ih vraća.


## Prelazak sa PicoTorrenta ili qBittorrenta

- **Datoteka > Import from PicoTorrent**: izaberite
  `PicoTorrent.sqlite` (pored prenosivog PicoTorrenta ili u
  `%LOCALAPPDATA%\PicoTorrent`). Dodaju se torenti i njihove oznake;
  datoteka se samo čita. Da biste preneli sve, uključujući podešavanja,
  kopirajte `PicoTorrent.sqlite` pored `RePicoTorrent.exe` pre prvog
  pokretanja: biće preimenovana u `RePicoTorrent.sqlite`.
- **Datoteka > Import from qBittorrent**: izaberite fasciklu
  `BT_backup` qBittorrenta (`%LOCALAPPDATA%\qBittorrent\BT_backup`).
  Zadržavaju se napredak, trekeri, brojači, fascikle i komentari.

Torenti koji su već na spisku preskaču se. Ne delite iste torente iz oba
klijenta istovremeno.


## Ažuriranja

Pri svakom pokretanju program pita GitHub za najnovije izdanje, a
**Pomoć > Proveri ažuriranje** proverava u bilo kom trenutku. Ako
postoji novija verzija, **Download and install** preuzima zip za vaš Windows,
proverava ga SHA-256 kontrolnim zbirovima izdanja, zamenjuje datoteke
programa i ponovo ga pokreće. Podešavanja i torenti ostaju.


## Prečice na tastaturi

| Tasteri | Radnja |
|---|---|
| Ctrl+O | dodaj torent |
| Ctrl+U | dodaj magnet linkove |
| Ctrl+A | izaberi sve torente |
| Del | ukloni izabrane torente, zadrži podatke |
| Shift+Del | ukloni izabrane torente sa podacima |
| F1 | otvori ovu dokumentaciju |


## Datoteke i komandna linija

Pored `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: podešavanja, torenti i podaci za nastavak;
- `coredb.sqlite`: prevodi (deo programa);
- `logs`: dnevnici;
- `Crashpad`: ispisi padova, nikad se ne šalju;
- `dbip-country-lite.mmdb`: baza zemalja.

Komandna linija:

```
RePicoTorrent.exe [--silent] [--save-path=<fascikla>] [file.torrent | magnet:?xt=...]...
```

`--silent` dodaje zadate torente bez prozora za dodavanje, `--save-path`
određuje gde se čuvaju.
