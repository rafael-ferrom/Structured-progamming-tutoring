🌐 [Português](README.md) · **English**

# 08 · File I/O and file operations

> **Course plan:** Class 13 (Oct 26) — File I/O · Classes 14 and 16 (Nov 9 and Nov 23) — Exercises with Files

## Goals

- Open, read, write and close text files
- Choose the right open mode
- Read until end of file without falling into the `feof` traps
- Persist data (save it to disk to use later)

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c` (it creates `.txt` files in the current folder)
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. A file in C: `FILE *`

A file is accessed through a `FILE *` pointer, defined in `<stdio.h>`.

```c
FILE *f = fopen("dados.txt", "r");
if (f == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
}
/* ... use f ... */
fclose(f);
```

> **Always** check whether `fopen` returned `NULL` and **always** close with `fclose`.

## 2. Open modes (text)

| Mode | Meaning | If the file doesn't exist | If it exists |
|------|---------|---------------------------|--------------|
| `"r"`  | read | error (`NULL`) | reads from the start |
| `"w"`  | write | creates it | **erases the contents** |
| `"a"`  | append | creates it | writes at the end |
| `"r+"` | read and write | error | keeps the contents |
| `"w+"` | read and write | creates it | **erases the contents** |

For binary files, add `b`: `"rb"`, `"wb"`, `"ab"` (module 09).

## 3. Read and write functions (text)

| Write | Read | Unit |
|-------|------|------|
| `fprintf(f, fmt, ...)` | `fscanf(f, fmt, ...)` | formatted data |
| `fputs(s, f)` | `fgets(s, n, f)` | line |
| `fputc(c, f)` | `fgetc(f)` | character |

`printf(...)` is the same as `fprintf(stdout, ...)`; `scanf(...)` is equivalent to `fscanf(stdin, ...)`.

## 4. Reading until end of file

**Correct way** — use the return value of the read:

```c
int x;
while (fscanf(f, "%d", &x) == 1) {
    /* use x */
}
```

```c
char linha[100];
while (fgets(linha, sizeof(linha), f) != NULL) {
    /* use linha */
}
```

```c
int c;                               /* int, not char! */
while ((c = fgetc(f)) != EOF) {
    /* use c */
}
```

**Wrong way (classic bug):**

```c
while (!feof(f)) {          /* feof only becomes true AFTER trying to read past the end */
    fscanf(f, "%d", &x);    /* the last read fails, but x is used anyway */
    printf("%d\n", x);      /* repeats the last value / prints garbage */
}
```

## 5. Text × binary

- **Text:** human-readable (`fprintf`, `fscanf`); numbers become characters
- **Binary:** bytes copied from memory (`fwrite`, `fread`); smaller, faster, not readable — module 09

## 6. File paths

`"dados.txt"` is relative to the **working directory** the program is run from (in VS Code, usually the project folder — not necessarily the `.c` file's folder). If you get `NULL`, check where you're running it.

## 7. Common mistakes

- Not checking the return of `fopen`
- Opening with `"w"` a file you wanted to keep (erases everything!)
- Forgetting `fclose` (data may not reach the disk)
- Using `while (!feof(f))`
- Storing `fgetc` in a `char` (prevents detecting `EOF`)
- Reading names with spaces using `%s` in `fscanf`

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
