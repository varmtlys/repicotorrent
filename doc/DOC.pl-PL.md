# Dokumentacja RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · **Polski** · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Pierwsze kroki](#pierwsze-kroki)
- [Okno główne](#okno-główne)
- [Dodawanie torrentów](#dodawanie-torrentów)
- [Zarządzanie torrentami](#zarządzanie-torrentami)
- [Etykiety](#etykiety)
- [Filtry i konsola](#filtry-i-konsola)
- [Tworzenie torrentów](#tworzenie-torrentów)
- [Ustawienia](#ustawienia)
- [Przejście z PicoTorrent lub qBittorrent](#przejście-z-picotorrent-lub-qbittorrent)
- [Aktualizacje](#aktualizacje)
- [Skróty klawiszowe](#skróty-klawiszowe)
- [Pliki i wiersz poleceń](#pliki-i-wiersz-poleceń)


## Pierwsze kroki

Pobierz zip dla swojego Windows ze
[strony wydań](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` dla 64-bitowego Windows, `arm64` dla Windows na ARM, `x86` dla
32-bitowego Windows. Rozpakuj go do dowolnego folderu z prawem zapisu i
uruchom `RePicoTorrent.exe`. Nic nie jest instalowane: ustawienia, lista
torrentów i logi są przechowywane obok exe, więc folder można przenieść
lub skopiować na pendrive.

Każdy folder to osobna kopia programu. Dwie kopie w różnych folderach mogą
działać jednocześnie, jeśli używają różnych portów.


## Okno główne

![Okno główne](images/en-US/main.png)

U góry jest lista torrentów. Każdą kolumnę sortuje się kliknięciem w jej
nagłówek; prawy klik na nagłówkach pokazuje lub ukrywa kolumny.

- **Postęp** i **Done**: ile z wybranych danych już pobrano.
- **Pozostały Czas**, **Pobieranie**, **Wysyłanie**: pozostały czas, prędkość pobierania i
  wysyłania.
- **Dostępność**: ile pełnych kopii mają razem połączeni peerzy.
- **Seedy**, **Peery**, **Leechers**: połączeni, a w nawiasie
  liczba w całym roju według trackerów.

Na dole są szczegóły zaznaczonego torrenta:

- **Podsumowanie**: nazwa, hashe (v1 i v2), rozmiar, folder zapisu,
  komentarz i sumy. Linki w komentarzu otwierają się w przeglądarce. Pasek
  u góry pokazuje części: każda pobrana część jest zamalowana w miejscu, w
  którym leży w torrencie. Części są pobierane nie po kolei (najpierw
  najrzadsze), więc nieukończony torrent ma luki.
- **Pliki**: pliki i foldery z postępem. Prawy klik ustawia priorytet
  lub pomija plik; podwójny klik otwiera pobrany plik.
- **Peery**: połączeni peerzy z krajem, klientem, prędkościami i flagami
  połączenia opisanymi słowami.
- **Tracker**: stan trackera, zgłaszane seedy i leechery oraz następne
  ogłoszenie. Prawy klik, aby dodać, usunąć lub ogłosić ponownie.

Pasek stanu pokazuje liczbę torrentów, węzłów DHT, bieżące prędkości, czy
filtr IP jest włączony i ile przesłano w tej sesji. Menu **Widok**
ukrywa lub pokazuje panel szczegółów, pasek stanu i konsolę.


## Dodawanie torrentów

- **Plik > Dodaj torrent'a** (Ctrl+O): wybierz jeden lub więcej
  plików `.torrent`.
- **Plik > Dodaj magnetlink(i)** (Ctrl+U): wklej linki magnet,
  po jednym w wierszu.
- Otwórz plik `.torrent` lub link magnet za pomocą `RePicoTorrent.exe`;
  jeśli program z tego folderu już działa, torrent zostanie mu przekazany.

Przed dodaniem można wybrać folder, potrzebne pliki i etykietę. Aby
dodawać torrenty od razu z ustawieniami domyślnymi, włącz
**Pomiń dialog dodawania torrenta** w ustawieniach.


## Zarządzanie torrentami

Prawy klik na jednym lub kilku torrentach:

- **Wznów**, **Wznów (Wymuś)** (pomija kolejkę), **Pauza**.
- **Wymuś aktualizację trackerów**, **Wymuś ponowne sprawdzenie** (sprawdza dane na dysku).
- **Pobieranie sekwencyjne**: pobieranie części po kolei, przydatne do
  oglądania filmu w trakcie pobierania.
- **Etykieta**: przypisz etykietę.
- **Export**: link magnet lub plik `.torrent`.
- **Przesuń**: przenieś dane do innego folderu.
- **Usuń**: usuń torrent (Del) albo torrent razem z plikami
  (Shift+Del).
- **W kolejce**: w górę lub w dół kolejki pobierania.
- **Kopiuj info-hash**, **Otwórz w Eksploratorze**.


## Etykiety

Etykiety grupują torrenty. Tworzy się je w
**Preferencje > Etykiety**:

- **Kolor**: kolor etykiety; przy włączonym
  **Użyj koloru etykiety jako tła dla listy torrentów** (**Ogólnie**)
  wiersze są nim malowane.
- **Ścieżka zapisu**: torrenty z tą etykietą są zapisywane tutaj.
- **Zaaplikuj filtr**: wyrażenie regularne; nowy torrent, którego nazwa do
  niego pasuje, dostaje tę etykietę automatycznie. Przykład:
  `ubuntu|debian|fedora`.

**Widok > Etykiety** pokazuje tylko torrenty z jedną etykietą.


## Filtry i konsola

W **Widok > Filtr** są zapisane filtry, na przykład torrenty,
które właśnie się pobierają. **Widok > Konsola** otwiera
wiersz pod listą: wpisz zapytanie i naciśnij Enter, aby zostawić tylko
pasujące torrenty; wyczyść go, aby znowu pokazać wszystkie.

| Pole | Typ | Znaczenie |
|---|---|---|
| `name` | tekst | nazwa torrenta |
| `label` | tekst | nazwa etykiety |
| `status` | tekst | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | liczba | procent ukończenia |
| `size` | rozmiar | wybrany rozmiar: `b` (domyślnie), `kb`, `mb`, `gb` |
| `dl`, `ul` | prędkość | bajty na sekundę (domyślnie), `kbps`, `mbps`, `gbps` |

Operatory: `=`, `<`, `<=`, `>`, `>=` i `~` (zawiera, bez rozróżniania
wielkości liter), łączone przez `and` i `or`. Tekst zapisuje się w
podwójnych cudzysłowach, jednostki małymi literami.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Tworzenie torrentów

**Plik > Stwórz torrent**:

![Tworzenie torrenta](images/en-US/create-torrent.png)

- Wybierz plik lub folder.
- **Tryb**: v1, v2 lub hybryda v1 + v2. Hybryda działa z każdym
  klientem i jest domyślna.
- **Komentarz** i **Stwórca** są opcjonalne.
- **Prywatny**: peerzy pochodzą tylko z trackerów, bez DHT, PeX i
  lokalnego wykrywania.
- **Dodaj do sesji**: od razu zacznij seedować nowy torrent.
- **Trackers (po jednym w lini)**: każdy tracker trafia do własnego
  poziomu; poziomy są próbowane po kolei.
- **URL seeds (po jednym w lini)**: serwery WWW z tymi samymi danymi. Dla
  folderu adres musi wskazywać folder, który go zawiera.


## Ustawienia

**Widok > Preferencje**. **Przywróć domyślne** przywraca
wszystkie ustawienia. Niektóre zmiany (język, motyw, porty) wymagają
ponownego uruchomienia; program sam je zaproponuje.

### Ogólnie

![Ogólne](images/en-US/preferences-general.png)

- **Język** i **Theme** (systemowy lub jasny; ciemny motyw
  włącza się zgodnie z ustawieniem Windows).
- **Pomiń dialog dodawania torrenta**, **Uruchom RePicoTorrent po starcie systemu**,
  **Pozycja uruchomienia** okna.
- **Pokaż RePicoTorrent w obszarze powiadomień** oraz czy minimalizowanie lub
  zamykanie okna chowa je tam.

### Pobrane

![Pobieranie](images/en-US/preferences-downloads.png)

- **Ścieżka zapisu**, **Przenieś zakończone pobierania** do innego folderu.
- **Zatrzymaj gdy na dysku będzie mało miejsca**.
- **Limity**: limity pobierania i wysyłania w KB/s, ile torrentów może
  być aktywnych jednocześnie i łączna liczba połączeń.

### Etykiety

![Etykiety](images/en-US/preferences-labels.png)

Zobacz [Etykiety](#etykiety).

### Połączenie

![Połączenie](images/en-US/preferences-connection.png)

- **Nasłuch interfejsu**: adresy i porty dla połączeń przychodzących.
  `0.0.0.0` i `[::]` oznaczają wszystkie adresy IPv4 i IPv6.
- **Szyfrowanie**: wymagaj szyfrowania połączeń przychodzących lub
  wychodzących.
- **Prywatność**: DHT, lokalne wykrywanie peerów (LSD), wymiana peerów
  (PeX), WebTorrent i kolumna z krajem peera. Baza krajów (DB-IP Lite) jest
  pobierana raz w miesiącu, dopóki ta kolumna jest włączona.
- **Filtr IP**: blokuj adresy z filtra w formacie eMule spakowanego do
  zip, na przykład z emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP lub SOCKS4/5, z hasłem lub bez, i co przez nie przechodzi:
rozwiązywanie nazw, połączenia z peerami i trackerami.

### Zaawansowane

![Zaawansowane](images/en-US/preferences-advanced.png)

Wszystkie ustawienia libtorrent. Zaznacz jedno, aby przeczytać jego opis
pod listą. Zmieniaj je tylko wtedy, gdy wiesz, co robią;
**Przywróć domyślne** je przywróci.


## Przejście z PicoTorrent lub qBittorrent

- **Plik > Import from PicoTorrent**: wybierz `PicoTorrent.sqlite`
  (obok przenośnego PicoTorrent lub w `%LOCALAPPDATA%\PicoTorrent`).
  Dodawane są torrenty i ich etykiety; plik jest tylko czytany. Aby
  przenieść wszystko razem z ustawieniami, skopiuj `PicoTorrent.sqlite`
  obok `RePicoTorrent.exe` przed pierwszym uruchomieniem: zostanie
  przemianowany na `RePicoTorrent.sqlite`.
- **Plik > Import from qBittorrent**: wybierz folder `BT_backup`
  qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Zachowywane są
  postęp, trackery, liczniki, foldery zapisu i komentarze.

Torrenty, które już są na liście, są pomijane. Nie seeduj tych samych
torrentów z obu klientów jednocześnie.


## Aktualizacje

Przy każdym uruchomieniu program pyta GitHub o najnowsze wydanie, a
**Pomoc > Sprawdź dostępność aktualizacji** sprawdza w dowolnej chwili. Jeśli
jest nowsza wersja, **Download and install** pobiera zip dla Twojego Windows,
sprawdza go z sumami SHA-256 wydania, podmienia pliki programu i
uruchamia go ponownie. Ustawienia i torrenty zostają.


## Skróty klawiszowe

| Klawisze | Działanie |
|---|---|
| Ctrl+O | dodaj torrent |
| Ctrl+U | dodaj linki magnet |
| Ctrl+A | zaznacz wszystkie torrenty |
| Del | usuń zaznaczone torrenty, zachowaj dane |
| Shift+Del | usuń zaznaczone torrenty razem z danymi |
| F1 | otwórz tę dokumentację |


## Pliki i wiersz poleceń

Obok `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: ustawienia, torrenty i dane do ich wznowienia;
- `coredb.sqlite`: tłumaczenia (część programu);
- `logs`: pliki dziennika;
- `Crashpad`: zrzuty awarii, nigdy nie są wysyłane;
- `dbip-country-lite.mmdb`: baza krajów.

Wiersz poleceń:

```
RePicoTorrent.exe [--silent] [--save-path=<folder>] [file.torrent | magnet:?xt=...]...
```

`--silent` dodaje podane torrenty bez okna dodawania, `--save-path`
określa, gdzie je zapisać.
