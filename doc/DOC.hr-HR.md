# Dokumentacija za RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · **Hrvatski** · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Prvi koraci](#prvi-koraci)
- [Glavni prozor](#glavni-prozor)
- [Dodavanje torrenata](#dodavanje-torrenata)
- [Upravljanje torrentima](#upravljanje-torrentima)
- [Oznake](#oznake)
- [Filtri i konzola](#filtri-i-konzola)
- [Stvaranje torrenata](#stvaranje-torrenata)
- [Postavke](#postavke)
- [Prelazak s PicoTorrenta ili qBittorrenta](#prelazak-s-picotorrenta-ili-qbittorrenta)
- [Ažuriranja](#ažuriranja)
- [Tipkovnički prečaci](#tipkovnički-prečaci)
- [Datoteke i naredbeni redak](#datoteke-i-naredbeni-redak)


## Prvi koraci

Preuzmite zip za svoj Windows sa
[stranice izdanja](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` za 64-bitni Windows, `arm64` za Windows na ARM-u, `x86` za 32-bitni
Windows. Raspakirajte ga u bilo koju mapu u koju možete pisati i pokrenite
`RePicoTorrent.exe`. Ništa se ne instalira: postavke, popis torrenata i
zapisnici čuvaju se pokraj exe datoteke, pa se mapa može premjestiti ili
kopirati na USB stick.

Svaka mapa je zasebna kopija programa. Dvije kopije u različitim mapama
mogu raditi istodobno ako koriste različite portove.


## Glavni prozor

![Glavni prozor](images/en-US/main.png)

Gore je popis torrenata. Svaki se stupac sortira klikom na njegovo
zaglavlje; desnim klikom na zaglavlja prikazujete ili skrivate stupce.

- **Napredak** i **Done**: koliko je željenih podataka preuzeto.
- **Otprilike**, **Preuzimanje**, **Slanje**: preostalo vrijeme, brzina preuzimanja
  i slanja.
- **Dostupnost**: koliko potpunih kopija zajedno imaju povezani
  peerovi.
- **Seederi**, **Peerevi**, **Leechers**: povezani, a u zagradi broj u
  cijelom roju prema trackerima.

Dolje su pojedinosti odabranog torrenta:

- **Pregled**: naziv, hashevi (v1 i v2), veličina, mapa, komentar i
  zbrojevi. Poveznice u komentaru otvaraju se u pregledniku. Traka na vrhu
  prikazuje dijelove: svaki preuzeti dio obojen je ondje gdje se nalazi u
  torrentu. Dijelovi se preuzimaju izvan redoslijeda (najrjeđi prvi), pa
  nedovršeni torrent ima praznine.
- **Datoteke**: datoteke i mape s napretkom. Desni klik postavlja
  prioritet ili preskače datoteku; dvoklik otvara preuzetu datoteku.
- **Peerevi**: povezani peerovi s državom, klijentom, brzinama i
  oznakama veze ispisanima riječima.
- **Pratitelji**: stanje trackera, prijavljeni seederi i leecheri te
  sljedeća objava. Desni klik za dodavanje, uklanjanje ili ponovnu objavu.

Traka stanja prikazuje broj torrenata, DHT čvorove, trenutne brzine, je
li IP filtar uključen i koliko je preneseno u ovoj sesiji. Izbornik
**Prikaz** skriva ili prikazuje ploču s pojedinostima, traku stanja i
konzolu.


## Dodavanje torrenata

- **Datoteka > Dodaj torrent** (Ctrl+O): odaberite jednu ili više
  `.torrent` datoteka.
- **Datoteka > Dodaj magnet link(ove)** (Ctrl+U): zalijepite magnet
  poveznice, jednu po retku.
- Otvorite `.torrent` datoteku ili magnet poveznicu s `RePicoTorrent.exe`;
  ako program iz te mape već radi, torrent se predaje njemu.

Prije dodavanja možete odabrati mapu, željene datoteke i oznaku. Da se
torrenti odmah dodaju sa zadanim postavkama, uključite
**Preskoči 'dodaj torrent' dijalog** u postavkama.


## Upravljanje torrentima

Desni klik na jedan ili više torrenata:

- **Nastavi**, **Nastavi (prisilno)** (zanemaruje red), **Pauziraj**.
- **Forsiraj najavu**, **Forsiraj provjeru** (provjerava podatke na
  disku).
- **Sekvencijalno preuzimanje**: preuzimanje dijelova redom, korisno za
  gledanje videa dok se preuzima.
- **Naljepnica**: dodijeliti oznaku.
- **Export**: magnet poveznica ili `.torrent` datoteka.
- **Preseli**: premjestiti podatke u drugu mapu.
- **Ukloniti**: ukloniti torrent (Del) ili torrent s datotekama
  (Shift+Del).
- **Čekanje u redu**: gore ili dolje u redu preuzimanja.
- **Kopiraj hash informaciju**, **Otvori u Exploreru**.


## Oznake

Oznake grupiraju torrente. Stvaraju se u
**Preferencija > Naljepnice**:

- **Boja**: boja oznake; uz uključeno
  **Koristi boju naljepnicu za podlogu u listi torrenta** (**Općenito**)
  retci se boje njome.
- **Mapa preuzimanja**: torrenti s ovom oznakom spremaju se ovdje.
- **Primijeni filter**: regularni izraz; novi torrent čiji mu naziv
  odgovara automatski dobiva ovu oznaku. Primjer: `ubuntu|debian|fedora`.

**Prikaz > Naljepnice** prikazuje samo torrente s jednom oznakom.


## Filtri i konzola

U **Prikaz > Filter** su spremljeni filtri, na primjer
torrenti koji se upravo preuzimaju. **Prikaz > Konzola** otvara
redak ispod popisa: upišite upit i pritisnite Enter da ostanu samo
odgovarajući torrenti; ispraznite ga da se opet prikažu svi.

| Polje | Vrsta | Značenje |
|---|---|---|
| `name` | tekst | naziv torrenta |
| `label` | tekst | naziv oznake |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | broj | postotak dovršenosti |
| `size` | veličina | željena veličina: `b` (zadano), `kb`, `mb`, `gb` |
| `dl`, `ul` | brzina | bajtova u sekundi (zadano), `kbps`, `mbps`, `gbps` |

Operatori: `=`, `<`, `<=`, `>`, `>=` i `~` (sadrži, bez obzira na velika i
mala slova), povezani s `and` i `or`. Tekst se piše u dvostrukim
navodnicima, jedinice malim slovima.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Stvaranje torrenata

**Datoteka > Stvori torrent**:

![Stvaranje torrenta](images/en-US/create-torrent.png)

- Odaberite datoteku ili mapu.
- **Mod**: v1, v2 ili hibrid v1 + v2. Hibrid radi sa svim klijentima i
  zadani je izbor.
- **Komentar** i **Tvorac** nisu obavezni.
- **Privatno**: peerovi dolaze samo od trackera, ne preko DHT-a, PeX-a
  ni lokalnog otkrivanja.
- **Dodaj u sesiju**: odmah početi dijeliti novi torrent.
- **Pratitelji (jedan po liniji)**: svaki tracker ide u svoju razinu; razine
  se isprobavaju redom.
- **URL seederi (jedan po liniji)**: web poslužitelji s istim podacima. Za
  mapu adresa mora pokazivati na mapu koja je sadrži.


## Postavke

**Prikaz > Preferencija**. **Vrati zadano** vraća sve
postavke. Neke promjene (jezik, tema, portovi) traže ponovno pokretanje;
program ga nudi.

### Općenito

![Općenito](images/en-US/preferences-general.png)

- **Jezik** i **Theme** (sustavna ili svijetla; tamna tema prati
  postavku Windowsa).
- **Preskoči 'dodaj torrent' dijalog**, **Pokreni RePicoTorrent s Windows**,
  **Početna pozicija** prozora.
- **Prikaži RePicoTorrent u traci za obavijesti** te skriva li ga ondje
  minimiziranje ili zatvaranje prozora.

### Preuzimanja

![Preuzimanja](images/en-US/preferences-downloads.png)

- **Mapa preuzimanja**, **Preseli završena preuzimanja** u drugu mapu.
- **Pauziraj kad je prostor na disk nedovoljan**.
- **Limiti**: ograničenja preuzimanja i slanja u KB/s, koliko torrenata
  smije biti aktivno istodobno i ukupan broj veza.

### Naljepnice

![Oznake](images/en-US/preferences-labels.png)

Vidi [Oznake](#oznake).

### Veza

![Veza](images/en-US/preferences-connection.png)

- **Sučelje slušanja**: adrese i portovi za dolazne veze. `0.0.0.0` i
  `[::]` znače sve IPv4 i IPv6 adrese.
- **Šifriranje**: zahtijevati šifriranje dolaznih ili odlaznih veza.
- **Privatnost**: DHT, lokalno otkrivanje peerova (LSD), razmjena peerova
  (PeX), WebTorrent i stupac s državom peera. Baza država (DB-IP Lite)
  preuzima se jednom mjesečno dok je stupac uključen.
- **IP filter**: blokirati adrese iz filtra u eMule formatu u zip
  datoteci, na primjer s emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP ili SOCKS4/5 proxy, s lozinkom ili bez nje, i što ide kroz njega:
razlučivanje imena, veze s peerovima i trackerima.

### Napredno

![Napredno](images/en-US/preferences-advanced.png)

Sve postavke libtorrenta. Odaberite jednu da ispod popisa pročitate njezin
opis. Mijenjajte ih samo ako znate što rade; **Vrati zadano** ih
vraća.


## Prelazak s PicoTorrenta ili qBittorrenta

- **Datoteka > Import from PicoTorrent**: odaberite
  `PicoTorrent.sqlite` (pokraj prijenosnog PicoTorrenta ili u
  `%LOCALAPPDATA%\PicoTorrent`). Dodaju se torrenti i njihove oznake;
  datoteka se samo čita. Da preuzmete sve, uključujući postavke, kopirajte
  `PicoTorrent.sqlite` pokraj `RePicoTorrent.exe` prije prvog pokretanja:
  bit će preimenovana u `RePicoTorrent.sqlite`.
- **Datoteka > Import from qBittorrent**: odaberite mapu `BT_backup`
  qBittorrenta (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Zadržavaju se
  napredak, trackeri, brojači, mape i komentari.

Torrenti koji su već na popisu preskaču se. Ne dijelite iste torrente iz
oba klijenta istodobno.


## Ažuriranja

Pri svakom pokretanju program pita GitHub za najnovije izdanje, a
**Pomoć > Provjeri ažuriranja** provjerava u bilo kojem trenutku.
Ako postoji novija inačica, **Download and install** preuzima zip za vaš
Windows, provjerava ga SHA-256 kontrolnim zbrojevima izdanja, zamjenjuje
datoteke programa i ponovno ga pokreće. Postavke i torrenti ostaju.


## Tipkovnički prečaci

| Tipke | Radnja |
|---|---|
| Ctrl+O | dodaj torrent |
| Ctrl+U | dodaj magnet poveznice |
| Ctrl+A | odaberi sve torrente |
| Del | ukloni odabrane torrente, zadrži podatke |
| Shift+Del | ukloni odabrane torrente s podacima |
| F1 | otvori ovu dokumentaciju |


## Datoteke i naredbeni redak

Pokraj `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: postavke, torrenti i podaci za nastavak;
- `coredb.sqlite`: prijevodi (dio programa);
- `logs`: zapisnici;
- `Crashpad`: ispisi rušenja, nikad se ne šalju;
- `dbip-country-lite.mmdb`: baza država.

Naredbeni redak:

```
RePicoTorrent.exe [--silent] [--save-path=<mapa>] [file.torrent | magnet:?xt=...]...
```

`--silent` dodaje zadane torrente bez prozora za dodavanje, `--save-path`
određuje gdje se spremaju.
