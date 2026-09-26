# Dokumentácia RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · **Slovenčina** · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Začíname](#začíname)
- [Hlavné okno](#hlavné-okno)
- [Pridávanie torrentov](#pridávanie-torrentov)
- [Správa torrentov](#správa-torrentov)
- [Štítky](#štítky)
- [Filtre a konzola](#filtre-a-konzola)
- [Vytváranie torrentov](#vytváranie-torrentov)
- [Nastavenia](#nastavenia)
- [Prechod z PicoTorrent alebo qBittorrent](#prechod-z-picotorrent-alebo-qbittorrent)
- [Aktualizácie](#aktualizácie)
- [Klávesové skratky](#klávesové-skratky)
- [Súbory a príkazový riadok](#súbory-a-príkazový-riadok)


## Začíname

Stiahnite si zip pre svoj Windows zo
[stránky vydaní](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` pre 64-bitový Windows, `arm64` pre Windows na ARM, `x86` pre 32-bitový
Windows. Rozbaľte ho do ľubovoľného priečinka s právom zápisu a spustite
`RePicoTorrent.exe`. Nič sa neinštaluje: nastavenia, zoznam torrentov a
logy sú uložené vedľa exe, takže priečinok sa dá presunúť alebo skopírovať
na USB kľúč.

Každý priečinok je samostatná kópia programu. Dve kópie v rôznych
priečinkoch môžu bežať súčasne, ak používajú rôzne porty.


## Hlavné okno

![Hlavné okno](images/en-US/main.png)

Hore je zoznam torrentov. Každý stĺpec sa triedi kliknutím na jeho
hlavičku; pravým kliknutím na hlavičky stĺpce zobrazíte alebo skryjete.

- **Priebeh** a **Done**: koľko z požadovaných dát je stiahnuté.
- **Odhad. čas**, **Stiahnuté**, **Nahraté**: zostávajúci čas, rýchlosť sťahovania a
  odosielania.
- **Dostupnosť**: koľko úplných kópií majú pripojení peeri spolu.
- **Seedov**, **Rovesníci**, **Leechers**: pripojení a v zátvorke počet
  v celom roji podľa trackerov.

Dole sú podrobnosti o vybranom torrente:

- **Prehľad**: názov, hashe (v1 a v2), veľkosť, priečinok, komentár a
  súčty. Odkazy v komentári sa otvárajú v prehliadači. Pruh hore ukazuje
  časti: každá stiahnutá časť je vyfarbená tam, kde v torrente leží. Časti
  sa sťahujú mimo poradia (najvzácnejšie prvé), preto má nedokončený
  torrent medzery.
- **Súbory**: súbory a priečinky s priebehom. Pravým kliknutím nastavíte
  prioritu alebo súbor preskočíte; dvojklik otvorí stiahnutý súbor.
- **Rovesníci**: pripojení peeri s krajinou, klientom, rýchlosťami a
  príznakmi spojenia vypísanými slovami.
- **Trackery**: stav trackera, hlásené seedy a leechery a ďalšie
  ohlásenie. Pravým kliknutím pridáte, odstránite alebo znova ohlásite.

Stavový riadok ukazuje počet torrentov, uzlov DHT, aktuálne rýchlosti, či
je zapnutý IP filter a koľko sa prenieslo v tejto relácii. Ponuka
**Zobraziť** skrýva alebo zobrazuje panel podrobností, stavový riadok a
konzolu.


## Pridávanie torrentov

- **Súbor > Pridať torrent** (Ctrl+O): vyberte jeden alebo viac
  súborov `.torrent`.
- **Súbor > Pridať magnet link(y)** (Ctrl+U): vložte magnet
  odkazy, jeden na riadok.
- Otvorte súbor `.torrent` alebo magnet odkaz pomocou `RePicoTorrent.exe`;
  ak program z tohto priečinka už beží, torrent sa mu odovzdá.

Pred pridaním môžete vybrať priečinok, požadované súbory a štítok. Ak
chcete torrenty pridávať hneď s predvolenými nastaveniami, zapnite
**Preskočiť dialóg "Pridať torrent"** v nastaveniach.


## Správa torrentov

Pravým kliknutím na jeden alebo viac torrentov:

- **Pokračovať**, **Vynútiť pokračovanie** (ignoruje frontu), **Pozastaviť**.
- **Vynútiť znovuohlásenie**, **Vynútiť opätovnú kontrolu** (overí dáta na disku).
- **Postupné sťahovanie**: sťahovať časti po poradí, užitočné na
  pozeranie videa počas sťahovania.
- **Štítok**: priradiť štítok.
- **Exportovať**: magnet odkaz alebo súbor `.torrent`.
- **Presunúť**: presunúť dáta do iného priečinka.
- **Odstrániť**: odstrániť torrent (Del) alebo torrent aj so súbormi
  (Shift+Del).
- **Čakanie vo fronte**: posunúť hore alebo dole vo fronte sťahovania.
- **Kopírovať hash s informáciami**, **Otvoriť cieľový priečinok**.


## Štítky

Štítky zoskupujú torrenty. Vytvárajú sa v
**Nastavenia > Štítky**:

- **Farba**: farba štítka; so zapnutým
  **Použite farbu štítku ako pozadie v zozname torrentov** (**Všeobecné**) sa
  ňou zafarbia riadky.
- **Cieľový priečinok**: torrenty s týmto štítkom sa ukladajú sem.
- **Použiť filter**: regulárny výraz; nový torrent, ktorého názov mu
  zodpovedá, dostane tento štítok automaticky. Príklad:
  `ubuntu|debian|fedora`.

**Zobraziť > Štítky** zobrazí len torrenty s jedným štítkom.


## Filtre a konzola

V **Zobraziť > Filter** sú uložené filtre, napríklad torrenty,
ktoré sa práve sťahujú. **Zobraziť > Konzola** otvorí riadok pod
zoznamom: napíšte dopyt a stlačte Enter, aby zostali len zodpovedajúce
torrenty; vymažte ho, aby sa znova zobrazili všetky.

| Pole | Typ | Význam |
|---|---|---|
| `name` | text | názov torrentu |
| `label` | text | názov štítka |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | číslo | percento dokončenia |
| `size` | veľkosť | požadovaná veľkosť: `b` (predvolené), `kb`, `mb`, `gb` |
| `dl`, `ul` | rýchlosť | bajty za sekundu (predvolené), `kbps`, `mbps`, `gbps` |

Operátory: `=`, `<`, `<=`, `>`, `>=` a `~` (obsahuje, bez ohľadu na veľkosť
písmen), spojené cez `and` a `or`. Text sa píše do dvojitých úvodzoviek,
jednotky malými písmenami.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Vytváranie torrentov

**Súbor > Vytvoriť torrent**:

![Vytvoriť torrent](images/en-US/create-torrent.png)

- Vyberte súbor alebo priečinok.
- **Mód**: v1, v2 alebo hybrid v1 + v2. Hybrid funguje s každým
  klientom a je predvolený.
- **Komentár** a **Autor** sú nepovinné.
- **Súkromné**: peeri prichádzajú len z trackerov, nie z DHT, PeX ani
  miestneho vyhľadávania.
- **Pridať do relácie**: nový torrent hneď začať zdieľať.
- **Trackery (jeden na riadok)**: každý tracker ide do vlastnej úrovne;
  úrovne sa skúšajú po poradí.
- **URL odosielajúcich (jeden na riadok)**: webové servery s rovnakými dátami. Pri
  priečinku musí adresa ukazovať na priečinok, ktorý ho obsahuje.


## Nastavenia

**Zobraziť > Nastavenia**. **obnoviť pôvodné** obnoví
všetky nastavenia. Niektoré zmeny (jazyk, motív, porty) vyžadujú reštart;
program ho ponúkne.

### Všeobecné

![Všeobecné](images/en-US/preferences-general.png)

- **Jazyk** a **Theme** (systémový alebo svetlý; tmavý motív sa
  riadi nastavením Windows).
- **Preskočiť dialóg "Pridať torrent"**, **Spustiť RePicoTorrent pri štarte Windows**,
  **Štartovacia pozícia** okna.
- **Zobraziť RePicoTorrent v oznamovacej oblasti** a či minimalizovanie alebo
  zatvorenie okna ho tam schová.

### Stiahnuté

![Sťahovanie](images/en-US/preferences-downloads.png)

- **Cieľový priečinok**, **Presunúť dokončené sťahovania** do iného priečinka.
- **Pozastaviť keď je málo miesta na disku**.
- **Limity**: limity sťahovania a odosielania v KB/s, koľko torrentov
  môže byť aktívnych súčasne a celkový počet spojení.

### Štítky

![Štítky](images/en-US/preferences-labels.png)

Pozri [Štítky](#štítky).

### Pripojenie

![Pripojenie](images/en-US/preferences-connection.png)

- **Načúvacie rozhranie**: adresy a porty pre prichádzajúce spojenia.
  `0.0.0.0` a `[::]` znamenajú všetky adresy IPv4 a IPv6.
- **Šifrovanie**: vyžadovať šifrovanie prichádzajúcich alebo
  odchádzajúcich spojení.
- **Súkromie**: DHT, miestne vyhľadávanie peerov (LSD), výmena peerov
  (PeX), WebTorrent a stĺpec s krajinou peera. Databáza krajín (DB-IP Lite)
  sa sťahuje raz mesačne, kým je stĺpec zapnutý.
- **IP filter**: blokovať adresy z filtra vo formáte eMule v súbore zip,
  napríklad z emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP alebo SOCKS4/5 proxy, s heslom alebo bez, a čo cez ňu ide: preklad
názvov, spojenia s peermi a trackermi.

### Rozšírené

![Rozšírené](images/en-US/preferences-advanced.png)

Všetky nastavenia libtorrent. Vyberte jedno a pod zoznamom si prečítate
jeho popis. Meňte ich, len ak viete, čo robia; **obnoviť pôvodné** ich
vráti.


## Prechod z PicoTorrent alebo qBittorrent

- **Súbor > Import from PicoTorrent**: vyberte `PicoTorrent.sqlite`
  (vedľa prenosného PicoTorrent alebo v `%LOCALAPPDATA%\PicoTorrent`).
  Pridajú sa torrenty a ich štítky; súbor sa len číta. Ak chcete prevziať
  všetko vrátane nastavení, skopírujte `PicoTorrent.sqlite` vedľa
  `RePicoTorrent.exe` pred prvým spustením: premenuje sa na
  `RePicoTorrent.sqlite`.
- **Súbor > Import from qBittorrent**: vyberte priečinok
  `BT_backup` qBittorrentu (`%LOCALAPPDATA%\qBittorrent\BT_backup`).
  Zachová sa priebeh, trackery, počítadlá, priečinky a komentáre.

Torrenty, ktoré už v zozname sú, sa preskočia. Nezdieľajte rovnaké
torrenty z oboch klientov naraz.


## Aktualizácie

Pri každom spustení sa program opýta GitHubu na najnovšie vydanie a
**Pomoc > Skontrolovať aktualizácie** to urobí kedykoľvek. Ak je k
dispozícii novšia verzia, **Download and install** stiahne zip pre váš
Windows, overí ho kontrolnými súčtami SHA-256 z vydania, nahradí súbory
programu a reštartuje ho. Nastavenia a torrenty zostanú.


## Klávesové skratky

| Klávesy | Akcia |
|---|---|
| Ctrl+O | pridať torrent |
| Ctrl+U | pridať magnet odkazy |
| Ctrl+A | vybrať všetky torrenty |
| Del | odstrániť vybrané torrenty, ponechať dáta |
| Shift+Del | odstrániť vybrané torrenty aj s dátami |
| F1 | otvoriť túto dokumentáciu |


## Súbory a príkazový riadok

Vedľa `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: nastavenia, torrenty a dáta na ich obnovenie;
- `coredb.sqlite`: preklady (súčasť programu);
- `logs`: súbory logov;
- `Crashpad`: výpisy pádov, nikdy sa neodosielajú;
- `dbip-country-lite.mmdb`: databáza krajín.

Príkazový riadok:

```
RePicoTorrent.exe [--silent] [--save-path=<priečinok>] [file.torrent | magnet:?xt=...]...
```

`--silent` pridá zadané torrenty bez okna pridania, `--save-path` určuje,
kam sa uložia.
