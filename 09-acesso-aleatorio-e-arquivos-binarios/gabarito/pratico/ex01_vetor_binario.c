/* Ex 1 - Gravar e ler um vetor de inteiros em binario */
/* Ex 1 - Write and read an integer array in binary */
#include <stdio.h>

int main(void) {
    int v[10], lido[10];
    for (int i = 0; i < 10; i++)
        v[i] = (i + 1) * 3;

    FILE *f = fopen("vetor.bin", "wb");
    if (f == NULL) {
        printf("Erro ao criar vetor.bin\n");
        return 1;
    }
    if (fwrite(v, sizeof(int), 10, f) != 10) {
        printf("Erro ao gravar.\n");
        fclose(f);
        return 1;
    }
    fclose(f);

    f = fopen("vetor.bin", "rb");
    if (f == NULL) {
        printf("Erro ao abrir vetor.bin\n");
        return 1;
    }
    if (fread(lido, sizeof(int), 10, f) != 10) {
        printf("Erro ao ler.\n");
        fclose(f);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long bytes = ftell(f);
    fclose(f);

    printf("Vetor lido: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", lido[i]);
    printf("\nTamanho do arquivo: %ld bytes (esperado: %lu)\n",
           bytes, (unsigned long)(10 * sizeof(int)));
    return 0;
}
