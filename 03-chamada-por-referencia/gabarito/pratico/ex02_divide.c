/* Ex 2 - Quociente e resto por referencia */
/* Ex 2 - Quotient and remainder by reference */
#include <stdio.h>

void divide(int a, int b, int *q, int *r) {
    *q = a / b;
    *r = a % b;
}

int main(void) {
    int a, b, q, r;
    printf("Digite dividendo e divisor: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Entrada invalida.\n");
        return 1;
    }
    if (b == 0) {
        printf("Divisao por zero!\n");
        return 1;
    }
    divide(a, b, &q, &r);
    printf("%d = %d * %d + %d\n", a, b, q, r);
    return 0;
}
