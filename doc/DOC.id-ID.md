# Dokumentasi RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · **Bahasa Indonesia** · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Memulai](#memulai)
- [Jendela utama](#jendela-utama)
- [Menambah torrent](#menambah-torrent)
- [Mengelola torrent](#mengelola-torrent)
- [Label](#label)
- [Filter dan konsol](#filter-dan-konsol)
- [Membuat torrent](#membuat-torrent)
- [Preferensi](#preferensi)
- [Pindah dari PicoTorrent atau qBittorrent](#pindah-dari-picotorrent-atau-qbittorrent)
- [Pembaruan](#pembaruan)
- [Pintasan papan ketik](#pintasan-papan-ketik)
- [Berkas dan baris perintah](#berkas-dan-baris-perintah)


## Memulai

Unduh zip untuk Windows Anda dari
[halaman rilis](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` untuk Windows 64-bit, `arm64` untuk Windows di ARM, `x86` untuk
Windows 32-bit. Ekstrak ke folder mana pun yang bisa Anda tulisi, lalu
jalankan `RePicoTorrent.exe`. Tidak ada yang dipasang: pengaturan, daftar
torrent, dan log disimpan di samping exe, jadi foldernya bisa dipindah
atau disalin ke flashdisk.

Setiap folder adalah salinan program yang terpisah. Dua salinan di folder
berbeda bisa berjalan bersamaan jika memakai port yang berbeda.


## Jendela utama

![Jendela utama](images/en-US/main.png)

Di atas ada daftar torrent. Setiap kolom diurutkan dengan mengeklik
judulnya; klik kanan pada judul untuk menampilkan atau menyembunyikan
kolom.

- **Laju** dan **Done**: berapa banyak data yang diinginkan
  sudah terunduh.
- **ETA**, **UD**, **UG**: sisa waktu, kecepatan unduh dan
  unggah.
- **Ketersediaan**: berapa salinan lengkap yang dimiliki bersama oleh
  peer yang terhubung.
- **Berbagi**, **Rekan**, **Leechers**: yang terhubung, dan dalam
  kurung jumlah di seluruh swarm menurut tracker.

Di bawah ada rincian torrent yang dipilih:

- **Ikhtisar**: nama, hash (v1 dan v2), ukuran, folder simpan, komentar,
  dan total. Tautan di komentar terbuka di peramban. Bilah di atas
  menunjukkan kepingan: setiap kepingan yang terunduh diwarnai di tempatnya
  dalam torrent. Kepingan datang tidak berurutan (yang paling langka
  dulu), jadi torrent yang sedang berjalan memiliki celah.
- **Berkas**: berkas dan folder beserta kemajuannya. Klik kanan untuk
  mengatur prioritas atau melewati berkas; klik ganda membuka berkas yang
  sudah terunduh.
- **Rekan**: peer yang terhubung dengan negara, klien, kecepatan, dan
  bendera koneksi yang ditulis dengan kata-kata.
- **Pelacak**: status tracker, seeder dan leecher yang dilaporkan, serta
  pengumuman berikutnya. Klik kanan untuk menambah, menghapus, atau
  mengumumkan ulang.

Bilah status menampilkan jumlah torrent, node DHT, kecepatan saat ini,
apakah filter IP aktif, dan jumlah yang ditransfer dalam sesi ini. Menu
**Tampilan** menyembunyikan atau menampilkan panel rincian, bilah
status, dan konsol.


## Menambah torrent

- **Berkas > Tambah torrent** (Ctrl+O): pilih satu atau beberapa
  berkas `.torrent`.
- **Berkas > Tambah tautan magnet** (Ctrl+U): tempelkan tautan
  magnet, satu per baris.
- Buka berkas `.torrent` atau tautan magnet dengan `RePicoTorrent.exe`; jika
  program dari folder itu sudah berjalan, torrent diteruskan kepadanya.

Sebelum ditambahkan, Anda bisa memilih folder, berkas yang diinginkan, dan
label. Untuk langsung menambahkan torrent dengan pengaturan bawaan,
aktifkan **Lewati dialog 'Tambah torrent'** di preferensi.


## Mengelola torrent

Klik kanan pada satu atau beberapa torrent:

- **Lanjut**, **Lanjut (paksa)** (mengabaikan antrean), **Jeda**.
- **Paksa siar ulang**, **Paksa periksa ulang** (memeriksa data di disk).
- **Unduh berurutan**: mengunduh kepingan secara berurutan, berguna
  untuk menonton video sambil mengunduh.
- **Label**: memberi label.
- **Export**: tautan magnet atau berkas `.torrent`.
- **Pindah**: memindahkan data ke folder lain.
- **Hapus**: menghapus torrent (Del) atau torrent beserta berkasnya
  (Shift+Del).
- **Mengantrekan**: naik atau turun dalam antrean unduhan.
- **Salin info hash**, **Buka di Explorer**.


## Label

Label mengelompokkan torrent. Label dibuat di
**Preferensi > Label**:

- **Warna**: warna label; dengan
  **Gunakan warna label sebagai warna latar di dalam daftar torrent** (**Umum**)
  baris-baris diwarnai dengannya.
- **Lokasi penyimpanan**: torrent dengan label ini disimpan di sini.
- **Terapkan filter**: ekspresi reguler; torrent baru yang namanya cocok
  otomatis mendapat label ini. Contoh: `ubuntu|debian|fedora`.

**Tampilan > Label** hanya menampilkan torrent dengan satu label.


## Filter dan konsol

**Tampilan > Filter** berisi filter tersimpan, misalnya torrent
yang sedang mengunduh sekarang. **Tampilan > Konsol** membuka
baris di bawah daftar: ketik kueri dan tekan Enter untuk menampilkan
hanya torrent yang cocok; kosongkan untuk menampilkan semuanya lagi.

| Bidang | Jenis | Arti |
|---|---|---|
| `name` | teks | nama torrent |
| `label` | teks | nama label |
| `status` | teks | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | angka | persen selesai |
| `size` | ukuran | ukuran yang diinginkan: `b` (bawaan), `kb`, `mb`, `gb` |
| `dl`, `ul` | kecepatan | bita per detik (bawaan), `kbps`, `mbps`, `gbps` |

Operator: `=`, `<`, `<=`, `>`, `>=`, dan `~` (mengandung, tanpa membedakan
huruf besar-kecil), digabung dengan `and` dan `or`. Teks ditulis dalam
tanda kutip ganda, satuan dengan huruf kecil.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Membuat torrent

**Berkas > Buat torrent**:

![Buat torrent](images/en-US/create-torrent.png)

- Pilih berkas atau folder.
- **Mode**: v1, v2, atau hibrida v1 + v2. Hibrida bekerja dengan semua
  klien dan menjadi bawaan.
- **Komentar** dan **Pembuat** boleh dikosongkan.
- **Privat**: peer hanya datang dari tracker, tidak dari DHT, PeX, atau
  penemuan lokal.
- **Tambahkan ke sesi**: langsung mulai membagikan torrent baru.
- **Pelacak (satu per baris)**: setiap tracker masuk ke tingkatnya
  sendiri; tingkat dicoba secara berurutan.
- **URL berbagi (satu per baris)**: server web dengan data yang sama. Untuk
  folder, URL harus menunjuk ke folder yang memuatnya.


## Preferensi

**Tampilan > Preferensi**. **Kembalikan ke bawaan** mengatur
ulang semua pengaturan. Beberapa perubahan (bahasa, tema, port) perlu
mulai ulang; program akan menawarkannya.

### Umum

![Umum](images/en-US/preferences-general.png)

- **Bahasa** dan **Theme** (sistem atau terang; tema gelap
  mengikuti pengaturan Windows).
- **Lewati dialog 'Tambah torrent'**, **Jalankan RePicoTorrent saat Windows dinyalakan**,
  **Posisi mulai** jendela.
- **Tampilkan RePicoTorrent di area notifikasi**, dan apakah meminimalkan
  atau menutup jendela menyembunyikannya di sana.

### Unduhan

![Unduhan](images/en-US/preferences-downloads.png)

- **Lokasi penyimpanan**, **Pindahkan unduhan yang sudah selesai** ke folder lain.
- **Jeda saat ruang diska rendah**.
- **Batasan**: batas unduh dan unggah dalam KB/s, berapa torrent yang
  boleh aktif bersamaan, dan jumlah total koneksi.

### Label

![Label](images/en-US/preferences-labels.png)

Lihat [Label](#label).

### Koneksi

![Koneksi](images/en-US/preferences-connection.png)

- **Antarmuka akses**: alamat dan port untuk koneksi masuk. `0.0.0.0`
  dan `[::]` berarti semua alamat IPv4 dan IPv6.
- **Enkripsi**: wajibkan enkripsi pada koneksi masuk atau keluar.
- **Privasi**: DHT, penemuan peer lokal (LSD), pertukaran peer (PeX),
  WebTorrent, dan kolom negara peer. Basis data negara (DB-IP Lite) diunduh
  sebulan sekali selama kolom itu aktif.
- **Filter IP**: blokir alamat dari filter berformat eMule dalam berkas
  zip, misalnya dari emule-security.org.

### Proksi

![Proksi](images/en-US/preferences-proxy.png)

Proksi HTTP atau SOCKS4/5, dengan atau tanpa kata sandi, dan apa yang
melewatinya: pencarian nama host, koneksi peer dan tracker.

### Lanjutan

![Lanjutan](images/en-US/preferences-advanced.png)

Semua pengaturan libtorrent. Pilih salah satu untuk membaca deskripsinya
di bawah daftar. Ubah hanya jika Anda tahu fungsinya;
**Kembalikan ke bawaan** akan mengembalikannya.


## Pindah dari PicoTorrent atau qBittorrent

- **Berkas > Import from PicoTorrent**: pilih `PicoTorrent.sqlite`
  (di samping PicoTorrent portabel atau di `%LOCALAPPDATA%\PicoTorrent`).
  Torrent dan labelnya ditambahkan; berkas hanya dibaca. Untuk memindahkan
  semuanya termasuk pengaturan, salin `PicoTorrent.sqlite` ke samping
  `RePicoTorrent.exe` sebelum menjalankan pertama kali: berkas akan diganti
  namanya menjadi `RePicoTorrent.sqlite`.
- **Berkas > Import from qBittorrent**: pilih folder `BT_backup`
  milik qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Kemajuan,
  tracker, penghitung, folder simpan, dan komentar dipertahankan.

Torrent yang sudah ada di daftar dilewati. Jangan membagikan torrent yang
sama dari kedua klien sekaligus.


## Pembaruan

Setiap kali dimulai, program menanyakan rilis terbaru ke GitHub, dan
**Bantuan > Periksa pembaruan** melakukannya kapan saja. Jika ada
versi yang lebih baru, **Download and install** mengunduh zip untuk Windows
Anda, memeriksanya dengan checksum SHA-256 dari rilis, mengganti berkas
program, lalu memulai ulang. Pengaturan dan torrent tetap ada.


## Pintasan papan ketik

| Tombol | Tindakan |
|---|---|
| Ctrl+O | tambah torrent |
| Ctrl+U | tambah tautan magnet |
| Ctrl+A | pilih semua torrent |
| Del | hapus torrent terpilih, simpan datanya |
| Shift+Del | hapus torrent terpilih beserta datanya |
| F1 | buka dokumentasi ini |


## Berkas dan baris perintah

Di samping `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: pengaturan, torrent, dan data lanjutannya;
- `coredb.sqlite`: terjemahan (bagian dari program);
- `logs`: berkas log;
- `Crashpad`: dump kerusakan, tidak pernah diunggah;
- `dbip-country-lite.mmdb`: basis data negara.

Baris perintah:

```
RePicoTorrent.exe [--silent] [--save-path=<folder>] [file.torrent | magnet:?xt=...]...
```

`--silent` menambahkan torrent yang diberikan tanpa jendela tambah,
`--save-path` menentukan tempat penyimpanannya.
