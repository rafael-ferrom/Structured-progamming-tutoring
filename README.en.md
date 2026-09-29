🌐 [Português](README.md) · **English**

# 📚 Structured Programming — Tutoring (C Language)

Support repository for the **Structured Programming** tutoring sessions (Computer Engineering), organized according to the course's **Learning Plan**.

For each topic you will find:

- 📖 **Content** — short, direct theory
- 💻 **Commented code** — `exemplo.c`, ready to compile and run
- ✍️ **Theory exercises** and 🛠️ **practical exercises**
- ✅ **Answer key** for both (commented theory answers + tested C solutions)

> 🌐 The repository is bilingual: every `.md` file has a Portuguese version (`file.md`) and an English version (`file.en.md`), and the C code comments are in both languages.  
> **Note:** identifiers (`soma`, `troca`, `Aluno`...) and the messages printed by the programs are in Portuguese (the language of the course), without accents so they display correctly in any terminal.

---

## 🎯 Goal

Help students master programming logic and the C language: functions, pointers, dynamic allocation, structs and files.

## 🗺️ Syllabus map

| Course plan topic | Module |
|-------------------|--------|
| Functions | [01 · Functions](01-funcoes/README.en.md) |
| Variable Addresses · Pointers | [02 · Addresses and pointers](02-enderecos-e-ponteiros/README.en.md) |
| Call by Reference | [03 · Call by reference](03-chamada-por-referencia/README.en.md) |
| Strings (review) · Strings and Pointers · Array of Pointers to Strings | [04 · Strings and pointers](04-strings-e-ponteiros/README.en.md) |
| Dynamic Memory Allocation | [05 · Dynamic allocation](05-alocacao-dinamica/README.en.md) |
| Structs · Matrix of Structs | [06 · Structs](06-estruturas/README.en.md) |
| Pointers and Structs · Structs and Dynamic Allocation | [07 · Pointers and structs](07-ponteiros-e-estruturas/README.en.md) |
| File I/O · File Operations | [08 · Files](08-arquivos/README.en.md) |
| Random Access · Structs and File I/O | [09 · Random access and binary files](09-acesso-aleatorio-e-arquivos-binarios/README.en.md) |

## 📅 Modules × class schedule

| Module | Class(es) in the schedule |
|--------|---------------------------|
| 01 Functions | Class 2 (Aug 10) |
| 02 Addresses and pointers | Class 3 (Aug 17) |
| 03 Call by reference | Class 5 (Aug 24) |
| 05 Dynamic allocation | Class 5 (Aug 24) · Class 7 (Sep 14) |
| 04 Strings and pointers | Class 7 (Sep 14) |
| 06 Structs | Classes 8 (Sep 21) and 10 (Sep 28) |
| 07 Pointers and structs | Class 11 (Oct 5) |
| 08 Files | Class 13 (Oct 26) · Classes 14 (Nov 9) and 16 (Nov 23) |
| 09 Random access | Class 13 (Oct 26) · Classes 14 and 16 |

## 📝 Semester assessments

| Assessment | Date | Where to study |
|------------|------|----------------|
| AC1 — Theory exam | Aug 31, 2026 | Modules 01 to 03 and 05 |
| AC1 — Practical exam | Sep 14, 2026 | Modules 01 to 05 |
| AG — Progress Test | Oct 7, 2026 | As per institutional guidelines |
| AC2 — Theory exam | Oct 19, 2026 | Modules 05 to 07 (Structs and Allocation) |
| AC2 — Practical exam | Oct 26, 2026 | Modules 05 to 07 (Structs and Allocation) |
| AF — Final Exam (theory) | Nov 30, 2026 | **All content** |
| AS — Make-up Exam (theory) | Dec 14, 2026 | **All content** |

> Always confirm the dates on Canvas: the institution may adjust the calendar.

---

## 📂 Repository structure

```
/programacao-estruturada-monitoria
│
├── /Instrucoes
│   ├── configurar-ambiente(.en).md   Install gcc and set up VS Code
│   └── erros-comuns(.en).md          Most frequent compile/run errors
│
├── /01-funcoes
├── /02-enderecos-e-ponteiros
├── /03-chamada-por-referencia
├── /04-strings-e-ponteiros
├── /05-alocacao-dinamica
├── /06-estruturas
├── /07-ponteiros-e-estruturas
├── /08-arquivos
├── /09-acesso-aleatorio-e-arquivos-binarios
│   │
│   ├── README(.en).md              📖 Module theory
│   ├── exemplo.c                   💻 Commented code
│   ├── /exercicios
│   │   ├── teorico(.en).md         ✍️ Theory questions
│   │   └── pratico(.en).md         🛠️ Practical exercises
│   └── /gabarito
│       ├── teorico(.en).md         ✅ Commented answers
│       └── /pratico                ✅ C solutions (ex01_*.c, ex02_*.c, ...)
│
├── /scripts
│   └── verificar_tudo.sh           Compiles and tests all the code
├── /.vscode
│   └── tasks.json                  Build shortcut (Ctrl+Shift+B)
└── .gitignore
```

(`(.en)` means there is a Portuguese file, `name.md`, and an English one, `name.en.md`.)

---

## ▶️ How to compile and run

Inside the module folder:

### Linux / macOS

```bash
gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
./exemplo
```

### Windows (PowerShell)

```powershell
gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo.exe
.\exemplo.exe
```

### In VS Code

Open the `.c` file and press **Ctrl+Shift+B** (uses this repository's `.vscode/tasks.json`). Details in [`Instrucoes/configurar-ambiente.en.md`](Instrucoes/configurar-ambiente.en.md).

> 💡 Always compile with `-Wall -Wextra`: compiler warnings point out most beginner mistakes.

## 🧠 Recommended study method

1. Read the theory (the module's `README.en.md`)
2. Compile and run `exemplo.c`; **modify** the code and watch what changes
3. Solve the **theory exercises** on paper
4. Solve the **practical exercises** on the computer **without looking at the answer key**
5. Compare with the answer key; if your solution is different and correct, great!
6. Redo the exercises you got wrong a few days later

## 🔎 For the tutor: checking the repository

```bash
bash scripts/verificar_tudo.sh              # compiles everything with -Werror and runs the examples
bash scripts/verificar_tudo.sh --sanitize   # same, with AddressSanitizer (detects leaks and invalid accesses)
```

## 🤝 Contributing

Suggestions for new exercises, fixes and improvements are welcome — open an *issue* or a *pull request*.

Possible next steps:

- Extra exercise lists per module (challenge level)
- Alternative solutions and notes on complexity
- Capstone project (full registry with structs, dynamic allocation and files)
- Introduction to ADTs and linked lists (continued in Data Structures)

## 👨‍💻 Author

Tutoring material created by **Rafael Machado**, Structured Programming tutor.
