/*
 * Modulo 08 - Arquivos de texto
 * Module 08 - Text files
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * O programa cria "exemplo_saida.txt" na pasta de execucao.
 * The program creates "exemplo_saida.txt" in the working folder.
 */
#include <stdio.h>

int main(void) {
    const char *nome_arquivo = "exemplo_saida.txt";

    /* --- 1. Escrita com "w" (cria ou APAGA o arquivo) --- */
    /* --- 1. Writing with "w" (creates or ERASES the file) --- */
    FILE *f = fopen(nome_arquivo, "w");
    if (f == NULL) {
        printf("Erro ao criar %s\n", nome_arquivo);
        return 1;
    }
    fprintf(f, "Programacao Estruturada\n");
    fputs("Linguagem C\n", f);
    for (int i = 1; i <= 3; i++)
        fprintf(f, "Linha numero %d\n", i);
    fclose(f);
    printf("Arquivo escrito.\n\n");

    /* --- 2. Acrescentando com "a" --- */
    /* --- 2. Appending with "a" --- */
    f = fopen(nome_arquivo, "a");
    if (f == NULL) return 1;
    fprintf(f, "Linha acrescentada\n");
    fclose(f);

    /* --- 3. Leitura linha a linha com fgets --- */
    /* --- 3. Reading line by line with fgets --- */
    f = fopen(nome_arquivo, "r");
    if (f == NULL) {
        printf("Erro ao abrir %s\n", nome_arquivo);
        return 1;
    }

    printf("Conteudo do arquivo:\n");
    char linha[100];
    int n = 0;
    while (fgets(linha, sizeof(linha), f) != NULL) {
        n++;
        printf("%2d: %s", n, linha);       /* fgets ja guarda o '\n' | fgets already keeps the '\n' */
    }
    fclose(f);
    printf("Total de linhas: %d\n\n", n);

    /* --- 4. Leitura caractere a caractere (int, nao char!) --- */
    /* --- 4. Reading character by character (int, not char!) --- */
    f = fopen(nome_arquivo, "r");
    if (f == NULL) return 1;
    int c, letras = 0;
    while ((c = fgetc(f)) != EOF)
        letras++;
    fclose(f);
    printf("Total de caracteres: %d\n\n", letras);

    /* --- 5. Numeros: escrever e ler com fprintf / fscanf --- */
    /* --- 5. Numbers: writing and reading with fprintf / fscanf --- */
    f = fopen("exemplo_numeros.txt", "w");
    if (f == NULL) return 1;
    for (int i = 1; i <= 5; i++)
        fprintf(f, "%d\n", i * i);
    fclose(f);

    f = fopen("exemplo_numeros.txt", "r");
    if (f == NULL) return 1;
    int x, soma = 0;
    while (fscanf(f, "%d", &x) == 1)       /* forma correta de ler ate o fim | correct way to read until the end */
        soma += x;
    fclose(f);
    printf("Soma dos quadrados lidos do arquivo: %d\n", soma);

    /* --- 6. Testando erro de abertura --- */
    /* --- 6. Testing an open error --- */
    f = fopen("nao_existe.txt", "r");
    if (f == NULL)
        printf("\nfopen devolveu NULL: arquivo inexistente.\n");
    else
        fclose(f);

    return 0;
}
