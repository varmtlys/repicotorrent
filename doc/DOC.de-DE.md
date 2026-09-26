# RePicoTorrent-Dokumentation

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · **Deutsch** · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Erste Schritte](#erste-schritte)
- [Hauptfenster](#hauptfenster)
- [Torrents hinzufügen](#torrents-hinzufügen)
- [Torrents verwalten](#torrents-verwalten)
- [Labels](#labels)
- [Filter und Konsole](#filter-und-konsole)
- [Torrents erstellen](#torrents-erstellen)
- [Einstellungen](#einstellungen)
- [Umstieg von PicoTorrent oder qBittorrent](#umstieg-von-picotorrent-oder-qbittorrent)
- [Updates](#updates)
- [Tastenkürzel](#tastenkürzel)
- [Dateien und Befehlszeile](#dateien-und-befehlszeile)


## Erste Schritte

Laden Sie das Zip für Ihr Windows von der
[Release-Seite](https://github.com/varmtlys/repicotorrent/releases/latest)
herunter: `x64` für 64-Bit-Windows, `arm64` für Windows auf ARM, `x86` für
32-Bit-Windows. Entpacken Sie es in einen beliebigen Ordner mit
Schreibrechten und starten Sie `RePicoTorrent.exe`. Es wird nichts
installiert: Einstellungen, Torrent-Liste und Protokolle liegen neben der
exe, der Ordner kann also verschoben oder auf einen USB-Stick kopiert
werden.

Jeder Ordner ist eine eigene Kopie des Programms. Zwei Kopien in
verschiedenen Ordnern können gleichzeitig laufen, wenn sie verschiedene
Ports verwenden.


## Hauptfenster

![Hauptfenster](images/en-US/main.png)

Oben steht die Torrent-Liste. Jede Spalte wird per Klick auf ihre
Überschrift sortiert; ein Rechtsklick auf die Überschriften blendet Spalten
ein oder aus.

- **Fortschritt** und **Done**: wie viel der gewünschten Daten
  heruntergeladen ist.
- **Verbleibende Zeit**, **DL**, **UL**: Restzeit, Download- und Upload-Rate.
- **Verfügbarkeit**: wie viele vollständige Kopien die verbundenen Peers
  zusammen haben.
- **Seeder**, **Peers**, **Leechers**: verbunden, in Klammern die
  Anzahl im ganzen Schwarm laut Trackern.

Unten stehen die Details des gewählten Torrents:

- **Übersicht**: Name, Info-Hashes (v1 und v2), Größe, Speicherort,
  Kommentar und Summen. Links im Kommentar öffnen sich im Browser. Der
  Balken oben zeigt die Teile: Jedes heruntergeladene Teil ist an seiner
  Stelle im Torrent eingefärbt. Teile werden nicht der Reihe nach geladen
  (seltenste zuerst), daher hat ein unfertiger Torrent Lücken.
- **Dateien**: Dateien und Ordner mit Fortschritt. Rechtsklick setzt die
  Priorität oder überspringt eine Datei; Doppelklick öffnet eine
  heruntergeladene Datei.
- **Peers**: verbundene Peers mit Land, Client, Raten und
  ausgeschriebenen Verbindungsflags.
- **Tracker**: Tracker-Status, gemeldete Seeds und Leecher und die
  nächste Ankündigung. Rechtsklick zum Hinzufügen, Entfernen oder erneuten
  Ankündigen.

Die Statusleiste zeigt die Anzahl der Torrents, DHT-Knoten, die aktuellen
Raten, ob der IP-Filter aktiv ist und die in dieser Sitzung übertragene
Menge. Über **Anzeige** lassen sich Detailbereich, Statusleiste und
Konsole ein- und ausblenden.


## Torrents hinzufügen

- **Datei > Torrent hinzufügen** (Strg+O): eine oder mehrere
  `.torrent`-Dateien wählen.
- **Datei > Magnetlink(s) hinzufügen** (Strg+U): Magnet-Links
  einfügen, einer pro Zeile.
- Eine `.torrent`-Datei oder einen Magnet-Link mit `RePicoTorrent.exe`
  öffnen; läuft das Programm aus diesem Ordner schon, wird der Torrent an
  es übergeben.

Vor dem Hinzufügen lassen sich Speicherort, gewünschte Dateien und ein
Label wählen. Um Torrents sofort mit den Standardeinstellungen
hinzuzufügen, aktivieren Sie **Dialog 'Torrent hinzufügen' überspringen** in den
Einstellungen.


## Torrents verwalten

Rechtsklick auf einen oder mehrere Torrents:

- **Fortfahren**, **Fortfahren (erzwingen)** (ignoriert die Warteschlange),
  **Pausieren**.
- **Neue Ankündigung erzwingen**, **Überprüfung erzwingen** (prüft die Daten auf der
  Festplatte).
- **Sequenzieller DL**: Teile der Reihe nach laden, praktisch, um
  ein Video schon während des Downloads anzusehen.
- **Label**: ein Label zuweisen.
- **Exportieren**: Magnet-Link oder `.torrent`-Datei.
- **Verschieben**: die Daten in einen anderen Ordner verschieben.
- **Entfernen**: den Torrent entfernen (Entf) oder den Torrent samt
  Dateien (Umschalt+Entf).
- **in Warteschlange**: in der Download-Warteschlange nach oben oder unten.
- **Info-Hash kopieren**, **Im Explorer öffnen**.


## Labels

Labels gruppieren Torrents. Sie werden unter
**Einstellungen > Labels** angelegt:

- **Farbe**: die Label-Farbe; mit
  **Labelfarbe als Hintergrund in Torrentliste verwenden** (**Generell**)
  werden die Zeilen darin eingefärbt.
- **Speicherpfad**: Torrents mit diesem Label werden hier gespeichert.
- **Filter anwenden**: ein regulärer Ausdruck; ein neuer Torrent, dessen
  Name passt, erhält dieses Label automatisch. Beispiel:
  `ubuntu|debian|fedora`.

**Anzeige > Labels** zeigt nur die Torrents mit einem Label.


## Filter und Konsole

**Anzeige > Filter** enthält gespeicherte Filter, etwa die gerade
ladenden Torrents. **Anzeige > Konsole** öffnet eine Zeile unter
der Liste: Abfrage eingeben und Enter drücken, um nur passende Torrents zu
zeigen; Zeile leeren, um wieder alle zu zeigen.

| Feld | Typ | Bedeutung |
|---|---|---|
| `name` | Text | Name des Torrents |
| `label` | Text | Name des Labels |
| `status` | Text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | Zahl | Prozent fertig |
| `size` | Größe | gewünschte Größe: `b` (Standard), `kb`, `mb`, `gb` |
| `dl`, `ul` | Rate | Bytes pro Sekunde (Standard), `kbps`, `mbps`, `gbps` |

Operatoren: `=`, `<`, `<=`, `>`, `>=` und `~` (enthält, ohne
Groß-/Kleinschreibung), verknüpft mit `and` und `or`. Text steht in
doppelten Anführungszeichen, Einheiten werden kleingeschrieben.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrents erstellen

**Datei > Torrent erstellen**:

![Torrent erstellen](images/en-US/create-torrent.png)

- Eine Datei oder einen Ordner wählen.
- **Modus**: v1, v2 oder Hybrid v1 + v2. Hybrid funktioniert mit jedem
  Client und ist voreingestellt.
- **Kommentar** und **Ersteller** sind optional.
- **Privat**: Peers kommen nur von den Trackern, nicht über DHT, PeX
  oder lokale Suche.
- **Zur Session hinzufügen**: den neuen Torrent sofort seeden.
- **Tracker (einer pro Zeile)**: jeder Tracker kommt in eine eigene Stufe;
  die Stufen werden der Reihe nach versucht.
- **URL seeds (einer pro Zeile)**: Webserver mit denselben Daten. Bei einem
  Ordner muss die URL auf den Ordner zeigen, der ihn enthält.


## Einstellungen

**Anzeige > Einstellungen**. **Standardwerte wiederherstellen** setzt alle
Einstellungen zurück. Manche Änderungen (Sprache, Design, Ports) brauchen
einen Neustart; das Programm bietet ihn an.

### Generell

![Allgemein](images/en-US/preferences-general.png)

- **Sprache** und **Theme** (System oder hell; das dunkle Design
  folgt der Windows-Einstellung).
- **Dialog 'Torrent hinzufügen' überspringen**, **RePicoTorrent mit Windows starten**,
  **Startposition** des Fensters.
- **RePicoTorrent im Benachrichtigungsfeld anzeigen** und ob Minimieren oder
  Schließen das Fenster dorthin verschiebt.

### Downloads

![Downloads](images/en-US/preferences-downloads.png)

- **Speicherpfad**, **Fertige Downloads verschieben** in einen anderen Ordner.
- **Pause bei zu wenig Speicherplatz**.
- **Begrenzungen**: Download- und Upload-Limit in KB/s, wie viele Torrents
  gleichzeitig aktiv sein dürfen und die Gesamtzahl der Verbindungen.

### Labels

![Labels](images/en-US/preferences-labels.png)

Siehe [Labels](#labels).

### Verbindung

![Verbindung](images/en-US/preferences-connection.png)

- **Listen-Interface**: Adressen und Ports für eingehende Verbindungen.
  `0.0.0.0` und `[::]` bedeuten alle IPv4- und IPv6-Adressen.
- **Verschlüsselung**: verschlüsselte ein- oder ausgehende Verbindungen
  verlangen.
- **Privatsphäre**: DHT, lokale Peer-Suche (LSD), Peer-Austausch (PeX),
  WebTorrent und die Länderspalte der Peers. Die Länderdatenbank (DB-IP
  Lite) wird einmal im Monat geladen, solange die Spalte aktiv ist.
- **IP Filter**: Adressen aus einem Filter im eMule-Format in einer
  Zip-Datei sperren, etwa von emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

HTTP- oder SOCKS4/5-Proxy, mit oder ohne Passwort, und was darüber läuft:
Namensauflösung, Peer- und Tracker-Verbindungen.

### Erweitert

![Erweitert](images/en-US/preferences-advanced.png)

Alle libtorrent-Einstellungen. Wählen Sie eine aus, um ihre Beschreibung
unter der Liste zu lesen. Ändern Sie sie nur, wenn Sie wissen, was sie
tun; **Standardwerte wiederherstellen** stellt sie wieder her.


## Umstieg von PicoTorrent oder qBittorrent

- **Datei > Import from PicoTorrent**: `PicoTorrent.sqlite` wählen
  (neben einem portablen PicoTorrent oder in `%LOCALAPPDATA%\PicoTorrent`).
  Torrents und ihre Labels werden hinzugefügt; die Datei wird nur gelesen.
  Um alles samt Einstellungen zu übernehmen, kopieren Sie
  `PicoTorrent.sqlite` vor dem ersten Start neben `RePicoTorrent.exe`: sie
  wird in `RePicoTorrent.sqlite` umbenannt.
- **Datei > Import from qBittorrent**: den Ordner `BT_backup` von
  qBittorrent wählen (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Fortschritt,
  Tracker, Zähler, Speicherorte und Kommentare bleiben erhalten.

Torrents, die schon in der Liste sind, werden übersprungen. Seeden Sie
dieselben Torrents nicht gleichzeitig aus beiden Clients.


## Updates

Bei jedem Start fragt das Programm GitHub nach dem neuesten Release,
**Hilfe > Nach Updates suchen** jederzeit. Gibt es eine neuere
Version, lädt **Download and install** das Zip für Ihr Windows, prüft es gegen
die SHA-256-Prüfsummen des Releases, ersetzt die Programmdateien und
startet neu. Einstellungen und Torrents bleiben.


## Tastenkürzel

| Tasten | Aktion |
|---|---|
| Strg+O | Torrent hinzufügen |
| Strg+U | Magnet-Links hinzufügen |
| Strg+A | alle Torrents auswählen |
| Entf | ausgewählte Torrents entfernen, Daten behalten |
| Umschalt+Entf | ausgewählte Torrents samt Daten entfernen |
| F1 | diese Dokumentation öffnen |


## Dateien und Befehlszeile

Neben `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: Einstellungen, Torrents und ihre Fortsetzungsdaten;
- `coredb.sqlite`: Übersetzungen (Teil des Programms);
- `logs`: Protokolldateien;
- `Crashpad`: Absturzabbilder, werden nie hochgeladen;
- `dbip-country-lite.mmdb`: die Länderdatenbank.

Befehlszeile:

```
RePicoTorrent.exe [--silent] [--save-path=<Ordner>] [file.torrent | magnet:?xt=...]...
```

`--silent` fügt die angegebenen Torrents ohne Dialog hinzu, `--save-path`
legt fest, wo sie gespeichert werden.
