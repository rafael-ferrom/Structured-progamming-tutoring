/* Ex 4 - Concatenar dois vetores em um novo vetor dinamico */
/* Ex 4 - Concatenate two arrays into a new dynamic array */
#include <stdio.h>
#include <stdlib.h>

int *concatena(const int *a, int na, const int *b, int nb, int *ntotal) {
    int *r = malloc((na + nb) * sizeof(*r));
    if (r == NULL) {
        *ntotal = 0;
        return NULL;
    }
    for (int i = 0; i < na; i++)
        r[i] = a[i];
    for (int i = 0; i < nb; i++)
        r[na + i] = b[i];
    *ntotal = na + nb;
    return r;
}

int main(void) {
    int a[] = {1, 2, 3};
    int b[] = {10, 20, 30, 40};
    int total;

    int *c = concatena(a, 3, b, 4, &total);
    if (c == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    printf("Resultado (%d elementos): ", total);
    for (int i = 0; i < total; i++)
        printf("%d ", c[i]);
    printf("\n");

    free(c);
    return 0;
}
