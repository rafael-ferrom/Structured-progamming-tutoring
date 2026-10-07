🌐 [Português](README.md) · **English**

# 02 · Variable addresses and pointers

> **Course plan:** Class 3 (Aug 17) — Variable Addresses / Pointers

## Goals

- Understand that every variable occupies an address in memory
- Use the `&` (address-of) and `*` (dereference) operators
- Declare, initialize and use pointers
- Walk through arrays using pointer arithmetic

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c` (addresses change on every run — that's normal)
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. Memory and addresses

Memory is a sequence of numbered bytes. Each variable occupies some bytes; the number of its first byte is the variable's **address**.

```c
int idade = 22;
printf("%p\n", (void *)&idade);   /* prints the address, e.g. 0x7ffd1c2a */
```

## 2. Pointers

A **pointer** is a variable that stores an **address**.

```c
int idade = 22;
int *p = &idade;    /* p points to idade */
```

| Expression | Meaning |
|------------|---------|
| `&idade`  | address of `idade` |
| `p`       | the address stored in `p` |
| `*p`      | the value **pointed to** by `p` (dereference) |
| `&p`      | the address of the pointer itself |

```c
*p = 23;            /* changes idade through the pointer */
printf("%d", idade); /* 23 */
```

> The `*` has two roles: in a **declaration** (`int *p`) it says `p` is a pointer; in an **expression** (`*p`) it accesses the content.

## 3. Null pointer and uninitialized pointer

- `int *p = NULL;` — points to "nowhere". Always test `if (p != NULL)` before using it
- `int *p;` (uninitialized) — points to garbage. Using `*p` is **undefined behavior** (may crash the program)

## 4. Pointers and arrays

An array's name is (almost always) the address of its first element:

```c
int v[3] = {10, 20, 30};
int *p = v;          /* same as &v[0] */
```

Pointer arithmetic: adding 1 advances **one element** (not one byte).

| Array | Pointer |
|-------|---------|
| `v[i]` | `*(p + i)` |
| `&v[i]` | `p + i` |

```c
for (int *q = v; q < v + 3; q++)
    printf("%d ", *q);
```

Subtracting two pointers into the same array gives the **distance in elements**: `(q - v)` is the index of `q`.

## 5. Sizes

- `sizeof(int)` is usually 4 bytes
- `sizeof(int *)` is 8 bytes on 64-bit systems (regardless of the pointed type)

## 6. Common mistakes

- Using an uninitialized pointer
- Confusing `p` (address) with `*p` (value)
- Forgetting the `&` in `scanf`
- Going out of array bounds with pointer arithmetic

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
