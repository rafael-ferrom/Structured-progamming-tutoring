🌐 **Português** · [English](teorico.en.md)

# Módulo 03 · Exercícios teóricos

**1.** Por que a função abaixo **não** troca os valores das variáveis do `main`? Como corrigi-la?

```c
void troca(int a, int b) {
    int t = a; a = b; b = t;
}
```

**2.** Qual a saída?

```c
void incrementa(int *x) { (*x)++; }

int main(void) {
    int n = 5;
    incrementa(&n);
    incrementa(&n);
    printf("%d", n);
    return 0;
}
```

**3.** Por que usamos `&` em `scanf("%d", &n)`, mas não em `scanf("%s", nome)` (com `char nome[30]`)?

**4.** Ao passar um vetor para uma função, ele é copiado? O que `sizeof(v)` retorna **dentro** da função quando o parâmetro é `int v[]`? Por isso, o que deve ser passado junto com o vetor?

**5.** Encontre o erro:

```c
void define_dez(int *p) {
    p = 10;
}
```
