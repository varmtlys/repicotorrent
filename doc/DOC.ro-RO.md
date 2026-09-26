# Documentația RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · **Română** · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Primii pași](#primii-pași)
- [Fereastra principală](#fereastra-principală)
- [Adăugarea torrentelor](#adăugarea-torrentelor)
- [Gestionarea torrentelor](#gestionarea-torrentelor)
- [Etichete](#etichete)
- [Filtre și consolă](#filtre-și-consolă)
- [Crearea torrentelor](#crearea-torrentelor)
- [Preferințe](#preferințe)
- [Trecerea de la PicoTorrent sau qBittorrent](#trecerea-de-la-picotorrent-sau-qbittorrent)
- [Actualizări](#actualizări)
- [Comenzi rapide](#comenzi-rapide)
- [Fișiere și linia de comandă](#fișiere-și-linia-de-comandă)


## Primii pași

Descărcați arhiva zip pentru Windows-ul dumneavoastră de pe
[pagina versiunilor](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` pentru Windows pe 64 de biți, `arm64` pentru Windows pe ARM, `x86`
pentru Windows pe 32 de biți. Dezarhivați-o în orice folder în care puteți
scrie și porniți `RePicoTorrent.exe`. Nu se instalează nimic: setările,
lista de torrente și jurnalele stau lângă exe, deci folderul poate fi mutat
sau copiat pe un stick USB.

Fiecare folder este o copie separată a programului. Două copii din
foldere diferite pot rula simultan dacă folosesc porturi diferite.


## Fereastra principală

![Fereastra principală](images/en-US/main.png)

Sus este lista de torrente. Orice coloană se sortează cu un clic pe
antet; clic dreapta pe antete afișează sau ascunde coloane.

- **Progres** și **Done**: cât din datele dorite s-a descărcat.
- **TEA**, **Descărcare**, **Urcare**: timpul rămas, vitezele de descărcare
  și de încărcare.
- **Availability**: câte copii complete au împreună partenerii
  conectați.
- **Semințe**, **Perechi**, **Leechers**: conectați, iar în paranteze
  numărul din întregul roi după trackere.

Jos sunt detaliile torrentului selectat:

- **Prezentare generală**: nume, hash-uri (v1 și v2), dimensiune, folder,
  comentariu și totaluri. Linkurile din comentariu se deschid în browser.
  Bara de sus arată bucățile: fiecare bucată descărcată e colorată acolo
  unde se află în torrent. Bucățile sosesc în altă ordine (întâi cele mai
  rare), așa că un torrent în lucru are goluri.
- **Fișiere**: fișiere și foldere cu progresul lor. Clic dreapta pentru
  prioritate sau pentru a sări un fișier; dublu clic deschide un fișier
  descărcat.
- **Perechi**: parteneri conectați cu țara, clientul, vitezele și
  indicatorii conexiunii scriși în cuvinte.
- **Tracker-e**: starea trackerului, seederii și leecherii raportați și
  următorul anunț. Clic dreapta pentru adăugare, eliminare sau reanunțare.

Bara de stare arată numărul de torrente, nodurile DHT, vitezele curente,
dacă filtrul IP e activ și cât s-a transferat în această sesiune. Meniul
**Vizualizează** ascunde sau afișează panoul de detalii, bara de stare și
consola.


## Adăugarea torrentelor

- **Fișier > Adaugă torrent** (Ctrl+O): alegeți unul sau mai
  multe fișiere `.torrent`.
- **Fișier > Add link-uri magnet** (Ctrl+U): lipiți linkuri
  magnet, câte unul pe linie.
- Deschideți un fișier `.torrent` sau un link magnet cu
  `RePicoTorrent.exe`; dacă programul din acel folder rulează deja,
  torrentul îi este transmis.

Înainte de adăugare puteți alege folderul, fișierele dorite și o etichetă.
Pentru a adăuga torrentele direct cu setările implicite, activați
**Skip 'Add torrent' dialog** în preferințe.


## Gestionarea torrentelor

Clic dreapta pe unul sau mai multe torrente:

- **Repornește**, **Repornește (forțat)** (ignoră coada), **Pauză**.
- **Force reannounce**, **Force recheck** (verifică datele de pe
  disc).
- **Descărcare secvențială**: descărcarea bucăților în ordine, utilă pentru
  a viziona un video în timp ce se descarcă.
- **Label**: atribuirea unei etichete.
- **Export**: linkul magnet sau fișierul `.torrent`.
- **Mută**: mutarea datelor în alt folder.
- **Șterge**: eliminarea torrentului (Del) sau a torrentului și a
  fișierelor (Shift+Del).
- **Coadă**: sus sau jos în coada de descărcare.
- **Copie informația hash**, **Deschide în Explorer**.


## Etichete

Etichetele grupează torrentele. Se creează în
**Preferințe > Labels**:

- **Color**: culoarea etichetei; cu
  **Use label color as background in torrent list** (**General**)
  rândurile sunt colorate cu ea.
- **Ruta pentru descărcare**: torrentele adăugate cu această etichetă se salvează
  aici.
- **Apply filter**: o expresie regulată; un torrent nou al cărui nume se
  potrivește primește eticheta automat. Exemplu: `ubuntu|debian|fedora`.

**Vizualizează > Labels** arată doar torrentele cu o anumită etichetă.


## Filtre și consolă

**Vizualizează > Filter** conține filtre salvate, de exemplu
torrentele care se descarcă acum. **Vizualizează > Console** deschide
o linie sub listă: scrieți o interogare și apăsați Enter pentru a vedea
doar torrentele potrivite; goliți-o pentru a le vedea din nou pe toate.

| Câmp | Tip | Sens |
|---|---|---|
| `name` | text | numele torrentului |
| `label` | text | numele etichetei |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | număr | procent finalizat |
| `size` | dimensiune | dimensiunea dorită: `b` (implicit), `kb`, `mb`, `gb` |
| `dl`, `ul` | viteză | octeți pe secundă (implicit), `kbps`, `mbps`, `gbps` |

Operatori: `=`, `<`, `<=`, `>`, `>=` și `~` (conține, fără a ține cont de
majuscule), legați cu `and` și `or`. Textul se scrie între ghilimele
duble, unitățile cu litere mici.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Crearea torrentelor

**Fișier > Create torrent**:

![Creare torrent](images/en-US/create-torrent.png)

- Alegeți un fișier sau un folder.
- **Mode**: v1, v2 sau hibrid v1 + v2. Hibridul merge cu orice client
  și este implicit.
- **Comment** și **Creator** sunt opționale.
- **Private**: partenerii vin doar de la trackere, nu din DHT, PeX sau
  descoperirea locală.
- **Add to session**: începeți imediat să distribuiți noul torrent.
- **Trackers (one per line)**: fiecare tracker are propriul nivel;
  nivelurile sunt încercate pe rând.
- **URL seeds (one per line)**: servere web cu aceleași date. Pentru un
  folder, URL-ul trebuie să indice folderul care îl conține.


## Preferințe

**Vizualizează > Preferințe**. **Restore defaults** resetează
toate setările. Unele schimbări (limbă, temă, porturi) cer repornire;
programul o propune.

### General

![General](images/en-US/preferences-general.png)

- **Limbă** și **Theme** (sistem sau luminoasă; tema întunecată
  urmează setarea Windows).
- **Skip 'Add torrent' dialog**, **Pornește RePicoTorrent cu Windows**,
  **Poziție de pornire** a ferestrei.
- **Show RePicoTorrent in notification area** și dacă minimizarea sau
  închiderea ferestrei o trimite acolo.

### Descărcări

![Descărcări](images/en-US/preferences-downloads.png)

- **Ruta pentru descărcare**, **Mută descarcările completare** în alt folder.
- **Pause when disk space is low**.
- **Limite**: limite de descărcare și încărcare în KB/s, câte torrente
  pot fi active simultan și numărul total de conexiuni.

### Labels

![Etichete](images/en-US/preferences-labels.png)

Vedeți [Etichete](#etichete).

### Conexiune

![Conexiune](images/en-US/preferences-connection.png)

- **Interfață de ascultare**: adrese și porturi pentru conexiunile de intrare.
  `0.0.0.0` și `[::]` înseamnă toate adresele IPv4 și IPv6.
- **Criptare**: cererea criptării conexiunilor de intrare sau ieșire.
- **Intimitate**: DHT, descoperirea locală (LSD), schimbul de parteneri
  (PeX), WebTorrent și coloana cu țara partenerului. Baza de țări (DB-IP
  Lite) se descarcă o dată pe lună cât timp coloana este activă.
- **IP filter**: blocarea adreselor dintr-un filtru în format eMule
  într-un zip, de exemplu de pe emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP sau SOCKS4/5, cu sau fără parolă, și ce trece prin el:
rezolvarea numelor, conexiunile cu partenerii și trackerele.

### Avansat

![Avansat](images/en-US/preferences-advanced.png)

Toate setările libtorrent. Selectați una pentru a-i citi descrierea sub
listă. Schimbați-le doar dacă știți ce fac; **Restore defaults** le
readuce.


## Trecerea de la PicoTorrent sau qBittorrent

- **Fișier > Import from PicoTorrent**: alegeți `PicoTorrent.sqlite`
  (lângă un PicoTorrent portabil sau în `%LOCALAPPDATA%\PicoTorrent`).
  Se adaugă torrentele și etichetele lor; fișierul este doar citit. Pentru
  a prelua totul, inclusiv setările, copiați `PicoTorrent.sqlite` lângă
  `RePicoTorrent.exe` înainte de prima pornire: va fi redenumit
  `RePicoTorrent.sqlite`.
- **Fișier > Import from qBittorrent**: alegeți folderul
  `BT_backup` al qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Se
  păstrează progresul, trackerele, contoarele, folderele și comentariile.

Torrentele deja existente în listă sunt sărite. Nu distribuiți aceleași
torrente din ambii clienți în același timp.


## Actualizări

La fiecare pornire programul întreabă GitHub de ultima versiune, iar
**Ajutor > Caută actualizări** o face oricând. Dacă există o
versiune mai nouă, **Download and install** descarcă arhiva zip pentru
Windows-ul dumneavoastră, o verifică cu sumele SHA-256 ale versiunii,
înlocuiește fișierele programului și îl repornește. Setările și torrentele
rămân.


## Comenzi rapide

| Taste | Acțiune |
|---|---|
| Ctrl+O | adaugă torrent |
| Ctrl+U | adaugă linkuri magnet |
| Ctrl+A | selectează toate torrentele |
| Del | elimină torrentele selectate, păstrează datele |
| Shift+Del | elimină torrentele selectate cu tot cu date |
| F1 | deschide această documentație |


## Fișiere și linia de comandă

Lângă `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: setări, torrente și datele lor de reluare;
- `coredb.sqlite`: traduceri (parte din program);
- `logs`: jurnale;
- `Crashpad`: rapoarte de blocare, nu se trimit niciodată;
- `dbip-country-lite.mmdb`: baza de țări.

Linia de comandă:

```
RePicoTorrent.exe [--silent] [--save-path=<folder>] [file.torrent | magnet:?xt=...]...
```

`--silent` adaugă torrentele date fără fereastra de adăugare,
`--save-path` stabilește unde se salvează.
