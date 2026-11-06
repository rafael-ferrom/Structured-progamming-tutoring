/*
 * Modulo 07 - Ponteiros e estruturas / Estruturas e alocacao dinamica
 * Module 07 - Pointers and structs / Structs and dynamic allocation
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  nome[40];
    int   idade;
    float altura;
} Pessoa;

typedef struct {
    char *nome;                    /* campo dinamico | dynamic field */
    int   idade;
} Contato;

/* Por referencia: altera o original */
/* By reference: changes the original */
void faz_aniversario(Pessoa *p) {
    p->idade++;
}

/* Por referencia + const: so leitura, sem copiar a struct */
/* By reference + const: read-only, without copying the struct */
void imprime(const Pessoa *p) {
    printf("%s, %d anos, %.2f m\n", p->nome, p->idade, p->altura);
}

int main(void) {
    /* --- Ponteiro para struct: . e -> --- */
    /* --- Pointer to struct: . and -> --- */
    Pessoa ana = {"Ana", 22, 1.65f};
    Pessoa *pp = &ana;

    printf("ana.idade = %d | pp->idade = %d | (*pp).idade = %d\n",
           ana.idade, pp->idade, (*pp).idade);

    faz_aniversario(&ana);
    imprime(&ana);

    /* --- Uma struct na heap --- */
    /* --- A struct on the heap --- */
    Pessoa *bruno = malloc(sizeof(*bruno));
    if (bruno == NULL) return 1;
    strcpy(bruno->nome, "Bruno");
    bruno->idade = 30;
    bruno->altura = 1.80f;
    imprime(bruno);
    free(bruno);

    /* --- Vetor dinamico de structs --- */
    /* --- Dynamic array of structs --- */
    int n = 3;
    Pessoa *v = malloc(n * sizeof(*v));
    if (v == NULL) return 1;

    const char *nomes[] = {"Carla", "Diego", "Elisa"};
    for (int i = 0; i < n; i++) {
        strcpy(v[i].nome, nomes[i]);       /* v[i] e struct: usa "." | v[i] is a struct: use "." */
        v[i].idade = 20 + i;
        v[i].altura = 1.60f + 0.05f * i;
    }
    printf("\nVetor dinamico:\n");
    for (int i = 0; i < n; i++)
        imprime(&v[i]);                    /* ou imprime(v + i) */
    free(v);

    /* --- Struct com campo dinamico --- */
    /* --- Struct with a dynamic field --- */
    Contato *c = malloc(sizeof(*c));
    if (c == NULL) return 1;
    c->nome = malloc(strlen("Fernanda Oliveira") + 1);   /* +1: '\0' | +1: room for the '\0' */
    if (c->nome == NULL) { free(c); return 1; }
    strcpy(c->nome, "Fernanda Oliveira");
    c->idade = 28;
    printf("\nContato: %s (%d)\n", c->nome, c->idade);

    free(c->nome);                         /* 1o o campo... | 1st the field... */
    free(c);                               /* ...depois a struct | ...then the struct */

    return 0;
}
