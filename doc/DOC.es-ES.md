# Documentación de RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · **Español** · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Primeros pasos](#primeros-pasos)
- [Ventana principal](#ventana-principal)
- [Añadir torrents](#añadir-torrents)
- [Gestionar torrents](#gestionar-torrents)
- [Etiquetas](#etiquetas)
- [Filtros y consola](#filtros-y-consola)
- [Crear torrents](#crear-torrents)
- [Preferencias](#preferencias)
- [Pasar de PicoTorrent o qBittorrent](#pasar-de-picotorrent-o-qbittorrent)
- [Actualizaciones](#actualizaciones)
- [Atajos de teclado](#atajos-de-teclado)
- [Archivos y línea de comandos](#archivos-y-línea-de-comandos)


## Primeros pasos

Descargue el zip para su Windows desde la
[página de versiones](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` para Windows de 64 bits, `arm64` para Windows en ARM, `x86` para
Windows de 32 bits. Descomprímalo en cualquier carpeta con permiso de
escritura y ejecute `RePicoTorrent.exe`. No se instala nada: la
configuración, la lista de torrents y los registros se guardan junto al
exe, así que la carpeta se puede mover o copiar a una memoria USB.

Cada carpeta es una copia independiente del programa. Dos copias en
carpetas distintas pueden funcionar a la vez si usan puertos distintos.


## Ventana principal

![Ventana principal](images/en-US/main.png)

Arriba está la lista de torrents. Cada columna se ordena haciendo clic en
su encabezado; con clic derecho en los encabezados se muestran u ocultan
columnas.

- **Progreso** y **Done**: cuánto de los datos deseados se ha
  descargado.
- **Tiempo estimado**, **Descarga**, **Subida**: tiempo restante, velocidades de
  descarga y subida.
- **Disponibilidad**: cuántas copias completas tienen entre todos los
  pares conectados.
- **Semillas**, **Pares**, **Leechers**: conectados y, entre
  paréntesis, el número en todo el enjambre según los trackers.

Abajo se muestran los detalles del torrent seleccionado:

- **Vista general**: nombre, hashes (v1 y v2), tamaño, carpeta, comentario y
  totales. Los enlaces del comentario se abren en el navegador. La barra
  superior muestra las piezas: cada pieza descargada se pinta en el lugar
  que ocupa en el torrent. Las piezas se descargan desordenadas (primero
  las más raras), así que un torrent en curso tiene huecos.
- **Archivos**: archivos y carpetas con su progreso. Clic derecho para
  cambiar la prioridad u omitir un archivo; doble clic abre un archivo
  descargado.
- **Pares**: pares conectados con su país, cliente, velocidades e
  indicadores de conexión escritos en palabras.
- **Rastreadores**: estado del tracker, semillas y leechers que informa y el
  próximo anuncio. Clic derecho para añadir, quitar o volver a anunciar.

La barra de estado muestra el número de torrents, nodos DHT, las
velocidades actuales, si el filtro IP está activo y lo transferido en la
sesión. El menú **Ver** oculta o muestra el panel de detalles, la
barra de estado y la consola.


## Añadir torrents

- **Archivo > Añadir torrent** (Ctrl+O): elija uno o varios
  archivos `.torrent`.
- **Archivo > Añadir enlace(s) magnético(s)** (Ctrl+U): pegue enlaces
  magnet, uno por línea.
- Abra un archivo `.torrent` o un enlace magnet con `RePicoTorrent.exe`; si
  el programa de esa carpeta ya está en marcha, el torrent se le pasa.

Antes de añadirlo puede elegir la carpeta, los archivos que quiere y una
etiqueta. Para añadir torrents directamente con la configuración por
defecto, active **Omitir cuadro de diálogo "Agregar torrent"** en las preferencias.


## Gestionar torrents

Clic derecho sobre uno o varios torrents:

- **Reanudar**, **Reanudar (forzado)** (ignora la cola), **Pausar**.
- **Forzar recomunicación**, **Forzar verificación** (comprueba los datos en
  disco).
- **Descarga secuencial**: descargar las piezas en orden, útil para ver
  un vídeo mientras se descarga.
- **Etiqueta**: asignar una etiqueta.
- **Export**: el enlace magnet o el archivo `.torrent`.
- **Mover**: mover los datos a otra carpeta.
- **Eliminar**: quitar el torrent (Supr) o el torrent y sus archivos
  (Mayús+Supr).
- **En cola**: subir o bajar en la cola de descargas.
- **Copiar información hash**, **Abrir en el Explorador**.


## Etiquetas

Las etiquetas agrupan torrents. Se crean en
**Preferencias > Etiquetas**:

- **Color**: el color de la etiqueta; con
  **Usar color de etiqueta como fondo en lista de torrents** (**General**)
  las filas se pintan de ese color.
- **Ruta para guardar**: los torrents añadidos con esta etiqueta se guardan
  aquí.
- **Aplicar filtro**: una expresión regular; un torrent nuevo cuyo nombre
  coincide recibe esta etiqueta automáticamente. Ejemplo:
  `ubuntu|debian|fedora`.

**Ver > Etiquetas** muestra solo los torrents de una etiqueta.


## Filtros y consola

**Ver > Filtrar** tiene filtros guardados, por ejemplo los
torrents que se están descargando ahora. **Ver > Consola**
abre una línea bajo la lista: escriba una consulta y pulse Intro para ver
solo los torrents que coinciden; bórrela para verlos todos de nuevo.

| Campo | Tipo | Significado |
|---|---|---|
| `name` | texto | nombre del torrent |
| `label` | texto | nombre de la etiqueta |
| `status` | texto | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | número | porcentaje completado |
| `size` | tamaño | tamaño deseado: `b` (por defecto), `kb`, `mb`, `gb` |
| `dl`, `ul` | velocidad | bytes por segundo (por defecto), `kbps`, `mbps`, `gbps` |

Operadores: `=`, `<`, `<=`, `>`, `>=` y `~` (contiene, sin distinguir
mayúsculas), unidos con `and` y `or`. El texto va entre comillas dobles y
las unidades se escriben en minúsculas.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Crear torrents

**Archivo > Crear torrent**:

![Crear torrent](images/en-US/create-torrent.png)

- Elija un archivo o una carpeta.
- **Modo**: v1, v2 o híbrido v1 + v2. El híbrido funciona con todos los
  clientes y es la opción por defecto.
- **Comentario** y **Creador** son opcionales.
- **Privado**: los pares llegan solo de los trackers, no de DHT, PeX ni
  el descubrimiento local.
- **Agregar a la sesión**: empezar a compartir el torrent nuevo en seguida.
- **Rastreadores (uno por línea)**: cada tracker va a su propio nivel; los
  niveles se prueban en orden.
- **Semillas URL (una por línea)**: servidores web con los mismos datos.
  Para una carpeta, la URL debe apuntar a la carpeta que la contiene.


## Preferencias

**Ver > Preferencias**. **Predeterminado** restablece
toda la configuración. Algunos cambios (idioma, tema, puertos) necesitan
reiniciar; el programa lo ofrece.

### General

![General](images/en-US/preferences-general.png)

- **Idioma** y **Theme** (sistema o claro; el tema oscuro sigue la
  configuración de Windows).
- **Omitir cuadro de diálogo "Agregar torrent"**, **Iniciar RePicoTorrent con Windows**,
  **Posición de inicio** de la ventana.
- **Mostrar RePicoTorrent en el área de notificación**, y si minimizar o cerrar la
  ventana la envía allí.

### Descargas

![Descargas](images/en-US/preferences-downloads.png)

- **Ruta para guardar**, **Mover descargas completadas** a otra carpeta.
- **Pausar cuando el espacio en disco es bajo**.
- **Límites**: límites de descarga y subida en KB/s, cuántos torrents
  pueden estar activos a la vez y el total de conexiones.

### Etiquetas

![Etiquetas](images/en-US/preferences-labels.png)

Vea [Etiquetas](#etiquetas).

### Conexión

![Conexión](images/en-US/preferences-connection.png)

- **Interfaz de escucha**: direcciones y puertos para conexiones entrantes.
  `0.0.0.0` y `[::]` significan todas las direcciones IPv4 e IPv6.
- **Cifrado**: exigir cifrado en las conexiones entrantes o salientes.
- **Privacidad**: DHT, descubrimiento local (LSD), intercambio de pares
  (PeX), WebTorrent y la columna del país de los pares. La base de países
  (DB-IP Lite) se descarga una vez al mes mientras la columna esté activa.
- **Filtro de IP**: bloquear direcciones de un filtro en formato eMule
  dentro de un zip, por ejemplo de emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP o SOCKS4/5, con o sin contraseña, y qué pasa por él: resolución
de nombres, conexiones con pares y trackers.

### Avanzado

![Avanzado](images/en-US/preferences-advanced.png)

Todos los ajustes de libtorrent. Seleccione uno para leer su descripción
bajo la lista. Cámbielos solo si sabe lo que hacen;
**Predeterminado** los devuelve a su valor.


## Pasar de PicoTorrent o qBittorrent

- **Archivo > Import from PicoTorrent**: elija `PicoTorrent.sqlite`
  (junto a un PicoTorrent portable o en `%LOCALAPPDATA%\PicoTorrent`). Se
  añaden los torrents y sus etiquetas; el archivo solo se lee. Para
  llevarse todo, configuración incluida, copie `PicoTorrent.sqlite` junto a
  `RePicoTorrent.exe` antes del primer inicio: se renombra a
  `RePicoTorrent.sqlite`.
- **Archivo > Import from qBittorrent**: elija la carpeta
  `BT_backup` de qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Se
  conservan el progreso, los trackers, los contadores, las carpetas y los
  comentarios.

Los torrents que ya están en la lista se omiten. No comparta los mismos
torrents desde los dos clientes a la vez.


## Actualizaciones

En cada inicio el programa pregunta a GitHub por la última versión, y
**Ayuda > Buscar actualización** lo hace en cualquier momento. Si
hay una versión nueva, **Download and install** descarga el zip para su
Windows, lo comprueba con las sumas SHA-256 de la versión, reemplaza los
archivos del programa y lo reinicia. La configuración y los torrents se
mantienen.


## Atajos de teclado

| Teclas | Acción |
|---|---|
| Ctrl+O | añadir torrent |
| Ctrl+U | añadir enlaces magnet |
| Ctrl+A | seleccionar todos los torrents |
| Supr | quitar los torrents seleccionados, conservar los datos |
| Mayús+Supr | quitar los torrents seleccionados y sus datos |
| F1 | abrir esta documentación |


## Archivos y línea de comandos

Junto a `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: configuración, torrents y sus datos de
  reanudación;
- `coredb.sqlite`: traducciones (parte del programa);
- `logs`: registros;
- `Crashpad`: volcados de fallos, nunca se envían;
- `dbip-country-lite.mmdb`: la base de países.

Línea de comandos:

```
RePicoTorrent.exe [--silent] [--save-path=<carpeta>] [file.torrent | magnet:?xt=...]...
```

`--silent` añade los torrents indicados sin la ventana de añadir,
`--save-path` indica dónde guardarlos.
