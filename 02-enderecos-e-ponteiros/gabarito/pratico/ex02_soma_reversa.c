/* Ex 2 - Soma e impressao reversa usando apenas ponteiros */
/* Ex 2 - Sum and reverse printing using only pointers */
#include <stdio.h>

int main(void) {
    int v[] = {4, 8, 15, 16, 23, 42};
    int n = (int)(sizeof(v) / sizeof(v[0]));

    int soma = 0;
    for (int *p = v; p < v + n; p++)
        soma += *p;
    printf("Soma = %d\n", soma);

    printf("Reverso: ");
    for (int *p = v + n; p > v; )
        printf("%d ", *--p);          /* decrementa e depois le | decrements, then reads */
    printf("\n");
    return 0;
}
