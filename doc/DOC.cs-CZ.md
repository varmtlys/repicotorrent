# Dokumentace RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · **Čeština** · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Začínáme](#začínáme)
- [Hlavní okno](#hlavní-okno)
- [Přidávání torrentů](#přidávání-torrentů)
- [Správa torrentů](#správa-torrentů)
- [Štítky](#štítky)
- [Filtry a konzole](#filtry-a-konzole)
- [Vytváření torrentů](#vytváření-torrentů)
- [Nastavení](#nastavení)
- [Přechod z PicoTorrent nebo qBittorrent](#přechod-z-picotorrent-nebo-qbittorrent)
- [Aktualizace](#aktualizace)
- [Klávesové zkratky](#klávesové-zkratky)
- [Soubory a příkazový řádek](#soubory-a-příkazový-řádek)


## Začínáme

Stáhněte zip pro svůj Windows ze
[stránky vydání](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` pro 64bitová Windows, `arm64` pro Windows na ARM, `x86` pro 32bitová
Windows. Rozbalte ho do libovolné složky, kam můžete zapisovat, a spusťte
`RePicoTorrent.exe`. Nic se neinstaluje: nastavení, seznam torrentů a logy
jsou uloženy vedle exe, takže složku lze přesunout nebo zkopírovat na
USB disk.

Každá složka je samostatná kopie programu. Dvě kopie v různých složkách
mohou běžet současně, pokud používají různé porty.


## Hlavní okno

![Hlavní okno](images/en-US/main.png)

Nahoře je seznam torrentů. Každý sloupec se řadí kliknutím na jeho
záhlaví; pravým kliknutím na záhlaví sloupce zobrazíte nebo skryjete.

- **Průběh** a **Done**: kolik z požadovaných dat je staženo.
- **Zbývající čas**, **Rychlost stahování**, **Rychlost odesílání**: zbývající čas, rychlost stahování a
  odesílání.
- **Dostupnost**: kolik úplných kopií mají připojení peeři dohromady.
- **Odesílající**, **Peeři**, **Leechers**: připojení a v závorce počet
  v celém roji podle trackerů.

Dole jsou podrobnosti o vybraném torrentu:

- **Přehled**: název, hashe (v1 a v2), velikost, složka, komentář a
  součty. Odkazy v komentáři se otevírají v prohlížeči. Pruh nahoře
  ukazuje části: každá stažená část je vybarvena tam, kde v torrentu leží.
  Části se stahují mimo pořadí (nejvzácnější první), proto má nedokončený
  torrent mezery.
- **Soubory**: soubory a složky s průběhem. Pravým kliknutím nastavíte
  prioritu nebo soubor přeskočíte; dvojklik otevře stažený soubor.
- **Peeři**: připojení peeři se zemí, klientem, rychlostmi a příznaky
  spojení vypsanými slovy.
- **Trackery**: stav trackeru, hlášené seedy a leechery a příští
  ohlášení. Pravým kliknutím přidáte, odeberete nebo znovu ohlásíte.

Stavový řádek ukazuje počet torrentů, uzlů DHT, aktuální rychlosti, zda je
zapnutý IP filtr a kolik bylo přeneseno v této relaci. Nabídka
**Zobrazit** skrývá nebo zobrazuje panel podrobností, stavový řádek a
konzoli.


## Přidávání torrentů

- **Soubor > Přidat torrent** (Ctrl+O): vyberte jeden nebo více
  souborů `.torrent`.
- **Soubor > Přidat magnet(y)** (Ctrl+U): vložte magnet
  odkazy, jeden na řádek.
- Otevřete soubor `.torrent` nebo magnet odkaz pomocí `RePicoTorrent.exe`;
  pokud program z této složky už běží, torrent se mu předá.

Před přidáním můžete vybrat složku, požadované soubory a štítek. Chcete-li
torrenty přidávat hned s výchozím nastavením, zapněte
**Přeskočit 'Přidat torrent' dialog** v nastavení.


## Správa torrentů

Pravým kliknutím na jeden nebo více torrentů:

- **Obnovit**, **Obnovit (vynuceně)** (ignoruje frontu), **Pauza**.
- **Vynucená reannounce**, **Vynucená kontrola** (ověří data na disku).
- **Postupné stahování**: stahovat části popořadě, užitečné pro
  sledování videa během stahování.
- **Štítek**: přiřadit štítek.
- **Export**: magnet odkaz nebo soubor `.torrent`.
- **Přesunout**: přesunout data do jiné složky.
- **Odebrat**: odebrat torrent (Del) nebo torrent i se soubory
  (Shift+Del).
- **Čekání ve frontě**: posunout nahoru nebo dolů ve frontě stahování.
- **Kopírovat hash s informacemi**, **Otevřít v Průzkumníku**.


## Štítky

Štítky seskupují torrenty. Vytvářejí se v
**Nastavení > Štítky**:

- **Barva**: barva štítku; se zapnutým
  **Použijte barvu štítku jako pozadí v seznamu torrentů** (**Obecné**) se
  jí obarví řádky.
- **Uložit cestu**: torrenty s tímto štítkem se ukládají sem.
- **Použít filtr**: regulární výraz; nový torrent, jehož název mu
  odpovídá, dostane tento štítek automaticky. Příklad:
  `ubuntu|debian|fedora`.

**Zobrazit > Štítky** zobrazí jen torrenty s jedním štítkem.


## Filtry a konzole

V **Zobrazit > Filtr** jsou uložené filtry, například torrenty,
které se právě stahují. **Zobrazit > Konzole** otevře řádek pod
seznamem: napište dotaz a stiskněte Enter, aby zůstaly jen odpovídající
torrenty; vymažte ho, aby se znovu zobrazily všechny.

| Pole | Typ | Význam |
|---|---|---|
| `name` | text | název torrentu |
| `label` | text | název štítku |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | číslo | procento dokončení |
| `size` | velikost | požadovaná velikost: `b` (výchozí), `kb`, `mb`, `gb` |
| `dl`, `ul` | rychlost | bajty za sekundu (výchozí), `kbps`, `mbps`, `gbps` |

Operátory: `=`, `<`, `<=`, `>`, `>=` a `~` (obsahuje, bez ohledu na
velikost písmen), spojené pomocí `and` a `or`. Text se píše do dvojitých
uvozovek, jednotky malými písmeny.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Vytváření torrentů

**Soubor > Vytvořit torrent**:

![Vytvořit torrent](images/en-US/create-torrent.png)

- Vyberte soubor nebo složku.
- **Mód**: v1, v2 nebo hybrid v1 + v2. Hybrid funguje s každým
  klientem a je výchozí.
- **Komentovat** a **Autor** jsou nepovinné.
- **Soukromé**: peeři přicházejí jen z trackerů, ne z DHT, PeX ani
  místního vyhledávání.
- **Přidat k relaci**: nový torrent hned začít sdílet.
- **Trackery (každý řádek jeden)**: každý tracker jde do vlastní úrovně;
  úrovně se zkoušejí popořadě.
- **URL odesílajících (každý řádek jeden)**: webové servery se stejnými daty. U
  složky musí adresa ukazovat na složku, která ji obsahuje.


## Nastavení

**Zobrazit > Nastavení**. **Obnovit výchozí** obnoví
všechna nastavení. Některé změny (jazyk, motiv, porty) vyžadují restart;
program ho nabídne.

### Obecné

![Obecné](images/en-US/preferences-general.png)

- **Jazyk** a **Theme** (systémový nebo světlý; tmavý motiv se
  řídí nastavením Windows).
- **Přeskočit 'Přidat torrent' dialog**, **Spustit RePicoTorrent s Windows**,
  **Startovací pozice** okna.
- **Zobrazit RePicoTorrent v panelu nástrojů** a zda minimalizace nebo
  zavření okna ho tam schová.

### Stažené

![Stahování](images/en-US/preferences-downloads.png)

- **Uložit cestu**, **Přesunout dokončené stahování** do jiné složky.
- **Pozastavit pokud dochází místo na disku**.
- **Limity**: limity stahování a odesílání v KB/s, kolik torrentů smí
  být aktivních současně a celkový počet spojení.

### Štítky

![Štítky](images/en-US/preferences-labels.png)

Viz [Štítky](#štítky).

### Spojení

![Připojení](images/en-US/preferences-connection.png)

- **Rozhraní pro naslouchání**: adresy a porty pro příchozí spojení. `0.0.0.0`
  a `[::]` znamenají všechny adresy IPv4 a IPv6.
- **Šifrování**: vyžadovat šifrování příchozích nebo odchozích
  spojení.
- **Soukromí**: DHT, místní vyhledávání peerů (LSD), výměna peerů (PeX),
  WebTorrent a sloupec se zemí peera. Databáze zemí (DB-IP Lite) se
  stahuje jednou měsíčně, dokud je sloupec zapnutý.
- **Filtr IP**: blokovat adresy z filtru ve formátu eMule v souboru
  zip, například z emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP nebo SOCKS4/5 proxy, s heslem nebo bez, a co přes ni jde: překlad
názvů, spojení s peery a trackery.

### Rozšířené

![Pokročilé](images/en-US/preferences-advanced.png)

Všechna nastavení libtorrent. Vyberte jedno a pod seznamem si přečtete
jeho popis. Měňte je, jen pokud víte, co dělají; **Obnovit výchozí**
je vrátí.


## Přechod z PicoTorrent nebo qBittorrent

- **Soubor > Import from PicoTorrent**: vyberte `PicoTorrent.sqlite`
  (vedle přenosného PicoTorrent nebo v `%LOCALAPPDATA%\PicoTorrent`).
  Přidají se torrenty a jejich štítky; soubor se jen čte. Chcete-li
  převzít vše včetně nastavení, zkopírujte `PicoTorrent.sqlite` vedle
  `RePicoTorrent.exe` před prvním spuštěním: přejmenuje se na
  `RePicoTorrent.sqlite`.
- **Soubor > Import from qBittorrent**: vyberte složku `BT_backup`
  qBittorrentu (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Zachová se průběh,
  trackery, počítadla, složky a komentáře.

Torrenty, které už v seznamu jsou, se přeskočí. Nesdílejte stejné torrenty
z obou klientů zároveň.


## Aktualizace

Při každém spuštění se program zeptá GitHubu na nejnovější vydání a
**Pomoc > Zkontrolovat aktualizace** to udělá kdykoli. Je-li k
dispozici novější verze, **Download and install** stáhne zip pro váš Windows,
ověří ho kontrolními součty SHA-256 z vydání, nahradí soubory programu a
restartuje ho. Nastavení a torrenty zůstanou.


## Klávesové zkratky

| Klávesy | Akce |
|---|---|
| Ctrl+O | přidat torrent |
| Ctrl+U | přidat magnet odkazy |
| Ctrl+A | vybrat všechny torrenty |
| Del | odebrat vybrané torrenty, ponechat data |
| Shift+Del | odebrat vybrané torrenty i s daty |
| F1 | otevřít tuto dokumentaci |


## Soubory a příkazový řádek

Vedle `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: nastavení, torrenty a data pro jejich obnovení;
- `coredb.sqlite`: překlady (součást programu);
- `logs`: soubory logů;
- `Crashpad`: výpisy pádů, nikdy se neodesílají;
- `dbip-country-lite.mmdb`: databáze zemí.

Příkazový řádek:

```
RePicoTorrent.exe [--silent] [--save-path=<složka>] [file.torrent | magnet:?xt=...]...
```

`--silent` přidá zadané torrenty bez okna přidání, `--save-path` určuje,
kam se uloží.
