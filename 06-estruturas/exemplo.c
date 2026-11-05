/*
 * Modulo 06 - Estruturas e matriz de estruturas
 * Module 06 - Structs and matrices of structs
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>
#include <string.h>

typedef struct {
    char  cidade[30];
    char  uf[3];
} Endereco;

typedef struct {
    char     nome[50];
    int      ra;
    float    nota1, nota2;
    Endereco end;                     /* estrutura aninhada | nested struct */
} Aluno;

float media(Aluno a) {                /* recebe uma COPIA | receives a COPY */
    return (a.nota1 + a.nota2) / 2.0f;
}

void imprime(Aluno a) {
    printf("%-12s RA %d | %s-%s | media %.1f\n",
           a.nome, a.ra, a.end.cidade, a.end.uf, media(a));
}

int main(void) {
    /* --- Declarando e preenchendo --- */
    /* --- Declaring and filling --- */
    Aluno a1;
    strcpy(a1.nome, "Ana Souza");     /* string: strcpy, nao = | string: strcpy, not = */
    a1.ra = 1001;
    a1.nota1 = 8.5f;
    a1.nota2 = 7.0f;
    strcpy(a1.end.cidade, "Campinas");
    strcpy(a1.end.uf, "SP");

    /* --- Inicializacao direta --- */
    /* --- Direct initialization --- */
    Aluno a2 = {"Bruno Lima", 1002, 6.0f, 9.0f, {"Salto", "SP"}};

    imprime(a1);
    imprime(a2);

    /* --- Atribuicao copia tudo --- */
    /* --- Assignment copies everything --- */
    Aluno copia = a2;
    strcpy(copia.nome, "Copia do Bruno");
    printf("\nOriginal: %s | Copia: %s\n", a2.nome, copia.nome);
    printf("sizeof(Aluno) = %lu bytes\n\n", (unsigned long)sizeof(Aluno));

    /* --- Vetor de estruturas --- */
    /* --- Array of structs --- */
    Aluno turma[3] = {
        {"Ana Souza",  1001, 8.5f, 7.0f, {"Campinas", "SP"}},
        {"Bruno Lima", 1002, 6.0f, 9.0f, {"Salto", "SP"}},
        {"Carla Reis", 1003, 9.5f, 9.0f, {"Itu", "SP"}}
    };

    int melhor = 0;
    for (int i = 1; i < 3; i++)
        if (media(turma[i]) > media(turma[melhor]))
            melhor = i;
    printf("Melhor da turma: %s (%.2f)\n\n", turma[melhor].nome, media(turma[melhor]));

    /* --- Matriz de estruturas: 2 turmas x 2 alunos --- */
    /* --- Matrix of structs: 2 classes x 2 students --- */
    Aluno turmas[2][2] = {
        {{"Ana",   1, 8.0f, 8.0f, {"Salto", "SP"}}, {"Bia",  2, 6.0f, 7.0f, {"Itu", "SP"}}},
        {{"Caio",  3, 9.0f, 9.5f, {"Salto", "SP"}}, {"Duda", 4, 5.0f, 6.0f, {"Itu", "SP"}}}
    };

    for (int t = 0; t < 2; t++) {
        float soma = 0;
        for (int i = 0; i < 2; i++)
            soma += media(turmas[t][i]);
        printf("Turma %d: media geral = %.2f\n", t, soma / 2);
    }

    return 0;
}
