🌐 **Português** · [English](README.en.md)

# 05 · Alocação dinâmica de memória

> **Plano de aprendizagem:** Aula 5 (24/08) — Alocação Dinâmica de Memória · Aula 7 (14/09) — Revisão de Strings e Alocação Dinâmica

## Objetivos

- Diferenciar pilha (*stack*) e heap
- Usar `malloc`, `calloc`, `realloc` e `free`
- Criar vetores e matrizes cujo tamanho só é conhecido em tempo de execução
- Evitar vazamentos de memória e ponteiros pendentes

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c`
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Por que alocar dinamicamente?

Vetores comuns (`int v[100]`) têm tamanho fixo definido na compilação. Com **alocação dinâmica** o programa pede memória ao sistema **durante a execução**, na quantidade que precisar, e devolve quando terminar.

| | Pilha (*stack*) | Heap |
|---|---|---|
| Quem gerencia | compilador | **você** |
| Tempo de vida | até o fim do bloco/função | até você chamar `free` |
| Tamanho | pequeno e fixo | grande e flexível |

## 2. Funções de `<stdlib.h>`

| Função | O que faz |
|--------|-----------|
| `malloc(bytes)` | reserva `bytes` sem inicializar |
| `calloc(n, tam)` | reserva `n * tam` bytes **zerados** |
| `realloc(p, novo)` | redimensiona o bloco (pode movê-lo!) |
| `free(p)` | devolve o bloco ao sistema |

Todas (menos `free`) devolvem `NULL` se faltar memória — **sempre teste**.

### Padrão de uso

```c
int *v = malloc(n * sizeof(int));     /* ou sizeof(*v) */
if (v == NULL) {
    printf("Sem memoria!\n");
    return 1;
}
/* ... usa v[0] .. v[n-1] ... */
free(v);
v = NULL;                             /* evita ponteiro pendente */
```

> Use `sizeof(*v)` ou `sizeof(tipo)` — nunca "chute" o número de bytes.

## 3. `realloc` com segurança

```c
int *novo = realloc(v, novo_tam * sizeof(int));
if (novo == NULL) {        /* v continua válido! */
    free(v);
    return 1;
}
v = novo;
```

Se você escrevesse `v = realloc(v, ...)` e falhasse, perderia o endereço original (vazamento).

Estratégia comum para vetor que cresce: **dobrar a capacidade** quando encher.

## 4. Matriz dinâmica

Vetor de ponteiros, cada um apontando para uma linha:

```c
int **m = malloc(linhas * sizeof(int *));
for (int i = 0; i < linhas; i++)
    m[i] = malloc(colunas * sizeof(int));
/* uso: m[i][j] */
for (int i = 0; i < linhas; i++)
    free(m[i]);          /* libera cada linha... */
free(m);                 /* ...depois o vetor de ponteiros */
```

## 5. Problemas clássicos

| Problema | O que é |
|----------|---------|
| **Vazamento** (*memory leak*) | perder o ponteiro sem chamar `free` |
| **Ponteiro pendente** (*dangling*) | usar o ponteiro depois do `free` |
| **Double free** | chamar `free` duas vezes no mesmo bloco |
| **Estouro** (*overflow*) | escrever fora do bloco alocado |

Regra de ouro: **para cada `malloc`, um `free`**.

Dica para conferir vazamentos (Linux/WSL): `valgrind ./programa`

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
