/* Ex 3 - Contato com nome alocado dinamicamente */
/* Ex 3 - Contact with a dynamically allocated name */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    long long telefone;
} Contato;

Contato *cria_contato(const char *nome, long long telefone) {
    Contato *c = malloc(sizeof(*c));
    if (c == NULL) return NULL;

    c->nome = malloc(strlen(nome) + 1);    /* +1 para o '\0' | +1 for the '\0' */
    if (c->nome == NULL) {
        free(c);
        return NULL;
    }
    strcpy(c->nome, nome);
    c->telefone = telefone;
    return c;
}

void imprime_contato(const Contato *c) {
    printf("%s - %lld\n", c->nome, c->telefone);
}

void libera_contato(Contato *c) {
    if (c == NULL) return;
    free(c->nome);                         /* 1o o campo | 1st the field */
    free(c);                               /* 2o a struct | 2nd the struct */
}

int main(void) {
    Contato *agenda[3];
    agenda[0] = cria_contato("Ana Beatriz", 19999990001LL);
    agenda[1] = cria_contato("Carlos Eduardo Nogueira", 19999990002LL);
    agenda[2] = cria_contato("Li", 19999990003LL);

    for (int i = 0; i < 3; i++) {
        if (agenda[i] == NULL) {
            printf("Falha ao criar contato %d\n", i);
            continue;
        }
        imprime_contato(agenda[i]);
    }

    for (int i = 0; i < 3; i++)
        libera_contato(agenda[i]);
    return 0;
}
