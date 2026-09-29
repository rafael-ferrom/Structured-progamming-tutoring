/* Ex 1 - Maximo de tres inteiros */
/* Ex 1 - Maximum of three integers */
#include <stdio.h>

int maximo(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

int main(void) {
    int a, b, c;
    printf("Digite tres inteiros: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }
    printf("Maior valor: %d\n", maximo(a, b, c));
    return 0;
}
