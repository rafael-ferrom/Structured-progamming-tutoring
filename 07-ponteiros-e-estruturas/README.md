🌐 **Português** · [English](README.en.md)

# 07 · Ponteiros e estruturas · Estruturas e alocação dinâmica

> **Plano de aprendizagem:** Aula 11 (05/10) — Estruturas e Alocação Dinâmica  
> (AC2 — Prova teórica 19/10 e prova prática 26/10: *Estruturas e Alocação*)

## Objetivos

- Usar ponteiros para estruturas e o operador `->`
- Passar estruturas **por referência** para funções
- Alocar dinamicamente uma estrutura e um **vetor de estruturas**
- Trabalhar com estruturas que contêm ponteiros (ex.: nome dinâmico)
- Construir um "vetor dinâmico" encapsulado em uma struct (base dos TADs)

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c`
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Ponteiro para estrutura e o operador `->`

```c
Pessoa p = {"Ana", 22};
Pessoa *pp = &p;

(*pp).idade = 23;    /* parênteses obrigatórios: . tem precedência sobre * */
pp->idade   = 23;    /* forma equivalente e preferida */
```

| Variável | Ponteiro |
|----------|----------|
| `p.idade` | `pp->idade` |

## 2. Passando estruturas por referência

Por valor, a struct **inteira** é copiada (lento se for grande e não altera o original). Por ponteiro, só o endereço é copiado:

```c
void faz_aniversario(Pessoa *p) { p->idade++; }        /* altera o original */
void imprime(const Pessoa *p)   { printf("%s", p->nome); } /* só leitura */
```

Chamada: `faz_aniversario(&p);`

## 3. Alocando uma estrutura

```c
Pessoa *p = malloc(sizeof(*p));
if (p == NULL) { /* trate o erro */ }
p->idade = 20;
free(p);
```

## 4. Vetor dinâmico de estruturas

```c
Produto *v = malloc(n * sizeof(*v));
for (int i = 0; i < n; i++)
    v[i].preco = 10.0f;      /* v[i] é uma struct, então usa "." */
free(v);
```

> Atenção: `v[i].campo` (ponto) ou `(v + i)->campo` (seta). Nunca `v[i]->campo`.

## 5. Estruturas com ponteiros (campos dinâmicos)

```c
typedef struct {
    char *nome;          /* alocado à parte */
    int   idade;
} Contato;
```

O `malloc` da struct **não** aloca o `nome`. É preciso alocar cada parte e liberar **na ordem inversa**:

```c
Contato *c = malloc(sizeof(*c));
c->nome = malloc(strlen("Ana") + 1);   /* +1 do '\0' */
strcpy(c->nome, "Ana");
/* ... */
free(c->nome);    /* 1º: o campo */
free(c);          /* 2º: a struct */
```

## 6. Vetor dinâmico encapsulado

Guardar o vetor, a quantidade e a capacidade juntos:

```c
typedef struct {
    Aluno *dados;
    int    n;        /* quantos elementos */
    int    cap;      /* quantos cabem */
} ListaAlunos;
```

Assim as funções recebem apenas `ListaAlunos *l` — é o primeiro passo para **TADs** e estruturas de dados.

## 7. Erros comuns

- Usar ponteiro para struct sem alocar/apontar (`Pessoa *p; p->idade = 1;`)
- Confundir `.` e `->`
- `malloc(sizeof(Pessoa *))` — aloca só o tamanho de um ponteiro; use `sizeof(Pessoa)` ou `sizeof(*p)`
- Esquecer de liberar os campos internos antes da struct
- `free` duas vezes

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
