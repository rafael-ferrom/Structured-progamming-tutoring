/* Ex 4 - Busca que devolve a posicao por referencia */
/* Ex 4 - Search that returns the position by reference */
#include <stdio.h>

int busca(const int *v, int n, int alvo, int *pos) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            *pos = i;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int v[] = {12, 7, 30, 5, 18, 7};
    int n = (int)(sizeof(v) / sizeof(v[0]));
    int alvos[] = {30, 7, 99};

    for (int i = 0; i < 3; i++) {
        int pos;
        if (busca(v, n, alvos[i], &pos))
            printf("%d encontrado na posicao %d\n", alvos[i], pos);
        else
            printf("%d nao encontrado\n", alvos[i]);
    }
    return 0;
}
