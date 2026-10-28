/* Ex 3 - Matriz dinamica e sua transposta */
/* Ex 3 - Dynamic matrix and its transpose */
#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int linhas, int colunas) {
    int **m = malloc(linhas * sizeof(*m));
    if (m == NULL) return NULL;

    for (int i = 0; i < linhas; i++) {
        m[i] = malloc(colunas * sizeof(**m));
        if (m[i] == NULL) {
            for (int k = 0; k < i; k++)
                free(m[k]);
            free(m);
            return NULL;
        }
    }
    return m;
}

void libera_matriz(int **m, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(m[i]);
    free(m);
}

void imprime_matriz(int **m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

int main(void) {
    int l, c;
    printf("Linhas e colunas: ");
    if (scanf("%d %d", &l, &c) != 2 || l <= 0 || c <= 0) {
        printf("Valores invalidos.\n");
        return 1;
    }

    int **m = aloca_matriz(l, c);
    int **t = aloca_matriz(c, l);          /* transposta: c x l | transpose: c x l */
    if (m == NULL || t == NULL) {
        printf("Sem memoria!\n");
        if (m) libera_matriz(m, l);
        if (t) libera_matriz(t, c);
        return 1;
    }

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) {
            m[i][j] = i * c + j + 1;
            t[j][i] = m[i][j];
        }

    printf("\nMatriz (%dx%d):\n", l, c);
    imprime_matriz(m, l, c);
    printf("\nTransposta (%dx%d):\n", c, l);
    imprime_matriz(t, c, l);

    libera_matriz(m, l);
    libera_matriz(t, c);
    return 0;
}
