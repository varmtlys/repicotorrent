# RePicoTorrent dokumentācija

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · **Latviešu** · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Darba sākšana](#darba-sākšana)
- [Galvenais logs](#galvenais-logs)
- [Torrentu pievienošana](#torrentu-pievienošana)
- [Torrentu pārvaldība](#torrentu-pārvaldība)
- [Etiķetes](#etiķetes)
- [Filtri un konsole](#filtri-un-konsole)
- [Torrentu izveide](#torrentu-izveide)
- [Iestatījumi](#iestatījumi)
- [Pāreja no PicoTorrent vai qBittorrent](#pāreja-no-picotorrent-vai-qbittorrent)
- [Atjauninājumi](#atjauninājumi)
- [Īsinājumtaustiņi](#īsinājumtaustiņi)
- [Faili un komandrinda](#faili-un-komandrinda)


## Darba sākšana

Lejupielādējiet savai Windows piemēroto zip no
[laidienu lapas](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` 64 bitu Windows, `arm64` Windows uz ARM, `x86` 32 bitu Windows.
Atarhivējiet to jebkurā mapē, kurā varat rakstīt, un palaidiet
`RePicoTorrent.exe`. Nekas netiek instalēts: iestatījumi, torrentu saraksts
un žurnāli glabājas blakus exe, tāpēc mapi var pārvietot vai nokopēt uz
USB zibatmiņu.

Katra mape ir atsevišķa programmas kopija. Divas kopijas no dažādām mapēm
var darboties vienlaikus, ja tās izmanto dažādus portus.


## Galvenais logs

![Galvenais logs](images/en-US/main.png)

Augšā ir torrentu saraksts. Katru kolonnu kārto, noklikšķinot uz tās
virsraksta; ar labo klikšķi uz virsrakstiem kolonnas var parādīt vai
paslēpt.

- **Progress** un **Done**: cik no vēlamajiem datiem ir
  lejupielādēts.
- **Atl. laiks**, **DL**, **UL**: atlikušais laiks, lejupielādes un
  augšupielādes ātrums.
- **Availability**: cik pilnu kopiju kopā ir savienotajiem vienādrangu
  dalībniekiem.
- **Seeds**, **Iesaistītie**, **Leechers**: savienotie, un iekavās skaits
  visā spietā pēc trekeru datiem.

Apakšā ir izvēlētā torrenta informācija:

- **Pārskats**: nosaukums, jaucējvērtības (v1 un v2), izmērs, mape,
  komentārs un kopsummas. Saites komentārā atveras pārlūkā. Josla augšā
  rāda daļas: katra lejupielādētā daļa ir iekrāsota tur, kur tā atrodas
  torrentā. Daļas pienāk nekārtīgi (vispirms retākās), tāpēc nepabeigtam
  torrentam ir robi.
- **Faili**: faili un mapes ar progresu. Ar labo klikšķi var iestatīt
  prioritāti vai izlaist failu; dubultklikšķis atver lejupielādētu failu.
- **Iesaistītie**: savienotie dalībnieki ar valsti, klientu, ātrumiem un
  vārdos izrakstītiem savienojuma karodziņiem.
- **Trakeri**: trekera stāvoklis, tā ziņotie devēji un ņēmēji un
  nākamā paziņošana. Ar labo klikšķi var pievienot, noņemt vai paziņot
  atkārtoti.

Statusa joslā redzams torrentu skaits, DHT mezgli, pašreizējie ātrumi, vai
IP filtrs ir ieslēgts un cik pārsūtīts šajā sesijā. Izvēlnē
**Skatīt** var paslēpt vai parādīt informācijas paneli, statusa joslu
un konsoli.


## Torrentu pievienošana

- **Fails > Pievienot torrentu** (Ctrl+O): izvēlieties vienu vai
  vairākus `.torrent` failus.
- **Fails > Add magnet link(s)** (Ctrl+U): ielīmējiet magnet
  saites, pa vienai rindā.
- Atveriet `.torrent` failu vai magnet saiti ar `RePicoTorrent.exe`; ja
  programma no šīs mapes jau darbojas, torrents tiek nodots tai.

Pirms pievienošanas var izvēlēties mapi, vajadzīgos failus un etiķeti.
Lai torrenti tiktu pievienoti uzreiz ar noklusējuma iestatījumiem,
ieslēdziet **Skip 'Add torrent' dialog** iestatījumos.


## Torrentu pārvaldība

Ar labo klikšķi uz viena vai vairākiem torrentiem:

- **Sākt**, **Sākt (piespiedu)** (neņem vērā rindu), **Pauze**.
- **Force reannounce**, **Force recheck** (pārbauda datus diskā).
- **Secīga lejupielāde**: daļas lejupielādē pēc kārtas, ērti, lai
  skatītos video lejupielādes laikā.
- **Label**: piešķirt etiķeti.
- **Export**: magnet saite vai `.torrent` fails.
- **Pārvietot**: pārvietot datus uz citu mapi.
- **Noņemt**: noņemt torrentu (Del) vai torrentu kopā ar failiem
  (Shift+Del).
- **Queuing**: uz augšu vai uz leju lejupielādes rindā.
- **Kopēt info hash**, **Atvērt failu pārlukā**.


## Etiķetes

Etiķetes grupē torrentus. Tās veido sadaļā
**Iestatījumi > Labels**:

- **Color**: etiķetes krāsa; ja sadaļā **Vispārīgi** ir ieslēgts
  **Use label color as background in torrent list**, rindas tiek
  iekrāsotas ar to.
- **Mape**: torrenti ar šo etiķeti tiek saglabāti šeit.
- **Apply filter**: regulārā izteiksme; jauns torrents, kura nosaukums
  tai atbilst, saņem šo etiķeti automātiski. Piemērs:
  `ubuntu|debian|fedora`.

**Skatīt > Labels** rāda tikai vienas etiķetes torrentus.


## Filtri un konsole

Sadaļā **Skatīt > Filter** ir saglabāti filtri, piemēram,
torrenti, kas tieši tagad lejupielādējas. **Skatīt > Console**
atver rindu zem saraksta: ierakstiet vaicājumu un nospiediet Enter, lai
paliktu tikai atbilstošie torrenti; notīriet rindu, lai atkal redzētu
visus.

| Lauks | Tips | Nozīme |
|---|---|---|
| `name` | teksts | torrenta nosaukums |
| `label` | teksts | etiķetes nosaukums |
| `status` | teksts | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | skaitlis | pabeigtības procents |
| `size` | izmērs | vēlamais izmērs: `b` (noklusējums), `kb`, `mb`, `gb` |
| `dl`, `ul` | ātrums | baiti sekundē (noklusējums), `kbps`, `mbps`, `gbps` |

Operatori: `=`, `<`, `<=`, `>`, `>=` un `~` (satur, reģistrnejutīgi),
savienoti ar `and` un `or`. Tekstu raksta dubultpēdiņās, mērvienības ar
mazajiem burtiem.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrentu izveide

**Fails > Create torrent**:

![Izveidot torrentu](images/en-US/create-torrent.png)

- Izvēlieties failu vai mapi.
- **Mode**: v1, v2 vai hibrīds v1 + v2. Hibrīds darbojas ar visiem
  klientiem un ir noklusējums.
- **Comment** un **Creator** nav obligāti.
- **Private**: dalībnieki nāk tikai no trekeriem, nevis no DHT, PeX vai
  lokālās meklēšanas.
- **Add to session**: uzreiz sākt dalīt jauno torrentu.
- **Trackers (one per line)**: katrs trekeris nonāk savā līmenī;
  līmeņus mēģina pēc kārtas.
- **URL seeds (one per line)**: tīmekļa serveri ar tiem pašiem datiem.
  Mapei adresei jānorāda uz mapi, kas to satur.


## Iestatījumi

**Skatīt > Iestatījumi**. **Restore defaults** atiestata
visus iestatījumus. Dažas izmaiņas (valoda, tēma, porti) prasa
restartēšanu; programma to piedāvā.

### Vispārīgi

![Vispārīgi](images/en-US/preferences-general.png)

- **Valoda** un **Theme** (sistēmas vai gaiša; tumšā tēma seko
  Windows iestatījumam).
- **Skip 'Add torrent' dialog**, **Start RePicoTorrent with Windows**, loga
  **Start position**.
- **Show RePicoTorrent in notification area** un vai loga minimizēšana vai
  aizvēršana to tur paslēpj.

### Lejupielādes

![Lejupielādes](images/en-US/preferences-downloads.png)

- **Mape**, **Move completed downloads** uz citu mapi.
- **Pause when disk space is low**.
- **Limiti**: lejupielādes un augšupielādes ierobežojumi KB/s, cik
  torrentu var būt aktīvi vienlaikus un kopējais savienojumu skaits.

### Labels

![Etiķetes](images/en-US/preferences-labels.png)

Skatiet [Etiķetes](#etiķetes).

### Savienojums

![Savienojums](images/en-US/preferences-connection.png)

- **Klausīšanās interfeiss**: adreses un porti ienākošajiem savienojumiem.
  `0.0.0.0` un `[::]` nozīmē visas IPv4 un IPv6 adreses.
- **Encryption**: pieprasīt ienākošo vai izejošo savienojumu šifrēšanu.
- **Privacy**: DHT, lokālā dalībnieku meklēšana (LSD), dalībnieku
  apmaiņa (PeX), WebTorrent un dalībnieka valsts kolonna. Valstu datubāze
  (DB-IP Lite) tiek lejupielādēta reizi mēnesī, kamēr kolonna ir ieslēgta.
- **IP filter**: bloķēt adreses no eMule formāta filtra zip failā,
  piemēram, no emule-security.org.

### Starpniekserveris

![Starpniekserveris](images/en-US/preferences-proxy.png)

HTTP vai SOCKS4/5 starpniekserveris, ar paroli vai bez tās, un kas caur to
iet: nosaukumu atrisināšana, savienojumi ar dalībniekiem un trekeriem.

### Papildus

![Papildu](images/en-US/preferences-advanced.png)

Visi libtorrent iestatījumi. Izvēlieties vienu, lai zem saraksta izlasītu
tā aprakstu. Mainiet tos tikai tad, ja zināt, ko tie dara;
**Restore defaults** tos atjaunos.


## Pāreja no PicoTorrent vai qBittorrent

- **Fails > Import from PicoTorrent**: izvēlieties
  `PicoTorrent.sqlite` (blakus pārnēsājamam PicoTorrent vai mapē
  `%LOCALAPPDATA%\PicoTorrent`). Tiek pievienoti torrenti un to etiķetes;
  fails tiek tikai lasīts. Lai pārņemtu visu, arī iestatījumus,
  nokopējiet `PicoTorrent.sqlite` blakus `RePicoTorrent.exe` pirms pirmās
  palaišanas: tas tiks pārdēvēts par `RePicoTorrent.sqlite`.
- **Fails > Import from qBittorrent**: izvēlieties qBittorrent
  mapi `BT_backup` (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Tiek saglabāts
  progress, trekeri, skaitītāji, mapes un komentāri.

Torrenti, kas jau ir sarakstā, tiek izlaisti. Nedaliet tos pašus
torrentus no abiem klientiem vienlaikus.


## Atjauninājumi

Katrā palaišanas reizē programma vaicā GitHub par jaunāko laidienu, un
**Palīdzība > Pārbaudīt atjauninājumus** to dara jebkurā brīdī. Ja ir
jaunāka versija, **Download and install** lejupielādē jūsu Windows zip,
pārbauda to ar laidiena SHA-256 kontrolsummām, aizstāj programmas failus
un to restartē. Iestatījumi un torrenti paliek.


## Īsinājumtaustiņi

| Taustiņi | Darbība |
|---|---|
| Ctrl+O | pievienot torrentu |
| Ctrl+U | pievienot magnet saites |
| Ctrl+A | atlasīt visus torrentus |
| Del | noņemt atlasītos torrentus, datus paturot |
| Shift+Del | noņemt atlasītos torrentus kopā ar datiem |
| F1 | atvērt šo dokumentāciju |


## Faili un komandrinda

Blakus `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: iestatījumi, torrenti un to atsākšanas dati;
- `coredb.sqlite`: tulkojumi (programmas daļa);
- `logs`: žurnālfaili;
- `Crashpad`: avāriju izmeti, nekad netiek nosūtīti;
- `dbip-country-lite.mmdb`: valstu datubāze.

Komandrinda:

```
RePicoTorrent.exe [--silent] [--save-path=<mape>] [file.torrent | magnet:?xt=...]...
```

`--silent` pievieno norādītos torrentus bez pievienošanas loga,
`--save-path` nosaka, kur tos saglabāt.
