/*
 * Modulo 01 - Funcoes
 * Module 01 - Functions
 * Compilar: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 * Compile: gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
 */
#include <stdio.h>

/* ---------- Prototipos ---------- */
/* ---------- Prototypes ---------- */
int soma(int a, int b);
int maior(int a, int b);
int eh_par(int n);
long long fatorial(int n);          /* versao iterativa | iterative version */
long long fatorial_rec(int n);      /* versao recursiva | recursive version */
void linha(char c, int n);          /* void: nao devolve nada | void: returns nothing */
void tenta_alterar(int x);
int conta_chamadas(void);

int global = 100;                   /* variavel global | global variable */

int main(void) {
    linha('=', 40);
    printf("  MODULO 01 - FUNCOES\n");
    linha('=', 40);

    int a = 7, b = 3;
    printf("soma(%d, %d)  = %d\n", a, b, soma(a, b));
    printf("maior(%d, %d) = %d\n", a, b, maior(a, b));
    printf("%d e %s\n", a, eh_par(a) ? "par" : "impar");
    printf("fatorial(5)     = %lld\n", fatorial(5));
    printf("fatorial_rec(5) = %lld\n", fatorial_rec(5));

    /* --- Passagem por valor --- */
    /* --- Pass by value --- */
    linha('-', 40);
    int x = 10;
    tenta_alterar(x);
    printf("x depois de tenta_alterar(x): %d (nao mudou!)\n", x);

    /* --- Escopo --- */
    /* --- Scope --- */
    int global_local = global;      /* copia da global | copy of the global */
    printf("global = %d, copia local = %d\n", global, global_local);

    /* --- static: memoria entre chamadas --- */
    /* --- static: memory between calls --- */
    linha('-', 40);
    for (int i = 0; i < 3; i++)
        printf("conta_chamadas() -> %d\n", conta_chamadas());

    return 0;
}

/* ---------- Definicoes ---------- */
/* ---------- Definitions ---------- */
int soma(int a, int b) {
    return a + b;
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int eh_par(int n) {
    return n % 2 == 0;              /* 1 se verdadeiro, 0 se falso | 1 if true, 0 if false */
}

long long fatorial(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++)
        r *= i;
    return r;
}

long long fatorial_rec(int n) {
    if (n <= 1) return 1;           /* caso base | base case */
    return n * fatorial_rec(n - 1); /* passo recursivo | recursive step */
}

void linha(char c, int n) {
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

void tenta_alterar(int x) {
    x = 99;                         /* altera so a COPIA | changes only the COPY */
    printf("  dentro da funcao, x = %d\n", x);
}

int conta_chamadas(void) {
    static int contador = 0;        /* inicializada uma unica vez | initialized only once */
    contador++;
    return contador;
}
