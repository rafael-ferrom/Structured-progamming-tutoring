/* Ex 2 - Copiar arquivo caractere a caractere contando caracteres e linhas */
/* Ex 2 - Copy a file character by character, counting characters and lines */
#include <stdio.h>

int main(void) {
    FILE *o = fopen("origem.txt", "w");
    if (o == NULL) {
        printf("Erro ao criar origem.txt\n");
        return 1;
    }
    fputs("Primeira linha\n", o);
    fputs("Segunda linha um pouco maior\n", o);
    fputs("Terceira\n", o);
    fclose(o);

    FILE *in = fopen("origem.txt", "r");
    FILE *out = fopen("copia.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Erro ao abrir arquivos.\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }

    int c;
    long caracteres = 0, linhas = 0;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
        caracteres++;
        if (c == '\n')
            linhas++;
    }
    fclose(in);
    fclose(out);

    printf("Copia concluida: %ld caracteres, %ld linhas.\n", caracteres, linhas);
    return 0;
}
