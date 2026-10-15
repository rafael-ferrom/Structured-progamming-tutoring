/*
 * Modulo 04 - Strings, ponteiros e vetor de ponteiros para strings
 * Module 04 - Strings, pointers and arrays of pointers to strings
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Meu proprio strlen, andando com ponteiro */
/* My own strlen, walking with a pointer */
int tamanho(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}

/* Converte para maiusculas no lugar */
/* Converts to uppercase in place */
void maiusculas(char *s) {
    for (; *s != '\0'; s++)
        *s = (char)toupper((unsigned char)*s);
}

int main(void) {
    /* --- String como vetor --- */
    /* --- String as an array --- */
    char nome[] = "Rafael";                 /* 7 bytes: 6 letras + '\0' | 7 bytes: 6 letters + '\0' */
    printf("nome = \"%s\"\n", nome);
    printf("strlen = %lu | sizeof = %lu\n",
           (unsigned long)strlen(nome), (unsigned long)sizeof(nome));
    printf("tamanho() = %d\n\n", tamanho(nome));

    /* --- Percorrendo com ponteiro --- */
    /* --- Traversing with a pointer --- */
    printf("Caractere a caractere: ");
    for (const char *p = nome; *p != '\0'; p++)
        printf("[%c]", *p);
    printf("\n");

    maiusculas(nome);
    printf("Maiusculas: %s\n\n", nome);

    /* --- strcpy, strcat, strcmp --- */
    char destino[40];
    strcpy(destino, "Programacao");
    strcat(destino, " Estruturada");
    printf("destino = %s\n", destino);

    printf("strcmp(\"abc\", \"abd\") = %s\n",
           strcmp("abc", "abd") < 0 ? "negativo (abc < abd)" : "nao negativo");
    printf("Comparar com == compara ENDERECOS, nao texto!\n\n");

    /* --- Literal x vetor --- */
    /* --- Literal vs. array --- */
    const char *lit = "constante";          /* nao modificar | do not modify */
    printf("Literal: %s (nao pode ser alterado)\n\n", lit);

    /* --- Vetor de ponteiros para strings --- */
    /* --- Array of pointers to strings --- */
    const char *dias[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    int n = (int)(sizeof(dias) / sizeof(dias[0]));

    for (int i = 0; i < n; i++)
        printf("dias[%d] = %-8s | primeira letra: %c | dias[%d][2] = %c\n",
               i, dias[i], dias[i][0], i, dias[i][2]);

    /* --- Ordenar trocando PONTEIROS (nao copia texto) --- */
    /* --- Sorting by swapping POINTERS (text is not copied) --- */
    const char *frutas[] = {"uva", "banana", "maca", "abacaxi", "kiwi"};
    int m = (int)(sizeof(frutas) / sizeof(frutas[0]));

    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if (strcmp(frutas[j], frutas[j + 1]) > 0) {
                const char *tmp = frutas[j];
                frutas[j] = frutas[j + 1];
                frutas[j + 1] = tmp;
            }

    printf("\nFrutas em ordem alfabetica: ");
    for (int i = 0; i < m; i++)
        printf("%s ", frutas[i]);
    printf("\n");

    return 0;
}
