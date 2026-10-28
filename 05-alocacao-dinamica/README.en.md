🌐 [Português](README.md) · **English**

# 05 · Dynamic memory allocation

> **Course plan:** Class 5 (Aug 24) — Dynamic Memory Allocation · Class 7 (Sep 14) — Strings and Dynamic Allocation review

## Goals

- Tell the stack from the heap
- Use `malloc`, `calloc`, `realloc` and `free`
- Create arrays and matrices whose size is only known at run time
- Avoid memory leaks and dangling pointers

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c`
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. Why allocate dynamically?

Ordinary arrays (`int v[100]`) have a fixed size set at compile time. With **dynamic allocation** the program asks the system for memory **while running**, in the amount it needs, and gives it back when done.

| | Stack | Heap |
|---|---|---|
| Managed by | the compiler | **you** |
| Lifetime | until the end of the block/function | until you call `free` |
| Size | small and fixed | large and flexible |

## 2. `<stdlib.h>` functions

| Function | What it does |
|----------|--------------|
| `malloc(bytes)` | reserves `bytes` without initializing |
| `calloc(n, size)` | reserves `n * size` bytes **zeroed** |
| `realloc(p, new)` | resizes the block (may move it!) |
| `free(p)` | gives the block back to the system |

All of them (except `free`) return `NULL` when memory runs out — **always check**.

### Usage pattern

```c
int *v = malloc(n * sizeof(int));     /* or sizeof(*v) */
if (v == NULL) {
    printf("Sem memoria!\n");
    return 1;
}
/* ... use v[0] .. v[n-1] ... */
free(v);
v = NULL;                             /* avoids a dangling pointer */
```

> Use `sizeof(*v)` or `sizeof(type)` — never "guess" the number of bytes.

## 3. Using `realloc` safely

```c
int *novo = realloc(v, novo_tam * sizeof(int));
if (novo == NULL) {        /* v is still valid! */
    free(v);
    return 1;
}
v = novo;
```

If you wrote `v = realloc(v, ...)` and it failed, you would lose the original address (a leak).

A common strategy for a growing array: **double the capacity** when it fills up.

## 4. Dynamic matrix

An array of pointers, each one pointing to a row:

```c
int **m = malloc(linhas * sizeof(int *));
for (int i = 0; i < linhas; i++)
    m[i] = malloc(colunas * sizeof(int));
/* use: m[i][j] */
for (int i = 0; i < linhas; i++)
    free(m[i]);          /* free each row... */
free(m);                 /* ...then the array of pointers */
```

## 5. Classic problems

| Problem | What it is |
|---------|------------|
| **Memory leak** | losing the pointer without calling `free` |
| **Dangling pointer** | using the pointer after `free` |
| **Double free** | calling `free` twice on the same block |
| **Overflow** | writing outside the allocated block |

Golden rule: **for every `malloc`, a `free`**.

Tip to check for leaks (Linux/WSL): `valgrind ./program`

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
