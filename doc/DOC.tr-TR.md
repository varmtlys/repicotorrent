# RePicoTorrent belgeleri

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · **Türkçe** · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Başlarken](#başlarken)
- [Ana pencere](#ana-pencere)
- [Torrent ekleme](#torrent-ekleme)
- [Torrentleri yönetme](#torrentleri-yönetme)
- [Etiketler](#etiketler)
- [Filtreler ve konsol](#filtreler-ve-konsol)
- [Torrent oluşturma](#torrent-oluşturma)
- [Tercihler](#tercihler)
- [PicoTorrent veya qBittorrent'ten geçiş](#picotorrent-veya-qbittorrentten-geçiş)
- [Güncellemeler](#güncellemeler)
- [Klavye kısayolları](#klavye-kısayolları)
- [Dosyalar ve komut satırı](#dosyalar-ve-komut-satırı)


## Başlarken

Windows'unuza uygun zip dosyasını
[sürümler sayfasından](https://github.com/varmtlys/repicotorrent/releases/latest)
indirin: 64 bit Windows için `x64`, ARM üzerinde Windows için `arm64`,
32 bit Windows için `x86`. Yazma izniniz olan herhangi bir klasöre açın ve
`RePicoTorrent.exe` dosyasını çalıştırın. Hiçbir şey kurulmaz: ayarlar,
torrent listesi ve günlükler exe'nin yanında tutulur, bu yüzden klasör
taşınabilir veya bir USB belleğe kopyalanabilir.

Her klasör programın ayrı bir kopyasıdır. Farklı klasörlerdeki iki kopya
farklı bağlantı noktaları kullanırsa aynı anda çalışabilir.


## Ana pencere

![Ana pencere](images/en-US/main.png)

Üstte torrent listesi bulunur. Her sütun başlığına tıklanarak sıralanır;
başlıklara sağ tıklamak sütunları gösterir veya gizler.

- **İlerleme** ve **Done**: istenen verinin ne kadarının indiği.
- **Kalan Süre**, **İndirme**, **Yükleme**: kalan süre, indirme ve gönderme hızı.
- **Ulaşılabilirlik**: bağlı eşlerin birlikte kaç tam kopyası olduğu.
- **Seed**, **Eşler**, **Leechers**: bağlı olanlar, parantez
  içinde izleyicilere göre tüm sürüdeki sayı.

Altta seçili torrentin ayrıntıları görünür:

- **Genel Görünüm**: ad, özetler (v1 ve v2), boyut, kayıt klasörü, açıklama
  ve toplamlar. Açıklamadaki bağlantılar tarayıcıda açılır. Üstteki çubuk
  parçaları gösterir: inen her parça torrentteki yerinde boyanır. Parçalar
  sırasız gelir (önce en nadir olanlar), bu yüzden devam eden bir
  torrentte boşluklar olur.
- **Dosyalar**: dosyalar ve klasörler ile ilerlemeleri. Sağ tıklayarak
  öncelik verin veya bir dosyayı atlayın; çift tıklama inmiş bir dosyayı
  açar.
- **Eşler**: bağlı eşler; ülke, istemci, hızlar ve kelimelerle yazılmış
  bağlantı bayraklarıyla.
- **İzleyiciler (trackerlar)**: izleyici durumu, bildirdiği gönderici ve indiriciler ve
  sonraki duyuru. Eklemek, kaldırmak veya yeniden duyurmak için sağ
  tıklayın.

Durum çubuğu torrent sayısını, DHT düğümlerini, anlık hızları, IP
filtresinin açık olup olmadığını ve bu oturumda aktarılan miktarı
gösterir. **Görünüm** menüsü ayrıntı panelini, durum çubuğunu ve
konsolu gizler veya gösterir.


## Torrent ekleme

- **Dosya > Torrent ekle** (Ctrl+O): bir veya daha fazla
  `.torrent` dosyası seçin.
- **Dosya > Magnet link(ler) ekle** (Ctrl+U): magnet
  bağlantılarını satır başına bir tane yapıştırın.
- Bir `.torrent` dosyasını veya magnet bağlantısını `RePicoTorrent.exe`
  ile açın; o klasördeki program zaten çalışıyorsa torrent ona iletilir.

Eklemeden önce kayıt klasörünü, istenen dosyaları ve bir etiketi
seçebilirsiniz. Torrentleri varsayılan ayarlarla hemen eklemek için
tercihlerde **'Torrent ekle' diyaloğunu atla** seçeneğini açın.


## Torrentleri yönetme

Bir veya birkaç torrente sağ tıklayın:

- **Devam Ettir**, **Devam Ettir (zorla)** (kuyruğu yok sayar), **Duraklat**.
- **Force reannounce**, **Tekrar kontrole zorla** (diskteki verileri
  doğrular).
- **Ardışık indirme**: parçaları sırayla indirir, bir videoyu inerken
  izlemek için kullanışlıdır.
- **Etiket**: etiket atama.
- **Dışa aktar**: magnet bağlantısı veya `.torrent` dosyası.
- **Taşı**: verileri başka bir klasöre taşıma.
- **Sil**: torrenti kaldırma (Del) veya torrenti dosyalarıyla
  birlikte kaldırma (Shift+Del).
- **Kuyruğa alınıyor**: indirme kuyruğunda yukarı veya aşağı.
- **Info-Hash kopyala**, **Dosya yöneticisi ile aç**.


## Etiketler

Etiketler torrentleri gruplar. **Tercihler > Etiketler** içinde
oluşturulur:

- **Renk**: etiketin rengi; **Genel** sayfasında
  **Etiket renklerini torrent listesinde arkaplan olarak kullan** açıksa satırlar bu
  renge boyanır.
- **İndirme Yeri**: bu etiketle eklenen torrentler buraya kaydedilir.
- **Filtreyi uygula**: bir düzenli ifade; adı buna uyan yeni torrent bu
  etiketi otomatik alır. Örnek: `ubuntu|debian|fedora`.

**Görünüm > Etiketler** yalnızca bir etiketin torrentlerini gösterir.


## Filtreler ve konsol

**Görünüm > Filtre** kayıtlı filtreler içerir, örneğin şu anda
inen torrentler. **Görünüm > Konsol** listenin altında bir satır
açar: bir sorgu yazıp Enter'a basın, yalnızca eşleşen torrentler kalsın;
tümünü yeniden görmek için satırı temizleyin.

| Alan | Tür | Anlamı |
|---|---|---|
| `name` | metin | torrent adı |
| `label` | metin | etiket adı |
| `status` | metin | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | sayı | tamamlanma yüzdesi |
| `size` | boyut | istenen boyut: `b` (varsayılan), `kb`, `mb`, `gb` |
| `dl`, `ul` | hız | saniyede bayt (varsayılan), `kbps`, `mbps`, `gbps` |

İşleçler: `=`, `<`, `<=`, `>`, `>=` ve `~` (içerir, büyük-küçük harf
duyarsız), `and` ve `or` ile birleştirilir. Metin çift tırnak içinde,
birimler küçük harfle yazılır.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Torrent oluşturma

**Dosya > Torrent oluştur**:

![Torrent oluştur](images/en-US/create-torrent.png)

- Bir dosya veya klasör seçin.
- **Mod**: v1, v2 veya v1 + v2 karma. Karma her istemciyle çalışır ve
  varsayılandır.
- **Yorum** ve **Oluşturucu** isteğe bağlıdır.
- **Özel**: eşler yalnızca izleyicilerden gelir; DHT, PeX veya yerel
  keşiften gelmez.
- **Oturuma ekle**: yeni torrenti hemen paylaşmaya başlar.
- **İzleyiciler (satır başına bir tane)**: her izleyici kendi katmanına girer;
  katmanlar sırayla denenir.
- **URL seedleri (satır başına bir tane)**: aynı verileri barındıran web
  sunucuları. Bir klasör için adres, onu içeren klasörü göstermelidir.


## Tercihler

**Görünüm > Tercihler**. **Varsayılanları geri yükle** tüm ayarları
sıfırlar. Bazı değişiklikler (dil, tema, bağlantı noktaları) yeniden
başlatma gerektirir; program bunu önerir.

### Genel

![Genel](images/en-US/preferences-general.png)

- **Dil** ve **Theme** (sistem veya açık; koyu tema Windows
  ayarını izler).
- **'Torrent ekle' diyaloğunu atla**, **RePicoTorrent'i Windows ile beraber başlat**, pencerenin
  **Başlangıç Durumu** ayarı.
- **RePicoTorrent'i bildirim alanında göster** ve pencereyi küçültmenin
  veya kapatmanın onu oraya gizleyip gizlemeyeceği.

### İndirmeler

![İndirmeler](images/en-US/preferences-downloads.png)

- **İndirme Yeri**, **Tamamlanmış indirmeleri taşı** başka bir klasöre.
- **Diskte az yer kaldığında duraklat**.
- **Limit**: KB/s cinsinden indirme ve gönderme sınırları, aynı anda
  kaç torrentin etkin olabileceği ve toplam bağlantı sayısı.

### Etiketler

![Etiketler](images/en-US/preferences-labels.png)

Bkz. [Etiketler](#etiketler).

### Bağlantı

![Bağlantı](images/en-US/preferences-connection.png)

- **Listen Interface**: gelen bağlantılar için adresler ve bağlantı
  noktaları. `0.0.0.0` ve `[::]` tüm IPv4 ve IPv6 adresleri anlamına gelir.
- **Şifreleme**: gelen veya giden bağlantılarda şifreleme zorunlu
  kılma.
- **Gizlilik**: DHT, yerel eş keşfi (LSD), eş değişimi (PeX), WebTorrent
  ve eş ülkesi sütunu. Ülke veritabanı (DB-IP Lite), sütun açık olduğu
  sürece ayda bir indirilir.
- **IP filtresi**: zip içindeki eMule biçimli bir filtredeki adresleri
  engelleme, örneğin emule-security.org'dan.

### Proxy

![Vekil sunucu](images/en-US/preferences-proxy.png)

Parolalı veya parolasız HTTP ya da SOCKS4/5 vekil sunucu ve üzerinden
nelerin geçeceği: ad çözümleme, eş ve izleyici bağlantıları.

### Gelişmiş

![Gelişmiş](images/en-US/preferences-advanced.png)

Tüm libtorrent ayarları. Açıklamasını listenin altında okumak için birini
seçin. Ne yaptıklarını bilmiyorsanız değiştirmeyin;
**Varsayılanları geri yükle** onları geri getirir.


## PicoTorrent veya qBittorrent'ten geçiş

- **Dosya > Import from PicoTorrent**: `PicoTorrent.sqlite`
  dosyasını seçin (taşınabilir bir PicoTorrent'in yanında veya
  `%LOCALAPPDATA%\PicoTorrent` içinde). Torrentler ve etiketleri eklenir;
  dosya yalnızca okunur. Ayarlar dahil her şeyi almak için ilk
  başlatmadan önce `PicoTorrent.sqlite` dosyasını `RePicoTorrent.exe`
  yanına kopyalayın: adı `RePicoTorrent.sqlite` olarak değiştirilir.
- **Dosya > Import from qBittorrent**: qBittorrent'in `BT_backup`
  klasörünü seçin (`%LOCALAPPDATA%\qBittorrent\BT_backup`). İlerleme,
  izleyiciler, sayaçlar, klasörler ve açıklamalar korunur.

Listede zaten olan torrentler atlanır. Aynı torrentleri iki istemciden aynı
anda paylaşmayın.


## Güncellemeler

Program her başlatıldığında GitHub'a en son sürümü sorar, **Yardım >
Yeni sürümü kontrol et** ise bunu istediğiniz an yapar. Daha yeni bir
sürüm varsa **Download and install**, Windows'unuza uygun zip dosyasını
indirir, sürümün SHA-256 sağlama toplamlarıyla doğrular, program
dosyalarını değiştirir ve programı yeniden başlatır. Ayarlar ve
torrentler kalır.


## Klavye kısayolları

| Tuşlar | Eylem |
|---|---|
| Ctrl+O | torrent ekle |
| Ctrl+U | magnet bağlantıları ekle |
| Ctrl+A | tüm torrentleri seç |
| Del | seçili torrentleri kaldır, verileri koru |
| Shift+Del | seçili torrentleri verileriyle birlikte kaldır |
| F1 | bu belgeleri aç |


## Dosyalar ve komut satırı

`RePicoTorrent.exe` yanında:

- `RePicoTorrent.sqlite`: ayarlar, torrentler ve devam verileri;
- `coredb.sqlite`: çeviriler (programın parçası);
- `logs`: günlük dosyaları;
- `Crashpad`: çökme dökümleri, asla gönderilmez;
- `dbip-country-lite.mmdb`: ülke veritabanı.

Komut satırı:

```
RePicoTorrent.exe [--silent] [--save-path=<klasör>] [file.torrent | magnet:?xt=...]...
```

`--silent` verilen torrentleri ekleme penceresi olmadan ekler,
`--save-path` nereye kaydedileceklerini belirler.
