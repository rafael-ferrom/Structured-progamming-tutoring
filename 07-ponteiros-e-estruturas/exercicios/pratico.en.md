🌐 [Português](pratico.md) · **English**

# Module 07 · Practical exercises

**Ex 1 — Person by reference.** Create `Pessoa` (nome[40], idade). Write `void inicializa(Pessoa *p, const char *nome, int idade)`, `void faz_aniversario(Pessoa *p)` and `void imprime(const Pessoa *p)`. In `main`, create a person, have two birthdays and print.

**Ex 2 — Dynamic array of products.** Read `n` and then, for each product, its code and price. Allocate a dynamic array of `Produto`, print the data, the **total value** and the **cheapest product**. Free the memory.

**Ex 3 — Contact with a dynamic name.** Create `Contato { char *nome; long long telefone; }`. Write `Contato *cria_contato(const char *nome, long long telefone)` (allocates the struct **and** the name), `void imprime_contato(const Contato *c)` and `void libera_contato(Contato *c)`. Create an array of 3 pointers to `Contato`, print and free everything.

**Ex 4 — Dynamic list of students.** Create `ListaAlunos { Aluno *dados; int n; int cap; }` with the functions `lista_inicia`, `lista_adiciona` (doubles the capacity when full), `lista_imprime`, `lista_media` and `lista_libera`. Start with capacity 2 and add 7 students.
