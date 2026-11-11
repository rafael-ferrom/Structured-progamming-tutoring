/* Ex 3 - Atualizar um registro no lugar com rb+ */
/* Ex 3 - Update a record in place with rb+ */
#include <stdio.h>

typedef struct {
    int   ra;
    char  nome[30];
    float nota;
} Registro;

int atualiza_nota(const char *arquivo, int indice, float nova_nota) {
    FILE *f = fopen(arquivo, "rb+");            /* NAO usar "wb": apagaria tudo | do NOT use "wb": it would erase everything */
    if (f == NULL) return 0;

    long pos = (long)indice * (long)sizeof(Registro);
    Registro r;

    if (fseek(f, pos, SEEK_SET) != 0 || fread(&r, sizeof(Registro), 1, f) != 1) {
        fclose(f);                              /* indice inexistente | index does not exist */
        return 0;
    }

    r.nota = nova_nota;
    fseek(f, pos, SEEK_SET);                    /* volta ao inicio do registro | goes back to the start of the record */
    int ok = fwrite(&r, sizeof(Registro), 1, f) == 1;
    fclose(f);
    return ok;
}

static void mostra(const char *arquivo, int indice) {
    FILE *f = fopen(arquivo, "rb");
    Registro r;
    if (f == NULL) return;
    fseek(f, (long)indice * (long)sizeof(Registro), SEEK_SET);
    if (fread(&r, sizeof(Registro), 1, f) == 1)
        printf("  indice %d -> RA %d | %s | %.1f\n", indice, r.ra, r.nome, r.nota);
    fclose(f);
}

int main(void) {
    Registro turma[3] = {
        {3001, "Ana", 5.0f}, {3002, "Bruno", 6.0f}, {3003, "Carla", 7.0f}
    };
    FILE *f = fopen("notas.bin", "wb");
    if (f == NULL) {
        printf("Erro ao criar notas.bin\n");
        return 1;
    }
    fwrite(turma, sizeof(Registro), 3, f);
    fclose(f);

    printf("Antes:\n");
    mostra("notas.bin", 1);

    if (atualiza_nota("notas.bin", 1, 9.5f))
        printf("Nota atualizada.\n");

    printf("Depois:\n");
    mostra("notas.bin", 0);       /* vizinhos nao foram afetados | neighbors were not affected */
    mostra("notas.bin", 1);
    mostra("notas.bin", 2);

    if (!atualiza_nota("notas.bin", 7, 10.0f))
        printf("Indice 7 nao existe: nada foi alterado.\n");
    return 0;
}
