🌐 **Português** · [English](teorico.en.md)

# Módulo 04 · Exercícios teóricos

**1.** Qual o papel do `'\0'` em uma string? Quantos bytes ocupa `char s[] = "ola";`?

**2.** Qual a diferença entre `char s[] = "abc";` e `char *p = "abc";` quanto à possibilidade de modificar o conteúdo?

**3.** Qual a saída?

```c
char s[] = "Programacao";
char *p = s + 3;
printf("%s %c", p, *p);
```

**4.** Por que devemos preferir `fgets` a `gets` e a `scanf("%s", ...)` para ler texto? O que o `fgets` faz com o `'\n'` digitado?

**5.** Dado `const char *dias[] = {"Seg", "Ter", "Qua"};`, qual o valor de `dias[1]`, `dias[1][0]` e `*(dias[2] + 1)`?
