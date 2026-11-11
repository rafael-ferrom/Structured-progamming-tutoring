🌐 [Português](README.md) · **English**

# 09 · Random access and structs in files

> **Course plan:** Class 13 (Oct 26) — Random Access with Files · Classes 14 and 16 — Exercises with Files  
> Syllabus: *Random Access* · *Structs and File I/O*

## Goals

- Write and read **blocks of bytes** with `fwrite` and `fread`
- Move around inside a file with `fseek`, `ftell` and `rewind` (random access)
- Store **structs** in binary files
- Read, change and search a record without scanning the whole file

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c` (it creates `alunos.bin` in the working folder)
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. Binary files

Open them with a mode ending in `b`: `"rb"`, `"wb"`, `"ab"`, `"rb+"`, `"wb+"`.

```c
FILE *f = fopen("dados.bin", "wb");
```

## 2. `fwrite` and `fread`

```c
size_t fwrite(const void *ptr, size_t tamanho, size_t quantidade, FILE *f);
size_t fread (      void *ptr, size_t tamanho, size_t quantidade, FILE *f);
```

Both return **how many elements** were actually written/read — compare with the expected value:

```c
int v[5] = {1, 2, 3, 4, 5};
if (fwrite(v, sizeof(int), 5, f) != 5) { /* error */ }
```

## 3. Structs in a file

With `fwrite` we write the whole struct at once:

```c
typedef struct {
    int   ra;
    char  nome[30];      /* fixed-size array */
    float nota;
} Registro;

Registro r = {1001, "Ana", 8.5f};
fwrite(&r, sizeof(Registro), 1, f);
```

Each record takes exactly `sizeof(Registro)` bytes, so the record with index `i` starts at byte `i * sizeof(Registro)`.

> ⚠️ **Don't write structs that contain pointers** (`char *nome`): the file would store only the *address*, which is meaningless in the next run. Use fixed-size arrays.  
> A binary file may also vary between computers/compilers (size of `int`, alignment); for teaching purposes in the same environment it is safe.

## 4. Random access: `fseek`, `ftell`, `rewind`

```c
int  fseek(FILE *f, long deslocamento, int origem);
long ftell(FILE *f);
void rewind(FILE *f);
```

| Origin | Meaning |
|--------|---------|
| `SEEK_SET` | start of the file |
| `SEEK_CUR` | current position |
| `SEEK_END` | end of the file |

Examples:

```c
fseek(f, i * sizeof(Registro), SEEK_SET);  /* go to record i */
fseek(f, 0, SEEK_END);                     /* go to the end */
long bytes = ftell(f);                     /* current position = size, if at the end */
rewind(f);                                 /* back to the start */
```

**How many records does the file have?**

```c
fseek(f, 0, SEEK_END);
long total = ftell(f) / (long)sizeof(Registro);
```

## 5. Updating a record in place

Use `"rb+"` (reads and writes **without erasing**):

```c
fseek(f, i * sizeof(Registro), SEEK_SET);
fread(&r, sizeof(Registro), 1, f);        /* read */
r.nota = 10.0f;                           /* change */
fseek(f, i * sizeof(Registro), SEEK_SET); /* go back to the start of the record! */
fwrite(&r, sizeof(Registro), 1, f);       /* overwrite */
```

> After the `fread` the position has advanced; you must `fseek` back before rewriting. An `fseek`/`fflush` is also required when switching between reading and writing on the same file.

`"wb"` would **erase** the file — never use it to update.

## 6. Common mistakes

- Forgetting the `b` in the mode (problems on Windows)
- Writing a struct that has a pointer
- Forgetting the `&` when writing/reading a simple struct (`fwrite(&r, ...)`); for arrays, the array name is already the address
- Not moving back before rewriting
- Swapping `fread` for `fscanf` (different formats!)
- Reading past the end: always compare the return value of `fread`

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
