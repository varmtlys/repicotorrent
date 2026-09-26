# Tài liệu RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · **Tiếng Việt** · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Bắt đầu](#bắt-đầu)
- [Cửa sổ chính](#cửa-sổ-chính)
- [Thêm torrent](#thêm-torrent)
- [Quản lý torrent](#quản-lý-torrent)
- [Nhãn](#nhãn)
- [Bộ lọc và bảng điều khiển](#bộ-lọc-và-bảng-điều-khiển)
- [Tạo torrent](#tạo-torrent)
- [Tùy chọn](#tùy-chọn)
- [Chuyển từ PicoTorrent hoặc qBittorrent](#chuyển-từ-picotorrent-hoặc-qbittorrent)
- [Cập nhật](#cập-nhật)
- [Phím tắt](#phím-tắt)
- [Tệp và dòng lệnh](#tệp-và-dòng-lệnh)


## Bắt đầu

Tải tệp zip cho Windows của bạn từ
[trang phát hành](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` cho Windows 64 bit, `arm64` cho Windows trên ARM, `x86` cho Windows
32 bit. Giải nén vào bất kỳ thư mục nào bạn có quyền ghi và chạy
`RePicoTorrent.exe`. Không có gì được cài đặt: cài đặt, danh sách torrent
và nhật ký được lưu cạnh tệp exe, nên có thể di chuyển thư mục hoặc chép
sang USB.

Mỗi thư mục là một bản sao riêng của chương trình. Hai bản sao ở hai thư
mục khác nhau có thể chạy cùng lúc nếu dùng cổng khác nhau.


## Cửa sổ chính

![Cửa sổ chính](images/en-US/main.png)

Phía trên là danh sách torrent. Mỗi cột được sắp xếp khi bấm vào tiêu đề;
bấm chuột phải vào tiêu đề để hiện hoặc ẩn cột.

- **Progress** và **Done**: đã tải được bao nhiêu phần dữ liệu
  cần tải.
- **Hoàn thành trong**, **DL**, **UL**: thời gian còn lại, tốc độ tải xuống và
  tải lên.
- **Availability**: các peer đang kết nối có tổng cộng bao nhiêu bản
  sao đầy đủ.
- **Seeds**, **Peers**, **Leechers**: số đang kết nối, trong
  ngoặc là số trong toàn bộ swarm theo tracker.

Phía dưới là chi tiết của torrent đang chọn:

- **Overview**: tên, mã băm (v1 và v2), kích thước, thư mục lưu, ghi
  chú và tổng số. Liên kết trong ghi chú mở trong trình duyệt. Thanh ở
  trên hiển thị các mảnh: mỗi mảnh đã tải được tô màu tại vị trí của nó
  trong torrent. Các mảnh được tải không theo thứ tự (hiếm nhất trước),
  nên một torrent đang tải có những khoảng trống.
- **Files**: tệp và thư mục kèm tiến độ. Bấm chuột phải để đặt mức ưu
  tiên hoặc bỏ qua tệp; bấm đúp để mở tệp đã tải.
- **Peers**: các peer đang kết nối với quốc gia, phần mềm, tốc độ và cờ
  kết nối được viết bằng chữ.
- **Trackers**: trạng thái tracker, số seeder và leecher nó báo và lần
  thông báo tiếp theo. Bấm chuột phải để thêm, xóa hoặc thông báo lại.

Thanh trạng thái hiển thị số torrent, số nút DHT, tốc độ hiện tại, bộ lọc
IP có bật không và lượng đã truyền trong phiên. Menu **View** ẩn
hoặc hiện bảng chi tiết, thanh trạng thái và bảng điều khiển.


## Thêm torrent

- **File > Thêm file torrent** (Ctrl+O): chọn một hoặc nhiều tệp
  `.torrent`.
- **File > Add magnet link(s)** (Ctrl+U): dán liên kết magnet,
  mỗi dòng một liên kết.
- Mở tệp `.torrent` hoặc liên kết magnet bằng `RePicoTorrent.exe`; nếu
  chương trình từ thư mục đó đang chạy, torrent sẽ được chuyển cho nó.

Trước khi thêm, bạn có thể chọn thư mục, các tệp cần tải và nhãn. Để thêm
torrent ngay với cài đặt mặc định, bật **Bỏ qua cửa sổ "Thêm file torrent"**
trong phần tùy chọn.


## Quản lý torrent

Bấm chuột phải vào một hoặc nhiều torrent:

- **Tiếp tục**, **Buộc tiếp tục** (bỏ qua hàng đợi), **Tạm dừng**.
- **Force reannounce**, **Force recheck** (kiểm tra dữ liệu trên
  đĩa).
- **Sequential download**: tải các mảnh theo thứ tự, tiện để xem video
  khi đang tải.
- **Label**: gán nhãn.
- **Export**: liên kết magnet hoặc tệp `.torrent`.
- **Di chuyển tệp tin đến**: chuyển dữ liệu sang thư mục khác.
- **Xóa**: xóa torrent (Del) hoặc xóa torrent cùng các tệp
  (Shift+Del).
- **Queuing**: lên hoặc xuống trong hàng đợi tải.
- **Copy info hash**, **Mở thư mục chứa tệp tin**.


## Nhãn

Nhãn dùng để nhóm torrent. Nhãn được tạo trong
**Cài đặt > Labels**:

- **Color**: màu của nhãn; khi bật
  **Use label color as background in torrent list** (**Chung**),
  các dòng được tô bằng màu đó.
- **Đường dẫn thư mục lưu tệp**: torrent có nhãn này được lưu vào đây.
- **Apply filter**: một biểu thức chính quy; torrent mới có tên khớp sẽ
  tự động nhận nhãn này. Ví dụ: `ubuntu|debian|fedora`.

**View > Labels** chỉ hiện các torrent có một nhãn.


## Bộ lọc và bảng điều khiển

**View > Filter** có các bộ lọc đã lưu, ví dụ các torrent
đang tải ngay lúc này. **View > Console** mở một dòng dưới
danh sách: gõ truy vấn và nhấn Enter để chỉ hiện các torrent khớp; xóa
trống để hiện lại tất cả.

| Trường | Kiểu | Ý nghĩa |
|---|---|---|
| `name` | văn bản | tên torrent |
| `label` | văn bản | tên nhãn |
| `status` | văn bản | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | số | phần trăm hoàn thành |
| `size` | kích thước | kích thước cần tải: `b` (mặc định), `kb`, `mb`, `gb` |
| `dl`, `ul` | tốc độ | byte mỗi giây (mặc định), `kbps`, `mbps`, `gbps` |

Toán tử: `=`, `<`, `<=`, `>`, `>=` và `~` (chứa, không phân biệt hoa
thường), nối bằng `and` và `or`. Văn bản đặt trong ngoặc kép, đơn vị viết
thường.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Tạo torrent

**File > Create torrent**:

![Tạo torrent](images/en-US/create-torrent.png)

- Chọn một tệp hoặc thư mục.
- **Mode**: v1, v2 hoặc lai v1 + v2. Kiểu lai dùng được với mọi phần
  mềm và là mặc định.
- **Comment** và **Creator** có thể để trống.
- **Private**: peer chỉ đến từ tracker, không từ DHT, PeX hay tìm kiếm
  cục bộ.
- **Add to session**: bắt đầu chia sẻ torrent mới ngay.
- **Trackers (one per line)**: mỗi tracker vào một tầng riêng; các tầng
  được thử lần lượt.
- **URL seeds (one per line)**: máy chủ web có cùng dữ liệu. Với thư
  mục, URL phải trỏ đến thư mục chứa nó.


## Tùy chọn

**View > Cài đặt**. **Restore defaults** đặt lại mọi
cài đặt. Một số thay đổi (ngôn ngữ, giao diện, cổng) cần khởi động lại;
chương trình sẽ đề nghị.

### Chung

![Chung](images/en-US/preferences-general.png)

- **Ngôn ngữ** và **Theme** (hệ thống hoặc sáng; giao diện tối theo
  cài đặt của Windows).
- **Bỏ qua cửa sổ "Thêm file torrent"**, **Khởi động RePicoTorrent cùng Windows**,
  **Start position** của cửa sổ.
- **Show RePicoTorrent in notification area**, và việc thu nhỏ hoặc đóng
  cửa sổ có ẩn nó vào đó hay không.

### Tải xuống

![Tải xuống](images/en-US/preferences-downloads.png)

- **Đường dẫn thư mục lưu tệp**, **Move completed downloads** sang thư mục khác.
- **Pause when disk space is low**.
- **Limits**: giới hạn tải xuống và tải lên theo KB/s, số torrent được
  hoạt động cùng lúc và tổng số kết nối.

### Labels

![Nhãn](images/en-US/preferences-labels.png)

Xem [Nhãn](#nhãn).

### Connection

![Kết nối](images/en-US/preferences-connection.png)

- **Listen interface**: địa chỉ và cổng cho kết nối đến. `0.0.0.0` và
  `[::]` nghĩa là mọi địa chỉ IPv4 và IPv6.
- **Mã hóa**: yêu cầu mã hóa cho kết nối đến hoặc đi.
- **Privacy**: DHT, tìm peer cục bộ (LSD), trao đổi peer (PeX),
  WebTorrent và cột quốc gia của peer. Cơ sở dữ liệu quốc gia (DB-IP Lite)
  được tải mỗi tháng một lần khi cột này đang bật.
- **IP filter**: chặn địa chỉ từ bộ lọc định dạng eMule trong tệp zip,
  ví dụ từ emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP hoặc SOCKS4/5, có hoặc không có mật khẩu, và những gì đi qua
nó: phân giải tên, kết nối peer và tracker.

### Nâng cao

![Nâng cao](images/en-US/preferences-advanced.png)

Toàn bộ cài đặt của libtorrent. Chọn một mục để đọc mô tả bên dưới danh
sách. Chỉ thay đổi khi bạn biết chúng làm gì; **Restore defaults** sẽ
khôi phục chúng.


## Chuyển từ PicoTorrent hoặc qBittorrent

- **File > Import from PicoTorrent**: chọn `PicoTorrent.sqlite`
  (cạnh PicoTorrent bản di động hoặc trong `%LOCALAPPDATA%\PicoTorrent`).
  Torrent và nhãn của chúng được thêm vào; tệp chỉ được đọc. Để chuyển tất
  cả kể cả cài đặt, chép `PicoTorrent.sqlite` vào cạnh `RePicoTorrent.exe`
  trước lần chạy đầu: tệp sẽ được đổi tên thành `RePicoTorrent.sqlite`.
- **File > Import from qBittorrent**: chọn thư mục `BT_backup`
  của qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Tiến độ,
  tracker, bộ đếm, thư mục lưu và ghi chú được giữ nguyên.

Các torrent đã có trong danh sách sẽ được bỏ qua. Đừng chia sẻ cùng một
torrent từ cả hai phần mềm cùng lúc.


## Cập nhật

Mỗi lần khởi động, chương trình hỏi GitHub về bản phát hành mới nhất, còn
**Help > Kiểm tra cập nhật** kiểm tra bất kỳ lúc nào. Nếu có
phiên bản mới hơn, **Download and install** tải tệp zip cho Windows của bạn,
kiểm tra bằng tổng kiểm SHA-256 của bản phát hành, thay các tệp chương
trình và khởi động lại. Cài đặt và torrent vẫn giữ nguyên.


## Phím tắt

| Phím | Tác vụ |
|---|---|
| Ctrl+O | thêm torrent |
| Ctrl+U | thêm liên kết magnet |
| Ctrl+A | chọn tất cả torrent |
| Del | xóa các torrent đã chọn, giữ dữ liệu |
| Shift+Del | xóa các torrent đã chọn cùng dữ liệu |
| F1 | mở tài liệu này |


## Tệp và dòng lệnh

Cạnh `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: cài đặt, torrent và dữ liệu tiếp tục;
- `coredb.sqlite`: bản dịch (một phần của chương trình);
- `logs`: tệp nhật ký;
- `Crashpad`: bản ghi sự cố, không bao giờ được gửi đi;
- `dbip-country-lite.mmdb`: cơ sở dữ liệu quốc gia.

Dòng lệnh:

```
RePicoTorrent.exe [--silent] [--save-path=<thư mục>] [file.torrent | magnet:?xt=...]...
```

`--silent` thêm các torrent được chỉ định mà không mở cửa sổ thêm,
`--save-path` chỉ định nơi lưu chúng.
