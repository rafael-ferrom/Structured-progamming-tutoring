/* Ex 4 - Agenda em arquivo binario: adiciona, lista, total e busca */
/* Ex 4 - Binary-file address book: add, list, total and search */
#include <stdio.h>
#include <string.h>

typedef struct {
    int  ra;
    char nome[30];
    char telefone[16];
} Contato;

#define ARQ "agenda.bin"

int adiciona(int ra, const char *nome, const char *telefone) {
    Contato c;
    memset(&c, 0, sizeof(c));                   /* zera, inclusive o padding | zeroes everything, padding included */
    c.ra = ra;
    snprintf(c.nome, sizeof(c.nome), "%s", nome);
    snprintf(c.telefone, sizeof(c.telefone), "%s", telefone);

    FILE *f = fopen(ARQ, "ab");                 /* acrescenta no final | appends at the end */
    if (f == NULL) return 0;
    int ok = fwrite(&c, sizeof(c), 1, f) == 1;
    fclose(f);
    return ok;
}

long total_registros(void) {
    FILE *f = fopen(ARQ, "rb");
    if (f == NULL) return 0;
    fseek(f, 0, SEEK_END);
    long total = ftell(f) / (long)sizeof(Contato);
    fclose(f);
    return total;
}

void lista(void) {
    FILE *f = fopen(ARQ, "rb");
    if (f == NULL) {
        printf("Agenda vazia.\n");
        return;
    }
    Contato c;
    int i = 0;
    while (fread(&c, sizeof(c), 1, f) == 1)
        printf("  [%d] RA %d | %-10s | %s\n", i++, c.ra, c.nome, c.telefone);
    fclose(f);
}

int busca_por_ra(int ra) {
    FILE *f = fopen(ARQ, "rb");
    if (f == NULL) return -1;
    Contato c;
    int i = 0;
    while (fread(&c, sizeof(c), 1, f) == 1) {
        if (c.ra == ra) {
            fclose(f);
            return i;
        }
        i++;
    }
    fclose(f);
    return -1;
}

int main(void) {
    remove(ARQ);                                /* comeca do zero para o teste | starts from scratch for the test */

    adiciona(101, "Ana",    "19 99999-0001");
    adiciona(102, "Bruno",  "19 99999-0002");
    adiciona(103, "Carla",  "19 99999-0003");
    adiciona(104, "Diego",  "19 99999-0004");

    printf("Total de registros: %ld\n", total_registros());
    lista();

    int ras[] = {103, 999};
    for (int i = 0; i < 2; i++) {
        int pos = busca_por_ra(ras[i]);
        if (pos >= 0)
            printf("RA %d encontrado no indice %d\n", ras[i], pos);
        else
            printf("RA %d nao encontrado\n", ras[i]);
    }
    return 0;
}
