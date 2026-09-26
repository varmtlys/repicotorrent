# RePicoTorrentin ohjeet

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · **Suomi** · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Aloittaminen](#aloittaminen)
- [Pääikkuna](#pääikkuna)
- [Torrenttien lisääminen](#torrenttien-lisääminen)
- [Torrenttien hallinta](#torrenttien-hallinta)
- [Tunnisteet](#tunnisteet)
- [Suodattimet ja konsoli](#suodattimet-ja-konsoli)
- [Torrenttien luominen](#torrenttien-luominen)
- [Asetukset](#asetukset)
- [Siirtyminen PicoTorrentista tai qBittorrentista](#siirtyminen-picotorrentista-tai-qbittorrentista)
- [Päivitykset](#päivitykset)
- [Pikanäppäimet](#pikanäppäimet)
- [Tiedostot ja komentorivi](#tiedostot-ja-komentorivi)


## Aloittaminen

Lataa Windowsillesi sopiva zip
[julkaisusivulta](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` 64-bittiselle Windowsille, `arm64` ARM-Windowsille, `x86`
32-bittiselle Windowsille. Pura se mihin tahansa kansioon, johon voit
kirjoittaa, ja käynnistä `RePicoTorrent.exe`. Mitään ei asenneta:
asetukset, torrenttilista ja lokit säilytetään exe-tiedoston vieressä,
joten kansion voi siirtää tai kopioida USB-muistille.

Jokainen kansio on ohjelman erillinen kopio. Kaksi kopiota eri kansioista
voi olla käynnissä yhtä aikaa, jos ne käyttävät eri portteja.


## Pääikkuna

![Pääikkuna](images/en-US/main.png)

Ylhäällä on torrenttilista. Jokainen sarake lajitellaan napsauttamalla
sen otsikkoa; otsikoiden hiiren oikealla painikkeella sarakkeita voi
näyttää tai piilottaa.

- **Eteneminen** ja **Done**: kuinka paljon halutuista tiedoista on
  ladattu.
- **Aika**, **Lad**, **Läh**: jäljellä oleva aika, lataus- ja
  lähetysnopeus.
- **Saatavuus**: kuinka monta täydellistä kopiota yhdistetyillä
  vertaisilla on yhteensä.
- **Jakajat**, **Lataajat**, **Leechers**: yhdistetyt ja suluissa
  koko parven määrä trackerien mukaan.

Alhaalla näkyvät valitun torrentin tiedot:

- **Tiedot**: nimi, tiivisteet (v1 ja v2), koko, tallennuskansio,
  kommentti ja summat. Kommentin linkit avautuvat selaimeen. Ylhäällä oleva
  palkki näyttää palat: jokainen ladattu pala on väritetty kohtaan, jossa
  se on torrentissa. Palat ladataan epäjärjestyksessä (harvinaisimmat
  ensin), joten keskeneräisessä torrentissa on aukkoja.
- **Tiedostot**: tiedostot ja kansiot edistymisineen. Hiiren oikealla
  painikkeella voi asettaa prioriteetin tai ohittaa tiedoston;
  kaksoisnapsautus avaa ladatun tiedoston.
- **Lataajat**: yhdistetyt vertaiset maineen, asiakasohjelmineen,
  nopeuksineen ja sanoin kirjoitettuine yhteysliputuksineen.
- **Seurantapalvelimet**: trackerin tila, sen ilmoittamat jakajat ja lataajat
  sekä seuraava ilmoitus. Hiiren oikealla painikkeella voi lisätä,
  poistaa tai ilmoittaa uudelleen.

Tilarivi näyttää torrenttien määrän, DHT-solmut, nykyiset nopeudet, onko
IP-suodatin päällä ja paljonko istunnossa on siirretty. Valikosta
**Näytä** voi piilottaa tai näyttää tietopaneelin, tilarivin ja
konsolin.


## Torrenttien lisääminen

- **Tiedosto > Lisää torrentti** (Ctrl+O): valitse yksi tai useampi
  `.torrent`-tiedosto.
- **Tiedosto > Lisää magnet-linkki** (Ctrl+U): liitä
  magnet-linkit, yksi riville.
- Avaa `.torrent`-tiedosto tai magnet-linkki `RePicoTorrent.exe`-ohjelmalla;
  jos ohjelma kyseisestä kansiosta on jo käynnissä, torrentti välitetään
  sille.

Ennen lisäämistä voit valita kansion, halutut tiedostot ja tunnisteen.
Jos haluat torrenttien lisättävän heti oletusasetuksilla, ota käyttöön
**Ohita 'Lisää torrentti' -dialogi** asetuksista.


## Torrenttien hallinta

Napsauta hiiren oikealla yhtä tai useampaa torrenttia:

- **Jatka**, **Jatka (pakotettu)** (ohittaa jonon), **Pysäytä**.
- **Pakota päivitys**, **Pakota uudelleentarkistus** (tarkistaa levyllä olevat
  tiedot).
- **Lataa osat järjestyksessä**: palat ladataan järjestyksessä, kätevää
  videon katsomiseen latauksen aikana.
- **Label**: tunnisteen asettaminen.
- **Export**: magnet-linkki tai `.torrent`-tiedosto.
- **Siirrä tiedostot**: tietojen siirto toiseen kansioon.
- **Poista**: torrentin poisto (Del) tai torrentin ja sen tiedostojen
  poisto (Vaihto+Del).
- **Siirrä jonossa**: ylös tai alas latausjonossa.
- **Kopioi tarkistesumma**, **Avaa latauskansio**.


## Tunnisteet

Tunnisteet ryhmittelevät torrentteja. Ne luodaan kohdassa
**Asetukset > Labels**:

- **Color**: tunnisteen väri; kun
  **Use label color as background in torrent list** (**Yleiset**) on
  päällä, rivit väritetään sillä.
- **Tallennussijainti**: tällä tunnisteella lisätyt torrentit tallennetaan
  tänne.
- **Apply filter**: säännöllinen lauseke; uusi torrentti, jonka nimi
  vastaa sitä, saa tunnisteen automaattisesti. Esimerkki:
  `ubuntu|debian|fedora`.

**Näytä > Labels** näyttää vain yhden tunnisteen torrentit.


## Suodattimet ja konsoli

Kohdassa **Näytä > Filter** on tallennettuja suodattimia,
esimerkiksi juuri nyt latautuvat torrentit. **Näytä > Console**
avaa rivin listan alle: kirjoita kysely ja paina Enter, niin vain
vastaavat torrentit näkyvät; tyhjennä rivi, niin kaikki näkyvät taas.

| Kenttä | Tyyppi | Merkitys |
|---|---|---|
| `name` | teksti | torrentin nimi |
| `label` | teksti | tunnisteen nimi |
| `status` | teksti | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | luku | valmistumisprosentti |
| `size` | koko | haluttu koko: `b` (oletus), `kb`, `mb`, `gb` |
| `dl`, `ul` | nopeus | tavua sekunnissa (oletus), `kbps`, `mbps`, `gbps` |

Operaattorit: `=`, `<`, `<=`, `>`, `>=` ja `~` (sisältää, kirjainkoolla ei
väliä), yhdistetään sanoilla `and` ja `or`. Teksti kirjoitetaan
lainausmerkkeihin, yksiköt pienillä kirjaimilla.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrenttien luominen

**Tiedosto > Create torrent**:

![Luo torrentti](images/en-US/create-torrent.png)

- Valitse tiedosto tai kansio.
- **Mode**: v1, v2 tai v1 + v2 -hybridi. Hybridi toimii kaikkien
  asiakasohjelmien kanssa ja on oletus.
- **Kommentti** ja **Creator** ovat valinnaisia.
- **Private**: vertaiset tulevat vain trackereilta, eivät DHT:stä,
  PeX:stä tai paikallisesta hausta.
- **Add to session**: uuden torrentin jakaminen alkaa heti.
- **Trackers (one per line)**: jokainen tracker saa oman tasonsa;
  tasoja kokeillaan järjestyksessä.
- **URL seeds (one per line)**: verkkopalvelimet, joilla on samat
  tiedot. Kansion kohdalla osoitteen on osoitettava kansioon, joka sen
  sisältää.


## Asetukset

**Näytä > Asetukset**. **Restore defaults** palauttaa
kaikki asetukset. Jotkin muutokset (kieli, teema, portit) vaativat
uudelleenkäynnistyksen; ohjelma tarjoaa sitä.

### Yleiset

![Yleiset](images/en-US/preferences-general.png)

- **Kieli** ja **Theme** (järjestelmä tai vaalea; tumma teema
  seuraa Windowsin asetusta).
- **Ohita 'Lisää torrentti' -dialogi**, **Käynnistä Windowsin käynnistyessä**, ikkunan
  **Käynnistä tilaan**.
- **Näytä kuvake ilmoitusalueella** sekä se, piilottaako
  pienentäminen tai sulkeminen ikkunan sinne.

### Lataukset

![Lataukset](images/en-US/preferences-downloads.png)

- **Tallennussijainti**, **Siirrä valmistuneet lataukset** toiseen kansioon.
- **Pause when disk space is low**.
- **Rajoitukset**: lataus- ja lähetysrajat KB/s, montako torrenttia voi olla
  aktiivisena yhtä aikaa ja yhteyksien kokonaismäärä.

### Labels

![Tunnisteet](images/en-US/preferences-labels.png)

Katso [Tunnisteet](#tunnisteet).

### Yhteys

![Yhteys](images/en-US/preferences-connection.png)

- **Kuuntele porttia**: osoitteet ja portit saapuville yhteyksille.
  `0.0.0.0` ja `[::]` tarkoittavat kaikkia IPv4- ja IPv6-osoitteita.
- **Salaus**: vaadi salaus saapuville tai lähteville yhteyksille.
- **Turvallisuus**: DHT, paikallinen vertaishaku (LSD), vertaisvaihto (PeX),
  WebTorrent ja vertaisten maasarake. Maatietokanta (DB-IP Lite) ladataan
  kerran kuussa niin kauan kuin sarake on päällä.
- **IP filter**: estä osoitteet zip-tiedostossa olevasta eMule-muotoisesta
  suodattimesta, esimerkiksi osoitteesta emule-security.org.

### Välityspalvelin

![Välityspalvelin](images/en-US/preferences-proxy.png)

HTTP- tai SOCKS4/5-välityspalvelin, salasanalla tai ilman, ja mitä sen
kautta kulkee: nimien selvitys, vertais- ja trackeriyhteydet.

### Lisäasetukset

![Lisäasetukset](images/en-US/preferences-advanced.png)

Kaikki libtorrentin asetukset. Valitse yksi lukeaksesi sen kuvauksen
listan alta. Muuta niitä vain, jos tiedät mitä ne tekevät;
**Restore defaults** palauttaa ne.


## Siirtyminen PicoTorrentista tai qBittorrentista

- **Tiedosto > Import from PicoTorrent**: valitse `PicoTorrent.sqlite`
  (siirrettävän PicoTorrentin vierestä tai kansiosta
  `%LOCALAPPDATA%\PicoTorrent`). Torrentit ja niiden tunnisteet lisätään;
  tiedostoa vain luetaan. Jos haluat siirtää kaiken asetuksineen, kopioi
  `PicoTorrent.sqlite` tiedoston `RePicoTorrent.exe` viereen ennen
  ensimmäistä käynnistystä: se nimetään uudelleen
  `RePicoTorrent.sqlite`-nimiseksi.
- **Tiedosto > Import from qBittorrent**: valitse qBittorrentin
  `BT_backup`-kansio (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Edistyminen,
  trackerit, laskurit, kansiot ja kommentit säilyvät.

Listalla jo olevat torrentit ohitetaan. Älä jaa samoja torrentteja
molemmista ohjelmista yhtä aikaa.


## Päivitykset

Jokaisella käynnistyskerralla ohjelma kysyy GitHubista uusinta julkaisua,
ja **Apua > Tarkista päivitykset** tekee sen milloin tahansa. Jos
uudempi versio on saatavilla, **Download and install** lataa Windowsillesi
sopivan zipin, tarkistaa sen julkaisun SHA-256-tarkistussummilla, korvaa
ohjelman tiedostot ja käynnistää sen uudelleen. Asetukset ja torrentit
säilyvät.


## Pikanäppäimet

| Näppäimet | Toiminto |
|---|---|
| Ctrl+O | lisää torrentti |
| Ctrl+U | lisää magnet-linkkejä |
| Ctrl+A | valitse kaikki torrentit |
| Del | poista valitut torrentit, säilytä tiedot |
| Vaihto+Del | poista valitut torrentit tietoineen |
| F1 | avaa nämä ohjeet |


## Tiedostot ja komentorivi

`RePicoTorrent.exe`-tiedoston vieressä:

- `RePicoTorrent.sqlite`: asetukset, torrentit ja niiden jatkotiedot;
- `coredb.sqlite`: käännökset (osa ohjelmaa);
- `logs`: lokitiedostot;
- `Crashpad`: kaatumisvedokset, joita ei koskaan lähetetä;
- `dbip-country-lite.mmdb`: maatietokanta.

Komentorivi:

```
RePicoTorrent.exe [--silent] [--save-path=<kansio>] [file.torrent | magnet:?xt=...]...
```

`--silent` lisää annetut torrentit ilman lisäysikkunaa, `--save-path`
määrää, minne ne tallennetaan.
