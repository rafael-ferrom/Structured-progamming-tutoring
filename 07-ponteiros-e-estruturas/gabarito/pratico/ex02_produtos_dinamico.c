/* Ex 2 - Vetor dinamico de produtos lido do teclado */
/* Ex 2 - Dynamic array of products read from the keyboard */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   codigo;
    float preco;
} Produto;

int main(void) {
    int n;
    printf("Quantos produtos? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor invalido.\n");
        return 1;
    }

    Produto *v = malloc(n * sizeof(*v));
    if (v == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Produto %d (codigo preco): ", i + 1);
        if (scanf("%d %f", &v[i].codigo, &v[i].preco) != 2) {
            printf("Entrada invalida.\n");
            free(v);
            return 1;
        }
    }

    float total = 0.0f;
    int barato = 0;
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("  codigo %d - R$ %.2f\n", v[i].codigo, v[i].preco);
        total += v[i].preco;
        if (v[i].preco < v[barato].preco)
            barato = i;
    }

    printf("Valor total: R$ %.2f\n", total);
    printf("Mais barato: codigo %d (R$ %.2f)\n", v[barato].codigo, v[barato].preco);

    free(v);
    return 0;
}
