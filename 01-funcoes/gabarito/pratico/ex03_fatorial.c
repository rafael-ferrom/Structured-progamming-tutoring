/* Ex 3 - Fatorial iterativo e recursivo */
/* Ex 3 - Iterative and recursive factorial */
#include <stdio.h>

long long fatorial_iter(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++)
        r *= i;
    return r;
}

long long fatorial_rec(int n) {
    if (n <= 1) return 1;
    return n * fatorial_rec(n - 1);
}

int main(void) {
    int n;
    printf("Digite n (0 a 20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Valor invalido.\n");
        return 1;
    }
    long long a = fatorial_iter(n);
    long long b = fatorial_rec(n);
    printf("Iterativo: %d! = %lld\n", n, a);
    printf("Recursivo: %d! = %lld\n", n, b);
    printf("%s\n", a == b ? "Resultados iguais." : "Resultados diferentes!");
    return 0;
}
