# RePicoTorrent 설명서

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · **한국어** · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [시작하기](#시작하기)
- [기본 창](#기본-창)
- [토렌트 추가](#토렌트-추가)
- [토렌트 관리](#토렌트-관리)
- [레이블](#레이블)
- [필터와 콘솔](#필터와-콘솔)
- [토렌트 만들기](#토렌트-만들기)
- [설정](#설정)
- [PicoTorrent나 qBittorrent에서 옮겨 오기](#picotorrent나-qbittorrent에서-옮겨-오기)
- [업데이트](#업데이트)
- [바로 가기 키](#바로-가기-키)
- [파일과 명령줄](#파일과-명령줄)


## 시작하기

[릴리스 페이지](https://github.com/varmtlys/repicotorrent/releases/latest)에서 사용하는
Windows에 맞는 zip을 내려받으세요. 64비트 Windows는 `x64`, ARM용 Windows는 `arm64`,
32비트 Windows는 `x86`입니다. 쓰기 권한이 있는 아무 폴더에 압축을 풀고
`RePicoTorrent.exe`를 실행하세요. 설치는 필요 없습니다. 설정, 토렌트 목록, 로그는 exe
옆에 저장되므로 폴더를 옮기거나 USB 메모리에 복사할 수 있습니다.

폴더마다 프로그램의 별도 사본입니다. 서로 다른 폴더에 있는 두 사본은 다른 포트를 쓰면 동시에 실행할 수 있습니다.


## 기본 창

![기본 창](images/en-US/main.png)

위쪽은 토렌트 목록입니다. 열 머리글을 클릭하면 정렬되고, 머리글을 마우스 오른쪽 단추로 클릭하면 열을 표시하거나 숨길 수 있습니다.

- **진행도** 및 **Done**: 원하는 데이터 중 받은 양.
- **시간**, **다운로드**, **업로드**: 남은 시간, 다운로드 및 업로드 속도.
- **Availability**: 연결된 피어들이 합쳐서 가진 완전한 사본의 수.
- **시드**, **피어**, **Leechers**: 연결된 수이며, 괄호 안은 트래커가 보고한 전체 스웜의 수입니다.

아래쪽에는 선택한 토렌트의 세부 정보가 표시됩니다.

- **오버뷰**: 이름, 해시(v1 및 v2), 크기, 저장 위치, 설명, 합계. 설명의 링크는 브라우저에서 열립니다.
  위쪽 막대는 조각을 보여 줍니다. 받은 조각은 토렌트 안의 해당 위치에 색이 칠해집니다.
  조각은 순서대로가 아니라(가장 드문 것부터) 받아지므로 진행 중인 토렌트에는 빈틈이 있습니다.
- **파일**: 파일과 폴더 및 진행률. 마우스 오른쪽 단추로 우선순위를 정하거나 파일을 건너뛰고, 두 번 클릭하면 받은 파일이 열립니다.
- **피어**: 연결된 피어의 국가, 클라이언트, 속도, 말로 풀어 쓴 연결 플래그.
- **트래커**: 트래커 상태, 보고된 시더와 리처 수, 다음 알림 시각. 마우스 오른쪽 단추로 추가, 제거, 다시 알림을 할 수 있습니다.

상태 표시줄에는 토렌트 수, DHT 노드 수, 현재 속도, IP 필터 사용 여부, 이번 세션의 전송량이 표시됩니다.
**보기** 메뉴에서 세부 정보 패널, 상태 표시줄, 콘솔을 숨기거나 표시합니다.


## 토렌트 추가

- **파일 > 토렌트 추가** (Ctrl+O): `.torrent` 파일을 하나 이상 고릅니다.
- **파일 > 마그넷 링크 추가** (Ctrl+U): 마그넷 링크를 한 줄에 하나씩 붙여 넣습니다.
- `.torrent` 파일이나 마그넷 링크를 `RePicoTorrent.exe`로 엽니다. 그 폴더의 프로그램이 이미 실행 중이면 토렌트가 그쪽으로 전달됩니다.

추가하기 전에 저장 위치, 받을 파일, 레이블을 고를 수 있습니다. 기본 설정으로 바로 추가하려면 설정에서
**Skip 'Add torrent' dialog**을(를) 켜세요.


## 토렌트 관리

토렌트 하나 이상을 마우스 오른쪽 단추로 클릭합니다.

- **재개**, **재개 (강제)**(대기열 무시), **정지**.
- **Force reannounce**, **Force recheck**(디스크의 데이터 검사).
- **순차 다운로드**: 조각을 순서대로 받습니다. 받는 중에 동영상을 볼 때 유용합니다.
- **Label**: 레이블 지정.
- **Export**: 마그넷 링크 또는 `.torrent` 파일.
- **옮기기**: 데이터를 다른 폴더로 이동.
- **제거**: 토렌트 제거(Del) 또는 파일과 함께 제거(Shift+Del).
- **대기**: 다운로드 대기열에서 위나 아래로 이동.
- **정보 해시 복사**, **폴더 열기**.


## 레이블

레이블은 토렌트를 묶습니다. **설정 > Labels**에서 만듭니다.

- **Color**: 레이블 색. **일반**에서
  **Use label color as background in torrent list**을(를) 켜면 행이 이 색으로 칠해집니다.
- **경로 저장**: 이 레이블로 추가한 토렌트가 여기에 저장됩니다.
- **Apply filter**: 정규식입니다. 이름이 일치하는 새 토렌트에 이 레이블이 자동으로 붙습니다. 예:
  `ubuntu|debian|fedora`.

**보기 > Labels**은(는) 한 레이블의 토렌트만 보여 줍니다.


## 필터와 콘솔

**보기 > Filter**에는 저장된 필터가 있습니다(예: 지금 받는 중인 토렌트).
**보기 > Console**을(를) 선택하면 목록 아래에 입력 줄이 열립니다. 쿼리를 입력하고 Enter를 누르면 일치하는 토렌트만 보이고, 비우면 다시 모두 보입니다.

| 필드 | 형식 | 의미 |
|---|---|---|
| `name` | 텍스트 | 토렌트 이름 |
| `label` | 텍스트 | 레이블 이름 |
| `status` | 텍스트 | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | 숫자 | 완료율(%) |
| `size` | 크기 | 원하는 크기: `b`(기본), `kb`, `mb`, `gb` |
| `dl`, `ul` | 속도 | 초당 바이트(기본), `kbps`, `mbps`, `gbps` |

연산자: `=`, `<`, `<=`, `>`, `>=`, `~`(포함, 대소문자 구분 없음). `and`와 `or`로
연결합니다. 텍스트는 큰따옴표로 감싸고 단위는 소문자로 씁니다.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## 토렌트 만들기

**파일 > Create torrent**:

![토렌트 만들기](images/en-US/create-torrent.png)

- 파일이나 폴더를 고릅니다.
- **Mode**: v1, v2 또는 v1 + v2 하이브리드. 하이브리드는 모든 클라이언트와 호환되며 기본값입니다.
- **Comment**와 **Creator**는 비워 둘 수 있습니다.
- **Private**: 피어를 트래커에서만 얻고 DHT, PeX, 로컬 검색은 쓰지 않습니다.
- **Add to session**: 새 토렌트의 시드를 바로 시작합니다.
- **Trackers (one per line)**: 트래커마다 별도의 계층에 들어가며 계층은 차례로 시도됩니다.
- **URL seeds (one per line)**: 같은 데이터를 가진 웹 서버. 폴더인 경우 URL은 그 폴더를 포함한 폴더를 가리켜야 합니다.


## 설정

**보기 > 설정**. **Restore defaults**은(는) 모든 설정을 되돌립니다.
일부 변경(언어, 테마, 포트)은 다시 시작해야 하며 프로그램이 이를 제안합니다.

### 일반

![일반](images/en-US/preferences-general.png)

- **언어** 및 **Theme**(시스템 또는 밝게. 어두운 테마는 Windows 설정을 따릅니다).
- **Skip 'Add torrent' dialog**, **Picotorrent 자동 시작**, 창의 **시작 위치**.
- **RePicoTorrent 알림 영역에 보이기**, 그리고 창을 최소화하거나 닫을 때 그곳으로 숨길지 여부.

### 다운로드

![다운로드](images/en-US/preferences-downloads.png)

- **경로 저장**, 다른 폴더로 **완료된 다운로드 이동**.
- **Pause when disk space is low**.
- **제한**: KB/s 단위 다운로드·업로드 제한, 동시에 활성화할 수 있는 토렌트 수, 전체 연결 수.

### Labels

![레이블](images/en-US/preferences-labels.png)

[레이블](#레이블)을(를) 참고하세요.

### 연결

![연결](images/en-US/preferences-connection.png)

- **수신 인터페이스**: 들어오는 연결의 주소와 포트. `0.0.0.0`과 `[::]`는 모든 IPv4 및 IPv6 주소를 뜻합니다.
- **암호화**: 들어오거나 나가는 연결에 암호화를 요구합니다.
- **프라이버시**: DHT, 로컬 피어 검색(LSD), 피어 교환(PeX), WebTorrent, 피어 국가 열.
  국가 열이 켜져 있는 동안 국가 데이터베이스(DB-IP Lite)를 한 달에 한 번 내려받습니다.
- **IP filter**: zip 파일 안의 eMule 형식 필터(예: emule-security.org)에 있는 주소를 차단합니다.

### 프록시

![프록시](images/en-US/preferences-proxy.png)

HTTP 또는 SOCKS4/5 프록시(암호 사용 여부 선택)와 그 프록시를 거칠 대상: 호스트 이름 조회, 피어 및 트래커 연결.

### 고급

![고급](images/en-US/preferences-advanced.png)

libtorrent의 모든 설정입니다. 하나를 고르면 목록 아래에 설명이 나옵니다. 무엇을 하는지 알 때만 바꾸세요.
**Restore defaults**(으)로 되돌릴 수 있습니다.


## PicoTorrent나 qBittorrent에서 옮겨 오기

- **파일 > Import from PicoTorrent**: `PicoTorrent.sqlite`를 고릅니다
  (포터블 PicoTorrent 옆 또는 `%LOCALAPPDATA%\PicoTorrent`). 토렌트와 레이블이 추가되며 파일은 읽기만 합니다.
  설정까지 모두 옮기려면 처음 실행하기 전에 `PicoTorrent.sqlite`를 `RePicoTorrent.exe` 옆에 복사하세요.
  이름이 `RePicoTorrent.sqlite`로 바뀝니다.
- **파일 > Import from qBittorrent**: qBittorrent의 `BT_backup` 폴더
  (`%LOCALAPPDATA%\qBittorrent\BT_backup`)를 고릅니다. 진행률, 트래커, 카운터, 저장 위치, 설명이 유지됩니다.

이미 목록에 있는 토렌트는 건너뜁니다. 같은 토렌트를 두 클라이언트에서 동시에 시드하지 마세요.


## 업데이트

프로그램은 시작할 때마다 GitHub에 최신 릴리스를 묻고, **도움말 > 업데이트 확인**(으)로
언제든 확인할 수 있습니다. 새 버전이 있으면 **Download and install**이(가) 사용하는 Windows용 zip을 내려받아
릴리스의 SHA-256 체크섬으로 검사한 뒤 프로그램 파일을 바꾸고 다시 시작합니다. 설정과 토렌트는 그대로 남습니다.


## 바로 가기 키

| 키 | 동작 |
|---|---|
| Ctrl+O | 토렌트 추가 |
| Ctrl+U | 마그넷 링크 추가 |
| Ctrl+A | 모든 토렌트 선택 |
| Del | 선택한 토렌트 제거(데이터 유지) |
| Shift+Del | 선택한 토렌트를 데이터와 함께 제거 |
| F1 | 이 설명서 열기 |


## 파일과 명령줄

`RePicoTorrent.exe` 옆:

- `RePicoTorrent.sqlite`: 설정, 토렌트, 이어받기 데이터
- `coredb.sqlite`: 번역(프로그램의 일부)
- `logs`: 로그 파일
- `Crashpad`: 충돌 덤프(절대 전송되지 않음)
- `dbip-country-lite.mmdb`: 국가 데이터베이스

명령줄:

```
RePicoTorrent.exe [--silent] [--save-path=<폴더>] [file.torrent | magnet:?xt=...]...
```

`--silent`는 추가 대화 상자 없이 지정한 토렌트를 추가하고, `--save-path`는 저장 위치를 정합니다.
