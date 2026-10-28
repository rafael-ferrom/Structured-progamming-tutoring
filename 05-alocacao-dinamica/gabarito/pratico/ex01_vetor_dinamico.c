/* Ex 1 - Vetor dinamico com quadrados */
/* Ex 1 - Dynamic array of squares */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quantos elementos? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor invalido.\n");
        return 1;
    }

    int *v = malloc(n * sizeof(*v));
    if (v == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    long soma = 0;
    for (int i = 0; i < n; i++) {
        v[i] = (i + 1) * (i + 1);
        soma += v[i];
    }

    printf("Vetor: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\nMedia = %.2f\n", (double)soma / n);

    free(v);
    return 0;
}
