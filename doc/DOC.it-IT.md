# Documentazione di RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · **Italiano** · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Per iniziare](#per-iniziare)
- [Finestra principale](#finestra-principale)
- [Aggiungere torrent](#aggiungere-torrent)
- [Gestire i torrent](#gestire-i-torrent)
- [Etichette](#etichette)
- [Filtri e console](#filtri-e-console)
- [Creare torrent](#creare-torrent)
- [Preferenze](#preferenze)
- [Passare da PicoTorrent o qBittorrent](#passare-da-picotorrent-o-qbittorrent)
- [Aggiornamenti](#aggiornamenti)
- [Scorciatoie da tastiera](#scorciatoie-da-tastiera)
- [File e riga di comando](#file-e-riga-di-comando)


## Per iniziare

Scaricate lo zip per il vostro Windows dalla
[pagina delle versioni](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` per Windows a 64 bit, `arm64` per Windows su ARM, `x86` per Windows a
32 bit. Estraetelo in una cartella qualsiasi con permesso di scrittura e
avviate `RePicoTorrent.exe`. Non viene installato nulla: impostazioni,
elenco dei torrent e log restano accanto all'exe, quindi la cartella può
essere spostata o copiata su una chiavetta USB.

Ogni cartella è una copia separata del programma. Due copie in cartelle
diverse possono funzionare insieme se usano porte diverse.


## Finestra principale

![Finestra principale](images/en-US/main.png)

In alto c'è l'elenco dei torrent. Ogni colonna si ordina con un clic
sull'intestazione; il clic destro sulle intestazioni mostra o nasconde le
colonne.

- **Progresso** e **Done**: quanta parte dei dati voluti è già
  scaricata.
- **Stimato**, **DL**, **UL**: tempo rimanente, velocità di download
  e upload.
- **Disponibilità**: quante copie complete hanno insieme i peer connessi.
- **Seed**, **Peer**, **Leechers**: connessi e, tra parentesi,
  il numero nell'intero sciame secondo i tracker.

In basso ci sono i dettagli del torrent selezionato:

- **Panoramica**: nome, hash (v1 e v2), dimensione, cartella, commento e
  totali. I link nel commento si aprono nel browser. La barra in alto
  mostra i pezzi: ogni pezzo scaricato è colorato nel punto in cui si trova
  nel torrent. I pezzi arrivano fuori ordine (prima i più rari), per questo
  un torrent in corso ha dei vuoti.
- **File**: file e cartelle con il progresso. Clic destro per la
  priorità o per saltare un file; doppio clic apre un file scaricato.
- **Peer**: peer connessi con paese, client, velocità e flag di
  connessione scritti per esteso.
- **Tracker**: stato del tracker, seed e leecher che riporta e il
  prossimo annuncio. Clic destro per aggiungere, rimuovere o riannunciare.

La barra di stato mostra il numero di torrent, i nodi DHT, le velocità
attuali, se il filtro IP è attivo e quanto è stato trasferito nella
sessione. Il menu **Visualizza** nasconde o mostra il pannello dei
dettagli, la barra di stato e la console.


## Aggiungere torrent

- **File > Aggiungi torrent** (Ctrl+O): scegliete uno o più file
  `.torrent`.
- **File > Aggiungi collegamento magnet** (Ctrl+U): incollate i link
  magnet, uno per riga.
- Aprite un file `.torrent` o un link magnet con `RePicoTorrent.exe`; se il
  programma di quella cartella è già avviato, il torrent gli viene passato.

Prima dell'aggiunta potete scegliere la cartella, i file da scaricare e
un'etichetta. Per aggiungere i torrent subito con le impostazioni
predefinite, attivate **Salta finestra 'Aggiungi torrent'** nelle preferenze.


## Gestire i torrent

Clic destro su uno o più torrent:

- **Riprendi**, **Ripresa (forzata)** (ignora la coda), **Pausa**.
- **Forza nuovo annuncio**, **Forza nuovo controllo** (verifica i dati sul
  disco).
- **Download sequenziale**: scaricare i pezzi in ordine, utile per
  guardare un video mentre si scarica.
- **Etichetta**: assegnare un'etichetta.
- **Export**: il link magnet o il file `.torrent`.
- **Sposta**: spostare i dati in un'altra cartella.
- **Rimuovi**: rimuovere il torrent (Canc) o il torrent e i suoi file
  (Maiusc+Canc).
- **Posizione in coda**: salire o scendere nella coda dei download.
- **Copia info hash**, **Apri in Esplora risorse**.


## Etichette

Le etichette raggruppano i torrent. Si creano in
**Impostazioni > Etichette**:

- **Colore**: il colore dell'etichetta; con
  **Usa colore etichetta come sfondo nell'elenco torrent** (**Generale**) le
  righe vengono colorate.
- **Percorso salvataggio**: i torrent aggiunti con questa etichetta vengono
  salvati qui.
- **Applica filtro**: un'espressione regolare; un nuovo torrent il cui
  nome corrisponde riceve questa etichetta automaticamente. Esempio:
  `ubuntu|debian|fedora`.

**Visualizza > Etichette** mostra solo i torrent di un'etichetta.


## Filtri e console

**Visualizza > Filtro** contiene filtri salvati, per esempio i
torrent che stanno scaricando ora. **Visualizza > Console** apre una
riga sotto l'elenco: scrivete una query e premete Invio per vedere solo i
torrent corrispondenti; svuotatela per rivederli tutti.

| Campo | Tipo | Significato |
|---|---|---|
| `name` | testo | nome del torrent |
| `label` | testo | nome dell'etichetta |
| `status` | testo | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | numero | percentuale completata |
| `size` | dimensione | dimensione voluta: `b` (predefinito), `kb`, `mb`, `gb` |
| `dl`, `ul` | velocità | byte al secondo (predefinito), `kbps`, `mbps`, `gbps` |

Operatori: `=`, `<`, `<=`, `>`, `>=` e `~` (contiene, senza distinguere
maiuscole), uniti con `and` e `or`. Il testo va tra virgolette doppie, le
unità si scrivono in minuscolo.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Creare torrent

**File > Crea torrent**:

![Crea torrent](images/en-US/create-torrent.png)

- Scegliete un file o una cartella.
- **Modalità**: v1, v2 o ibrido v1 + v2. L'ibrido funziona con tutti i
  client ed è la scelta predefinita.
- **Commento** e **Creatore** sono facoltativi.
- **Privato**: i peer arrivano solo dai tracker, non da DHT, PeX o dalla
  ricerca locale.
- **Aggiungi alla sessione**: iniziare subito a condividere il nuovo torrent.
- **Tracker (uno per riga)**: ogni tracker ha il proprio livello; i
  livelli vengono provati in ordine.
- **URL seed (uno per riga)**: server web con gli stessi dati. Per una
  cartella, l'URL deve puntare alla cartella che la contiene.


## Preferenze

**Visualizza > Impostazioni**. **Ripristina predefiniti** ripristina
tutte le impostazioni. Alcune modifiche (lingua, tema, porte) richiedono un
riavvio; il programma lo propone.

### Generale

![Generale](images/en-US/preferences-general.png)

- **Lingua** e **Theme** (sistema o chiaro; il tema scuro segue
  l'impostazione di Windows).
- **Salta finestra 'Aggiungi torrent'**, **Esegui RePicoTorrent all'avvio di Windows**,
  **Posizione iniziale** della finestra.
- **Visualizza RePicoTorrent nell'area di notifica**, e se ridurre o chiudere la
  finestra la sposta lì.

### Download

![Download](images/en-US/preferences-downloads.png)

- **Percorso salvataggio**, **Sposta download completati** in un'altra cartella.
- **Metti in pausa quando lo spazio su disco è scarso**.
- **Limiti**: limiti di download e upload in KB/s, quanti torrent
  possono essere attivi insieme e il numero totale di connessioni.

### Etichette

![Etichette](images/en-US/preferences-labels.png)

Vedi [Etichette](#etichette).

### Connessione

![Connessione](images/en-US/preferences-connection.png)

- **Interfaccia di rete in ascolto**: indirizzi e porte per le connessioni in
  ingresso. `0.0.0.0` e `[::]` indicano tutti gli indirizzi IPv4 e IPv6.
- **Crittografia**: richiedere la cifratura delle connessioni in ingresso
  o in uscita.
- **Privacy**: DHT, ricerca locale dei peer (LSD), scambio di peer
  (PeX), WebTorrent e la colonna del paese dei peer. Il database dei paesi
  (DB-IP Lite) viene scaricato una volta al mese finché la colonna è
  attiva.
- **Filtro IP**: bloccare gli indirizzi di un filtro in formato eMule
  dentro uno zip, per esempio da emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP o SOCKS4/5, con o senza password, e cosa passa attraverso:
risoluzione dei nomi, connessioni con peer e tracker.

### Avanzate

![Avanzate](images/en-US/preferences-advanced.png)

Tutte le impostazioni di libtorrent. Selezionatene una per leggerne la
descrizione sotto l'elenco. Cambiatele solo se sapete cosa fanno;
**Ripristina predefiniti** le ripristina.


## Passare da PicoTorrent o qBittorrent

- **File > Import from PicoTorrent**: scegliete
  `PicoTorrent.sqlite` (accanto a un PicoTorrent portatile o in
  `%LOCALAPPDATA%\PicoTorrent`). Vengono aggiunti i torrent e le loro
  etichette; il file viene solo letto. Per portare tutto, impostazioni
  comprese, copiate `PicoTorrent.sqlite` accanto a `RePicoTorrent.exe`
  prima del primo avvio: verrà rinominato in `RePicoTorrent.sqlite`.
- **File > Import from qBittorrent**: scegliete la cartella
  `BT_backup` di qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`).
  Progresso, tracker, contatori, cartelle e commenti vengono mantenuti.

I torrent già presenti vengono saltati. Non condividete gli stessi torrent
da entrambi i client contemporaneamente.


## Aggiornamenti

A ogni avvio il programma chiede a GitHub l'ultima versione, e
**Aiuto > Verifica disponibilità aggiornamenti** lo fa in qualsiasi momento. Se c'è
una versione più recente, **Download and install** scarica lo zip per il vostro
Windows, lo verifica con i checksum SHA-256 della versione, sostituisce i
file del programma e lo riavvia. Impostazioni e torrent restano.


## Scorciatoie da tastiera

| Tasti | Azione |
|---|---|
| Ctrl+O | aggiungi torrent |
| Ctrl+U | aggiungi link magnet |
| Ctrl+A | seleziona tutti i torrent |
| Canc | rimuovi i torrent selezionati, mantieni i dati |
| Maiusc+Canc | rimuovi i torrent selezionati e i loro dati |
| F1 | apri questa documentazione |


## File e riga di comando

Accanto a `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: impostazioni, torrent e dati di ripresa;
- `coredb.sqlite`: traduzioni (parte del programma);
- `logs`: file di log;
- `Crashpad`: dump dei crash, mai inviati;
- `dbip-country-lite.mmdb`: il database dei paesi.

Riga di comando:

```
RePicoTorrent.exe [--silent] [--save-path=<cartella>] [file.torrent | magnet:?xt=...]...
```

`--silent` aggiunge i torrent indicati senza la finestra di aggiunta,
`--save-path` stabilisce dove salvarli.
