🌐 **Português** · [English](teorico.en.md)

# Módulo 01 · Exercícios teóricos

**1.** Qual a diferença entre o **protótipo** e a **definição** de uma função? Por que o protótipo é necessário quando a função é definida depois do `main`?

**2.** Qual a saída do programa?

```c
#include <stdio.h>
int f(int x) { x = x * 2; return x; }
int main(void) {
    int a = 5;
    int b = f(a);
    printf("%d %d", a, b);
    return 0;
}
```

**3.** Assinale a alternativa correta. Em C, quando passamos uma variável `int` como argumento para uma função:

- a) a função recebe a própria variável e pode alterá-la
- b) a função recebe uma cópia do valor
- c) a função recebe o endereço da variável
- d) o compilador impede que a função altere o valor

**4.** Encontre o erro e explique o que acontece:

```c
int dobro(int x) {
    x * 2;
}
```

**5.** Qual a saída do programa? Explique.

```c
#include <stdio.h>
int x = 10;
void f(void) { int x = 20; printf("%d ", x); }
int main(void) {
    f();
    printf("%d", x);
    return 0;
}
```
