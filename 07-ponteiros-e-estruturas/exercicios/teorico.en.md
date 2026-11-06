🌐 [Português](teorico.md) · **English**

# Module 07 · Theory exercises

**1.** Given `Pessoa *p = &x;`, write in two different ways the statement that assigns 30 to the `idade` field. Why is `*p.idade` wrong?

**2.** Why do we usually pass structs by pointer (with `const` when we only read) instead of by value?

**3.** Find the error:

```c
Aluno *a;
a->ra = 1001;
```

**4.** Consider:

```c
typedef struct { char *nome; int idade; } Contato;
Contato *c = malloc(sizeof(Contato));
c->nome = malloc(20);
```

In what order should the memory be freed? What would happen if we did `free(c)` before `free(c->nome)`?

**5.** To allocate space for `n` structs of type `Produto`, which expression is correct? Justify.

- a) `malloc(n)`
- b) `malloc(n * sizeof(Produto *))`
- c) `malloc(n * sizeof(Produto))`
