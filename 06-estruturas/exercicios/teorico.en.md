🌐 [Português](teorico.md) · **English**

# Module 06 · Theory exercises

**1.** Declare a `Livro` (book) struct with a title (up to 60 characters), a year and a price, using `typedef`. What is the advantage of `typedef`?

**2.** What is the output?

```c
typedef struct { int x, y; } Ponto;
Ponto p1 = {1, 2};
Ponto p2 = p1;
p2.x = 99;
printf("%d %d", p1.x, p2.x);
```

**3.** What is the difference between an array and a struct? Give an example of when to use each.

**4.** Given the declarations below, write the statement that assigns `"Salto"` to the city of customer `c`.

```c
typedef struct { char cidade[30]; } Endereco;
typedef struct { char nome[40]; Endereco end; } Cliente;
Cliente c;
```

**5.** If a function is declared as `void reajusta(Produto p)` and changes `p.preco` inside it, does the price of the original product in `main` change? Explain.
