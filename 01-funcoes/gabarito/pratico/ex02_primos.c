/* Ex 2 - Primos de 1 a 50 */
/* Ex 2 - Primes from 1 to 50 */
#include <stdio.h>

int eh_primo(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0) return 0;
    return 1;
}

int main(void) {
    printf("Primos de 1 a 50:\n");
    for (int i = 1; i <= 50; i++)
        if (eh_primo(i))
            printf("%d ", i);
    printf("\n");
    return 0;
}
