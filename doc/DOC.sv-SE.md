# Dokumentation för RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · **Svenska** · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Kom igång](#kom-igång)
- [Huvudfönster](#huvudfönster)
- [Lägga till torrenter](#lägga-till-torrenter)
- [Hantera torrenter](#hantera-torrenter)
- [Etiketter](#etiketter)
- [Filter och konsolen](#filter-och-konsolen)
- [Skapa torrenter](#skapa-torrenter)
- [Inställningar](#inställningar)
- [Byta från PicoTorrent eller qBittorrent](#byta-från-picotorrent-eller-qbittorrent)
- [Uppdateringar](#uppdateringar)
- [Kortkommandon](#kortkommandon)
- [Filer och kommandorad](#filer-och-kommandorad)


## Kom igång

Ladda ner zip-filen för ditt Windows från
[versionssidan](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` för 64-bitars Windows, `arm64` för Windows på ARM, `x86` för
32-bitars Windows. Packa upp den i valfri mapp där du har skrivrätt och
starta `RePicoTorrent.exe`. Inget installeras: inställningar,
torrentlistan och loggar sparas bredvid exe-filen, så mappen kan flyttas
eller kopieras till ett USB-minne.

Varje mapp är en egen kopia av programmet. Två kopior i olika mappar kan
köras samtidigt om de använder olika portar.


## Huvudfönster

![Huvudfönster](images/en-US/main.png)

Överst finns torrentlistan. Varje kolumn sorteras genom att klicka på
rubriken; högerklicka på rubrikerna för att visa eller dölja kolumner.

- **Förlopp** och **Done**: hur mycket av önskade data som har
  laddats ner.
- **ETA**, **DL**, **UL**: återstående tid, nedladdnings- och
  uppladdningshastighet.
- **Tillgänglighet**: hur många fullständiga kopior de anslutna peers har
  tillsammans.
- **Uppladdare**, **Svärm**, **Leechers**: anslutna, och inom parentes
  antalet i hela svärmen enligt trackerna.

Nedtill visas detaljer om den valda torrenten:

- **Översikt**: namn, hashvärden (v1 och v2), storlek, sparmapp,
  kommentar och summor. Länkar i kommentaren öppnas i webbläsaren. Stapeln
  överst visar delarna: varje nedladdad del färgas där den ligger i
  torrenten. Delar hämtas inte i ordning (de ovanligaste först), så en
  pågående torrent har luckor.
- **Filer**: filer och mappar med förlopp. Högerklicka för att ange
  prioritet eller hoppa över en fil; dubbelklick öppnar en nedladdad fil.
- **Svärm**: anslutna peers med land, klient, hastigheter och
  anslutningsflaggor utskrivna i ord.
- **Trackers**: trackerns status, rapporterade seeders och leechers och
  nästa annonsering. Högerklicka för att lägga till, ta bort eller
  annonsera igen.

Statusfältet visar antal torrenter, DHT-noder, aktuella hastigheter, om
IP-filtret är på och hur mycket som har överförts under sessionen. Menyn
**Visa** döljer eller visar detaljpanelen, statusfältet och
konsolen.


## Lägga till torrenter

- **Arkiv > Lägg till torrent** (Ctrl+O): välj en eller flera
  `.torrent`-filer.
- **Arkiv > Lägg till magnetlänk(ar)** (Ctrl+U): klistra in
  magnetlänkar, en per rad.
- Öppna en `.torrent`-fil eller en magnetlänk med `RePicoTorrent.exe`; om
  programmet från den mappen redan körs skickas torrenten till det.

Innan torrenten läggs till kan du välja mapp, vilka filer som ska hämtas
och en etikett. För att lägga till torrenter direkt med
standardinställningarna, slå på **Skippa 'Lägg till torrent'-dialog** i
inställningarna.


## Hantera torrenter

Högerklicka på en eller flera torrenter:

- **Återuppta**, **Återuppta (tvinga)** (ignorerar kön), **Pausa**.
- **Tvinga nyannonsering**, **Tvinga återkontroll** (kontrollerar data på
  disken).
- **Sekventiell nedladdning**: hämta delar i ordning, praktiskt för att
  titta på en video medan den laddas ner.
- **Label**: tilldela en etikett.
- **Export**: magnetlänken eller `.torrent`-filen.
- **Flytta**: flytta data till en annan mapp.
- **Ta bort**: ta bort torrenten (Del) eller torrenten och dess filer
  (Skift+Del).
- **Köar**: upp eller ner i nedladdningskön.
- **Kopiera infohash**, **Öppna i Utforskaren**.


## Etiketter

Etiketter grupperar torrenter. De skapas i
**Inställningar > Labels**:

- **Color**: etikettens färg; med
  **Use label color as background in torrent list** (**Generellt**)
  färgas raderna med den.
- **Sökväg**: torrenter som läggs till med denna etikett sparas här.
- **Apply filter**: ett reguljärt uttryck; en ny torrent vars namn
  matchar får etiketten automatiskt. Exempel: `ubuntu|debian|fedora`.

**Visa > Labels** visar bara torrenterna med en etikett.


## Filter och konsolen

**Visa > Filter** innehåller sparade filter, till exempel
torrenterna som laddas ner just nu. **Visa > Console** öppnar
en rad under listan: skriv en fråga och tryck Enter för att bara visa
matchande torrenter; töm raden för att visa alla igen.

| Fält | Typ | Betydelse |
|---|---|---|
| `name` | text | torrentens namn |
| `label` | text | etikettens namn |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | tal | procent klart |
| `size` | storlek | önskad storlek: `b` (standard), `kb`, `mb`, `gb` |
| `dl`, `ul` | hastighet | byte per sekund (standard), `kbps`, `mbps`, `gbps` |

Operatorer: `=`, `<`, `<=`, `>`, `>=` och `~` (innehåller, skiftlägesokänsligt),
sammanfogade med `and` och `or`. Text skrivs inom dubbla citattecken,
enheter med gemener.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Skapa torrenter

**Arkiv > Create torrent**:

![Skapa torrent](images/en-US/create-torrent.png)

- Välj en fil eller en mapp.
- **Mode**: v1, v2 eller hybrid v1 + v2. Hybrid fungerar med alla
  klienter och är förvalt.
- **Kommentar** och **Creator** är valfria.
- **Privat**: peers kommer bara från trackerna, inte från DHT, PeX eller
  lokal upptäckt.
- **Add to session**: börja seeda den nya torrenten direkt.
- **Trackers (one per line)**: varje tracker hamnar i en egen nivå;
  nivåerna provas i tur och ordning.
- **URL seeds (one per line)**: webbservrar med samma data. För en mapp
  måste adressen peka på mappen som innehåller den.


## Inställningar

**Visa > Inställningar**. **Restore defaults** återställer
alla inställningar. Vissa ändringar (språk, tema, portar) kräver omstart;
programmet erbjuder det.

### Generellt

![Allmänt](images/en-US/preferences-general.png)

- **Språk** och **Theme** (system eller ljust; det mörka temat
  följer Windows-inställningen).
- **Skippa 'Lägg till torrent'-dialog**, **Starta RePicoTorrent med Windows**, fönstrets
  **Startposition**.
- **Visa RePicoTorrent i notifikationsområdet**, och om minimering eller
  stängning av fönstret gömmer det där.

### Nedladdningar

![Nedladdningar](images/en-US/preferences-downloads.png)

- **Sökväg**, **Flytta färdiga nedladdningar** till en annan mapp.
- **Pause when disk space is low**.
- **Begränsningar**: nedladdnings- och uppladdningsgräns i KB/s, hur många
  torrenter som får vara aktiva samtidigt och totalt antal anslutningar.

### Labels

![Etiketter](images/en-US/preferences-labels.png)

Se [Etiketter](#etiketter).

### Anslutning

![Anslutning](images/en-US/preferences-connection.png)

- **Nätverksadapter**: adresser och portar för inkommande
  anslutningar. `0.0.0.0` och `[::]` betyder alla IPv4- och IPv6-adresser.
- **Kryptering**: kräv kryptering för inkommande eller utgående
  anslutningar.
- **Sekretess**: DHT, lokal peer-upptäckt (LSD), peer-utbyte (PeX),
  WebTorrent och landskolumnen för peers. Landsdatabasen (DB-IP Lite)
  laddas ner en gång i månaden så länge kolumnen är på.
- **IP filter**: blockera adresser från ett filter i eMule-format i en
  zip-fil, till exempel från emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP- eller SOCKS4/5-proxy, med eller utan lösenord, och vad som går
genom den: namnuppslag, peer- och trackeranslutningar.

### Avancerat

![Avancerat](images/en-US/preferences-advanced.png)

Alla inställningar i libtorrent. Markera en för att läsa beskrivningen
under listan. Ändra dem bara om du vet vad de gör; **Restore defaults**
återställer dem.


## Byta från PicoTorrent eller qBittorrent

- **Arkiv > Import from PicoTorrent**: välj `PicoTorrent.sqlite`
  (bredvid en portabel PicoTorrent eller i `%LOCALAPPDATA%\PicoTorrent`).
  Torrenter och deras etiketter läggs till; filen läses bara. För att ta
  över allt, även inställningar, kopiera `PicoTorrent.sqlite` bredvid
  `RePicoTorrent.exe` före första starten: den byter namn till
  `RePicoTorrent.sqlite`.
- **Arkiv > Import from qBittorrent**: välj qBittorrents mapp
  `BT_backup` (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Förlopp, trackers,
  räknare, sparmappar och kommentarer behålls.

Torrenter som redan finns i listan hoppas över. Seeda inte samma
torrenter från båda klienterna samtidigt.


## Uppdateringar

Vid varje start frågar programmet GitHub efter den senaste versionen, och
**Hjälp > Sök efter ny version** gör det när som helst. Finns en
nyare version laddar **Download and install** ner zip-filen för ditt Windows,
kontrollerar den mot versionens SHA-256-kontrollsummor, ersätter
programfilerna och startar om. Inställningar och torrenter finns kvar.


## Kortkommandon

| Tangenter | Åtgärd |
|---|---|
| Ctrl+O | lägg till torrent |
| Ctrl+U | lägg till magnetlänkar |
| Ctrl+A | markera alla torrenter |
| Del | ta bort markerade torrenter, behåll data |
| Skift+Del | ta bort markerade torrenter och deras data |
| F1 | öppna denna dokumentation |


## Filer och kommandorad

Bredvid `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: inställningar, torrenter och deras återupptagningsdata;
- `coredb.sqlite`: översättningar (del av programmet);
- `logs`: loggfiler;
- `Crashpad`: kraschdumpar, laddas aldrig upp;
- `dbip-country-lite.mmdb`: landsdatabasen.

Kommandorad:

```
RePicoTorrent.exe [--silent] [--save-path=<mapp>] [file.torrent | magnet:?xt=...]...
```

`--silent` lägger till angivna torrenter utan dialogrutan, `--save-path`
anger var de sparas.
