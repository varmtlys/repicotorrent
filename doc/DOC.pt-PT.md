# Documentação do RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · [Português (Brasil)](DOC.pt-BR.md) · **Português (Portugal)** · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Primeiros passos](#primeiros-passos)
- [Janela principal](#janela-principal)
- [Adicionar torrents](#adicionar-torrents)
- [Gerir torrents](#gerir-torrents)
- [Etiquetas](#etiquetas)
- [Filtros e consola](#filtros-e-consola)
- [Criar torrents](#criar-torrents)
- [Preferências](#preferências)
- [Vir do PicoTorrent ou qBittorrent](#vir-do-picotorrent-ou-qbittorrent)
- [Atualizações](#atualizações)
- [Atalhos de teclado](#atalhos-de-teclado)
- [Ficheiros e linha de comandos](#ficheiros-e-linha-de-comandos)


## Primeiros passos

Transfira o zip para o seu Windows a partir da
[página de versões](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` para Windows de 64 bits, `arm64` para Windows em ARM, `x86` para
Windows de 32 bits. Extraia-o para qualquer pasta com permissão de escrita
e execute `RePicoTorrent.exe`. Nada é instalado: definições, lista de
torrents e registos ficam junto do exe, pelo que a pasta pode ser movida
ou copiada para uma pen USB.

Cada pasta é uma cópia separada do programa. Duas cópias em pastas
diferentes podem funcionar ao mesmo tempo se usarem portas diferentes.


## Janela principal

![Janela principal](images/en-US/main.png)

Em cima está a lista de torrents. Cada coluna ordena-se com um clique no
cabeçalho; um clique com o botão direito nos cabeçalhos mostra ou oculta
colunas.

- **Progresso** e **Done**: quanto dos dados pretendidos já foi
  transferido.
- **Estimado**, **DL**, **UL**: tempo restante, velocidades de
  transferência e envio.
- **Availability**: quantas cópias completas os pares ligados têm em
  conjunto.
- **Seeds**, **Peers**, **Leechers**: ligados e, entre
  parênteses, o número em todo o enxame segundo os trackers.

Em baixo estão os detalhes do torrent selecionado:

- **Visão geral**: nome, hashes (v1 e v2), tamanho, pasta, comentário e
  totais. As ligações no comentário abrem no navegador. A barra de cima
  mostra as partes: cada parte transferida é pintada no sítio onde fica no
  torrent. As partes chegam fora de ordem (as mais raras primeiro), por
  isso um torrent em curso tem falhas.
- **Ficheiros**: ficheiros e pastas com o progresso. Botão direito para
  definir a prioridade ou ignorar um ficheiro; duplo clique abre um
  ficheiro transferido.
- **Peers**: pares ligados com país, cliente, velocidades e indicadores
  de ligação escritos por extenso.
- **Trackers**: estado do tracker, seeds e leechers que indica e o
  próximo anúncio. Botão direito para adicionar, remover ou reanunciar.

A barra de estado mostra o número de torrents, nós DHT, as velocidades
atuais, se o filtro de IP está ativo e quanto foi transferido na sessão.
O menu **Visualizar** oculta ou mostra o painel de detalhes, a barra de
estado e a consola.


## Adicionar torrents

- **Ficheiro > Adicionar torrent** (Ctrl+O): escolha um ou mais
  ficheiros `.torrent`.
- **Ficheiro > Add magnet link(s)** (Ctrl+U): cole ligações
  magnet, uma por linha.
- Abra um ficheiro `.torrent` ou uma ligação magnet com
  `RePicoTorrent.exe`; se o programa dessa pasta já estiver em execução, o
  torrent é-lhe passado.

Antes de adicionar, pode escolher a pasta, os ficheiros pretendidos e uma
etiqueta. Para adicionar torrents de imediato com as definições
predefinidas, ative **Skip 'Add torrent' dialog** nas preferências.


## Gerir torrents

Clique com o botão direito num ou mais torrents:

- **Continuar**, **Continuar (forçar)** (ignora a fila), **Pausa**.
- **Force reannounce**, **Force recheck** (verifica os dados no
  disco).
- **Download sequencial**: transferir as partes por ordem, útil para ver
  um vídeo enquanto é transferido.
- **Label**: atribuir uma etiqueta.
- **Export**: a ligação magnet ou o ficheiro `.torrent`.
- **Mover**: mover os dados para outra pasta.
- **Remover**: remover o torrent (Del) ou o torrent e os seus ficheiros
  (Shift+Del).
- **Queuing**: subir ou descer na fila de transferências.
- **Copiar informação hash**, **Abrir no Explorador**.


## Etiquetas

As etiquetas agrupam torrents. São criadas em
**Preferências > Labels**:

- **Color**: a cor da etiqueta; com
  **Use label color as background in torrent list** (**General**) as
  linhas são pintadas com ela.
- **Caminho para salvar**: os torrents adicionados com esta etiqueta são
  guardados aqui.
- **Apply filter**: uma expressão regular; um torrent novo cujo nome
  corresponda recebe esta etiqueta automaticamente. Exemplo:
  `ubuntu|debian|fedora`.

**Visualizar > Labels** mostra apenas os torrents de uma etiqueta.


## Filtros e consola

**Visualizar > Filter** tem filtros guardados, por exemplo os
torrents que estão a ser transferidos agora. **Visualizar >
Console** abre uma linha por baixo da lista: escreva uma consulta e
prima Enter para mostrar só os torrents correspondentes; apague-a para
voltar a mostrar todos.

| Campo | Tipo | Significado |
|---|---|---|
| `name` | texto | nome do torrent |
| `label` | texto | nome da etiqueta |
| `status` | texto | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | número | percentagem concluída |
| `size` | tamanho | tamanho pretendido: `b` (predefinido), `kb`, `mb`, `gb` |
| `dl`, `ul` | velocidade | bytes por segundo (predefinido), `kbps`, `mbps`, `gbps` |

Operadores: `=`, `<`, `<=`, `>`, `>=` e `~` (contém, sem distinguir
maiúsculas), ligados com `and` e `or`. O texto vai entre aspas duplas e as
unidades escrevem-se em minúsculas.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Criar torrents

**Ficheiro > Create torrent**:

![Criar torrent](images/en-US/create-torrent.png)

- Escolha um ficheiro ou uma pasta.
- **Mode**: v1, v2 ou híbrido v1 + v2. O híbrido funciona com qualquer
  cliente e é o predefinido.
- **Comment** e **Creator** são opcionais.
- **Private**: os pares vêm apenas dos trackers, não de DHT, PeX nem da
  descoberta local.
- **Add to session**: começar a partilhar o novo torrent de imediato.
- **Trackers (one per line)**: cada tracker vai para o seu próprio
  nível; os níveis são tentados por ordem.
- **URL seeds (one per line)**: servidores web com os mesmos dados.
  Para uma pasta, o URL deve apontar para a pasta que a contém.


## Preferências

**Visualizar > Preferências**. **Restore defaults** repõe todas
as definições. Algumas alterações (idioma, tema, portas) exigem reiniciar;
o programa propõe-no.

### General

![Geral](images/en-US/preferences-general.png)

- **Language** e **Theme** (sistema ou claro; o tema escuro segue a
  definição do Windows).
- **Skip 'Add torrent' dialog**, **Start RePicoTorrent with Windows**,
  **Start position** da janela.
- **Show RePicoTorrent in notification area**, e se minimizar ou fechar a
  janela a envia para lá.

### Downloads

![Transferências](images/en-US/preferences-downloads.png)

- **Caminho para salvar**, **Move completed downloads** para outra pasta.
- **Pause when disk space is low**.
- **Limites**: limites de transferência e envio em KB/s, quantos
  torrents podem estar ativos em simultâneo e o total de ligações.

### Labels

![Etiquetas](images/en-US/preferences-labels.png)

Ver [Etiquetas](#etiquetas).

### Conexão

![Ligação](images/en-US/preferences-connection.png)

- **Interface escuta**: endereços e portas para ligações de entrada.
  `0.0.0.0` e `[::]` significam todos os endereços IPv4 e IPv6.
- **Encryption**: exigir encriptação nas ligações de entrada ou saída.
- **Privacy**: DHT, descoberta local (LSD), troca de pares (PeX),
  WebTorrent e a coluna do país dos pares. A base de dados de países
  (DB-IP Lite) é transferida uma vez por mês enquanto a coluna estiver
  ativa.
- **IP filter**: bloquear endereços de um filtro em formato eMule dentro
  de um zip, por exemplo do emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP ou SOCKS4/5, com ou sem palavra-passe, e o que passa por ele:
resolução de nomes, ligações a pares e trackers.

### Avançadas

![Avançado](images/en-US/preferences-advanced.png)

Todas as definições do libtorrent. Selecione uma para ler a descrição por
baixo da lista. Altere-as só se souber o que fazem;
**Restore defaults** repõe-nas.


## Vir do PicoTorrent ou qBittorrent

- **Ficheiro > Import from PicoTorrent**: escolha `PicoTorrent.sqlite`
  (junto de um PicoTorrent portátil ou em `%LOCALAPPDATA%\PicoTorrent`).
  Os torrents e as suas etiquetas são adicionados; o ficheiro é apenas
  lido. Para trazer tudo, definições incluídas, copie `PicoTorrent.sqlite`
  para junto de `RePicoTorrent.exe` antes da primeira execução: é
  renomeado para `RePicoTorrent.sqlite`.
- **Ficheiro > Import from qBittorrent**: escolha a pasta `BT_backup`
  do qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Progresso,
  trackers, contadores, pastas e comentários são mantidos.

Os torrents que já estão na lista são ignorados. Não partilhe os mesmos
torrents a partir dos dois clientes ao mesmo tempo.


## Atualizações

Em cada arranque o programa pergunta ao GitHub pela versão mais recente, e
**Ajuda > Verificar por atualizações** fá-lo a qualquer momento. Se
houver uma versão nova, **Download and install** transfere o zip para o seu
Windows, verifica-o com as somas SHA-256 da versão, substitui os ficheiros
do programa e reinicia-o. Definições e torrents mantêm-se.


## Atalhos de teclado

| Teclas | Ação |
|---|---|
| Ctrl+O | adicionar torrent |
| Ctrl+U | adicionar ligações magnet |
| Ctrl+A | selecionar todos os torrents |
| Del | remover os torrents selecionados, manter os dados |
| Shift+Del | remover os torrents selecionados e os seus dados |
| F1 | abrir esta documentação |


## Ficheiros e linha de comandos

Junto de `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: definições, torrents e dados de retoma;
- `coredb.sqlite`: traduções (parte do programa);
- `logs`: ficheiros de registo;
- `Crashpad`: relatórios de falhas, nunca enviados;
- `dbip-country-lite.mmdb`: a base de dados de países.

Linha de comandos:

```
RePicoTorrent.exe [--silent] [--save-path=<pasta>] [file.torrent | magnet:?xt=...]...
```

`--silent` adiciona os torrents indicados sem a janela de adicionar,
`--save-path` define onde guardá-los.
