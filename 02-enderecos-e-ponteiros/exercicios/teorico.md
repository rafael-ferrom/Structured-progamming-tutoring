🌐 **Português** · [English](teorico.en.md)

# Módulo 02 · Exercícios teóricos

**1.** Explique o que fazem os operadores `&` e `*` em C. Dê um exemplo de cada.

**2.** Qual a saída?

```c
int a = 10;
int *p = &a;
*p = *p + 5;
printf("%d", a);
```

**3.** Qual a saída?

```c
int v[] = {10, 20, 30};
int *p = v;
p++;
printf("%d %d", *p, *(p + 1));
```

**4.** Por que o trecho abaixo é perigoso?

```c
int *p;
*p = 5;
```

**5.** O que representa `NULL` para um ponteiro? Por que é boa prática inicializar ponteiros com `NULL` e testar antes de usá-los?
