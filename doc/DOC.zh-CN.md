# RePicoTorrent 文档

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · **简体中文** · [繁體中文](DOC.zh-TW.md)

- [快速开始](#快速开始)
- [主窗口](#主窗口)
- [添加种子](#添加种子)
- [管理种子](#管理种子)
- [标签](#标签)
- [过滤器和控制台](#过滤器和控制台)
- [创建种子](#创建种子)
- [首选项](#首选项)
- [从 PicoTorrent 或 qBittorrent 迁移](#从-picotorrent-或-qbittorrent-迁移)
- [更新](#更新)
- [键盘快捷键](#键盘快捷键)
- [文件和命令行](#文件和命令行)


## 快速开始

从[发布页面](https://github.com/varmtlys/repicotorrent/releases/latest)下载适合你的
Windows 的 zip：`x64` 用于 64 位 Windows，`arm64` 用于 ARM 版 Windows，`x86`
用于 32 位 Windows。把它解压到任何有写入权限的文件夹，然后运行
`RePicoTorrent.exe`。程序不需要安装：设置、种子列表和日志都保存在 exe
旁边，因此可以移动文件夹或复制到 U 盘。

每个文件夹都是程序的独立副本。不同文件夹中的两个副本只要使用不同端口就能同时运行。


## 主窗口

![主窗口](images/en-US/main.png)

上方是种子列表。点击列标题即可排序；右键点击标题可以显示或隐藏列。

- **进度** 和 **Done**：所需数据已下载的比例。
- **剩余时间**、**下载速度**、**上传速度**：剩余时间、下载和上传速度。
- **可用性**：已连接的用户合计拥有多少份完整副本。
- **种子**、**用户**、**Leechers**：已连接的数量，括号内是 Tracker
  报告的整个群体中的数量。

下方显示所选种子的详细信息：

- **概述**：名称、哈希值（v1 和 v2）、大小、保存路径、注释和合计。
  注释中的链接会在浏览器中打开。顶部的条显示各个分块：每个已下载的分块都会在它在种子中的位置上着色。
  分块不是按顺序下载的（最稀有的优先），所以下载中的种子会有空隙。
- **文件**：文件和文件夹及其进度。右键可设置优先级或跳过文件；双击打开已下载的文件。
- **用户**：已连接的用户，显示国家、客户端、速度，以及用文字写出的连接标志。
- **Trackers**：Tracker 状态、它报告的做种者和下载者数量以及下次汇报时间。右键可添加、删除或重新汇报。

状态栏显示种子数量、DHT 节点数、当前速度、IP 过滤器是否开启以及本次会话的传输量。
**查看** 菜单可以隐藏或显示详细信息面板、状态栏和控制台。


## 添加种子

- **文件 > 添加种子**（Ctrl+O）：选择一个或多个 `.torrent` 文件。
- **文件 > 添加磁力链接**（Ctrl+U）：粘贴磁力链接，每行一个。
- 用 `RePicoTorrent.exe` 打开 `.torrent` 文件或磁力链接；如果该文件夹中的程序已在运行，种子会交给它。

添加前可以选择保存路径、要下载的文件和标签。若要直接以默认设置添加种子，请在首选项中开启
**跳过'添加种子'对话框**。


## 管理种子

右键点击一个或多个种子：

- **继续**、**继续 (强制)**（忽略队列）、**暂停**。
- **强制发布**、**强制再次核对**（校验磁盘上的数据）。
- **逐个下载**：按顺序下载分块，便于边下边看视频。
- **标签**：设置标签。
- **导出**：磁力链接或 `.torrent` 文件。
- **移动**：把数据移到另一个文件夹。
- **删除**：删除种子（Del），或连同文件一起删除（Shift+Del）。
- **队列**：在下载队列中上移或下移。
- **复制哈希值**、**在文件管理器中打开**。


## 标签

标签用于给种子分组，在 **设置 > 标签** 中创建：

- **Color**：标签颜色；在 **普通** 中开启
  **Use label color as background in torrent list** 后，行会以此颜色显示。
- **保存路径**：带此标签添加的种子保存在这里。
- **Apply filter**：一个正则表达式；名称与之匹配的新种子会自动获得此标签。例如：
  `ubuntu|debian|fedora`。

**查看 > 标签** 只显示某个标签的种子。


## 过滤器和控制台

**查看 > 筛选** 中有已保存的过滤器，例如当前正在下载的种子。
**查看 > Console** 会在列表下方打开一行：输入查询并按 Enter，只显示匹配的种子；清空即可重新显示全部。

| 字段 | 类型 | 含义 |
|---|---|---|
| `name` | 文本 | 种子名称 |
| `label` | 文本 | 标签名称 |
| `status` | 文本 | `downloading`、`seeding`、`uploading`、`paused`、`queued`、`error` |
| `progress` | 数字 | 完成百分比 |
| `size` | 大小 | 所需大小：`b`（默认）、`kb`、`mb`、`gb` |
| `dl`、`ul` | 速度 | 字节每秒（默认）、`kbps`、`mbps`、`gbps` |

运算符：`=`、`<`、`<=`、`>`、`>=` 和 `~`（包含，不区分大小写），用 `and` 和 `or`
连接。文本放在双引号中，单位用小写。

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## 创建种子

**文件 > 创建种子(C)**：

![创建种子](images/en-US/create-torrent.png)

- 选择文件或文件夹。
- **模式**：v1、v2 或 v1 + v2 混合。混合模式兼容所有客户端，是默认选项。
- **注释** 和 **创建者** 可以不填。
- **私有**：只从 Tracker 获取用户，不使用 DHT、PeX 或本地发现。
- **Add to session**：立即开始做种。
- **Trackers (每行一个)**：每个 Tracker 单独一层，按顺序尝试。
- **URL做种地址 (每行一个)**：拥有相同数据的 Web 服务器。对于文件夹，URL 必须指向包含它的文件夹。


## 首选项

**查看 > 设置**。**恢复初始设置** 会重置所有设置。
部分更改（语言、主题、端口）需要重启，程序会提示。

### 普通

![常规](images/en-US/preferences-general.png)

- **语言** 和 **Theme**（跟随系统或浅色；深色主题跟随 Windows 设置）。
- **跳过'添加种子'对话框**、**随系统启动RePicoTorrent**、窗口的 **启动后位置**。
- **在通知区域显示RePicoTorrent**，以及最小化或关闭窗口时是否隐藏到那里。

### 下载

![下载](images/en-US/preferences-downloads.png)

- **保存路径**、**移动下载完成的** 到另一个文件夹。
- **当磁盘空间不足时暂停**。
- **限速**：以 KB/s 为单位的下载和上传限速、可同时活动的种子数以及连接总数。

### 标签

![标签](images/en-US/preferences-labels.png)

参见[标签](#标签)。

### 连接

![连接](images/en-US/preferences-connection.png)

- **监听端口**：接受传入连接的地址和端口。`0.0.0.0` 和 `[::]` 表示所有 IPv4 和 IPv6 地址。
- **加密**：要求传入或传出连接加密。
- **隐私**：DHT、本地用户发现（LSD）、用户交换（PeX）、WebTorrent 以及用户国家列。
  开启国家列时，国家数据库（DB-IP Lite）每月下载一次。
- **IP过滤器**：屏蔽 zip 文件中 eMule 格式过滤器列出的地址，例如来自 emule-security.org 的过滤器。

### 代理

![代理](images/en-US/preferences-proxy.png)

HTTP 或 SOCKS4/5 代理，可带密码，以及哪些流量经过代理：主机名解析、用户连接和 Tracker 连接。

### 高级

![高级](images/en-US/preferences-advanced.png)

libtorrent 的全部设置。选中一项即可在列表下方阅读说明。只有在了解其作用时才修改；
**恢复初始设置** 可以恢复。


## 从 PicoTorrent 或 qBittorrent 迁移

- **文件 > Import from PicoTorrent**：选择 `PicoTorrent.sqlite`
  （位于便携版 PicoTorrent 旁边，或 `%LOCALAPPDATA%\PicoTorrent` 中）。种子及其标签会被添加；
  该文件只会被读取。若要连同设置全部迁移，请在首次启动前把 `PicoTorrent.sqlite` 复制到
  `RePicoTorrent.exe` 旁边：它会被重命名为 `RePicoTorrent.sqlite`。
- **文件 > Import from qBittorrent**：选择 qBittorrent 的 `BT_backup` 文件夹
  （`%LOCALAPPDATA%\qBittorrent\BT_backup`）。进度、Tracker、计数、保存路径和注释都会保留。

列表中已有的种子会被跳过。不要同时用两个客户端为相同的种子做种。


## 更新

每次启动时程序会向 GitHub 查询最新版本，**帮助 > 检查更新**
可随时检查。若有新版本，**Download and install** 会下载适合你的 Windows 的 zip，
用发布中的 SHA-256 校验和进行验证，替换程序文件并重启。设置和种子都会保留。


## 键盘快捷键

| 按键 | 操作 |
|---|---|
| Ctrl+O | 添加种子 |
| Ctrl+U | 添加磁力链接 |
| Ctrl+A | 选择所有种子 |
| Del | 删除所选种子，保留数据 |
| Shift+Del | 删除所选种子及其数据 |
| F1 | 打开本文档 |


## 文件和命令行

`RePicoTorrent.exe` 旁边：

- `RePicoTorrent.sqlite`：设置、种子及其续传数据；
- `coredb.sqlite`：翻译（程序的一部分）；
- `logs`：日志文件；
- `Crashpad`：崩溃转储，从不上传；
- `dbip-country-lite.mmdb`：国家数据库。

命令行：

```
RePicoTorrent.exe [--silent] [--save-path=<文件夹>] [file.torrent | magnet:?xt=...]...
```

`--silent` 会不经添加对话框直接添加给定的种子，`--save-path` 指定保存位置。
