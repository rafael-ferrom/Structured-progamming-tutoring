🌐 [Português](configurar-ambiente.md) · **English**

# Setting up your environment to program in C

## 1. Install the compiler (gcc)

### Windows

1. Install **MSYS2** (https://www.msys2.org) and, in the *MSYS2 UCRT64* terminal, run:
   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc
   ```
2. Add `C:\msys64\ucrt64\bin` to the **Path** environment variable
3. Open a new PowerShell and check:
   ```powershell
   gcc --version
   ```

(Alternatives used in class: Dev-C++ or Code::Blocks, which already ship with the compiler.)

### Linux (Debian/Ubuntu)

```bash
sudo apt update && sudo apt install build-essential gdb
```

### macOS

```bash
xcode-select --install
```

## 2. Visual Studio Code

1. Install the **C/C++** extension (Microsoft)
2. Open the **repository folder** (`File > Open Folder`), not just a file
3. Open any `.c` file and press **Ctrl+Shift+B** to compile (uses `.vscode/tasks.json`)
4. Run in the integrated terminal (`Ctrl+'`):
   - Windows: `.\exemplo.exe`
   - Linux/macOS: `./exemplo`

To debug, use the C/C++ extension (`F5`) — the task's `-g` flag already includes debug information.

## 3. Compiling from the terminal

```bash
gcc -Wall -Wextra -std=c11 arquivo.c -o programa
```

| Option | What it does |
|--------|--------------|
| `-Wall -Wextra` | shows important warnings |
| `-std=c11` | uses the C11 standard |
| `-g` | debug information |
| `-o programa` | executable name |
| `-fsanitize=address,undefined` | detects leaks and invalid memory access (Linux/macOS/WSL) |

If the program uses `<math.h>` (e.g. `sqrt`), add `-lm` at the end on Linux.

## 4. Accents in the Windows terminal

The code in this repository prints messages **without accents** to avoid strange characters in PowerShell. If you want accents in your own programs, run this first:

```powershell
chcp 65001
```

and save the `.c` file as UTF-8.

## 5. Where does the program look for files?

In modules 08 and 09 the programs create files (`.txt`, `.bin`) in the **folder you run the program from** — run it from inside the module folder.

## 6. Checking for memory leaks

On Linux/WSL:

```bash
gcc -g -fsanitize=address,undefined arquivo.c -o programa && ./programa
```

or, if you have valgrind installed: `valgrind --leak-check=full ./programa`
