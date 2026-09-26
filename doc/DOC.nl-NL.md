# Documentatie van RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · **Nederlands** · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Aan de slag](#aan-de-slag)
- [Hoofdvenster](#hoofdvenster)
- [Torrents toevoegen](#torrents-toevoegen)
- [Torrents beheren](#torrents-beheren)
- [Labels](#labels)
- [Filters en de console](#filters-en-de-console)
- [Torrents maken](#torrents-maken)
- [Voorkeuren](#voorkeuren)
- [Overstappen van PicoTorrent of qBittorrent](#overstappen-van-picotorrent-of-qbittorrent)
- [Updates](#updates)
- [Sneltoetsen](#sneltoetsen)
- [Bestanden en opdrachtregel](#bestanden-en-opdrachtregel)


## Aan de slag

Download de zip voor uw Windows van de
[releasepagina](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` voor 64-bits Windows, `arm64` voor Windows op ARM, `x86` voor 32-bits
Windows. Pak hem uit in een map waar u mag schrijven en start
`RePicoTorrent.exe`. Er wordt niets geïnstalleerd: instellingen, de
torrentlijst en logbestanden staan naast de exe, dus de map kan worden
verplaatst of naar een USB-stick gekopieerd.

Elke map is een aparte kopie van het programma. Twee kopieën in
verschillende mappen kunnen tegelijk draaien als ze verschillende poorten
gebruiken.


## Hoofdvenster

![Hoofdvenster](images/en-US/main.png)

Bovenaan staat de torrentlijst. Elke kolom sorteert u door op de kop te
klikken; met een rechtsklik op de koppen toont of verbergt u kolommen.

- **Voortgang** en **Done**: hoeveel van de gewenste gegevens is
  gedownload.
- **ETA**, **DL**, **UL**: resterende tijd, download- en
  uploadsnelheid.
- **Beschikbaarheid**: hoeveel volledige kopieën de verbonden peers samen
  hebben.
- **Seeds**, **Peers**, **Leechers**: verbonden, en tussen haakjes
  het aantal in de hele zwerm volgens de trackers.

Onderaan staan de details van de geselecteerde torrent:

- **Overzicht**: naam, info-hashes (v1 en v2), grootte, opslagmap,
  opmerking en totalen. Links in de opmerking openen in de browser. De
  balk bovenaan toont de stukken: elk gedownload stuk is gekleurd op de
  plek waar het in de torrent ligt. Stukken komen niet op volgorde binnen
  (zeldzaamste eerst), dus een torrent in uitvoering heeft gaten.
- **Bestanden**: bestanden en mappen met hun voortgang. Rechtsklik om een
  prioriteit in te stellen of een bestand over te slaan; dubbelklik opent
  een gedownload bestand.
- **Peers**: verbonden peers met land, client, snelheden en
  verbindingsvlaggen in woorden.
- **Trackers**: trackerstatus, gemelde seeds en leechers en de volgende
  aankondiging. Rechtsklik om toe te voegen, te verwijderen of opnieuw aan
  te kondigen.

De statusbalk toont het aantal torrents, DHT-knooppunten, de huidige
snelheden, of het IP-filter aan staat en hoeveel er deze sessie is
overgedragen. Via **Beeld** verbergt of toont u het detailpaneel,
de statusbalk en de console.


## Torrents toevoegen

- **Bestand > Torrent toevoegen** (Ctrl+O): kies een of meer
  `.torrent`-bestanden.
- **Bestand > Magnet link(s) toevoegen** (Ctrl+U): plak magnetlinks,
  één per regel.
- Open een `.torrent`-bestand of magnetlink met `RePicoTorrent.exe`; draait
  het programma uit die map al, dan krijgt het de torrent doorgegeven.

Voor het toevoegen kunt u de map, de gewenste bestanden en een label
kiezen. Om torrents meteen met de standaardinstellingen toe te voegen,
zet u **'Torrent toevoegen' overslaan** aan in de voorkeuren.


## Torrents beheren

Rechtsklik op een of meer torrents:

- **Hervatten**, **Hervatten (forceren)** (negeert de wachtrij), **Pauzeren**.
- **Forceer opnieuw aankondigen**, **Forceer opnieuw controleren** (controleert de gegevens op
  schijf).
- **Opeenvolgend downloaden**: stukken op volgorde downloaden, handig om een
  video te kijken terwijl hij binnenkomt.
- **Label**: een label toekennen.
- **Exporteren**: de magnetlink of het `.torrent`-bestand.
- **Verplaatsen**: de gegevens naar een andere map verplaatsen.
- **Verwijderen**: de torrent verwijderen (Del) of de torrent met zijn
  bestanden (Shift+Del).
- **Wachtrij**: omhoog of omlaag in de downloadwachtrij.
- **Info-hash kopiëren**, **Open in Verkenner**.


## Labels

Labels groeperen torrents. U maakt ze aan in
**Instellingen > Labels**:

- **Kleur**: de kleur van het label; met
  **Gebruik labelkleur als achtergrond in de torrent-lijst** (**Algemeen**)
  krijgen de regels die kleur.
- **Opslagpad**: torrents met dit label worden hier opgeslagen.
- **Filter toepassen**: een reguliere expressie; een nieuwe torrent waarvan
  de naam overeenkomt, krijgt dit label automatisch. Voorbeeld:
  `ubuntu|debian|fedora`.

**Beeld > Labels** toont alleen de torrents met één label.


## Filters en de console

**Beeld > Filter** bevat opgeslagen filters, bijvoorbeeld de
torrents die nu aan het downloaden zijn. **Beeld > Console**
opent een regel onder de lijst: typ een zoekopdracht en druk op Enter om
alleen passende torrents te tonen; maak hem leeg om weer alles te tonen.

| Veld | Type | Betekenis |
|---|---|---|
| `name` | tekst | naam van de torrent |
| `label` | tekst | naam van het label |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | getal | procent klaar |
| `size` | grootte | gewenste grootte: `b` (standaard), `kb`, `mb`, `gb` |
| `dl`, `ul` | snelheid | bytes per seconde (standaard), `kbps`, `mbps`, `gbps` |

Operatoren: `=`, `<`, `<=`, `>`, `>=` en `~` (bevat, hoofdletterongevoelig),
verbonden met `and` en `or`. Tekst staat tussen dubbele aanhalingstekens,
eenheden worden in kleine letters geschreven.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrents maken

**Bestand > Torrent aanmaken**:

![Torrent maken](images/en-US/create-torrent.png)

- Kies een bestand of een map.
- **Modus**: v1, v2 of hybride v1 + v2. Hybride werkt met elke client en
  is de standaard.
- **Opmerking** en **Maker** zijn optioneel.
- **Privé**: peers komen alleen van de trackers, niet via DHT, PeX of
  lokale ontdekking.
- **Toevoegen aan sessie**: de nieuwe torrent meteen seeden.
- **Trackers (een per regel)**: elke tracker komt in een eigen laag; de
  lagen worden op volgorde geprobeerd.
- **URL-seeds (een per regel)**: webservers met dezelfde gegevens. Voor
  een map moet de URL wijzen naar de map die hem bevat.


## Voorkeuren

**Beeld > Instellingen**. **Standaardwaarden herstellen** zet alle
instellingen terug. Sommige wijzigingen (taal, thema, poorten) vereisen een
herstart; het programma biedt die aan.

### Algemeen

![Algemeen](images/en-US/preferences-general.png)

- **Taal** en **Theme** (systeem of licht; het donkere thema
  volgt de instelling van Windows).
- **'Torrent toevoegen' overslaan**, **RePicoTorrent automatisch starten met Windows**,
  **Startpositie** van het venster.
- **RePicoTorrent in systeemvak weergeven**, en of minimaliseren of
  sluiten het venster daarheen verplaatst.

### Downloads

![Downloads](images/en-US/preferences-downloads.png)

- **Opslagpad**, **Voltooide downloads verplaatsen** naar een andere map.
- **Pauzeren bij onvoldoende schijfruimte**.
- **Begrenzingen**: download- en uploadlimiet in KB/s, hoeveel torrents
  tegelijk actief mogen zijn en het totale aantal verbindingen.

### Labels

![Labels](images/en-US/preferences-labels.png)

Zie [Labels](#labels).

### Verbinding

![Verbinding](images/en-US/preferences-connection.png)

- **Luister-interface**: adressen en poorten voor inkomende verbindingen.
  `0.0.0.0` en `[::]` betekenen alle IPv4- en IPv6-adressen.
- **Encryptie**: versleuteling eisen voor inkomende of uitgaande
  verbindingen.
- **Privacy**: DHT, lokale peerontdekking (LSD), peeruitwisseling (PeX),
  WebTorrent en de landkolom van peers. De landendatabase (DB-IP Lite)
  wordt eens per maand gedownload zolang de kolom aan staat.
- **IP-filter**: adressen blokkeren uit een filter in eMule-formaat in
  een zip, bijvoorbeeld van emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP- of SOCKS4/5-proxy, met of zonder wachtwoord, en wat erdoorheen gaat:
naamopzoekingen, peer- en trackerverbindingen.

### Geavanceerd

![Geavanceerd](images/en-US/preferences-advanced.png)

Alle instellingen van libtorrent. Selecteer er een om de beschrijving
onder de lijst te lezen. Wijzig ze alleen als u weet wat ze doen;
**Standaardwaarden herstellen** zet ze terug.


## Overstappen van PicoTorrent of qBittorrent

- **Bestand > Import from PicoTorrent**: kies `PicoTorrent.sqlite`
  (naast een draagbare PicoTorrent of in `%LOCALAPPDATA%\PicoTorrent`).
  Torrents en hun labels worden toegevoegd; het bestand wordt alleen
  gelezen. Om alles over te nemen, inclusief instellingen, kopieert u
  `PicoTorrent.sqlite` vóór de eerste start naast `RePicoTorrent.exe`: het
  wordt hernoemd naar `RePicoTorrent.sqlite`.
- **Bestand > Import from qBittorrent**: kies de map `BT_backup` van
  qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Voortgang, trackers,
  tellers, opslagmappen en opmerkingen blijven behouden.

Torrents die al in de lijst staan, worden overgeslagen. Seed dezelfde
torrents niet tegelijk vanuit beide clients.


## Updates

Bij elke start vraagt het programma GitHub naar de nieuwste release, en
**Help > Controleer op update's** doet dat op elk moment. Is er een
nieuwere versie, dan downloadt **Download and install** de zip voor uw Windows,
controleert hem met de SHA-256-controlesommen van de release, vervangt de
programmabestanden en herstart. Instellingen en torrents blijven.


## Sneltoetsen

| Toetsen | Actie |
|---|---|
| Ctrl+O | torrent toevoegen |
| Ctrl+U | magnetlinks toevoegen |
| Ctrl+A | alle torrents selecteren |
| Del | geselecteerde torrents verwijderen, gegevens houden |
| Shift+Del | geselecteerde torrents met hun gegevens verwijderen |
| F1 | deze documentatie openen |


## Bestanden en opdrachtregel

Naast `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: instellingen, torrents en hun hervattingsgegevens;
- `coredb.sqlite`: vertalingen (onderdeel van het programma);
- `logs`: logbestanden;
- `Crashpad`: crashdumps, worden nooit geüpload;
- `dbip-country-lite.mmdb`: de landendatabase.

Opdrachtregel:

```
RePicoTorrent.exe [--silent] [--save-path=<map>] [file.torrent | magnet:?xt=...]...
```

`--silent` voegt de opgegeven torrents toe zonder het toevoegvenster,
`--save-path` bepaalt waar ze worden opgeslagen.
