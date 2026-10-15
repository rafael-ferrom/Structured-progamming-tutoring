/* Ex 4 - Ordenar vetor de ponteiros para strings (troca de ponteiros) */
/* Ex 4 - Sort an array of pointers to strings (pointer swapping) */
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *nomes[] = {
        "Marcos", "Ana", "Juliana", "Bruno", "Carla", "Alberto"
    };
    int n = (int)(sizeof(nomes) / sizeof(nomes[0]));

    /* bubble sort: troca apenas os ponteiros */
    /* bubble sort: swaps only the pointers */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                const char *tmp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = tmp;
            }
        }
    }

    printf("Nomes em ordem alfabetica:\n");
    for (int i = 0; i < n; i++)
        printf("  %d. %s\n", i + 1, nomes[i]);

    const char *maior = nomes[0];
    for (int i = 1; i < n; i++)
        if (strlen(nomes[i]) > strlen(maior))
            maior = nomes[i];
    printf("Nome mais longo: %s (%lu letras)\n", maior, (unsigned long)strlen(maior));
    return 0;
}
