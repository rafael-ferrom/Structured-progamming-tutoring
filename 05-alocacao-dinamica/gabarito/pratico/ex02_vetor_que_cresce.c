/* Ex 2 - Vetor dinamico que dobra de capacidade com realloc */
/* Ex 2 - Dynamic array that doubles its capacity with realloc */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidade = 2;
    int qtd = 0;
    int *v = malloc(capacidade * sizeof(*v));
    if (v == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    printf("Digite inteiros (0 para terminar):\n");
    int x;
    while (scanf("%d", &x) == 1 && x != 0) {
        if (qtd == capacidade) {
            int nova = capacidade * 2;
            int *aux = realloc(v, nova * sizeof(*v));
            if (aux == NULL) {          /* v ainda e valido | v is still valid */
                printf("Sem memoria!\n");
                free(v);
                return 1;
            }
            v = aux;
            capacidade = nova;
        }
        v[qtd++] = x;
    }

    long soma = 0;
    for (int i = 0; i < qtd; i++)
        soma += v[i];

    printf("Quantidade = %d | Soma = %ld | Capacidade final = %d\n",
           qtd, soma, capacidade);

    free(v);
    return 0;
}
