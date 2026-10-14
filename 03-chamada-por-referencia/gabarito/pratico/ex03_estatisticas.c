/* Ex 3 - Minimo, maximo e media devolvidos por referencia */
/* Ex 3 - Minimum, maximum and average returned by reference */
#include <stdio.h>

#define MAX 100

void estatisticas(const int *v, int n, int *min, int *max, float *media) {
    int soma = v[0];
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
        soma += v[i];
    }
    *media = (float)soma / n;
}

int main(void) {
    int v[MAX], n;
    printf("Quantos valores (1 a %d)? ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Quantidade invalida.\n");
        return 1;
    }
    printf("Digite os %d valores: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &v[i]) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
    }

    int min, max;
    float media;
    estatisticas(v, n, &min, &max, &media);
    printf("Minimo = %d\nMaximo = %d\nMedia  = %.2f\n", min, max, media);
    return 0;
}
