🌐 **Português** · [English](teorico.en.md)

# Módulo 08 · Exercícios teóricos

**1.** Explique a diferença entre os modos `"r"`, `"w"` e `"a"`. O que acontece com um arquivo já existente aberto em modo `"w"`?

**2.** Por que devemos sempre testar o valor devolvido por `fopen`? Em que situações ele devolve `NULL`?

**3.** Qual a relação entre `printf` e `fprintf`? O que é `stdout`?

**4.** Explique por que o laço abaixo pode processar a última linha duas vezes ou usar lixo. Reescreva-o corretamente.

```c
while (!feof(f)) {
    fscanf(f, "%d", &x);
    printf("%d\n", x);
}
```

**5.** Qual a diferença entre um arquivo de texto e um binário? Por que o retorno de `fgetc` deve ser guardado em `int` e não em `char`?
