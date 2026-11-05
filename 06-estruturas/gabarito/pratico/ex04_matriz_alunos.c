/* Ex 4 - Matriz de estruturas: 2 turmas x 3 alunos */
/* Ex 4 - Matrix of structs: 2 classes x 3 students */
#include <stdio.h>

#define T 2
#define A 3

typedef struct {
    char  nome[30];
    float nota1, nota2;
} Aluno;

float media(Aluno a) {
    return (a.nota1 + a.nota2) / 2.0f;
}

int main(void) {
    Aluno turmas[T][A] = {
        {{"Ana",   8.0f, 7.0f}, {"Bruno", 6.0f, 5.5f}, {"Carla", 9.0f, 8.5f}},
        {{"Diego", 7.5f, 9.5f}, {"Elisa", 10.0f, 9.0f}, {"Fabio", 4.0f, 6.0f}}
    };

    int mt = 0, ma = 0;                       /* posicao do melhor aluno | position of the best student */
    for (int t = 0; t < T; t++) {
        float soma = 0.0f;
        for (int i = 0; i < A; i++) {
            float m = media(turmas[t][i]);
            soma += m;
            if (m > media(turmas[mt][ma])) {
                mt = t;
                ma = i;
            }
        }
        printf("Turma %d: media geral = %.2f\n", t + 1, soma / A);
    }

    printf("Melhor aluno: %s (turma %d) com media %.2f\n",
           turmas[mt][ma].nome, mt + 1, media(turmas[mt][ma]));
    return 0;
}
