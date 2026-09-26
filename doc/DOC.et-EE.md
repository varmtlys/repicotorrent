# RePicoTorrenti dokumentatsioon

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · **Eesti** · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Alustamine](#alustamine)
- [Peaaken](#peaaken)
- [Torrentite lisamine](#torrentite-lisamine)
- [Torrentite haldamine](#torrentite-haldamine)
- [Sildid](#sildid)
- [Filtrid ja konsool](#filtrid-ja-konsool)
- [Torrentite loomine](#torrentite-loomine)
- [Seaded](#seaded)
- [Üleminek PicoTorrentilt või qBittorrentilt](#üleminek-picotorrentilt-või-qbittorrentilt)
- [Uuendused](#uuendused)
- [Kiirklahvid](#kiirklahvid)
- [Failid ja käsurida](#failid-ja-käsurida)


## Alustamine

Laadige oma Windowsi jaoks zip
[väljalasete lehelt](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` 64-bitise Windowsi jaoks, `arm64` ARM-il töötava Windowsi jaoks, `x86`
32-bitise Windowsi jaoks. Pakkige see lahti ükskõik millisesse kausta, kuhu
saate kirjutada, ja käivitage `RePicoTorrent.exe`. Midagi ei paigaldata:
seaded, torrentite loend ja logid hoitakse exe kõrval, nii et kausta saab
teisaldada või kopeerida USB-mälupulgale.

Iga kaust on programmi eraldi koopia. Kaks koopiat eri kaustadest võivad
töötada korraga, kui need kasutavad eri porte.


## Peaaken

![Peaaken](images/en-US/main.png)

Üleval on torrentite loend. Iga veergu saab sortida selle päisel
klõpsates; päistel paremklõps näitab või peidab veerge.

- **Progress** ja **Done**: kui palju soovitud andmetest on alla
  laaditud.
- **ETA**, **AL**, **ÜL**: järelejäänud aeg, allalaadimis- ja
  üleslaadimiskiirus.
- **Saadavus**: mitu täielikku koopiat on ühendatud partneritel
  kokku.
- **Seemneid**, **Partnerid**, **Leechers**: ühendatud ja sulgudes kogu
  parve arv jälgurite andmetel.

All on valitud torrenti üksikasjad:

- **Ülevaade**: nimi, räsid (v1 ja v2), suurus, salvestuskaust,
  kommentaar ja kokkuvõtted. Kommentaari lingid avanevad brauseris. Ülemine
  riba näitab tükke: iga alla laaditud tükk on värvitud kohas, kus see
  torrentis asub. Tükid saabuvad suvalises järjekorras (kõige haruldasemad
  enne), seega pooleliolevas torrentis on lünki.
- **Failid**: failid ja kaustad koos edenemisega. Paremklõpsuga saab
  määrata prioriteedi või faili vahele jätta; topeltklõps avab alla
  laaditud faili.
- **Partnerid**: ühendatud partnerid koos riigi, kliendi, kiiruste ja
  sõnadega välja kirjutatud ühenduslippudega.
- **Jälitajad**: jälguri olek, teatatud jagajad ja allalaadijad ning
  järgmine teadaanne. Paremklõpsuga saab lisada, eemaldada või uuesti
  teatada.

Olekuriba näitab torrentite arvu, DHT sõlmi, praeguseid kiirusi, kas
IP-filter on sees ja kui palju on selle seansi jooksul edastatud. Menüü
**Vaade** peidab või näitab üksikasjade paneeli, olekuriba ja
konsooli.


## Torrentite lisamine

- **Fail > Lisa torrent** (Ctrl+O): valige üks või mitu
  `.torrent` faili.
- **Fail > Lisa magneti lingid** (Ctrl+U): kleepige
  magnetlingid, üks rea kohta.
- Avage `.torrent` fail või magnetlink programmiga `RePicoTorrent.exe`; kui
  programm sellest kaustast juba töötab, antakse torrent sellele üle.

Enne lisamist saate valida kausta, soovitud failid ja sildi. Et torrentid
lisataks kohe vaikeseadetega, lülitage seadetes sisse
**Skip 'Add torrent' dialog**.


## Torrentite haldamine

Paremklõps ühel või mitmel torrentil:

- **Jätka**, **Jätka (sunni)** (eirab järjekorda), **Pausi**.
- **Force reannounce**, **Sunni ülekontrolli** (kontrollib kettal olevaid
  andmeid).
- **Järjestikus allalaadimine**: tükid laaditakse järjest, kasulik video
  vaatamiseks allalaadimise ajal.
- **Silt**: sildi määramine.
- **Ekspordi**: magnetlink või `.torrent` fail.
- **Liiguta**: andmete teisaldamine teise kausta.
- **Eemalda**: torrenti eemaldamine (Del) või torrenti eemaldamine koos
  failidega (Shift+Del).
- **Queuing**: üles või alla allalaadimisjärjekorras.
- **Kopeeri info räsi**, **Ava Exploreris**.


## Sildid

Sildid rühmitavad torrenteid. Need luuakse jaotises
**Seadistused > Labels**:

- **Värv**: sildi värv; kui **Üldine** all on sees
  **Use label color as background in torrent list**, värvitakse read
  selle värviga.
- **Save path**: selle sildiga lisatud torrentid salvestatakse siia.
- **Rakenda filter**: regulaaravaldis; uus torrent, mille nimi sellele
  vastab, saab sildi automaatselt. Näide: `ubuntu|debian|fedora`.

**Vaade > Labels** näitab ainult ühe sildiga torrenteid.


## Filtrid ja konsool

Jaotises **Vaade > Filter** on salvestatud filtrid, näiteks
praegu allalaaditavad torrentid. **Vaade > Konsool** avab
loendi alla rea: kirjutage päring ja vajutage Enter, et näha ainult
sobivaid torrenteid; tühjendage rida, et näha jälle kõiki.

| Väli | Tüüp | Tähendus |
|---|---|---|
| `name` | tekst | torrenti nimi |
| `label` | tekst | sildi nimi |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | arv | valmimise protsent |
| `size` | suurus | soovitud suurus: `b` (vaikimisi), `kb`, `mb`, `gb` |
| `dl`, `ul` | kiirus | baiti sekundis (vaikimisi), `kbps`, `mbps`, `gbps` |

Tehtemärgid: `=`, `<`, `<=`, `>`, `>=` ja `~` (sisaldab, tõstutundetu),
ühendatakse sõnadega `and` ja `or`. Tekst kirjutatakse jutumärkides,
ühikud väiketähtedega.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrentite loomine

**Fail > Loo torrent**:

![Torrenti loomine](images/en-US/create-torrent.png)

- Valige fail või kaust.
- **Režiim**: v1, v2 või hübriid v1 + v2. Hübriid töötab kõigi
  klientidega ja on vaikimisi valitud.
- **Kommentaar** ja **Looja** ei ole kohustuslikud.
- **Privaatne**: partnerid tulevad ainult jälguritelt, mitte DHT-st,
  PeX-ist ega kohalikust otsingust.
- **Add to session**: uut torrentit hakatakse kohe jagama.
- **Jälitajad (üks rea kohta)**: iga jälgur läheb oma tasemele; tasemeid
  proovitakse järjest.
- **URL seeds (one per line)**: samade andmetega veebiserverid. Kausta
  puhul peab aadress osutama kaustale, mis seda sisaldab.


## Seaded

**Vaade > Seadistused**. **Taasta algseaded** lähtestab
kõik seaded. Mõned muudatused (keel, teema, pordid) vajavad taaskäivitust;
programm pakub seda ise.

### Üldine

![Üldine](images/en-US/preferences-general.png)

- **Keel** ja **Theme** (süsteemi või hele; tume teema järgib
  Windowsi seadet).
- **Skip 'Add torrent' dialog**, **Käivita RePicoTorrent koos Windowsiga**, akna
  **Stardi positsioon**.
- **Show RePicoTorrent in notification area** ning kas akna minimeerimine
  või sulgemine peidab selle sinna.

### Allalaadimised

![Allalaadimised](images/en-US/preferences-downloads.png)

- **Save path**, **Liiguta lõpetatud allalaadimised** teise kausta.
- **Pausi kui kettal on vähe ruumi**.
- **Limiidid**: allalaadimise ja üleslaadimise piirangud KB/s, mitu
  torrentit võib korraga aktiivne olla ja ühenduste koguarv.

### Labels

![Sildid](images/en-US/preferences-labels.png)

Vt [Sildid](#sildid).

### Ühendus

![Ühendus](images/en-US/preferences-connection.png)

- **Listen interface**: aadressid ja pordid sissetulevate ühenduste
  jaoks. `0.0.0.0` ja `[::]` tähendavad kõiki IPv4- ja IPv6-aadresse.
- **Krüpteering**: nõua sissetulevate või väljaminevate ühenduste
  krüpteerimist.
- **Privaatsus**: DHT, kohalik partnerite otsing (LSD), partnerite vahetus
  (PeX), WebTorrent ja partneri riigi veerg. Riikide andmebaas (DB-IP Lite)
  laaditakse alla kord kuus, kuni veerg on sees.
- **IP filter**: blokeeri aadressid zip-failis olevast eMule-vormingus
  filtrist, näiteks lehelt emule-security.org.

### Proxy

![Puhverserver](images/en-US/preferences-proxy.png)

HTTP- või SOCKS4/5-puhverserver, parooliga või ilma, ja mis sellest läbi
käib: nimede lahendamine, ühendused partnerite ja jälguritega.

### Edasijõudnutele

![Täpsem](images/en-US/preferences-advanced.png)

Kõik libtorrenti seaded. Valige üks, et lugeda selle kirjeldust loendi
all. Muutke neid ainult siis, kui teate, mida need teevad;
**Taasta algseaded** taastab need.


## Üleminek PicoTorrentilt või qBittorrentilt

- **Fail > Import from PicoTorrent**: valige `PicoTorrent.sqlite`
  (kaasaskantava PicoTorrenti kõrval või kaustas
  `%LOCALAPPDATA%\PicoTorrent`). Lisatakse torrentid ja nende sildid;
  faili ainult loetakse. Et kõik koos seadetega üle võtta, kopeerige
  `PicoTorrent.sqlite` enne esimest käivitust `RePicoTorrent.exe` kõrvale:
  see nimetatakse ümber `RePicoTorrent.sqlite`-ks.
- **Fail > Import from qBittorrent**: valige qBittorrenti kaust
  `BT_backup` (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Edenemine,
  jälgurid, loendurid, kaustad ja kommentaarid säilivad.

Juba loendis olevad torrentid jäetakse vahele. Ärge jagage samu
torrenteid mõlemast kliendist korraga.


## Uuendused

Iga käivituse ajal küsib programm GitHubist uusimat väljalaset ning
**Abi > Kontrolli uuendusi** teeb seda igal ajal. Kui on uuem
versioon, laadib **Download and install** alla teie Windowsi zipi, kontrollib
seda väljalaske SHA-256 kontrollsummadega, asendab programmi failid ja
taaskäivitab selle. Seaded ja torrentid jäävad alles.


## Kiirklahvid

| Klahvid | Tegevus |
|---|---|
| Ctrl+O | lisa torrent |
| Ctrl+U | lisa magnetlingid |
| Ctrl+A | vali kõik torrentid |
| Del | eemalda valitud torrentid, jäta andmed alles |
| Shift+Del | eemalda valitud torrentid koos andmetega |
| F1 | ava see dokumentatsioon |


## Failid ja käsurida

`RePicoTorrent.exe` kõrval:

- `RePicoTorrent.sqlite`: seaded, torrentid ja nende jätkamisandmed;
- `coredb.sqlite`: tõlked (programmi osa);
- `logs`: logifailid;
- `Crashpad`: krahhitõmmised, neid ei saadeta kunagi;
- `dbip-country-lite.mmdb`: riikide andmebaas.

Käsurida:

```
RePicoTorrent.exe [--silent] [--save-path=<kaust>] [file.torrent | magnet:?xt=...]...
```

`--silent` lisab antud torrentid ilma lisamisaknata, `--save-path` määrab,
kuhu need salvestatakse.
