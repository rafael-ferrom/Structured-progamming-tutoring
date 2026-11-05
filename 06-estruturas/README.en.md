🌐 [Português](README.md) · **English**

# 06 · Structs and matrices of structs

> **Course plan:** Class 8 (Sep 21) and Class 10 (Sep 28) — Structs and Matrix of Structs

## Goals

- Group data of different types into a single `struct`
- Use `typedef` to simplify the code
- Work with **arrays** and **matrices** of structs
- Pass structs to functions

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c`
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. What is a struct?

An array groups elements of the **same type**. A `struct` groups fields of **different types** under a single name:

```c
struct Aluno {
    char  nome[50];
    int   ra;
    float nota;
};

struct Aluno a1;
```

### With `typedef` (more common)

```c
typedef struct {
    char  nome[50];
    int   ra;
    float nota;
} Aluno;

Aluno a1;        /* no need to write "struct" */
```

## 2. Accessing fields: the `.` operator

```c
a1.ra = 1001;
a1.nota = 8.5f;
strcpy(a1.nome, "Ana");     /* string: you do NOT assign with =, use strcpy */
```

### Initialization

```c
Aluno a2 = {"Bruno", 1002, 7.0f};
```

### Assignment between structs

`a3 = a2;` **copies all fields** (including arrays inside the struct).

## 3. Nested structs

```c
typedef struct { char cidade[30]; char uf[3]; } Endereco;
typedef struct { char nome[50]; Endereco end; } Cliente;

Cliente c;
strcpy(c.end.cidade, "Campinas");
```

## 4. Array of structs

```c
Aluno turma[3] = {
    {"Ana",   1001, 8.5f},
    {"Bruno", 1002, 7.0f},
    {"Carla", 1003, 9.0f}
};
for (int i = 0; i < 3; i++)
    printf("%s: %.1f\n", turma[i].nome, turma[i].nota);
```

## 5. Matrix of structs

A matrix where each cell is a `struct`:

```c
Aluno turmas[2][3];        /* 2 classes x 3 students */
turmas[1][2].nota = 9.5f;  /* student 2 of class 1 */
```

## 6. Structs and functions

- **By value:** `void imprime(Aluno a)` — copies the whole struct (the original doesn't change)
- **By reference:** `void le(Aluno *a)` — module 07

A function can also **return** a struct: `Aluno cria_aluno(...)`.

## 7. Common mistakes

- Assigning a string with `=` (`a.nome = "Ana"` doesn't compile) → use `strcpy`
- Forgetting the `;` after the struct's `}`
- Comparing two structs with `==` (not allowed; compare field by field)
- Forgetting that `sizeof(struct)` may be larger than the sum of the fields (alignment/*padding*)

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
