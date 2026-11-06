🌐 **Português** · [English](pratico.en.md)

# Módulo 07 · Exercícios práticos

**Ex 1 — Pessoa por referência.** Crie `Pessoa` (nome[40], idade). Escreva `void inicializa(Pessoa *p, const char *nome, int idade)`, `void faz_aniversario(Pessoa *p)` e `void imprime(const Pessoa *p)`. No `main`, crie uma pessoa, faça dois aniversários e imprima.

**Ex 2 — Vetor dinâmico de produtos.** Leia `n` e depois, para cada produto, o código e o preço. Aloque um vetor dinâmico de `Produto`, imprima os dados, o **valor total** e o **produto mais barato**. Libere a memória.

**Ex 3 — Contato com nome dinâmico.** Crie `Contato { char *nome; long long telefone; }`. Escreva `Contato *cria_contato(const char *nome, long long telefone)` (aloca a struct **e** o nome), `void imprime_contato(const Contato *c)` e `void libera_contato(Contato *c)`. Crie um vetor de 3 ponteiros para `Contato`, imprima e libere tudo.

**Ex 4 — Lista dinâmica de alunos.** Crie `ListaAlunos { Aluno *dados; int n; int cap; }` com funções `lista_inicia`, `lista_adiciona` (dobra a capacidade quando cheia), `lista_imprime`, `lista_media` e `lista_libera`. Comece com capacidade 2 e adicione 7 alunos.
