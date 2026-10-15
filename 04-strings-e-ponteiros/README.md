🌐 **Português** · [English](README.en.md)

# 04 · Strings, ponteiros e matriz de ponteiros para strings

> **Plano de aprendizagem:** Strings – revisão · Strings e Ponteiros · Matriz de Ponteiros para Strings  
> (Aula 7, 14/09 — Revisão de Strings)

## Objetivos

- Revisar como C representa texto (vetor de `char` terminado em `'\0'`)
- Usar a biblioteca `<string.h>` e `<ctype.h>`
- Percorrer e alterar strings com ponteiros
- Trabalhar com **vetores de ponteiros para strings** (`char *nomes[]`)

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c`
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. String em C

Não existe o tipo "string": é um **vetor de `char` terminado em `'\0'`** (caractere nulo, valor 0).

```c
char s[] = "ola";      /* 'o' 'l' 'a' '\0'  -> 4 bytes */
```

O `'\0'` marca o fim. Sem ele, as funções não sabem onde a string termina.

## 2. Leitura segura

| Função | Comportamento |
|--------|---------------|
| `scanf("%s", s)` | lê até o primeiro espaço; **não** limita o tamanho (perigoso) |
| `scanf("%29s", s)` | limita a 29 caracteres (para `char s[30]`) |
| `fgets(s, tam, stdin)` | lê a linha inteira **incluindo `'\n'`**, respeitando `tam` |
| `gets` | **nunca use** (removida do C11) |

Remover o `'\n'` que o `fgets` deixa:

```c
s[strcspn(s, "\n")] = '\0';
```

## 3. Funções de `<string.h>`

| Função | O que faz |
|--------|-----------|
| `strlen(s)` | tamanho (sem o `'\0'`) |
| `strcpy(dst, src)` | copia `src` em `dst` (`dst` precisa caber!) |
| `strcat(dst, src)` | concatena `src` no fim de `dst` |
| `strcmp(a, b)` | 0 se iguais; `<0` se `a` < `b`; `>0` se `a` > `b` |
| `strchr(s, c)` | ponteiro para a 1ª ocorrência de `c` (ou `NULL`) |
| `strstr(s, sub)` | ponteiro para a 1ª ocorrência da substring |

**Nunca compare strings com `==`**: isso compara endereços, não conteúdo.

De `<ctype.h>`: `toupper`, `tolower`, `isalpha`, `isdigit`, `isalnum`, `isspace`.

## 4. Strings e ponteiros

Como o nome do vetor é um endereço, dá para percorrer uma string com ponteiro:

```c
int tamanho(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}
```

### Vetor × ponteiro para literal

```c
char  a[] = "abc";   /* cópia modificável, dentro do vetor */
char *b   = "abc";   /* aponta para literal: NÃO pode ser modificado */
a[0] = 'X';          /* OK */
/* b[0] = 'X'; */    /* comportamento indefinido (crash) */
```

Prefira `const char *b = "abc";`.

## 5. Vetor de ponteiros para strings

```c
const char *dias[] = {"Seg", "Ter", "Qua"};
```

- `dias[1]` é um `const char *` → `"Ter"`
- `dias[1][0]` → `'T'`
- Cada string pode ter tamanho diferente (economiza memória em relação a `char m[3][20]`)
- Ordenar o vetor é só **trocar ponteiros**, sem copiar texto

Comparação com matriz de `char`:

| | `char m[3][20]` | `const char *v[3]` |
|---|---|---|
| Memória | 60 bytes fixos | 3 ponteiros + literais |
| Alterar texto | sim | não (se literais) |
| Trocar posições | copiar strings (`strcpy`) | trocar ponteiros |

## 6. Erros comuns

- Esquecer espaço para o `'\0'` (`char s[3] = "abc";` não cabe)
- Comparar com `==` em vez de `strcmp`
- `strcpy` em destino menor que a origem (*buffer overflow*)
- Modificar literal de string
- Esquecer de remover o `'\n'` do `fgets`

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
