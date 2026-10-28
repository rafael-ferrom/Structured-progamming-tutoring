🌐 **Português** · [English](pratico.en.md)

# Módulo 05 · Exercícios práticos

**Ex 1 — Vetor dinâmico.** Leia `n`, aloque um vetor de `n` inteiros, preencha com os quadrados `1, 4, 9, ...`, imprima, calcule a média e libere a memória.

**Ex 2 — Vetor que cresce.** Leia números inteiros até o usuário digitar `0`. Guarde-os em um vetor dinâmico que começa com capacidade 2 e **dobra** quando enche (`realloc`). Ao final, mostre a quantidade, a soma e a capacidade final.

**Ex 3 — Matriz dinâmica e transposta.** Leia `linhas` e `colunas`, aloque uma matriz preenchida com `1, 2, 3, ...`, aloque sua **transposta** e imprima as duas. Crie funções `aloca_matriz` e `libera_matriz`.

**Ex 4 — Concatenação.** Escreva `int *concatena(const int *a, int na, const int *b, int nb, int *ntotal)` que devolve um **novo** vetor dinâmico com os elementos de `a` seguidos dos de `b`. Teste no `main` e libere a memória.
