🌐 **Português** · [English](configurar-ambiente.en.md)

# Configurando o ambiente para programar em C

## 1. Instalar o compilador (gcc)

### Windows

1. Instale o **MSYS2** (https://www.msys2.org) e, no terminal *MSYS2 UCRT64*, rode:
   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc
   ```
2. Adicione `C:\msys64\ucrt64\bin` à variável de ambiente **Path**
3. Abra um novo PowerShell e confirme:
   ```powershell
   gcc --version
   ```

(Alternativas usadas em aula: Dev-C++ ou Code::Blocks, que já trazem o compilador.)

### Linux (Debian/Ubuntu)

```bash
sudo apt update && sudo apt install build-essential gdb
```

### macOS

```bash
xcode-select --install
```

## 2. Visual Studio Code

1. Instale a extensão **C/C++** (Microsoft)
2. Abra a **pasta do repositório** (`File > Open Folder`), não apenas um arquivo
3. Abra qualquer `.c` e pressione **Ctrl+Shift+B** para compilar (usa `.vscode/tasks.json`)
4. Execute no terminal integrado (`Ctrl+'`):
   - Windows: `.\exemplo.exe`
   - Linux/macOS: `./exemplo`

Para depurar, use a extensão C/C++ (`F5`) — o parâmetro `-g` do task já inclui as informações de depuração.

## 3. Compilando pelo terminal

```bash
gcc -Wall -Wextra -std=c11 arquivo.c -o programa
```

| Opção | Para que serve |
|-------|----------------|
| `-Wall -Wextra` | mostra avisos importantes |
| `-std=c11` | usa o padrão C11 |
| `-g` | informações para depuração |
| `-o programa` | nome do executável |
| `-fsanitize=address,undefined` | detecta vazamentos e acessos inválidos à memória (Linux/macOS/WSL) |

Se o programa usa `<math.h>` (ex.: `sqrt`), acrescente `-lm` no final no Linux.

## 4. Acentos no terminal do Windows

Os códigos deste repositório imprimem mensagens **sem acentos** para evitar caracteres estranhos no PowerShell. Se quiser acentos nos seus programas, rode antes:

```powershell
chcp 65001
```

e salve o arquivo `.c` em UTF-8.

## 5. Onde o programa procura arquivos?

Nos módulos 08 e 09 os programas criam arquivos (`.txt`, `.bin`) na **pasta em que você executa** o programa — execute-o de dentro da pasta do módulo.

## 6. Verificando vazamentos de memória

No Linux/WSL:

```bash
gcc -g -fsanitize=address,undefined arquivo.c -o programa && ./programa
```

ou, se tiver o valgrind instalado: `valgrind --leak-check=full ./programa`
