/* Ex 4 - Gravar e ler notas com fprintf / fscanf */
/* Ex 4 - Write and read grades with fprintf / fscanf */
#include <stdio.h>

int main(void) {
    const char *nomes[] = {"Ana", "Bruno", "Carla", "Diego", "Elisa"};
    float notas[] = {8.5f, 6.0f, 9.5f, 5.0f, 7.5f};

    FILE *f = fopen("notas.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar notas.txt\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
        fprintf(f, "%s %.1f\n", nomes[i], notas[i]);
    fclose(f);

    f = fopen("notas.txt", "r");
    if (f == NULL) {
        printf("notas.txt nao encontrado.\n");
        return 1;
    }

    char nome[30], melhor[30] = "";
    float nota, soma = 0.0f, maior = -1.0f;
    int qtd = 0;

    while (fscanf(f, "%29s %f", nome, &nota) == 2) {
        soma += nota;
        qtd++;
        if (nota > maior) {
            maior = nota;
            snprintf(melhor, sizeof(melhor), "%s", nome);
        }
    }
    fclose(f);

    if (qtd == 0) {
        printf("Arquivo vazio.\n");
        return 0;
    }
    printf("Alunos lidos: %d\n", qtd);
    printf("Media da turma: %.2f\n", soma / qtd);
    printf("Maior nota: %s (%.1f)\n", melhor, maior);
    return 0;
}
