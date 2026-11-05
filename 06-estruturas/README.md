🌐 **Português** · [English](README.en.md)

# 06 · Estruturas e matriz de estruturas

> **Plano de aprendizagem:** Aula 8 (21/09) e Aula 10 (28/09) — Estruturas e Matriz de Estruturas

## Objetivos

- Agrupar dados de tipos diferentes em uma única `struct`
- Usar `typedef` para simplificar o código
- Trabalhar com **vetores** e **matrizes** de estruturas
- Passar estruturas para funções

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c`
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. O que é uma estrutura?

Um vetor agrupa elementos do **mesmo tipo**. Uma `struct` agrupa campos de **tipos diferentes** sob um único nome:

```c
struct Aluno {
    char  nome[50];
    int   ra;
    float nota;
};

struct Aluno a1;
```

### Com `typedef` (mais comum)

```c
typedef struct {
    char  nome[50];
    int   ra;
    float nota;
} Aluno;

Aluno a1;        /* sem precisar escrever "struct" */
```

## 2. Acessando campos: operador `.`

```c
a1.ra = 1001;
a1.nota = 8.5f;
strcpy(a1.nome, "Ana");     /* string: NÃO se atribui com =, use strcpy */
```

### Inicialização

```c
Aluno a2 = {"Bruno", 1002, 7.0f};
```

### Atribuição entre estruturas

`a3 = a2;` **copia todos os campos** (inclusive vetores dentro da struct).

## 3. Estruturas aninhadas

```c
typedef struct { char cidade[30]; char uf[3]; } Endereco;
typedef struct { char nome[50]; Endereco end; } Cliente;

Cliente c;
strcpy(c.end.cidade, "Campinas");
```

## 4. Vetor de estruturas

```c
Aluno turma[3] = {
    {"Ana",   1001, 8.5f},
    {"Bruno", 1002, 7.0f},
    {"Carla", 1003, 9.0f}
};
for (int i = 0; i < 3; i++)
    printf("%s: %.1f\n", turma[i].nome, turma[i].nota);
```

## 5. Matriz de estruturas

Uma matriz onde cada célula é uma `struct`:

```c
Aluno turmas[2][3];        /* 2 turmas x 3 alunos */
turmas[1][2].nota = 9.5f;  /* aluno 2 da turma 1 */
```

## 6. Estruturas e funções

- **Por valor:** `void imprime(Aluno a)` — copia a struct inteira (a original não muda)
- **Por referência:** `void le(Aluno *a)` — módulo 07

Uma função também pode **devolver** uma struct: `Aluno cria_aluno(...)`.

## 7. Erros comuns

- Atribuir string com `=` (`a.nome = "Ana"` não compila) → use `strcpy`
- Esquecer o `;` depois da `}` da struct
- Comparar duas structs com `==` (não é permitido; compare campo a campo)
- Esquecer de que `sizeof(struct)` pode ser maior que a soma dos campos (alinhamento/*padding*)

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
