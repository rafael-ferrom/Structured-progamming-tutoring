/* Ex 4 - Copia e inversao com ponteiros */
/* Ex 4 - Copy and reversal with pointers */
#include <stdio.h>

static void imprime(const char *rotulo, const int *v, int n) {
    printf("%s", rotulo);
    for (const int *p = v; p < v + n; p++)
        printf("%d ", *p);
    printf("\n");
}

int main(void) {
    int v[] = {1, 2, 3, 4, 5, 6, 7};
    int n = (int)(sizeof(v) / sizeof(v[0]));
    int w[7];

    /* copia */
    /* copy */
    int *dst = w;
    for (const int *src = v; src < v + n; src++, dst++)
        *dst = *src;

    /* inversao no lugar: dois ponteiros se encontrando */
    /* in-place reversal: two pointers meeting */
    int *ini = w;
    int *fim = w + n - 1;
    while (ini < fim) {
        int tmp = *ini;
        *ini = *fim;
        *fim = tmp;
        ini++;
        fim--;
    }

    imprime("v: ", v, n);
    imprime("w: ", w, n);
    return 0;
}
