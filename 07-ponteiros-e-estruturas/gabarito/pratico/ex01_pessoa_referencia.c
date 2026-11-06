/* Ex 1 - Pessoa manipulada por referencia */
/* Ex 1 - Person handled by reference */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    int  idade;
} Pessoa;

void inicializa(Pessoa *p, const char *nome, int idade) {
    strncpy(p->nome, nome, sizeof(p->nome) - 1);
    p->nome[sizeof(p->nome) - 1] = '\0';
    p->idade = idade;
}

void faz_aniversario(Pessoa *p) {
    p->idade++;
}

void imprime(const Pessoa *p) {
    printf("%s tem %d anos\n", p->nome, p->idade);
}

int main(void) {
    Pessoa p;
    inicializa(&p, "Rafael", 22);
    imprime(&p);

    faz_aniversario(&p);
    faz_aniversario(&p);
    imprime(&p);
    return 0;
}
