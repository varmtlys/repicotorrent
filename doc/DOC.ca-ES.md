# Documentació del RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · **Català** · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Primers passos](#primers-passos)
- [Finestra principal](#finestra-principal)
- [Afegir torrents](#afegir-torrents)
- [Gestionar torrents](#gestionar-torrents)
- [Etiquetes](#etiquetes)
- [Filtres i consola](#filtres-i-consola)
- [Crear torrents](#crear-torrents)
- [Preferències](#preferències)
- [Venir del PicoTorrent o del qBittorrent](#venir-del-picotorrent-o-del-qbittorrent)
- [Actualitzacions](#actualitzacions)
- [Dreceres de teclat](#dreceres-de-teclat)
- [Fitxers i línia d'ordres](#fitxers-i-línia-dordres)


## Primers passos

Baixeu el zip per al vostre Windows de la
[pàgina de versions](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` per a Windows de 64 bits, `arm64` per a Windows en ARM, `x86` per a
Windows de 32 bits. Descomprimiu-lo en qualsevol carpeta on pugueu escriure
i executeu `RePicoTorrent.exe`. No s'instal·la res: la configuració, la
llista de torrents i els registres es desen al costat de l'exe, de manera
que la carpeta es pot moure o copiar a una memòria USB.

Cada carpeta és una còpia independent del programa. Dues còpies en
carpetes diferents poden funcionar alhora si fan servir ports diferents.


## Finestra principal

![Finestra principal](images/en-US/main.png)

A dalt hi ha la llista de torrents. Cada columna s'ordena fent clic a la
capçalera; amb el botó dret a les capçaleres es mostren o s'amaguen
columnes.

- **Progrés** i **Done**: quina part de les dades volgudes s'ha
  baixat.
- **Temps estimat**, **Baixada**, **Pujada**: temps restant, velocitats de baixada i
  pujada.
- **Availability**: quantes còpies completes tenen entre tots els
  parells connectats.
- **Llavors**, **Parells**, **Leechers**: connectats i, entre
  parèntesis, el nombre a tot l'eixam segons els rastrejadors.

A baix hi ha els detalls del torrent seleccionat:

- **Visió de conjunt**: nom, hashos (v1 i v2), mida, carpeta, comentari i
  totals. Els enllaços del comentari s'obren al navegador. La barra de dalt
  mostra les peces: cada peça baixada es pinta al lloc que ocupa dins el
  torrent. Les peces arriben desordenades (primer les més rares), per això
  un torrent en curs té buits.
- **Fitxers**: fitxers i carpetes amb el progrés. Botó dret per canviar
  la prioritat o ometre un fitxer; doble clic obre un fitxer baixat.
- **Parells**: parells connectats amb el país, el client, les velocitats
  i els indicadors de connexió escrits en paraules.
- **Trackers**: estat del rastrejador, les llavors i sangoneres que
  informa i el proper anunci. Botó dret per afegir, treure o tornar a
  anunciar.

La barra d'estat mostra el nombre de torrents, els nodes DHT, les
velocitats actuals, si el filtre IP és actiu i quant s'ha transferit en
aquesta sessió. El menú **Veure** amaga o mostra el tauler de
detalls, la barra d'estat i la consola.


## Afegir torrents

- **Fitxer > Afegeix torrent** (Ctrl+O): trieu un o més fitxers
  `.torrent`.
- **Fitxer > Add enllaç(os) magnètic(s)** (Ctrl+U): enganxeu enllaços
  magnet, un per línia.
- Obriu un fitxer `.torrent` o un enllaç magnet amb `RePicoTorrent.exe`; si
  el programa d'aquella carpeta ja s'executa, el torrent se li passa.

Abans d'afegir-lo podeu triar la carpeta, els fitxers que voleu i una
etiqueta. Per afegir torrents directament amb la configuració per
defecte, activeu **Skip 'Add torrent' dialog** a les preferències.


## Gestionar torrents

Botó dret sobre un o més torrents:

- **Reprén**, **Reprén (forçat)** (ignora la cua), **Pausa**.
- **Force reannounce**, **Force recheck** (comprova les dades del
  disc).
- **Descarregues seqüencials**: baixar les peces en ordre, útil per mirar un
  vídeo mentre es baixa.
- **Label**: assignar una etiqueta.
- **Export**: l'enllaç magnet o el fitxer `.torrent`.
- **Mou**: moure les dades a una altra carpeta.
- **Esborra**: treure el torrent (Supr) o el torrent i els seus fitxers
  (Maj+Supr).
- **En cola**: pujar o baixar a la cua de baixades.
- **Copia la informació hash**, **Obre en el Explorador**.


## Etiquetes

Les etiquetes agrupen torrents. Es creen a
**Preferències > Labels**:

- **Color**: el color de l'etiqueta; amb
  **Use label color as background in torrent list** (**General**) les
  files se'n pinten.
- **Ruta per guardar**: els torrents afegits amb aquesta etiqueta es desen
  aquí.
- **Apply filter**: una expressió regular; un torrent nou el nom del
  qual hi coincideix rep aquesta etiqueta automàticament. Exemple:
  `ubuntu|debian|fedora`.

**Veure > Labels** mostra només els torrents d'una etiqueta.


## Filtres i consola

**Veure > Filter** té filtres desats, per exemple els torrents
que s'estan baixant ara. **Veure > Console** obre una línia
sota la llista: escriviu una consulta i premeu Retorn per veure només els
torrents que hi coincideixen; buideu-la per tornar-los a veure tots.

| Camp | Tipus | Significat |
|---|---|---|
| `name` | text | nom del torrent |
| `label` | text | nom de l'etiqueta |
| `status` | text | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | nombre | percentatge completat |
| `size` | mida | mida volguda: `b` (per defecte), `kb`, `mb`, `gb` |
| `dl`, `ul` | velocitat | bytes per segon (per defecte), `kbps`, `mbps`, `gbps` |

Operadors: `=`, `<`, `<=`, `>`, `>=` i `~` (conté, sense distingir
majúscules), units amb `and` i `or`. El text va entre cometes dobles i les
unitats s'escriuen en minúscules.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Crear torrents

**Fitxer > Create torrent**:

![Crea un torrent](images/en-US/create-torrent.png)

- Trieu un fitxer o una carpeta.
- **Mode**: v1, v2 o híbrid v1 + v2. L'híbrid funciona amb qualsevol
  client i és l'opció per defecte.
- **Comment** i **Creator** són opcionals.
- **Private**: els parells arriben només dels rastrejadors, no de DHT,
  PeX ni del descobriment local.
- **Add to session**: començar a compartir el torrent nou de seguida.
- **Trackers (one per line)**: cada rastrejador va al seu propi nivell;
  els nivells es proven en ordre.
- **URL seeds (one per line)**: servidors web amb les mateixes dades. Per
  a una carpeta, l'URL ha d'apuntar a la carpeta que la conté.


## Preferències

**Veure > Preferències**. **Restore defaults** restableix
tota la configuració. Alguns canvis (idioma, tema, ports) necessiten
reiniciar; el programa ho ofereix.

### General

![General](images/en-US/preferences-general.png)

- **Idioma** i **Theme** (sistema o clar; el tema fosc segueix la
  configuració de Windows).
- **Skip 'Add torrent' dialog**, **Inicia RePicoTorrent amb Windows**,
  **Pisició d'inici** de la finestra.
- **Show RePicoTorrent in notification area**, i si minimitzar o tancar la
  finestra l'hi envia.

### Descarregues

![Baixades](images/en-US/preferences-downloads.png)

- **Ruta per guardar**, **Moure descarregues completades** a una altra carpeta.
- **Pause when disk space is low**.
- **Límits**: límits de baixada i pujada en KB/s, quants torrents poden
  estar actius alhora i el total de connexions.

### Labels

![Etiquetes](images/en-US/preferences-labels.png)

Vegeu [Etiquetes](#etiquetes).

### Connexió

![Connexió](images/en-US/preferences-connection.png)

- **Escolta a la interficie**: adreces i ports per a les connexions entrants.
  `0.0.0.0` i `[::]` volen dir totes les adreces IPv4 i IPv6.
- **Encriptació**: exigir xifratge a les connexions entrants o sortints.
- **Privacitat**: DHT, descobriment local (LSD), intercanvi de parells
  (PeX), WebTorrent i la columna del país dels parells. La base de països
  (DB-IP Lite) es baixa un cop al mes mentre la columna és activa.
- **IP filter**: bloquejar adreces d'un filtre en format eMule dins d'un
  zip, per exemple d'emule-security.org.

### Servidor intermediari

![Servidor intermediari](images/en-US/preferences-proxy.png)

Servidor intermediari HTTP o SOCKS4/5, amb contrasenya o sense, i què hi
passa: resolució de noms, connexions amb parells i rastrejadors.

### Avançat

![Avançat](images/en-US/preferences-advanced.png)

Tots els paràmetres de libtorrent. Seleccioneu-ne un per llegir-ne la
descripció sota la llista. Canvieu-los només si sabeu què fan;
**Restore defaults** els restableix.


## Venir del PicoTorrent o del qBittorrent

- **Fitxer > Import from PicoTorrent**: trieu `PicoTorrent.sqlite`
  (al costat d'un PicoTorrent portàtil o a `%LOCALAPPDATA%\PicoTorrent`).
  S'afegeixen els torrents i les seves etiquetes; el fitxer només es llegeix.
  Per portar-ho tot, configuració inclosa, copieu `PicoTorrent.sqlite` al
  costat de `RePicoTorrent.exe` abans de la primera execució: es
  reanomenarà `RePicoTorrent.sqlite`.
- **Fitxer > Import from qBittorrent**: trieu la carpeta `BT_backup`
  del qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Es conserven el
  progrés, els rastrejadors, els comptadors, les carpetes i els
  comentaris.

Els torrents que ja són a la llista s'ometen. No compartiu els mateixos
torrents des dels dos clients alhora.


## Actualitzacions

A cada inici el programa demana a GitHub la darrera versió, i
**Ajuda > Busca actualitzacions** ho fa en qualsevol moment. Si hi
ha una versió més nova, **Download and install** baixa el zip per al vostre
Windows, el comprova amb les sumes SHA-256 de la versió, substitueix els
fitxers del programa i el reinicia. La configuració i els torrents es
mantenen.


## Dreceres de teclat

| Tecles | Acció |
|---|---|
| Ctrl+O | afegir torrent |
| Ctrl+U | afegir enllaços magnet |
| Ctrl+A | seleccionar tots els torrents |
| Supr | treure els torrents seleccionats, conservar les dades |
| Maj+Supr | treure els torrents seleccionats i les seves dades |
| F1 | obrir aquesta documentació |


## Fitxers i línia d'ordres

Al costat de `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: configuració, torrents i dades per reprendre'ls;
- `coredb.sqlite`: traduccions (part del programa);
- `logs`: registres;
- `Crashpad`: bolcats de fallades, mai s'envien;
- `dbip-country-lite.mmdb`: la base de països.

Línia d'ordres:

```
RePicoTorrent.exe [--silent] [--save-path=<carpeta>] [file.torrent | magnet:?xt=...]...
```

`--silent` afegeix els torrents indicats sense la finestra d'afegir,
`--save-path` indica on desar-los.
