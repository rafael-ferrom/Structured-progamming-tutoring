/* Ex 4 - MDC (Euclides) e MMC */
/* Ex 4 - GCD (Euclid) and LCM */
#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int mmc(int a, int b) {
    return a / mdc(a, b) * b;   /* divide antes para evitar overflow | divides first to avoid overflow */
}

int main(void) {
    int a, b;
    printf("Digite dois inteiros positivos: ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Entrada invalida.\n");
        return 1;
    }
    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    printf("MMC(%d, %d) = %d\n", a, b, mmc(a, b));
    return 0;
}
