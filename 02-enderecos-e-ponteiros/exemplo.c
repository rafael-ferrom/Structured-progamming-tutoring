/*
 * Modulo 02 - Endereco de variaveis e ponteiros
 * Module 02 - Variable addresses and pointers
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>

int main(void) {
    /* --- Endereco e ponteiro --- */
    /* --- Address and pointer --- */
    int idade = 22;
    int *p = &idade;                       /* p guarda o endereco de idade | p holds the address of idade */

    printf("idade   = %d\n", idade);
    printf("&idade  = %p\n", (void *)&idade);
    printf("p       = %p  (mesmo endereco)\n", (void *)p);
    printf("*p      = %d  (valor apontado)\n", *p);
    printf("&p      = %p  (endereco do proprio ponteiro)\n\n", (void *)&p);

    /* --- Alterando pelo ponteiro --- */
    /* --- Changing through the pointer --- */
    *p = 23;
    printf("Depois de *p = 23 -> idade = %d\n\n", idade);

    /* --- Vetor e ponteiro --- */
    /* --- Array and pointer --- */
    int v[5] = {10, 20, 30, 40, 50};
    int *q = v;                            /* q = &v[0] */

    for (int i = 0; i < 5; i++)
        printf("v[%d] = %d | *(q+%d) = %d | endereco = %p\n",
               i, v[i], i, *(q + i), (void *)(q + i));

    /* --- Percorrendo com ponteiro --- */
    /* --- Traversing with a pointer --- */
    printf("\nPercorrendo com ponteiro: ");
    for (int *r = v; r < v + 5; r++)
        printf("%d ", *r);
    printf("\n");

    /* --- Subtracao de ponteiros --- */
    /* --- Pointer subtraction --- */
    int *fim = &v[4];
    printf("fim - v = %ld elementos\n\n", (long)(fim - v));

    /* --- NULL --- */
    int *nulo = NULL;
    if (nulo == NULL)
        printf("nulo aponta para NULL: nao pode ser desreferenciado.\n");

    /* --- Tamanhos --- */
    /* --- Sizes --- */
    printf("\nsizeof(int)   = %lu bytes\n", (unsigned long)sizeof(int));
    printf("sizeof(int *) = %lu bytes\n", (unsigned long)sizeof(int *));
    printf("sizeof(v)     = %lu bytes (5 ints)\n", (unsigned long)sizeof(v));

    return 0;
}
