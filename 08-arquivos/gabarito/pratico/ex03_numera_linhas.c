/* Ex 3 - Numerar linhas e achar a mais longa */
/* Ex 3 - Number the lines and find the longest one */
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *f = fopen("texto.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar texto.txt\n");
        return 1;
    }
    fputs("C e uma linguagem estruturada\n", f);
    fputs("Ponteiros guardam enderecos\n", f);
    fputs("Structs agrupam campos\n", f);
    fputs("Arquivos guardam dados em disco\n", f);
    fputs("Fim\n", f);
    fclose(f);

    f = fopen("texto.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir texto.txt\n");
        return 1;
    }

    char linha[100], maior[100] = "";
    int n = 0, n_maior = 0;
    while (fgets(linha, sizeof(linha), f) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        n++;
        printf("%d: %s\n", n, linha);
        if (strlen(linha) > strlen(maior)) {
            strcpy(maior, linha);
            n_maior = n;
        }
    }
    fclose(f);

    printf("\nLinha mais longa (%d): \"%s\" com %lu caracteres\n",
           n_maior, maior, (unsigned long)strlen(maior));
    return 0;
}
