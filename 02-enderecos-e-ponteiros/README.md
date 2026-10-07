🌐 **Português** · [English](README.en.md)

# 02 · Endereço de variáveis e ponteiros

> **Plano de aprendizagem:** Aula 3 (17/08) — Endereço de Variáveis / Ponteiros

## Objetivos

- Entender que toda variável ocupa um endereço na memória
- Usar os operadores `&` (endereço de) e `*` (conteúdo de)
- Declarar, inicializar e usar ponteiros
- Percorrer vetores com aritmética de ponteiros

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c` (os endereços mudam a cada execução — é normal)
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Memória e endereços

A memória é uma sequência de bytes numerados. Cada variável ocupa alguns bytes; o número do primeiro byte é o **endereço** da variável.

```c
int idade = 22;
printf("%p\n", (void *)&idade);   /* imprime o endereço, ex.: 0x7ffd1c2a */
```

## 2. Ponteiros

Um **ponteiro** é uma variável que guarda um **endereço**.

```c
int idade = 22;
int *p = &idade;    /* p aponta para idade */
```

| Expressão | Significado |
|-----------|-------------|
| `&idade`  | endereço de `idade` |
| `p`       | o endereço guardado em `p` |
| `*p`      | o valor **apontado** por `p` (desreferência) |
| `&p`      | o endereço do próprio ponteiro |

```c
*p = 23;            /* altera idade através do ponteiro */
printf("%d", idade); /* 23 */
```

> O `*` tem dois papéis: na **declaração** (`int *p`) diz que `p` é ponteiro; na **expressão** (`*p`) acessa o conteúdo.

## 3. Ponteiro nulo e ponteiro não inicializado

- `int *p = NULL;` — aponta para "lugar nenhum". Sempre teste `if (p != NULL)` antes de usar
- `int *p;` (sem inicializar) — aponta para um lixo. Usar `*p` é **comportamento indefinido** (pode travar o programa)

## 4. Ponteiros e vetores

O nome de um vetor é (quase sempre) o endereço do primeiro elemento:

```c
int v[3] = {10, 20, 30};
int *p = v;          /* o mesmo que &v[0] */
```

Aritmética de ponteiros: somar 1 avança **um elemento** (e não um byte).

| Vetor | Ponteiro |
|-------|----------|
| `v[i]` | `*(p + i)` |
| `&v[i]` | `p + i` |

```c
for (int *q = v; q < v + 3; q++)
    printf("%d ", *q);
```

Subtrair dois ponteiros do mesmo vetor dá a **distância em elementos**: `(q - v)` é o índice de `q`.

## 5. Tamanhos

- `sizeof(int)` costuma ser 4 bytes
- `sizeof(int *)` é 8 bytes em sistemas de 64 bits (independente do tipo apontado)

## 6. Erros comuns

- Usar ponteiro não inicializado
- Confundir `p` (endereço) com `*p` (valor)
- Esquecer o `&` no `scanf`
- Sair dos limites do vetor com aritmética de ponteiros

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
