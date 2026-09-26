# RePicoTorrent 說明文件

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · **繁體中文**

- [開始使用](#開始使用)
- [主視窗](#主視窗)
- [新增種子](#新增種子)
- [管理種子](#管理種子)
- [標籤](#標籤)
- [過濾器與主控台](#過濾器與主控台)
- [建立種子](#建立種子)
- [偏好設定](#偏好設定)
- [從 PicoTorrent 或 qBittorrent 轉移](#從-picotorrent-或-qbittorrent-轉移)
- [更新](#更新)
- [鍵盤快速鍵](#鍵盤快速鍵)
- [檔案與命令列](#檔案與命令列)


## 開始使用

從[發行頁面](https://github.com/varmtlys/repicotorrent/releases/latest)下載適合你的
Windows 的 zip：`x64` 用於 64 位元 Windows，`arm64` 用於 ARM 版 Windows，`x86`
用於 32 位元 Windows。將它解壓縮到任何有寫入權限的資料夾，然後執行
`RePicoTorrent.exe`。程式不需要安裝：設定、種子清單和記錄檔都存放在 exe
旁邊，因此可以搬移資料夾或複製到隨身碟。

每個資料夾都是程式的獨立副本。不同資料夾中的兩個副本只要使用不同的連接埠就能同時執行。


## 主視窗

![主視窗](images/en-US/main.png)

上方是種子清單。按一下欄位標題即可排序；在標題上按右鍵可以顯示或隱藏欄位。

- **進度** 和 **Done**：需要的資料已下載多少。
- **剩餘時間**、**下載速度**、**上傳速度**：剩餘時間、下載與上傳速度。
- **Availability**：已連線的用戶合計擁有幾份完整副本。
- **Seeds**、**Peers**、**Leechers**：已連線的數量，括號內是 Tracker
  回報的整個群集中的數量。

下方顯示所選種子的詳細資訊：

- **Overview**：名稱、雜湊值（v1 和 v2）、大小、儲存路徑、註解與合計。
  註解中的連結會在瀏覽器中開啟。頂端的長條顯示各個區塊：每個已下載的區塊都會在它於種子中的位置著色。
  區塊不是依序下載（最稀有的優先），所以下載中的種子會有空隙。
- **Files**：檔案和資料夾及其進度。按右鍵可設定優先順序或略過檔案；按兩下開啟已下載的檔案。
- **Peers**：已連線的用戶，顯示國家、用戶端、速度，以及用文字寫出的連線旗標。
- **Trackers**：Tracker 狀態、它回報的做種者與下載者數量以及下次宣告時間。按右鍵可新增、移除或重新宣告。

狀態列顯示種子數量、DHT 節點數、目前速度、IP 過濾器是否開啟以及本次工作階段的傳輸量。
**查看** 選單可以隱藏或顯示詳細資訊面板、狀態列與主控台。


## 新增種子

- **檔案 > 添加種子**（Ctrl+O）：選擇一或多個 `.torrent` 檔案。
- **檔案 > Add magnet link(s)**（Ctrl+U）：貼上磁力連結，每行一個。
- 用 `RePicoTorrent.exe` 開啟 `.torrent` 檔案或磁力連結；若該資料夾中的程式已在執行，種子會交給它。

新增前可以選擇儲存路徑、要下載的檔案和標籤。若要直接以預設設定新增種子，請在偏好設定中開啟
**Skip 'Add torrent' dialog**。


## 管理種子

在一或多個種子上按右鍵：

- **繼續下載**、**繼續下載(強制)**（忽略佇列）、**暫停**。
- **Force reannounce**、**Force recheck**（檢查磁碟上的資料）。
- **Sequential download**：依序下載區塊，方便邊下載邊看影片。
- **Label**：設定標籤。
- **Export**：磁力連結或 `.torrent` 檔案。
- **移動**：將資料移到另一個資料夾。
- **刪除**：移除種子（Del），或連同檔案一起移除（Shift+Del）。
- **Queuing**：在下載佇列中上移或下移。
- **複製雜湊信息**、**在檔案總管中打開**。


## 標籤

標籤用來將種子分組，在 **偏好設定 > Labels** 中建立：

- **Color**：標籤顏色；在 **General** 中開啟
  **Use label color as background in torrent list** 後，各列會以此顏色顯示。
- **儲存路徑**：帶有此標籤新增的種子會儲存在這裡。
- **Apply filter**：一個規則運算式；名稱符合的新種子會自動取得此標籤。例如：
  `ubuntu|debian|fedora`。

**查看 > Labels** 只顯示某個標籤的種子。


## 過濾器與主控台

**查看 > Filter** 中有已儲存的過濾器，例如目前正在下載的種子。
**查看 > Console** 會在清單下方開啟一行：輸入查詢並按 Enter，只顯示符合的種子；清空即可再次顯示全部。

| 欄位 | 類型 | 意義 |
|---|---|---|
| `name` | 文字 | 種子名稱 |
| `label` | 文字 | 標籤名稱 |
| `status` | 文字 | `downloading`、`seeding`、`uploading`、`paused`、`queued`、`error` |
| `progress` | 數字 | 完成百分比 |
| `size` | 大小 | 需要的大小：`b`（預設）、`kb`、`mb`、`gb` |
| `dl`、`ul` | 速度 | 位元組每秒（預設）、`kbps`、`mbps`、`gbps` |

運算子：`=`、`<`、`<=`、`>`、`>=` 和 `~`（包含，不分大小寫），以 `and` 和 `or`
連接。文字放在雙引號中，單位使用小寫。

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## 建立種子

**檔案 > Create torrent**：

![建立種子](images/en-US/create-torrent.png)

- 選擇檔案或資料夾。
- **Mode**：v1、v2 或 v1 + v2 混合。混合模式相容所有用戶端，是預設選項。
- **Comment** 和 **Creator** 可以留空。
- **Private**：只從 Tracker 取得用戶，不使用 DHT、PeX 或本機探索。
- **Add to session**：立即開始做種。
- **Trackers (one per line)**：每個 Tracker 自成一層，依序嘗試。
- **URL seeds (one per line)**：擁有相同資料的網頁伺服器。若為資料夾，URL 必須指向包含它的資料夾。


## 偏好設定

**查看 > 偏好設定**。**Restore defaults** 會重設所有設定。
部分變更（語言、佈景主題、連接埠）需要重新啟動，程式會提示。

### General

![一般](images/en-US/preferences-general.png)

- **Language** 和 **Theme**（跟隨系統或淺色；深色佈景主題跟隨 Windows 設定）。
- **Skip 'Add torrent' dialog**、**Start RePicoTorrent with Windows**、視窗的 **Start position**。
- **Show RePicoTorrent in notification area**，以及最小化或關閉視窗時是否隱藏到那裡。

### 下載

![下載](images/en-US/preferences-downloads.png)

- **儲存路徑**、**Move completed downloads** 到另一個資料夾。
- **Pause when disk space is low**。
- **Limits**：以 KB/s 為單位的下載與上傳速度限制、可同時作用中的種子數以及連線總數。

### Labels

![標籤](images/en-US/preferences-labels.png)

請參閱[標籤](#標籤)。

### Connection

![連線](images/en-US/preferences-connection.png)

- **偵聽界面**：接受傳入連線的位址和連接埠。`0.0.0.0` 和 `[::]` 代表所有 IPv4 和 IPv6 位址。
- **Encryption**：要求傳入或傳出連線加密。
- **Privacy**：DHT、本機用戶探索（LSD）、用戶交換（PeX）、WebTorrent 以及用戶國家欄位。
  開啟國家欄位時，國家資料庫（DB-IP Lite）每月下載一次。
- **IP filter**：封鎖 zip 檔中 eMule 格式過濾器所列的位址，例如來自 emule-security.org 的過濾器。

### 代理伺服器

![Proxy](images/en-US/preferences-proxy.png)

HTTP 或 SOCKS4/5 Proxy，可帶密碼，以及哪些流量經過 Proxy：主機名稱解析、用戶連線和 Tracker 連線。

### Advanced

![進階](images/en-US/preferences-advanced.png)

libtorrent 的所有設定。選取一項即可在清單下方閱讀說明。只有在了解其作用時才修改；
**Restore defaults** 可以還原。


## 從 PicoTorrent 或 qBittorrent 轉移

- **檔案 > Import from PicoTorrent**：選擇 `PicoTorrent.sqlite`
  （位於可攜式 PicoTorrent 旁邊，或 `%LOCALAPPDATA%\PicoTorrent` 中）。種子及其標籤會被新增；
  該檔案只會被讀取。若要連同設定全部轉移，請在第一次啟動前將 `PicoTorrent.sqlite` 複製到
  `RePicoTorrent.exe` 旁邊：它會被重新命名為 `RePicoTorrent.sqlite`。
- **檔案 > Import from qBittorrent**：選擇 qBittorrent 的 `BT_backup` 資料夾
  （`%LOCALAPPDATA%\qBittorrent\BT_backup`）。進度、Tracker、計數、儲存路徑和註解都會保留。

清單中已有的種子會被略過。不要同時用兩個用戶端為相同的種子做種。


## 更新

每次啟動時程式會向 GitHub 查詢最新版本，**幫助 > 檢查更新**
則可隨時檢查。若有新版本，**Download and install** 會下載適合你的 Windows 的 zip，
以發行中的 SHA-256 總和檢查碼驗證，取代程式檔案並重新啟動。設定與種子都會保留。


## 鍵盤快速鍵

| 按鍵 | 動作 |
|---|---|
| Ctrl+O | 新增種子 |
| Ctrl+U | 新增磁力連結 |
| Ctrl+A | 選取所有種子 |
| Del | 移除所選種子，保留資料 |
| Shift+Del | 移除所選種子及其資料 |
| F1 | 開啟本說明文件 |


## 檔案與命令列

`RePicoTorrent.exe` 旁邊：

- `RePicoTorrent.sqlite`：設定、種子及其續傳資料；
- `coredb.sqlite`：翻譯（程式的一部分）；
- `logs`：記錄檔；
- `Crashpad`：當機傾印，從不上傳；
- `dbip-country-lite.mmdb`：國家資料庫。

命令列：

```
RePicoTorrent.exe [--silent] [--save-path=<資料夾>] [file.torrent | magnet:?xt=...]...
```

`--silent` 會略過新增對話方塊直接新增指定的種子，`--save-path` 指定儲存位置。
