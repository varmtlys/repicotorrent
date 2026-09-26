# RePicoTorrent dokumentáció

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · **Magyar** · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Első lépések](#első-lépések)
- [Főablak](#főablak)
- [Torrentek hozzáadása](#torrentek-hozzáadása)
- [Torrentek kezelése](#torrentek-kezelése)
- [Címkék](#címkék)
- [Szűrők és konzol](#szűrők-és-konzol)
- [Torrentek készítése](#torrentek-készítése)
- [Beállítások](#beállítások)
- [Áttérés PicoTorrentről vagy qBittorrentről](#áttérés-picotorrentről-vagy-qbittorrentről)
- [Frissítések](#frissítések)
- [Billentyűparancsok](#billentyűparancsok)
- [Fájlok és parancssor](#fájlok-és-parancssor)


## Első lépések

Töltse le a Windowsához illő zipet a
[kiadások oldaláról](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` 64 bites Windowshoz, `arm64` ARM-es Windowshoz, `x86` 32 bites
Windowshoz. Csomagolja ki bármely írható mappába, és indítsa el a
`RePicoTorrent.exe` fájlt. Semmi sem települ: a beállítások, a torrentlista
és a naplók az exe mellett vannak, így a mappa áthelyezhető vagy
pendrive-ra másolható.

Minden mappa a program külön példánya. Két példány különböző mappákból
egyszerre futhat, ha eltérő portot használnak.


## Főablak

![Főablak](images/en-US/main.png)

Felül van a torrentlista. Bármely oszlop a fejlécére kattintva
rendezhető; a fejlécekre jobb gombbal kattintva oszlopok jeleníthetők meg
vagy rejthetők el.

- **Folyamat** és **Done**: a kívánt adatokból mennyi töltődött
  le.
- **Hátralévő idő**, **Letöltés**, **Feltöltés**: hátralévő idő, letöltési és feltöltési
  sebesség.
- **Elérhetőség**: hány teljes másolattal rendelkeznek együtt a
  csatlakozott partnerek.
- **Seedek**, **Peerek**, **Leechers**: csatlakozott, zárójelben
  pedig a teljes rajban lévők száma a trackerek szerint.

Alul a kijelölt torrent részletei láthatók:

- **Áttekintés**: név, hash-ek (v1 és v2), méret, mentési hely, megjegyzés
  és összesítések. A megjegyzésben lévő hivatkozások a böngészőben nyílnak
  meg. A felső sáv a darabokat mutatja: minden letöltött darab ott van
  kiszínezve, ahol a torrentben elhelyezkedik. A darabok nem sorrendben
  érkeznek (a legritkábbak először), ezért egy folyamatban lévő torrentben
  hézagok vannak.
- **Fájlok**: fájlok és mappák a haladásukkal. Jobb gombbal prioritás
  állítható vagy fájl kihagyható; dupla kattintás megnyit egy letöltött
  fájlt.
- **Peerek**: csatlakozott partnerek országgal, klienssel, sebességekkel
  és szavakkal kiírt kapcsolatjelzőkkel.
- **Trackerek**: a tracker állapota, a jelentett seederek és leecherek
  és a következő bejelentés. Jobb gombbal hozzáadás, eltávolítás vagy
  újbóli bejelentés.

Az állapotsor a torrentek számát, a DHT-csomópontokat, az aktuális
sebességeket, az IP-szűrő állapotát és a munkamenetben átvitt mennyiséget
mutatja. A **Nézet** menü elrejti vagy megjeleníti a
részletpanelt, az állapotsort és a konzolt.


## Torrentek hozzáadása

- **Fájl > Torrent hozzáadás** (Ctrl+O): válasszon egy vagy több
  `.torrent` fájlt.
- **Fájl > Mágnes link hozzáadása** (Ctrl+U): illesszen be magnet
  hivatkozásokat, soronként egyet.
- Nyisson meg egy `.torrent` fájlt vagy magnet hivatkozást a
  `RePicoTorrent.exe` programmal; ha az adott mappából már fut a program, a
  torrent hozzá kerül.

Hozzáadás előtt kiválasztható a mappa, a kívánt fájlok és egy címke. Ha a
torrenteket azonnal, alapbeállításokkal szeretné hozzáadni, kapcsolja be a
**'Torrent hozzáadása' párbeszédablak kihagyása** beállítást.


## Torrentek kezelése

Jobb gombbal egy vagy több torrenten:

- **Folytatás**, **Kényszerített folytatás** (figyelmen kívül hagyja a sort),
  **Szünet**.
- **Kényszerített újrabejelentés**, **Kényszerített újraellenőrzés** (ellenőrzi az adatokat a
  lemezen).
- **Egymás utáni letöltés**: darabok letöltése sorrendben, hasznos, ha
  letöltés közben néz egy videót.
- **Label**: címke hozzárendelése.
- **Export**: magnet hivatkozás vagy `.torrent` fájl.
- **Áthelyezés**: az adatok áthelyezése másik mappába.
- **Eltávolítás**: a torrent eltávolítása (Del), vagy a torrent és fájljai
  (Shift+Del).
- **Várakozási sorban**: fel vagy le a letöltési sorban.
- **Hash infó másolása**, **Tárolómappa megnyitása**.


## Címkék

A címkék csoportosítják a torrenteket. Itt hozhatók létre:
**Beállítások > Labels**:

- **Color**: a címke színe; ha a **Általános** oldalon be van
  kapcsolva a **Use label color as background in torrent list**, a sorok
  ezzel a színnel jelennek meg.
- **Letöltési mappa**: az ezzel a címkével hozzáadott torrentek ide kerülnek.
- **Apply filter**: reguláris kifejezés; az új torrent, amelynek neve
  illeszkedik rá, automatikusan megkapja a címkét. Példa:
  `ubuntu|debian|fedora`.

A **Nézet > Labels** csak egy címke torrentjeit mutatja.


## Szűrők és konzol

A **Nézet > Szűrés** menüben mentett szűrők vannak, például az
éppen letöltődő torrentek. A **Nézet > Console** egy sort nyit
a lista alatt: írjon be egy lekérdezést és nyomjon Entert, hogy csak az
illeszkedő torrentek látsszanak; ürítse ki, hogy ismét mind látsszon.

| Mező | Típus | Jelentés |
|---|---|---|
| `name` | szöveg | a torrent neve |
| `label` | szöveg | a címke neve |
| `status` | szöveg | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | szám | készültség százalékban |
| `size` | méret | kívánt méret: `b` (alapértelmezett), `kb`, `mb`, `gb` |
| `dl`, `ul` | sebesség | bájt másodpercenként (alapértelmezett), `kbps`, `mbps`, `gbps` |

Operátorok: `=`, `<`, `<=`, `>`, `>=` és `~` (tartalmazza, kis- és
nagybetűtől függetlenül), `and` és `or` kapcsolja össze őket. A szöveg
dupla idézőjelbe kerül, a mértékegységek kisbetűvel írandók.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrentek készítése

**Fájl > Create torrent**:

![Torrent készítése](images/en-US/create-torrent.png)

- Válasszon egy fájlt vagy mappát.
- **Mode**: v1, v2 vagy v1 + v2 hibrid. A hibrid minden klienssel
  működik, és ez az alapértelmezett.
- A **Komment** és a **Creator** elhagyható.
- **Private**: a partnerek csak a trackerektől jönnek, nem DHT-ból,
  PeX-ből vagy helyi felderítésből.
- **Add to session**: az új torrent azonnali megosztása.
- **Trackers (one per line)**: minden tracker saját szintre kerül; a
  szinteket sorban próbálja.
- **URL seeds (one per line)**: ugyanazokat az adatokat tároló
  webszerverek. Mappánál az URL-nek az azt tartalmazó mappára kell
  mutatnia.


## Beállítások

**Nézet > Beállítások**. A **Restore defaults** minden
beállítást visszaállít. Egyes változások (nyelv, téma, portok)
újraindítást igényelnek; a program felajánlja.

### Általános

![Általános](images/en-US/preferences-general.png)

- **Nyelv** és **Theme** (rendszer vagy világos; a sötét téma a
  Windows beállítását követi).
- **'Torrent hozzáadása' párbeszédablak kihagyása**, **RePicoTorrent indítása a Windows-szal**, az ablak
  **Indítás módja** beállítása.
- **RePicoTorrent megjelenítése az értesítési területen**, és hogy a kis méret vagy a
  bezárás oda rejtse-e az ablakot.

### Letöltés

![Letöltések](images/en-US/preferences-downloads.png)

- **Letöltési mappa**, **Kész letöltések áthelyezése** másik mappába.
- **Szüneteltetés kevés lemezterület esetén**.
- **Korlátok**: letöltési és feltöltési korlát KB/s-ban, egyszerre hány
  torrent lehet aktív és a kapcsolatok teljes száma.

### Labels

![Címkék](images/en-US/preferences-labels.png)

Lásd: [Címkék](#címkék).

### Hálózat

![Kapcsolat](images/en-US/preferences-connection.png)

- **Interfész figyelése**: címek és portok a bejövő kapcsolatokhoz.
  A `0.0.0.0` és a `[::]` az összes IPv4- és IPv6-címet jelenti.
- **Titkosítás**: titkosítás megkövetelése a bejövő vagy kimenő
  kapcsolatoknál.
- **Adatvédelem**: DHT, helyi partnerfelderítés (LSD), partnercsere (PeX),
  WebTorrent és a partnerek országoszlopa. Az országadatbázis (DB-IP Lite)
  havonta egyszer töltődik le, amíg az oszlop be van kapcsolva.
- **IP filter**: címek tiltása egy zip-fájlban lévő eMule formátumú
  szűrőből, például az emule-security.org oldalról.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP- vagy SOCKS4/5-proxy, jelszóval vagy anélkül, és hogy mi megy rajta
keresztül: névfeloldás, partner- és trackerkapcsolatok.

### Haladó

![Speciális](images/en-US/preferences-advanced.png)

Az összes libtorrent-beállítás. Válasszon ki egyet, hogy a lista alatt
elolvassa a leírását. Csak akkor módosítsa őket, ha tudja, mit csinálnak;
a **Restore defaults** visszaállítja őket.


## Áttérés PicoTorrentről vagy qBittorrentről

- **Fájl > Import from PicoTorrent**: válassza ki a
  `PicoTorrent.sqlite` fájlt (egy hordozható PicoTorrent mellett vagy a
  `%LOCALAPPDATA%\PicoTorrent` mappában). A torrentek és címkéik
  hozzáadódnak; a fájlt csak olvassa. Ha mindent, a beállításokat is át
  szeretné venni, másolja a `PicoTorrent.sqlite` fájlt a
  `RePicoTorrent.exe` mellé az első indítás előtt: átnevezi
  `RePicoTorrent.sqlite` névre.
- **Fájl > Import from qBittorrent**: válassza ki a qBittorrent
  `BT_backup` mappáját (`%LOCALAPPDATA%\qBittorrent\BT_backup`). A haladás,
  a trackerek, a számlálók, a mappák és a megjegyzések megmaradnak.

A már listán lévő torrenteket kihagyja. Ne ossza meg ugyanazokat a
torrenteket egyszerre mindkét kliensből.


## Frissítések

A program minden indításkor megkérdezi a GitHubot a legújabb kiadásról,
a **Segítség > Frissítések keresése** pedig bármikor. Ha van újabb
verzió, a **Download and install** letölti a Windowsához illő zipet,
ellenőrzi a kiadás SHA-256 ellenőrzőösszegeivel, lecseréli a program
fájljait és újraindítja. A beállítások és a torrentek megmaradnak.


## Billentyűparancsok

| Billentyűk | Művelet |
|---|---|
| Ctrl+O | torrent hozzáadása |
| Ctrl+U | magnet hivatkozások hozzáadása |
| Ctrl+A | az összes torrent kijelölése |
| Del | a kijelölt torrentek eltávolítása, az adatok megtartásával |
| Shift+Del | a kijelölt torrentek eltávolítása az adataikkal együtt |
| F1 | ennek a dokumentációnak a megnyitása |


## Fájlok és parancssor

A `RePicoTorrent.exe` mellett:

- `RePicoTorrent.sqlite`: beállítások, torrentek és folytatási adataik;
- `coredb.sqlite`: fordítások (a program része);
- `logs`: naplófájlok;
- `Crashpad`: összeomlási memóriaképek, soha nem töltődnek fel;
- `dbip-country-lite.mmdb`: az országadatbázis.

Parancssor:

```
RePicoTorrent.exe [--silent] [--save-path=<mappa>] [file.torrent | magnet:?xt=...]...
```

A `--silent` a megadott torrenteket a hozzáadási ablak nélkül adja hozzá,
a `--save-path` megadja, hová mentse őket.
