# RePicoTorrent dokumentacija

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · **Lietuvių** · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Pradžia](#pradžia)
- [Pagrindinis langas](#pagrindinis-langas)
- [Torentų pridėjimas](#torentų-pridėjimas)
- [Torentų valdymas](#torentų-valdymas)
- [Žymės](#žymės)
- [Filtrai ir konsolė](#filtrai-ir-konsolė)
- [Torentų kūrimas](#torentų-kūrimas)
- [Nustatymai](#nustatymai)
- [Perėjimas iš PicoTorrent ar qBittorrent](#perėjimas-iš-picotorrent-ar-qbittorrent)
- [Atnaujinimai](#atnaujinimai)
- [Spartieji klavišai](#spartieji-klavišai)
- [Failai ir komandinė eilutė](#failai-ir-komandinė-eilutė)


## Pradžia

Atsisiųskite savo Windows tinkantį zip iš
[leidimų puslapio](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` 64 bitų Windows, `arm64` Windows ant ARM, `x86` 32 bitų Windows.
Išskleiskite jį į bet kurį aplanką, į kurį galite rašyti, ir paleiskite
`RePicoTorrent.exe`. Niekas neįdiegiama: nustatymai, torentų sąrašas ir
žurnalai laikomi šalia exe, todėl aplanką galima perkelti ar nukopijuoti į
USB atmintuką.

Kiekvienas aplankas yra atskira programos kopija. Dvi kopijos iš skirtingų
aplankų gali veikti kartu, jei naudoja skirtingus prievadus.


## Pagrindinis langas

![Pagrindinis langas](images/en-US/main.png)

Viršuje yra torentų sąrašas. Kiekvienas stulpelis rikiuojamas spustelėjus
jo antraštę; dešiniu pelės mygtuku ant antraščių stulpelius galima rodyti
ar slėpti.

- **Eiga** ir **Done**: kiek norimų duomenų jau atsiųsta.
- **Likęs laikas**, **Ats**, **Skl**: likęs laikas, atsiuntimo ir išsiuntimo
  greitis.
- **Pasiekiamumas**: kiek pilnų kopijų kartu turi prisijungę siuntėjai.
- **Skleidėjai**, **Siuntėjai**, **Leechers**: prisijungę, o skliaustuose
  skaičius visame spiečiuje pagal sekiklius.

Apačioje rodoma pasirinkto torento informacija:

- **Apžvalga**: pavadinimas, maišos (v1 ir v2), dydis, aplankas,
  komentaras ir sumos. Nuorodos komentare atsidaro naršyklėje. Juosta
  viršuje rodo dalis: kiekviena atsiųsta dalis nuspalvinta ten, kur ji yra
  torente. Dalys atsiunčiamos ne iš eilės (pirmiausia rečiausios), todėl
  nebaigtas torentas turi tarpų.
- **Failai**: failai ir aplankai su eiga. Dešiniu mygtuku galima
  nustatyti prioritetą arba praleisti failą; dukart spustelėjus atsiųstas
  failas atsidaro.
- **Siuntėjai**: prisijungę siuntėjai su šalimi, klientu, greičiais ir
  žodžiais išrašytomis ryšio vėliavėlėmis.
- **Sekikliai**: sekiklio būsena, jo praneštas skleidėjų ir siuntėjų
  skaičius ir kitas skelbimas. Dešiniu mygtuku galima pridėti, pašalinti
  ar paskelbti iš naujo.

Būsenos juosta rodo torentų skaičių, DHT mazgus, dabartinius greičius, ar
įjungtas IP filtras ir kiek perduota per seansą. Meniu **Rodymas**
slepia arba rodo informacijos skydelį, būsenos juostą ir konsolę.


## Torentų pridėjimas

- **Failas > Pridėti torentą** (Ctrl+O): pasirinkite vieną ar
  kelis `.torrent` failus.
- **Failas > Pridėti magnet saitą (-us)** (Ctrl+U): įklijuokite magnet
  nuorodas, po vieną eilutėje.
- Atverkite `.torrent` failą ar magnet nuorodą su `RePicoTorrent.exe`; jei
  programa iš to aplanko jau veikia, torentas perduodamas jai.

Prieš pridedant galima pasirinkti aplanką, norimus failus ir žymę. Kad
torentai būtų pridedami iškart su numatytaisiais nustatymais, įjunkite
**Nerodyti torento pridėjimo lango** nustatymuose.


## Torentų valdymas

Dešiniu mygtuku ant vieno ar kelių torentų:

- **Pratęsti**, **Pratęsti (priverstinai)** (nepaiso eilės), **Pristabdyti**.
- **Priverstinai apsiskelbti**, **Pakartotinai patikrinti** (patikrina duomenis
  diske).
- **Sekvencinis parsiuntimas**: dalys atsiunčiamos iš eilės, patogu žiūrėti
  vaizdo įrašą jam dar siunčiantis.
- **Etiketė**: priskirti žymę.
- **Export**: magnet nuoroda arba `.torrent` failas.
- **Perkelti**: perkelti duomenis į kitą aplanką.
- **Pašalinti**: pašalinti torentą (Del) arba torentą kartu su failais
  (Shift+Del).
- **Perkelti eilėje**: aukštyn ar žemyn atsiuntimų eilėje.
- **Kopijuoti informacijos santrauką**, **Atverti failų naršyklėje**.


## Žymės

Žymės grupuoja torentus. Jos kuriamos skiltyje
**Parametrai > Etiketės**:

- **Spalva**: žymės spalva; kai **Bendrieji** skiltyje įjungta
  **Naudoti spalvines etiketes kaip foną torrrent sąraše**, eilutės
  nuspalvinamos ja.
- **Paskirties vieta**: torentai su šia žyme įrašomi čia.
- **Naudoti filtrą**: reguliarioji išraiška; naujas torentas, kurio
  pavadinimas ją atitinka, gauna žymę automatiškai. Pavyzdys:
  `ubuntu|debian|fedora`.

**Rodymas > Etiketės** rodo tik vienos žymės torentus.


## Filtrai ir konsolė

Skiltyje **Rodymas > Filtras** yra išsaugoti filtrai, pavyzdžiui,
šiuo metu siunčiami torentai. **Rodymas > Konsolė** atveria
eilutę po sąrašu: įveskite užklausą ir paspauskite Enter, kad liktų tik
atitinkantys torentai; išvalykite ją, kad vėl matytumėte visus.

| Laukas | Tipas | Reikšmė |
|---|---|---|
| `name` | tekstas | torento pavadinimas |
| `label` | tekstas | žymės pavadinimas |
| `status` | tekstas | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | skaičius | užbaigtumo procentas |
| `size` | dydis | norimas dydis: `b` (numatytasis), `kb`, `mb`, `gb` |
| `dl`, `ul` | greitis | baitai per sekundę (numatytasis), `kbps`, `mbps`, `gbps` |

Operatoriai: `=`, `<`, `<=`, `>`, `>=` ir `~` (turi, neatsižvelgiant į
raidžių dydį), jungiami `and` ir `or`. Tekstas rašomas dvigubose
kabutėse, vienetai mažosiomis raidėmis.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torentų kūrimas

**Failas > Sukurti torent**:

![Sukurti torentą](images/en-US/create-torrent.png)

- Pasirinkite failą arba aplanką.
- **Režimas**: v1, v2 arba mišrus v1 + v2. Mišrus veikia su visais
  klientais ir yra numatytasis.
- **Komentaras** ir **Kūrėjas** neprivalomi.
- **Privatus**: siuntėjai gaunami tik iš sekiklių, ne iš DHT, PeX ar
  vietinės paieškos.
- **Pridėti į sesiją**: iškart pradėti skleisti naują torentą.
- **Sekikliai (vienas per eilutę)**: kiekvienas sekiklis patenka į savo lygį;
  lygiai bandomi iš eilės.
- **URL skleidėjai (vienas eilutėje)**: žiniatinklio serveriai su tais pačiais
  duomenimis. Aplankui adresas turi rodyti į aplanką, kuriame jis yra.


## Nustatymai

**Rodymas > Parametrai**. **Atkurti numatytus nustatymus** atkuria
visus nustatymus. Kai kuriems pakeitimams (kalba, tema, prievadai) reikia
paleisti iš naujo; programa tai pasiūlo.

### Bendrieji

![Bendri](images/en-US/preferences-general.png)

- **Kalba** ir **Theme** (sistemos arba šviesi; tamsi tema seka
  Windows nustatymą).
- **Nerodyti torento pridėjimo lango**, **Paleisti „RePicoTorrent“ kartu su „Windows“**, lango
  **Pradinė būsena**.
- **Rodyti „RePicoTorrent“ pranešimų srityje** ir ar lango sumažinimas ar
  uždarymas jį ten paslepia.

### Siuntiniai

![Atsiuntimai](images/en-US/preferences-downloads.png)

- **Paskirties vieta**, **Perkelti parsiųstus torentus** į kitą aplanką.
- **Sustabdyti kai mažėja diske vieta**.
- **Ribos**: atsiuntimo ir išsiuntimo ribos KB/s, kiek torentų gali
  būti aktyvūs vienu metu ir bendras ryšių skaičius.

### Etiketės

![Žymės](images/en-US/preferences-labels.png)

Žr. [Žymės](#žymės).

### Tinklas

![Ryšys](images/en-US/preferences-connection.png)

- **Tinklo sąsaja**: adresai ir prievadai įeinantiems ryšiams.
  `0.0.0.0` ir `[::]` reiškia visus IPv4 ir IPv6 adresus.
- **Šifravimas**: reikalauti įeinančių ar išeinančių ryšių šifravimo.
- **Privatumas**: DHT, vietinė siuntėjų paieška (LSD), siuntėjų mainai
  (PeX), WebTorrent ir siuntėjo šalies stulpelis. Šalių duomenų bazė
  (DB-IP Lite) atsiunčiama kartą per mėnesį, kol stulpelis įjungtas.
- **IP adresų filtras**: blokuoti adresus iš eMule formato filtro zip faile,
  pavyzdžiui, iš emule-security.org.

### Įgaliotasis serveris

![Įgaliotasis serveris](images/en-US/preferences-proxy.png)

HTTP arba SOCKS4/5 įgaliotasis serveris, su slaptažodžiu arba be jo, ir
kas per jį eina: vardų nustatymas, ryšiai su siuntėjais ir sekikliais.

### Kiti

![Išplėstiniai](images/en-US/preferences-advanced.png)

Visi libtorrent nustatymai. Pasirinkite vieną, kad po sąrašu
perskaitytumėte jo aprašą. Keiskite juos, tik jei žinote, ką jie daro;
**Atkurti numatytus nustatymus** juos atkurs.


## Perėjimas iš PicoTorrent ar qBittorrent

- **Failas > Import from PicoTorrent**: pasirinkite
  `PicoTorrent.sqlite` (šalia nešiojamo PicoTorrent arba aplanke
  `%LOCALAPPDATA%\PicoTorrent`). Pridedami torentai ir jų žymės; failas tik
  skaitomas. Norėdami perkelti viską, taip pat ir nustatymus, prieš
  pirmąjį paleidimą nukopijuokite `PicoTorrent.sqlite` šalia
  `RePicoTorrent.exe`: jis bus pervadintas į `RePicoTorrent.sqlite`.
- **Failas > Import from qBittorrent**: pasirinkite qBittorrent
  aplanką `BT_backup` (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Išsaugoma
  eiga, sekikliai, skaitikliai, aplankai ir komentarai.

Torentai, kurie jau yra sąraše, praleidžiami. Neskleiskite tų pačių
torentų iš abiejų klientų vienu metu.


## Atnaujinimai

Kaskart paleidžiama programa klausia GitHub apie naujausią leidimą, o
**Žinynas > Tikrinti ar nėra naujinimų** tai daro bet kada. Jei yra
naujesnė versija, **Download and install** atsisiunčia jūsų Windows zip,
patikrina jį leidimo SHA-256 kontrolinėmis sumomis, pakeičia programos
failus ir ją paleidžia iš naujo. Nustatymai ir torentai lieka.


## Spartieji klavišai

| Klavišai | Veiksmas |
|---|---|
| Ctrl+O | pridėti torentą |
| Ctrl+U | pridėti magnet nuorodas |
| Ctrl+A | pažymėti visus torentus |
| Del | pašalinti pažymėtus torentus, paliekant duomenis |
| Shift+Del | pašalinti pažymėtus torentus kartu su duomenimis |
| F1 | atverti šią dokumentaciją |


## Failai ir komandinė eilutė

Šalia `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: nustatymai, torentai ir jų tęsimo duomenys;
- `coredb.sqlite`: vertimai (programos dalis);
- `logs`: žurnalų failai;
- `Crashpad`: strigčių išklotinės, niekada nesiunčiamos;
- `dbip-country-lite.mmdb`: šalių duomenų bazė.

Komandinė eilutė:

```
RePicoTorrent.exe [--silent] [--save-path=<aplankas>] [file.torrent | magnet:?xt=...]...
```

`--silent` prideda nurodytus torentus be pridėjimo lango, `--save-path`
nurodo, kur juos įrašyti.
