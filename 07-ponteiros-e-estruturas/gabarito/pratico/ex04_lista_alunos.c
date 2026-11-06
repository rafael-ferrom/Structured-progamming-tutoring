/* Ex 4 - Lista dinamica de alunos (vetor que cresce, encapsulado em struct) */
/* Ex 4 - Dynamic list of students (growing array wrapped in a struct) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  nome[30];
    float nota;
} Aluno;

typedef struct {
    Aluno *dados;
    int    n;      /* quantos elementos ha | how many elements there are */
    int    cap;    /* quantos cabem | how many fit */
} ListaAlunos;

int lista_inicia(ListaAlunos *l, int cap_inicial) {
    l->dados = malloc(cap_inicial * sizeof(*l->dados));
    if (l->dados == NULL) return 0;
    l->n = 0;
    l->cap = cap_inicial;
    return 1;
}

int lista_adiciona(ListaAlunos *l, const char *nome, float nota) {
    if (l->n == l->cap) {
        int nova_cap = l->cap * 2;
        Aluno *aux = realloc(l->dados, nova_cap * sizeof(*aux));
        if (aux == NULL) return 0;         /* l->dados continua valido | l->dados is still valid */
        l->dados = aux;
        l->cap = nova_cap;
        printf("  (capacidade aumentou para %d)\n", nova_cap);
    }
    strncpy(l->dados[l->n].nome, nome, sizeof(l->dados[l->n].nome) - 1);
    l->dados[l->n].nome[sizeof(l->dados[l->n].nome) - 1] = '\0';
    l->dados[l->n].nota = nota;
    l->n++;
    return 1;
}

void lista_imprime(const ListaAlunos *l) {
    for (int i = 0; i < l->n; i++)
        printf("  %d. %-10s %.1f\n", i + 1, l->dados[i].nome, l->dados[i].nota);
}

float lista_media(const ListaAlunos *l) {
    if (l->n == 0) return 0.0f;
    float soma = 0.0f;
    for (int i = 0; i < l->n; i++)
        soma += l->dados[i].nota;
    return soma / l->n;
}

void lista_libera(ListaAlunos *l) {
    free(l->dados);
    l->dados = NULL;
    l->n = l->cap = 0;
}

int main(void) {
    ListaAlunos turma;
    if (!lista_inicia(&turma, 2)) {
        printf("Sem memoria!\n");
        return 1;
    }

    const char *nomes[] = {"Ana", "Bruno", "Carla", "Diego", "Elisa", "Fabio", "Gabi"};
    float notas[] = {8.5f, 6.0f, 9.0f, 5.5f, 10.0f, 7.0f, 6.5f};

    for (int i = 0; i < 7; i++) {
        if (!lista_adiciona(&turma, nomes[i], notas[i])) {
            printf("Falha ao adicionar!\n");
            lista_libera(&turma);
            return 1;
        }
    }

    printf("Alunos (n=%d, cap=%d):\n", turma.n, turma.cap);
    lista_imprime(&turma);
    printf("Media da turma: %.2f\n", lista_media(&turma));

    lista_libera(&turma);
    return 0;
}
