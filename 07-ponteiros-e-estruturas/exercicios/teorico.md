🌐 **Português** · [English](teorico.en.md)

# Módulo 07 · Exercícios teóricos

**1.** Dado `Pessoa *p = &x;`, escreva de duas formas diferentes o comando que atribui 30 ao campo `idade`. Por que `*p.idade` está errado?

**2.** Por que geralmente passamos estruturas por ponteiro (com `const` quando só lemos) em vez de por valor?

**3.** Encontre o erro:

```c
Aluno *a;
a->ra = 1001;
```

**4.** Considere:

```c
typedef struct { char *nome; int idade; } Contato;
Contato *c = malloc(sizeof(Contato));
c->nome = malloc(20);
```

Em que ordem devemos liberar a memória? O que aconteceria se fizéssemos `free(c)` antes de `free(c->nome)`?

**5.** Para alocar espaço para `n` estruturas do tipo `Produto`, qual expressão está correta? Justifique.

- a) `malloc(n)`
- b) `malloc(n * sizeof(Produto *))`
- c) `malloc(n * sizeof(Produto))`
