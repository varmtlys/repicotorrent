# Dokumentasjon for RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · **Norsk bokmål** · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Kom i gang](#kom-i-gang)
- [Hovedvindu](#hovedvindu)
- [Legge til torrenter](#legge-til-torrenter)
- [Behandle torrenter](#behandle-torrenter)
- [Etiketter](#etiketter)
- [Filtre og konsollen](#filtre-og-konsollen)
- [Lage torrenter](#lage-torrenter)
- [Innstillinger](#innstillinger)
- [Bytte fra PicoTorrent eller qBittorrent](#bytte-fra-picotorrent-eller-qbittorrent)
- [Oppdateringer](#oppdateringer)
- [Hurtigtaster](#hurtigtaster)
- [Filer og kommandolinje](#filer-og-kommandolinje)


## Kom i gang

Last ned zip-filen for din Windows fra
[utgivelsessiden](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` for 64-biters Windows, `arm64` for Windows på ARM, `x86` for 32-biters
Windows. Pakk den ut i en hvilken som helst mappe du kan skrive til, og
start `RePicoTorrent.exe`. Ingenting installeres: innstillinger,
torrentlisten og logger ligger ved siden av exe-filen, så mappen kan
flyttes eller kopieres til en minnepinne.

Hver mappe er en egen kopi av programmet. To kopier i forskjellige mapper
kan kjøre samtidig hvis de bruker forskjellige porter.


## Hovedvindu

![Hovedvindu](images/en-US/main.png)

Øverst er torrentlisten. Hver kolonne sorteres ved å klikke på
overskriften; høyreklikk på overskriftene for å vise eller skjule
kolonner.

- **Framdrift** og **Done**: hvor mye av ønskede data som er lastet
  ned.
- **Forventet**, **Ned**, **Opp**: gjenstående tid, nedlastings- og
  opplastingshastighet.
- **Tilgjengelighet**: hvor mange fullstendige kopier de tilkoblede peerne
  har til sammen.
- **Delere**, **Likemenn**, **Leechers**: tilkoblet, og i parentes
  antallet i hele svermen ifølge trackerne.

Nederst vises detaljene for valgt torrent:

- **Oversikt**: navn, hasher (v1 og v2), størrelse, lagringsmappe,
  kommentar og summer. Lenker i kommentaren åpnes i nettleseren. Linjen
  øverst viser bitene: hver nedlastet bit er farget der den ligger i
  torrenten. Biter hentes ikke i rekkefølge (de sjeldneste først), så en
  pågående torrent har hull.
- **Filer**: filer og mapper med fremdrift. Høyreklikk for å sette
  prioritet eller hoppe over en fil; dobbeltklikk åpner en nedlastet fil.
- **Likemenn**: tilkoblede peers med land, klient, hastigheter og
  tilkoblingsflagg skrevet ut i ord.
- **Sporere**: trackerstatus, rapporterte seedere og leechere og neste
  kunngjøring. Høyreklikk for å legge til, fjerne eller kunngjøre på nytt.

Statuslinjen viser antall torrenter, DHT-noder, gjeldende hastigheter, om
IP-filteret er på og hvor mye som er overført i økten. Menyen
**Vis** skjuler eller viser detaljpanelet, statuslinjen og
konsollen.


## Legge til torrenter

- **Fil > Legg til torrent** (Ctrl+O): velg én eller flere
  `.torrent`-filer.
- **Fil > Legg til magnetlenke(r)** (Ctrl+U): lim inn
  magnetlenker, én per linje.
- Åpne en `.torrent`-fil eller en magnetlenke med `RePicoTorrent.exe`; hvis
  programmet fra den mappen allerede kjører, sendes torrenten til det.

Før torrenten legges til, kan du velge mappe, hvilke filer som skal
lastes ned og en etikett. For å legge til torrenter straks med
standardinnstillingene, slå på **Hopp over «Legg til torrent»-oppsprett** i
innstillingene.


## Behandle torrenter

Høyreklikk på én eller flere torrenter:

- **Fortsett**, **Fortsett (påtving)** (ignorerer køen), **Pause**.
- **Påtving omannonsering**, **Påtving omsjekk** (kontrollerer dataene på
  disken).
- **Sekvensiell nedlasting**: hent biter i rekkefølge, nyttig for å se en
  video mens den lastes ned.
- **Etikett**: tildele en etikett.
- **Export**: magnetlenken eller `.torrent`-filen.
- **Flytt**: flytte dataene til en annen mappe.
- **Fjern**: fjerne torrenten (Del) eller torrenten og filene
  (Shift+Del).
- **Legger i kø**: opp eller ned i nedlastingskøen.
- **Kopier infosjekksum**, **Åpne i filutforsker**.


## Etiketter

Etiketter grupperer torrenter. De opprettes i
**Innstillinger > Etiketter**:

- **Farge**: etikettens farge; med
  **Bruk etikettfarge som bakgrunn i torrent-liste** (**Generelt**)
  farges radene med den.
- **Lagringsmappe**: torrenter som legges til med denne etiketten, lagres
  her.
- **Bruk filter**: et regulært uttrykk; en ny torrent med et navn som
  passer, får etiketten automatisk. Eksempel: `ubuntu|debian|fedora`.

**Vis > Etiketter** viser bare torrentene med én etikett.


## Filtre og konsollen

**Vis > Filtrer** har lagrede filtre, for eksempel
torrentene som lastes ned akkurat nå. **Vis > Konsoll**
åpner en linje under listen: skriv en spørring og trykk Enter for å vise
bare torrenter som passer; tøm linjen for å vise alle igjen.

| Felt | Type | Betydning |
|---|---|---|
| `name` | tekst | torrentens navn |
| `label` | tekst | etikettens navn |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | tall | prosent ferdig |
| `size` | størrelse | ønsket størrelse: `b` (standard), `kb`, `mb`, `gb` |
| `dl`, `ul` | hastighet | byte per sekund (standard), `kbps`, `mbps`, `gbps` |

Operatorer: `=`, `<`, `<=`, `>`, `>=` og `~` (inneholder, uten hensyn til
store og små bokstaver), bundet sammen med `and` og `or`. Tekst skrives i
doble anførselstegn, enheter med små bokstaver.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Lage torrenter

**Fil > Opprett torrent**:

![Lag torrent](images/en-US/create-torrent.png)

- Velg en fil eller en mappe.
- **Modus**: v1, v2 eller hybrid v1 + v2. Hybrid fungerer med alle
  klienter og er standard.
- **Kommentar** og **Skaper** er valgfrie.
- **Privat**: peers kommer bare fra trackerne, ikke fra DHT, PeX eller
  lokal oppdagelse.
- **Legg til økt**: begynn å seede den nye torrenten straks.
- **Sporere (én per linje)**: hver tracker havner i sitt eget nivå;
  nivåene prøves etter tur.
- **Nettadresse-delere (én per linje)**: webservere med de samme dataene. For en
  mappe må adressen peke på mappen som inneholder den.


## Innstillinger

**Vis > Innstillinger**. **Gjenopprett forvalg** tilbakestiller
alle innstillinger. Noen endringer (språk, tema, porter) krever omstart;
programmet tilbyr det.

### Generelt

![Generelt](images/en-US/preferences-general.png)

- **Språk** og **Theme** (system eller lyst; det mørke temaet
  følger Windows-innstillingen).
- **Hopp over «Legg til torrent»-oppsprett**, **Start RePicoTorrent med Windows**, vinduets
  **Startposisjon**.
- **Vis RePicoTorrent i merknadsområde**, og om minimering eller
  lukking av vinduet skjuler det der.

### Nedlastinger

![Nedlastinger](images/en-US/preferences-downloads.png)

- **Lagringsmappe**, **Flytt fullførte nedlastinger** til en annen mappe.
- **Sett på pause ved liten diskplass**.
- **Begrensninger**: grenser for nedlasting og opplasting i KB/s, hvor mange
  torrenter som kan være aktive samtidig og totalt antall tilkoblinger.

### Etiketter

![Etiketter](images/en-US/preferences-labels.png)

Se [Etiketter](#etiketter).

### Tilkobling

![Tilkobling](images/en-US/preferences-connection.png)

- **Lyttegrensesnitt**: adresser og porter for innkommende
  tilkoblinger. `0.0.0.0` og `[::]` betyr alle IPv4- og IPv6-adresser.
- **Kryptering**: krev kryptering for innkommende eller utgående
  tilkoblinger.
- **Personvern**: DHT, lokal peer-oppdagelse (LSD), peer-utveksling (PeX),
  WebTorrent og landkolonnen for peers. Landdatabasen (DB-IP Lite) lastes
  ned én gang i måneden så lenge kolonnen er på.
- **IP-filter**: blokker adresser fra et filter i eMule-format i en
  zip-fil, for eksempel fra emule-security.org.

### Mellomtjener

![Proxy](images/en-US/preferences-proxy.png)

HTTP- eller SOCKS4/5-proxy, med eller uten passord, og hva som går
gjennom den: navneoppslag, peer- og trackertilkoblinger.

### Avansert

![Avansert](images/en-US/preferences-advanced.png)

Alle innstillinger i libtorrent. Velg én for å lese beskrivelsen under
listen. Endre dem bare hvis du vet hva de gjør; **Gjenopprett forvalg**
tilbakestiller dem.


## Bytte fra PicoTorrent eller qBittorrent

- **Fil > Import from PicoTorrent**: velg `PicoTorrent.sqlite`
  (ved siden av en bærbar PicoTorrent eller i `%LOCALAPPDATA%\PicoTorrent`).
  Torrenter og etikettene deres legges til; filen blir bare lest. For å ta
  over alt, også innstillinger, kopier `PicoTorrent.sqlite` ved siden av
  `RePicoTorrent.exe` før første oppstart: den får nytt navn,
  `RePicoTorrent.sqlite`.
- **Fil > Import from qBittorrent**: velg mappen `BT_backup` til
  qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Fremdrift, trackere,
  tellere, lagringsmapper og kommentarer beholdes.

Torrenter som allerede er i listen, hoppes over. Ikke seed de samme
torrentene fra begge klientene samtidig.


## Oppdateringer

Ved hver oppstart spør programmet GitHub om den nyeste utgivelsen, og
**Hjelp > Se etter oppdateringer** gjør det når som helst. Finnes en
nyere versjon, laster **Download and install** ned zip-filen for din Windows,
kontrollerer den mot utgivelsens SHA-256-sjekksummer, erstatter
programfilene og starter på nytt. Innstillinger og torrenter blir
værende.


## Hurtigtaster

| Taster | Handling |
|---|---|
| Ctrl+O | legg til torrent |
| Ctrl+U | legg til magnetlenker |
| Ctrl+A | merk alle torrenter |
| Del | fjern valgte torrenter, behold dataene |
| Shift+Del | fjern valgte torrenter og dataene deres |
| F1 | åpne denne dokumentasjonen |


## Filer og kommandolinje

Ved siden av `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: innstillinger, torrenter og gjenopptakingsdata;
- `coredb.sqlite`: oversettelser (del av programmet);
- `logs`: loggfiler;
- `Crashpad`: krasjdumper, lastes aldri opp;
- `dbip-country-lite.mmdb`: landdatabasen.

Kommandolinje:

```
RePicoTorrent.exe [--silent] [--save-path=<mappe>] [file.torrent | magnet:?xt=...]...
```

`--silent` legger til de angitte torrentene uten dialogvinduet,
`--save-path` angir hvor de lagres.
