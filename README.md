# 🚀 Guia de Configuração: Workspace ProjetosEmbarcatech

Este repositório foi configurado para permitir o desenvolvimento *Bare Metal* para a placa **BitDogLab (Raspberry Pi Pico W)** diretamente pelo navegador usando o **GitHub Codespaces**, contornando a necessidade de instalações complexas no sistema operacional local.

---

## 🛠️ Como Iniciar o Ambiente

1. No GitHub, clique no botão verde **Code** e selecione a aba **Codespaces**.
2. Clique em **Create codespace on main**.
3. Aguarde a inicialização. Na primeira vez, o GitHub instalará automaticamente o compilador ARM GCC e o SDK da Raspberry Pi Pico dentro do contêiner Linux.

---

## 🔨 Compilando o Projeto

1. Na barra inferior azul do VS Code, clique em **No Kit Selected** (ou selecione o ícone de engrenagem).
2. Escolha o kit: `GCC 10.3.1 arm-none-eabi`.
3. Clique no botão **Compilar** (ícone de engrenagem) na barra inferior.
4. Após a conclusão, o arquivo `main.uf2` estará disponível dentro da pasta `build/`.

---

## ⚡ Gravando na Placa

1. Clique com o botão direito no arquivo `main.uf2` (dentro da pasta `build/`) e selecione **Download**.
2. Coloque sua BitDogLab em modo **BOOTSEL**:
   * Desconecte o cabo USB.
   * Mantenha pressionado o botão branco **BOOTSEL**.
   * Conecte o cabo USB ao computador e solte o botão.
3. Arraste o arquivo `main.uf2` baixado para a unidade de disco que apareceu no seu computador. A placa reiniciará automaticamente.
    * Pode alterar o nome do arquivo, só a parte `main`, depois da instalação e antes de colocar na placa. Por exemplo: `MeuSenhorQueCoisaFacilVouPedirOPixDoAutorParaEnviarCemConto.uf2`.

---

## 📟 Monitor Serial (Sem Instalação)

Como não é necessário instalar o PuTTY ou drivers Zadig para apenas visualizar os logs, recomendamos o uso da **Web Serial API**:

1. Acesse o terminal web (ex: [Google Chrome Labs Serial Terminal](https://googlechromelabs.github.io/serial-terminal/)).
2. Clique em **Connect** e selecione a porta **Board CDC**.
    * Pode ser outro nome, teste removendo a placa, confira as opções, depois conecte o cabo USB novamente, clique na opção que não apareceu sem o cabo conectado.
3. Defina a velocidade (*Baud rate*) para `115200`.

---

## ❓ Problemas Comuns (Troubleshooting)

### 1. O IntelliSense mostra linhas vermelhas no `main.c` (não encontra `pico/stdlib.h`)
* **Causa:** O cache do CMake está corrompido ou apontando para um caminho inexistente do Windows.
* **Solução:** Apague a pasta `build/` no explorador de ficheiros do VS Code e clique novamente em **Compilar**. Isso força o CMake a mapear o SDK corretamente no ambiente Linux.

### 2. Erro de compilação: `fatal error: cstdlib: No such file or directory`
* **Causa:** A biblioteca padrão de C++ para arquitetura ARM não está instalada no contêiner atual.
* **Solução:** No terminal do Codespaces, execute o comando abaixo:
  ```bash
  sudo apt update && sudo apt install -y libstdc++-arm-none-eabi-newlib
  ```
  > **Nota:** Já atualizamos o `Dockerfile` para que novos ambientes não tenham este problema.

### 3. O arquivo `.uf2` não aparece após a compilação
* **Causa:** O arquivo `CMakeLists.txt` pode estar com erro de sintaxe ou você esqueceu de salvar as alterações antes de compilar.
* **Solução:** Verifique se há uma "bolinha branca" na aba do ficheiro `CMakeLists.txt`. Pressione `Ctrl + S` para salvar e tente compilar novamente.

### 4. A placa não aparece como unidade de disco (RPI-RP2)
* **Causa:** A placa não entrou corretamente no modo BOOTSEL.
* **Solução:** Se estiver a usar a BitDogLab com bateria, certifique-se de que a placa está **totalmente desligada** antes de segurar o botão BOOTSEL e conectar o cabo USB.

### 5. O Monitor Serial não exibe nada ou mostra caracteres estranhos
* **Causa:** Taxa de transmissão (*Baud rate*) incorreta.
* **Solução:** Garanta que a velocidade no terminal web está configurada para `115200`. Verifique também se selecionou a porta **Board CDC**.