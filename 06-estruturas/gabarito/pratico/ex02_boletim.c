/* Ex 2 - Boletim com vetor de estruturas */
/* Ex 2 - Report card with an array of structs */
#include <stdio.h>

#define N 4

typedef struct {
    char  nome[40];
    int   ra;
    float nota1, nota2;
} Aluno;

float media(Aluno a) {
    return (a.nota1 + a.nota2) / 2.0f;
}

int main(void) {
    Aluno turma[N] = {
        {"Ana Souza",  1001, 8.5f, 7.0f},
        {"Bruno Lima", 1002, 4.0f, 6.5f},
        {"Carla Reis", 1003, 9.5f, 9.0f},
        {"Diego Melo", 1004, 5.0f, 6.0f}
    };

    printf("%-12s %-6s %-6s %-6s %-7s %s\n",
           "Nome", "RA", "N1", "N2", "Media", "Situacao");
    for (int i = 0; i < N; i++) {
        float m = media(turma[i]);
        printf("%-12s %-6d %-6.1f %-6.1f %-7.2f %s\n",
               turma[i].nome, turma[i].ra, turma[i].nota1, turma[i].nota2,
               m, m >= 6.0f ? "Aprovado" : "Reprovado");
    }
    return 0;
}
