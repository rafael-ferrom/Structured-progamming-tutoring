/* Ex 2 - Acesso aleatorio: ler o registro de indice i com fseek */
/* Ex 2 - Random access: read the record at index i with fseek */
#include <stdio.h>

typedef struct {
    int   ra;
    char  nome[30];
    float nota;
} Registro;

int le_registro(FILE *f, int indice, Registro *r) {
    if (indice < 0) return 0;
    if (fseek(f, (long)indice * (long)sizeof(Registro), SEEK_SET) != 0)
        return 0;
    return fread(r, sizeof(Registro), 1, f) == 1;   /* 0 se passou do fim | 0 if it went past the end */
}

int main(void) {
    Registro turma[6] = {
        {2001, "Ana",   8.0f}, {2002, "Bruno", 6.5f}, {2003, "Carla", 9.5f},
        {2004, "Diego", 5.0f}, {2005, "Elisa", 7.0f}, {2006, "Fabio", 10.0f}
    };

    FILE *f = fopen("turma.bin", "wb");
    if (f == NULL) {
        printf("Erro ao criar turma.bin\n");
        return 1;
    }
    fwrite(turma, sizeof(Registro), 6, f);
    fclose(f);

    f = fopen("turma.bin", "rb");
    if (f == NULL) {
        printf("Erro ao abrir turma.bin\n");
        return 1;
    }

    int indices[] = {0, 3, 5, 9};
    for (int i = 0; i < 4; i++) {
        Registro r;
        if (le_registro(f, indices[i], &r))
            printf("Indice %d: RA %d | %s | %.1f\n", indices[i], r.ra, r.nome, r.nota);
        else
            printf("Indice %d: registro inexistente\n", indices[i]);
    }
    fclose(f);
    return 0;
}
