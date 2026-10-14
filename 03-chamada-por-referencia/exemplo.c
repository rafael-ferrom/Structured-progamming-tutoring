/*
 * Modulo 03 - Chamada por referencia
 * Module 03 - Call by reference
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>

void troca_errada(int a, int b);            /* por valor: nao funciona | by value: does not work */
void troca(int *a, int *b);                 /* por referencia: funciona | by reference: works */
void divide(int a, int b, int *q, int *r);  /* varios resultados | multiple results */
void dobra(int *v, int n);                  /* altera o vetor original | changes the original array */
int soma(const int *v, int n);              /* so le: const | read-only: const */
void imprime(const int *v, int n);

int main(void) {
    int x = 1, y = 2;

    troca_errada(x, y);
    printf("Depois de troca_errada: x=%d y=%d\n", x, y);

    troca(&x, &y);
    printf("Depois de troca:        x=%d y=%d\n\n", x, y);

    int q, r;
    divide(17, 5, &q, &r);
    printf("17 / 5 -> quociente=%d resto=%d\n\n", q, r);

    int v[5] = {1, 2, 3, 4, 5};
    int n = (int)(sizeof(v) / sizeof(v[0]));   /* tamanho: so no escopo do vetor | size: only works in the array's scope */
    printf("Antes de dobra:  ");
    imprime(v, n);
    dobra(v, n);
    printf("Depois de dobra: ");
    imprime(v, n);
    printf("Soma = %d\n", soma(v, n));

    return 0;
}

void troca_errada(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;                                /* troca apenas as copias | swaps only the copies */
}

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void divide(int a, int b, int *q, int *r) {
    *q = a / b;
    *r = a % b;
}

void dobra(int *v, int n) {
    for (int i = 0; i < n; i++)
        v[i] *= 2;
}

int soma(const int *v, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}

void imprime(const int *v, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}
