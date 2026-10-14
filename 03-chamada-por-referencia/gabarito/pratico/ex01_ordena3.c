/* Ex 1 - Ordenar tres valores com troca por referencia */
/* Ex 1 - Sort three values using a swap by reference */
#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ordena3(int *a, int *b, int *c) {
    if (*a > *b) troca(a, b);
    if (*b > *c) troca(b, c);
    if (*a > *b) troca(a, b);
}

int main(void) {
    int x, y, z;
    printf("Digite tres inteiros: ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }
    ordena3(&x, &y, &z);
    printf("Ordenados: %d %d %d\n", x, y, z);
    return 0;
}
