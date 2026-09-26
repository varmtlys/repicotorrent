# RePicoTorrent ドキュメント

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · **日本語** · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [はじめに](#はじめに)
- [メインウィンドウ](#メインウィンドウ)
- [トレントの追加](#トレントの追加)
- [トレントの管理](#トレントの管理)
- [ラベル](#ラベル)
- [フィルターとコンソール](#フィルターとコンソール)
- [トレントの作成](#トレントの作成)
- [設定](#設定)
- [PicoTorrent や qBittorrent からの移行](#picotorrent-や-qbittorrent-からの移行)
- [更新](#更新)
- [キーボードショートカット](#キーボードショートカット)
- [ファイルとコマンドライン](#ファイルとコマンドライン)


## はじめに

[リリースページ](https://github.com/varmtlys/repicotorrent/releases/latest)から、お使いの
Windows に合った zip をダウンロードします。64 ビット Windows は `x64`、ARM 版 Windows は
`arm64`、32 ビット Windows は `x86` です。書き込みできる任意のフォルダーに展開し、
`RePicoTorrent.exe` を実行します。インストールは不要です。設定、トレントの一覧、ログは exe
の隣に保存されるため、フォルダーごと移動したり USB メモリにコピーしたりできます。

フォルダーごとにプログラムは別のコピーとして動きます。別々のフォルダーにある 2 つのコピーは、
異なるポートを使えば同時に実行できます。


## メインウィンドウ

![メインウィンドウ](images/en-US/main.png)

上部はトレントの一覧です。列見出しをクリックすると並べ替えられ、見出しを右クリックすると列の表示と非表示を切り替えられます。

- **進行状況** と **Done**：必要なデータのうちダウンロード済みの割合。
- **ETA**、**DL**、**UL**：残り時間、ダウンロード速度とアップロード速度。
- **Availability**：接続中のピアが合計で持っている完全なコピーの数。
- **Seeds**、**ピア**、**Leechers**：接続中の数と、括弧内はトラッカーが報告するスウォーム全体の数。

下部には選択したトレントの詳細が表示されます。

- **概要**：名前、ハッシュ（v1 と v2）、サイズ、保存先、コメント、合計。
  コメント内のリンクはブラウザーで開きます。上部のバーはピースを表し、ダウンロード済みの各ピースがトレント内の位置に塗られます。
  ピースは順番どおりではなく（最もまれなものから）取得されるため、ダウンロード中のトレントには隙間があります。
- **ファイル**：ファイルとフォルダー、およびその進捗。右クリックで優先度を設定したりファイルをスキップしたりでき、ダブルクリックでダウンロード済みのファイルを開きます。
- **ピア**：接続中のピアの国、クライアント、速度、言葉で書かれた接続フラグ。
- **トラッカー**：トラッカーの状態、報告されたシーダーとリーチャーの数、次回のアナウンス。右クリックで追加、削除、再アナウンスができます。

ステータスバーにはトレント数、DHT ノード数、現在の速度、IP フィルターのオン/オフ、このセッションでの転送量が表示されます。
**表示** メニューで詳細パネル、ステータスバー、コンソールの表示を切り替えます。


## トレントの追加

- **ファイル > トレントを追加**（Ctrl+O）：1 つ以上の `.torrent` ファイルを選びます。
- **ファイル > マグネットリンクを加える**（Ctrl+U）：マグネットリンクを 1 行に 1 つずつ貼り付けます。
- `.torrent` ファイルやマグネットリンクを `RePicoTorrent.exe` で開きます。そのフォルダーのプログラムがすでに動いていれば、トレントはそちらに渡されます。

追加する前に、保存先、ダウンロードするファイル、ラベルを選べます。既定の設定ですぐに追加するには、設定で
**Skip 'Add torrent' dialog** をオンにします。


## トレントの管理

1 つ以上のトレントを右クリックします。

- **再開**、**再開 (力)**（キューを無視）、**一時停止**。
- **Force reannounce**、**Force recheck**（ディスク上のデータを検証）。
- **シーケンシャルダウンロード**：ピースを順番に取得します。ダウンロードしながら動画を見るのに便利です。
- **Label**：ラベルを付けます。
- **Export**：マグネットリンクまたは `.torrent` ファイル。
- **移動**：データを別のフォルダーに移動します。
- **削除する**：トレントを削除（Del）、またはファイルごと削除（Shift+Del）。
- **キューイング**：ダウンロードキュー内で上下に移動します。
- **情報ハッシュをコピーする**、**Explorerで開く**。


## ラベル

ラベルはトレントをグループにまとめます。**環境設定 > Labels** で作成します。

- **Color**：ラベルの色。**一般** で
  **Use label color as background in torrent list** をオンにすると、行がこの色で塗られます。
- **保存パス**：このラベルで追加したトレントはここに保存されます。
- **Apply filter**：正規表現。名前が一致する新しいトレントには自動でこのラベルが付きます。例：
  `ubuntu|debian|fedora`。

**表示 > Labels** では 1 つのラベルのトレントだけを表示します。


## フィルターとコンソール

**表示 > Filter** には保存済みのフィルターがあります（例：現在ダウンロード中のトレント）。
**表示 > Console** を選ぶと一覧の下に入力欄が開きます。クエリを入力して Enter を押すと一致するトレントだけが表示され、空にするとすべて表示されます。

| フィールド | 型 | 意味 |
|---|---|---|
| `name` | テキスト | トレント名 |
| `label` | テキスト | ラベル名 |
| `status` | テキスト | `downloading`、`seeding`、`uploading`、`paused`、`queued`、`error` |
| `progress` | 数値 | 完了率（%） |
| `size` | サイズ | 必要なサイズ：`b`（既定）、`kb`、`mb`、`gb` |
| `dl`、`ul` | 速度 | バイト毎秒（既定）、`kbps`、`mbps`、`gbps` |

演算子：`=`、`<`、`<=`、`>`、`>=`、`~`（含む、大文字小文字を区別しない）。`and` と `or`
でつなぎます。テキストは二重引用符で囲み、単位は小文字で書きます。

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## トレントの作成

**ファイル > Create torrent**：

![トレントの作成](images/en-US/create-torrent.png)

- ファイルまたはフォルダーを選びます。
- **Mode**：v1、v2、または v1 + v2 ハイブリッド。ハイブリッドはどのクライアントでも使え、既定になっています。
- **Comment** と **Creator** は省略できます。
- **Private**：ピアはトラッカーからのみ取得し、DHT、PeX、ローカル探索は使いません。
- **Add to session**：新しいトレントのシードをすぐに始めます。
- **Trackers (one per line)**：トラッカーはそれぞれ別の階層に入り、階層は順番に試されます。
- **URL seeds (one per line)**：同じデータを持つ Web サーバー。フォルダーの場合、URL はそれを含むフォルダーを指す必要があります。


## 設定

**表示 > 環境設定**。**Restore defaults** ですべての設定を初期状態に戻します。
一部の変更（言語、テーマ、ポート）には再起動が必要で、プログラムが再起動を提案します。

### 一般

![全般](images/en-US/preferences-general.png)

- **言語** と **Theme**（システムまたはライト。ダークテーマは Windows の設定に従います）。
- **Skip 'Add torrent' dialog**、**WindowsかたわらにRePicoTorrentを起動する**、ウィンドウの **開始位置**。
- **Show RePicoTorrent in notification area**、および最小化や閉じる操作でそこに隠すかどうか。

### ダウンロード

![ダウンロード](images/en-US/preferences-downloads.png)

- **保存パス**、**Move completed downloads**（別のフォルダーへ）。
- **Pause when disk space is low**。
- **制限**：KB/s 単位のダウンロード・アップロード制限、同時にアクティブにできるトレント数、接続の総数。

### Labels

![ラベル](images/en-US/preferences-labels.png)

[ラベル](#ラベル) を参照してください。

### 接続

![接続](images/en-US/preferences-connection.png)

- **リッスンインタフェース**：受信接続用のアドレスとポート。`0.0.0.0` と `[::]` はすべての IPv4 と IPv6 アドレスを意味します。
- **Encryption**：受信または送信の接続に暗号化を必須にします。
- **Privacy**：DHT、ローカルピア探索（LSD）、ピア交換（PeX）、WebTorrent、ピアの国の列。
  国の列がオンの間、国データベース（DB-IP Lite）は月に 1 回ダウンロードされます。
- **IP filter**：zip に入った eMule 形式のフィルター（例：emule-security.org のもの）にあるアドレスをブロックします。

### プロキシ

![プロキシ](images/en-US/preferences-proxy.png)

HTTP または SOCKS4/5 プロキシ（パスワードの有無を選択）と、プロキシを通すもの：ホスト名の解決、ピアとトラッカーへの接続。

### 先進的な

![詳細](images/en-US/preferences-advanced.png)

libtorrent のすべての設定。項目を選ぶと一覧の下に説明が表示されます。意味がわかる場合にだけ変更してください。
**Restore defaults** で元に戻せます。


## PicoTorrent や qBittorrent からの移行

- **ファイル > Import from PicoTorrent**：`PicoTorrent.sqlite` を選びます
  （ポータブル版 PicoTorrent の隣、または `%LOCALAPPDATA%\PicoTorrent`）。トレントとそのラベルが追加され、
  ファイルは読み取られるだけです。設定を含めてすべて引き継ぐには、初回起動の前に `PicoTorrent.sqlite` を
  `RePicoTorrent.exe` の隣にコピーします。`RePicoTorrent.sqlite` に名前が変更されます。
- **ファイル > Import from qBittorrent**：qBittorrent の `BT_backup` フォルダー
  （`%LOCALAPPDATA%\qBittorrent\BT_backup`）を選びます。進捗、トラッカー、カウンター、保存先、コメントが引き継がれます。

一覧にすでにあるトレントはスキップされます。同じトレントを両方のクライアントから同時にシードしないでください。


## 更新

起動するたびにプログラムは GitHub に最新リリースを問い合わせます。**ヘルプ > 更新の確認**
でいつでも確認できます。新しいバージョンがあれば、**Download and install** がお使いの Windows 用の zip をダウンロードし、
リリースの SHA-256 チェックサムで検証してからプログラムのファイルを置き換え、再起動します。設定とトレントはそのまま残ります。


## キーボードショートカット

| キー | 操作 |
|---|---|
| Ctrl+O | トレントを追加 |
| Ctrl+U | マグネットリンクを追加 |
| Ctrl+A | すべてのトレントを選択 |
| Del | 選択したトレントを削除（データは残す） |
| Shift+Del | 選択したトレントをデータごと削除 |
| F1 | このドキュメントを開く |


## ファイルとコマンドライン

`RePicoTorrent.exe` の隣：

- `RePicoTorrent.sqlite`：設定、トレント、再開用データ
- `coredb.sqlite`：翻訳（プログラムの一部）
- `logs`：ログファイル
- `Crashpad`：クラッシュダンプ（送信されることはありません）
- `dbip-country-lite.mmdb`：国データベース

コマンドライン：

```
RePicoTorrent.exe [--silent] [--save-path=<フォルダー>] [file.torrent | magnet:?xt=...]...
```

`--silent` は追加ダイアログを出さずに指定のトレントを追加し、`--save-path` は保存先を指定します。
