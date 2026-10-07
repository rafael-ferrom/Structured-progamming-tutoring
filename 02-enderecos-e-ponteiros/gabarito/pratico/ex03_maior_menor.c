/* Ex 3 - Maior e menor com aritmetica de ponteiros */
/* Ex 3 - Largest and smallest using pointer arithmetic */
#include <stdio.h>

int main(void) {
    int v[] = {17, 3, 42, -8, 25, 9, 42, 0};
    int n = (int)(sizeof(v) / sizeof(v[0]));

    int *pmaior = v;
    int *pmenor = v;
    for (int *p = v + 1; p < v + n; p++) {
        if (*p > *pmaior) pmaior = p;
        if (*p < *pmenor) pmenor = p;
    }

    printf("Maior = %d no indice %ld\n", *pmaior, (long)(pmaior - v));
    printf("Menor = %d no indice %ld\n", *pmenor, (long)(pmenor - v));
    return 0;
}
