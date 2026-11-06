🌐 [Português](README.md) · **English**

# 07 · Pointers and structs · Structs and dynamic allocation

> **Course plan:** Class 11 (Oct 5) — Structs and Dynamic Allocation  
> (AC2 — Theory exam Oct 19 and practical exam Oct 26: *Structs and Allocation*)

## Goals

- Use pointers to structs and the `->` operator
- Pass structs **by reference** to functions
- Dynamically allocate a struct and an **array of structs**
- Work with structs that contain pointers (e.g. a dynamic name)
- Build a "dynamic array" wrapped in a struct (the basis of ADTs)

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c`
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. Pointer to struct and the `->` operator

```c
Pessoa p = {"Ana", 22};
Pessoa *pp = &p;

(*pp).idade = 23;    /* parentheses required: . has higher precedence than * */
pp->idade   = 23;    /* equivalent, preferred form */
```

| Variable | Pointer |
|----------|---------|
| `p.idade` | `pp->idade` |

## 2. Passing structs by reference

By value, the **whole** struct is copied (slow if it's big, and it doesn't change the original). By pointer, only the address is copied:

```c
void faz_aniversario(Pessoa *p) { p->idade++; }        /* changes the original */
void imprime(const Pessoa *p)   { printf("%s", p->nome); } /* read-only */
```

Call: `faz_aniversario(&p);`

## 3. Allocating a struct

```c
Pessoa *p = malloc(sizeof(*p));
if (p == NULL) { /* handle the error */ }
p->idade = 20;
free(p);
```

## 4. Dynamic array of structs

```c
Produto *v = malloc(n * sizeof(*v));
for (int i = 0; i < n; i++)
    v[i].preco = 10.0f;      /* v[i] is a struct, so use "." */
free(v);
```

> Careful: `v[i].campo` (dot) or `(v + i)->campo` (arrow). Never `v[i]->campo`.

## 5. Structs with pointers (dynamic fields)

```c
typedef struct {
    char *nome;          /* allocated separately */
    int   idade;
} Contato;
```

The struct's `malloc` does **not** allocate `nome`. You must allocate each part and free them in **reverse order**:

```c
Contato *c = malloc(sizeof(*c));
c->nome = malloc(strlen("Ana") + 1);   /* +1 for the '\0' */
strcpy(c->nome, "Ana");
/* ... */
free(c->nome);    /* 1st: the field */
free(c);          /* 2nd: the struct */
```

## 6. Encapsulated dynamic array

Keep the array, the count and the capacity together:

```c
typedef struct {
    Aluno *dados;
    int    n;        /* how many elements */
    int    cap;      /* how many fit */
} ListaAlunos;
```

This way functions receive just `ListaAlunos *l` — the first step toward **ADTs** and data structures.

## 7. Common mistakes

- Using a struct pointer without allocating/pointing it anywhere (`Pessoa *p; p->idade = 1;`)
- Confusing `.` and `->`
- `malloc(sizeof(Pessoa *))` — allocates only a pointer's size; use `sizeof(Pessoa)` or `sizeof(*p)`
- Forgetting to free the inner fields before the struct
- Calling `free` twice

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
