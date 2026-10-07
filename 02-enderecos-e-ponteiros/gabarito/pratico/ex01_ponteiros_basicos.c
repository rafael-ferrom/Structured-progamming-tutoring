/* Ex 1 - Ponteiros basicos */
/* Ex 1 - Basic pointers */
#include <stdio.h>

int main(void) {
    int i = 10;
    float f = 3.5f;
    char c = 'A';

    int *pi = &i;
    float *pf = &f;
    char *pc = &c;

    printf("Antes:\n");
    printf("  i = %d   (endereco %p)\n", *pi, (void *)pi);
    printf("  f = %.1f (endereco %p)\n", *pf, (void *)pf);
    printf("  c = %c   (endereco %p)\n", *pc, (void *)pc);

    *pi = 20;
    *pf = 7.25f;
    *pc = 'Z';

    printf("Depois (variaveis originais):\n");
    printf("  i = %d\n  f = %.2f\n  c = %c\n", i, f, c);
    return 0;
}
