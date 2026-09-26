# Documentação do RePicoTorrent

[English](../DOC.md) · [العربية](DOC.ar-SA.md) · [Български](DOC.bg-BG.md) · [Català](DOC.ca-ES.md) · [Čeština](DOC.cs-CZ.md) · [Deutsch](DOC.de-DE.md) · [Ελληνικά](DOC.el-GR.md) · [Español](DOC.es-ES.md) · [Eesti](DOC.et-EE.md) · [Suomi](DOC.fi-FI.md) · [Français](DOC.fr-FR.md) · [עברית](DOC.he-IL.md) · [हिन्दी](DOC.hi-IN.md) · [Hrvatski](DOC.hr-HR.md) · [Magyar](DOC.hu-HU.md) · [Հայերեն](DOC.hy-AM.md) · [Bahasa Indonesia](DOC.id-ID.md) · [Italiano](DOC.it-IT.md) · [日本語](DOC.ja-JP.md) · [ქართული](DOC.ka-GE.md) · [한국어](DOC.ko-KR.md) · [Lietuvių](DOC.lt-LT.md) · [Latviešu](DOC.lv-LV.md) · [Norsk bokmål](DOC.nb-NO.md) · [Nederlands](DOC.nl-NL.md) · [Polski](DOC.pl-PL.md) · **Português (Brasil)** · [Português (Portugal)](DOC.pt-PT.md) · [Română](DOC.ro-RO.md) · [Русский](DOC.ru-RU.md) · [සිංහල](DOC.si-LK.md) · [Slovenčina](DOC.sk-SK.md) · [Srpski](DOC.sr-SP.md) · [Svenska](DOC.sv-SE.md) · [Türkçe](DOC.tr-TR.md) · [Українська](DOC.uk-UA.md) · [Tiếng Việt](DOC.vi-VN.md) · [简体中文](DOC.zh-CN.md) · [繁體中文](DOC.zh-TW.md)

- [Primeiros passos](#primeiros-passos)
- [Janela principal](#janela-principal)
- [Adicionar torrents](#adicionar-torrents)
- [Gerenciar torrents](#gerenciar-torrents)
- [Rótulos](#rótulos)
- [Filtros e console](#filtros-e-console)
- [Criar torrents](#criar-torrents)
- [Preferências](#preferências)
- [Vindo do PicoTorrent ou qBittorrent](#vindo-do-picotorrent-ou-qbittorrent)
- [Atualizações](#atualizações)
- [Atalhos de teclado](#atalhos-de-teclado)
- [Arquivos e linha de comando](#arquivos-e-linha-de-comando)


## Primeiros passos

Baixe o zip para o seu Windows na
[página de versões](https://github.com/varmtlys/repicotorrent/releases/latest):
`x64` para Windows 64 bits, `arm64` para Windows em ARM, `x86` para Windows
32 bits. Extraia-o em qualquer pasta com permissão de escrita e execute
`RePicoTorrent.exe`. Nada é instalado: configurações, lista de torrents e
logs ficam ao lado do exe, então a pasta pode ser movida ou copiada para
um pendrive.

Cada pasta é uma cópia separada do programa. Duas cópias em pastas
diferentes podem rodar ao mesmo tempo se usarem portas diferentes.


## Janela principal

![Janela principal](images/en-US/main.png)

Em cima fica a lista de torrents. Cada coluna é ordenada com um clique no
cabeçalho; clique com o botão direito nos cabeçalhos para mostrar ou
ocultar colunas.

- **Progresso** e **Done**: quanto dos dados desejados já foi
  baixado.
- **Tempo restante**, **Download**, **Upload**: tempo restante, velocidades de
  download e upload.
- **Disponibilidade**: quantas cópias completas os pares conectados têm
  juntos.
- **Sementes**, **Pares**, **Leechers**: conectados e, entre
  parênteses, o número no enxame inteiro segundo os trackers.

Embaixo ficam os detalhes do torrent selecionado:

- **Visão geral**: nome, hashes (v1 e v2), tamanho, pasta, comentário e
  totais. Links no comentário abrem no navegador. A barra de cima mostra
  as partes: cada parte baixada é pintada onde ela fica no torrent. As
  partes chegam fora de ordem (as mais raras primeiro), por isso um torrent
  em andamento tem lacunas.
- **Arquivos**: arquivos e pastas com o progresso. Botão direito para
  definir prioridade ou pular um arquivo; clique duplo abre um arquivo
  baixado.
- **Pares**: pares conectados com país, cliente, velocidades e flags de
  conexão escritas por extenso.
- **Rastreadores**: estado do tracker, seeds e leechers informados e o
  próximo anúncio. Botão direito para adicionar, remover ou reanunciar.

A barra de status mostra o número de torrents, nós DHT, as velocidades
atuais, se o filtro de IP está ativo e quanto foi transferido na sessão.
O menu **Visualizar** oculta ou mostra o painel de detalhes, a barra de
status e o console.


## Adicionar torrents

- **Arquivo > Adicionar torrent** (Ctrl+O): escolha um ou mais
  arquivos `.torrent`.
- **Arquivo > Adicionar link(s) magnéticos** (Ctrl+U): cole links magnet,
  um por linha.
- Abra um arquivo `.torrent` ou um link magnet com `RePicoTorrent.exe`; se
  o programa daquela pasta já estiver rodando, o torrent é passado a ele.

Antes de adicionar, você pode escolher a pasta, os arquivos desejados e um
rótulo. Para adicionar torrents direto com as configurações padrão, ative
**Pular Diálogo 'Adicionar torrent'** nas preferências.


## Gerenciar torrents

Clique com o botão direito em um ou mais torrents:

- **Retomar**, **Retomar (forçado)** (ignora a fila), **Pausar**.
- **Forçar reanúncio**, **Forçar rechecagem** (verifica os dados no
  disco).
- **Download sequencial**: baixar as partes em ordem, útil para assistir
  a um vídeo enquanto ele baixa.
- **Etiqueta**: atribuir um rótulo.
- **Exportar**: o link magnet ou o arquivo `.torrent`.
- **Mover**: mover os dados para outra pasta.
- **Remover**: remover o torrent (Del) ou o torrent e seus arquivos
  (Shift+Del).
- **Fila**: subir ou descer na fila de downloads.
- **Copiar info hash**, **Abrir no Explorador de Arquivos**.


## Rótulos

Rótulos agrupam torrents. Eles são criados em
**Preferências > Etiqueta**:

- **Cor**: a cor do rótulo; com
  **Usar a cor de etiqueta como fundo na lista de torrents** (**Geral**) as
  linhas são pintadas com ela.
- **Salvar no local**: torrents adicionados com este rótulo são salvos aqui.
- **Aplicar filtro**: uma expressão regular; um torrent novo cujo nome
  corresponde recebe este rótulo automaticamente. Exemplo:
  `ubuntu|debian|fedora`.

**Visualizar > Etiqueta** mostra só os torrents de um rótulo.


## Filtros e console

**Visualizar > Filtro** tem filtros salvos, por exemplo os
torrents que estão baixando agora. **Visualizar > Console** abre
uma linha abaixo da lista: digite uma consulta e pressione Enter para
mostrar só os torrents correspondentes; apague-a para mostrar todos de
novo.

| Campo | Tipo | Significado |
|---|---|---|
| `name` | texto | nome do torrent |
| `label` | texto | nome do rótulo |
| `status` | texto | `downloading`, `seeding`, `uploading`, `paused`, `queued`, `error` |
| `progress` | número | porcentagem concluída |
| `size` | tamanho | tamanho desejado: `b` (padrão), `kb`, `mb`, `gb` |
| `dl`, `ul` | velocidade | bytes por segundo (padrão), `kbps`, `mbps`, `gbps` |

Operadores: `=`, `<`, `<=`, `>`, `>=` e `~` (contém, sem diferenciar
maiúsculas), ligados com `and` e `or`. Texto vai entre aspas duplas, e as
unidades são escritas em minúsculas.

```
name ~ "ubuntu"
size > 1gb and status = "downloading"
progress >= 90 or label = "Linux"
dl > 500kbps
```


## Criar torrents

**Arquivo > Criar torrent**:

![Criar torrent](images/en-US/create-torrent.png)

- Escolha um arquivo ou uma pasta.
- **Modo**: v1, v2 ou híbrido v1 + v2. O híbrido funciona com qualquer
  cliente e é o padrão.
- **Comentário** e **Criador** são opcionais.
- **Privado**: os pares vêm só dos trackers, não de DHT, PeX ou da
  descoberta local.
- **Adicionar à sessão**: começar a semear o novo torrent imediatamente.
- **Rastreadores (um por linha)**: cada tracker vai para o seu próprio
  nível; os níveis são tentados em ordem.
- **URL seeds (um por linha)**: servidores web com os mesmos dados. Para
  uma pasta, a URL deve apontar para a pasta que a contém.


## Preferências

**Visualizar > Preferências**. **Restaurar padrões** redefine
todas as configurações. Algumas mudanças (idioma, tema, portas) exigem
reiniciar; o programa oferece isso.

### Geral

![Geral](images/en-US/preferences-general.png)

- **Idioma** e **Theme** (sistema ou claro; o tema escuro segue a
  configuração do Windows).
- **Pular Diálogo 'Adicionar torrent'**, **Iniciar RePicoTorrent com o Windows**,
  **Posição ao iniciar** da janela.
- **Mostrar RePicoTorrent na área de notificação**, e se minimizar ou fechar a
  janela a manda para lá.

### Downloads

![Downloads](images/en-US/preferences-downloads.png)

- **Salvar no local**, **Mover downloads concluídos** para outra pasta.
- **Pausar quando o espaço em disco estiver baixo**.
- **Limites**: limites de download e upload em KB/s, quantos torrents
  podem estar ativos ao mesmo tempo e o total de conexões.

### Etiqueta

![Rótulos](images/en-US/preferences-labels.png)

Veja [Rótulos](#rótulos).

### Conexão

![Conexão](images/en-US/preferences-connection.png)

- **Interface de escuta**: endereços e portas para conexões de entrada.
  `0.0.0.0` e `[::]` significam todos os endereços IPv4 e IPv6.
- **Criptografia**: exigir criptografia nas conexões de entrada ou saída.
- **Privacidade**: DHT, descoberta local (LSD), troca de pares (PeX),
  WebTorrent e a coluna de país dos pares. O banco de países (DB-IP Lite)
  é baixado uma vez por mês enquanto a coluna estiver ativa.
- **Filtro de IP**: bloquear endereços de um filtro no formato eMule dentro
  de um zip, por exemplo do emule-security.org.

### Proxy

![Proxy](images/en-US/preferences-proxy.png)

Proxy HTTP ou SOCKS4/5, com ou sem senha, e o que passa por ele:
resolução de nomes, conexões com pares e trackers.

### Avançado

![Avançado](images/en-US/preferences-advanced.png)

Todas as configurações do libtorrent. Selecione uma para ler a descrição
abaixo da lista. Altere-as só se souber o que fazem;
**Restaurar padrões** as restaura.


## Vindo do PicoTorrent ou qBittorrent

- **Arquivo > Import from PicoTorrent**: escolha `PicoTorrent.sqlite`
  (ao lado de um PicoTorrent portátil ou em `%LOCALAPPDATA%\PicoTorrent`).
  Os torrents e seus rótulos são adicionados; o arquivo é apenas lido.
  Para levar tudo, configurações incluídas, copie `PicoTorrent.sqlite` para
  junto de `RePicoTorrent.exe` antes da primeira execução: ele é
  renomeado para `RePicoTorrent.sqlite`.
- **Arquivo > Import from qBittorrent**: escolha a pasta `BT_backup`
  do qBittorrent (`%LOCALAPPDATA%\qBittorrent\BT_backup`). Progresso,
  trackers, contadores, pastas e comentários são mantidos.

Torrents que já estão na lista são pulados. Não semeie os mesmos torrents
pelos dois clientes ao mesmo tempo.


## Atualizações

A cada início o programa pergunta ao GitHub pela versão mais recente, e
**Ajuda > Verificar atualizações** faz isso a qualquer momento. Se
houver uma versão nova, **Download and install** baixa o zip para o seu
Windows, confere com as somas SHA-256 da versão, substitui os arquivos do
programa e reinicia. Configurações e torrents continuam.


## Atalhos de teclado

| Teclas | Ação |
|---|---|
| Ctrl+O | adicionar torrent |
| Ctrl+U | adicionar links magnet |
| Ctrl+A | selecionar todos os torrents |
| Del | remover os torrents selecionados, manter os dados |
| Shift+Del | remover os torrents selecionados e seus dados |
| F1 | abrir esta documentação |


## Arquivos e linha de comando

Ao lado de `RePicoTorrent.exe`:

- `RePicoTorrent.sqlite`: configurações, torrents e dados de retomada;
- `coredb.sqlite`: traduções (parte do programa);
- `logs`: arquivos de log;
- `Crashpad`: despejos de falhas, nunca enviados;
- `dbip-country-lite.mmdb`: o banco de países.

Linha de comando:

```
RePicoTorrent.exe [--silent] [--save-path=<pasta>] [file.torrent | magnet:?xt=...]...
```

`--silent` adiciona os torrents informados sem a janela de adicionar,
`--save-path` define onde salvá-los.
