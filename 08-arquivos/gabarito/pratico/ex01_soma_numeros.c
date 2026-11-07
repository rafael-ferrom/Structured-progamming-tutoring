/* Ex 1 - Gravar 1..10 em arquivo e ler para somar */
/* Ex 1 - Write 1..10 to a file and read it back to sum */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("numeros.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar numeros.txt\n");
        return 1;
    }
    for (int i = 1; i <= 10; i++)
        fprintf(f, "%d\n", i);
    fclose(f);

    f = fopen("numeros.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir numeros.txt\n");
        return 1;
    }

    int x, soma = 0, qtd = 0;
    while (fscanf(f, "%d", &x) == 1) {
        soma += x;
        qtd++;
    }
    fclose(f);

    printf("Lidos %d numeros | Soma = %d | Media = %.2f\n",
           qtd, soma, qtd > 0 ? (double)soma / qtd : 0.0);
    return 0;
}
