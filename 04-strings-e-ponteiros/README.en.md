🌐 [Português](README.md) · **English**

# 04 · Strings, pointers and arrays of pointers to strings

> **Course plan:** Strings – review · Strings and Pointers · Array of Pointers to Strings  
> (Class 7, Sep 14 — Strings review)

## Goals

- Review how C represents text (a `char` array ending in `'\0'`)
- Use `<string.h>` and `<ctype.h>`
- Walk through and modify strings using pointers
- Work with **arrays of pointers to strings** (`char *nomes[]`)

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c`
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. Strings in C

There is no "string" type: it's a **`char` array terminated by `'\0'`** (the null character, value 0).

```c
char s[] = "ola";      /* 'o' 'l' 'a' '\0'  -> 4 bytes */
```

The `'\0'` marks the end. Without it, functions can't tell where the string finishes.

## 2. Safe input

| Function | Behavior |
|----------|----------|
| `scanf("%s", s)` | reads up to the first space; does **not** limit the size (dangerous) |
| `scanf("%29s", s)` | limits to 29 characters (for `char s[30]`) |
| `fgets(s, tam, stdin)` | reads the whole line **including `'\n'`**, respecting `tam` |
| `gets` | **never use** (removed in C11) |

Removing the `'\n'` that `fgets` leaves:

```c
s[strcspn(s, "\n")] = '\0';
```

## 3. `<string.h>` functions

| Function | What it does |
|----------|--------------|
| `strlen(s)` | length (without the `'\0'`) |
| `strcpy(dst, src)` | copies `src` into `dst` (`dst` must be big enough!) |
| `strcat(dst, src)` | appends `src` to the end of `dst` |
| `strcmp(a, b)` | 0 if equal; `<0` if `a` < `b`; `>0` if `a` > `b` |
| `strchr(s, c)` | pointer to the 1st occurrence of `c` (or `NULL`) |
| `strstr(s, sub)` | pointer to the 1st occurrence of the substring |

**Never compare strings with `==`**: that compares addresses, not contents.

From `<ctype.h>`: `toupper`, `tolower`, `isalpha`, `isdigit`, `isalnum`, `isspace`.

## 4. Strings and pointers

Since the array name is an address, you can walk through a string with a pointer:

```c
int tamanho(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}
```

### Array × pointer to a literal

```c
char  a[] = "abc";   /* modifiable copy, stored inside the array */
char *b   = "abc";   /* points to a literal: CANNOT be modified */
a[0] = 'X';          /* OK */
/* b[0] = 'X'; */    /* undefined behavior (crash) */
```

Prefer `const char *b = "abc";`.

## 5. Array of pointers to strings

```c
const char *dias[] = {"Seg", "Ter", "Qua"};
```

- `dias[1]` is a `const char *` → `"Ter"`
- `dias[1][0]` → `'T'`
- Each string may have a different length (saves memory compared to `char m[3][20]`)
- Sorting the array only **swaps pointers**, without copying text

Comparison with a `char` matrix:

| | `char m[3][20]` | `const char *v[3]` |
|---|---|---|
| Memory | 60 fixed bytes | 3 pointers + literals |
| Change the text | yes | no (if literals) |
| Swap positions | copy strings (`strcpy`) | swap pointers |

## 6. Common mistakes

- Forgetting room for the `'\0'` (`char s[3] = "abc";` doesn't fit)
- Comparing with `==` instead of `strcmp`
- `strcpy` into a destination smaller than the source (*buffer overflow*)
- Modifying a string literal
- Forgetting to remove the `'\n'` from `fgets`

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
