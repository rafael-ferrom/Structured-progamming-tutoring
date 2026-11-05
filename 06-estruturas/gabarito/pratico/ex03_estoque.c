/* Ex 3 - Estoque de produtos */
/* Ex 3 - Product inventory */
#include <stdio.h>

#define N 5

typedef struct {
    int   codigo;
    char  nome[30];
    float preco;
    int   estoque;
} Produto;

int main(void) {
    Produto p[N] = {
        {101, "Teclado",    89.90f, 25},
        {102, "Mouse",      45.50f,  8},
        {103, "Monitor",   899.00f,  4},
        {104, "Cabo HDMI",  19.90f, 60},
        {105, "Webcam",    159.00f,  9}
    };

    int mais_caro = 0;
    float total = 0.0f;
    for (int i = 0; i < N; i++) {
        if (p[i].preco > p[mais_caro].preco)
            mais_caro = i;
        total += p[i].preco * p[i].estoque;
    }

    printf("Produto mais caro: %s (R$ %.2f)\n", p[mais_caro].nome, p[mais_caro].preco);
    printf("Valor total do estoque: R$ %.2f\n", total);

    printf("Estoque baixo (< 10):\n");
    for (int i = 0; i < N; i++)
        if (p[i].estoque < 10)
            printf("  [%d] %s - %d unidades\n", p[i].codigo, p[i].nome, p[i].estoque);
    return 0;
}
