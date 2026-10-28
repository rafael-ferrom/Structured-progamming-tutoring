/*
 * Modulo 05 - Alocacao dinamica de memoria
 * Module 05 - Dynamic memory allocation
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* --- 1. malloc: vetor de tamanho definido em tempo de execucao --- */
    /* --- 1. malloc: array whose size is set at run time --- */
    int n = 5;
    int *v = malloc(n * sizeof(*v));
    if (v == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        v[i] = (i + 1) * 10;

    printf("malloc : ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    /* --- 2. realloc: aumentar o vetor --- */
    /* --- 2. realloc: growing the array --- */
    int novo_n = 8;
    int *aux = realloc(v, novo_n * sizeof(*v));
    if (aux == NULL) {                 /* v continua valido | v is still valid */
        free(v);
        return 1;
    }
    v = aux;
    for (int i = n; i < novo_n; i++)
        v[i] = (i + 1) * 10;
    n = novo_n;

    printf("realloc: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);
    v = NULL;                          /* evita ponteiro pendente | avoids a dangling pointer */

    /* --- 3. calloc: memoria zerada --- */
    /* --- 3. calloc: zero-initialized memory --- */
    int *z = calloc(6, sizeof(*z));
    if (z == NULL) return 1;
    printf("calloc : ");
    for (int i = 0; i < 6; i++)
        printf("%d ", z[i]);
    printf("(tudo zero)\n");
    free(z);

    /* --- 4. matriz dinamica --- */
    /* --- 4. dynamic matrix --- */
    int linhas = 3, colunas = 4;
    int **m = malloc(linhas * sizeof(*m));
    if (m == NULL) return 1;
    for (int i = 0; i < linhas; i++) {
        m[i] = malloc(colunas * sizeof(**m));
        if (m[i] == NULL) {            /* libera o que ja foi alocado | frees what was already allocated */
            for (int k = 0; k < i; k++)
                free(m[k]);
            free(m);
            return 1;
        }
        for (int j = 0; j < colunas; j++)
            m[i][j] = i * colunas + j + 1;
    }

    printf("\nMatriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%3d", m[i][j]);
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
        free(m[i]);                    /* primeiro as linhas... | first the rows... */
    free(m);                           /* ...depois o vetor de ponteiros | ...then the array of pointers */

    return 0;
}
