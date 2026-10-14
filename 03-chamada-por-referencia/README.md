🌐 **Português** · [English](README.en.md)

# 03 · Chamada por referência

> **Plano de aprendizagem:** Aula 5 (24/08) — Chamada por referência

## Objetivos

- Diferenciar passagem **por valor** e **por referência**
- Escrever funções que alteram variáveis do chamador
- Devolver **mais de um resultado** de uma função
- Entender por que vetores "são alterados" dentro de funções

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c`
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Por valor × por referência

| | Por valor | Por referência |
|---|---|---|
| O que a função recebe | uma **cópia** do valor | o **endereço** da variável |
| Altera o original? | não | **sim** |
| Sintaxe | `void f(int x)` | `void f(int *x)` |
| Chamada | `f(a)` | `f(&a)` |

> Tecnicamente, C **só** tem passagem por valor: na "referência" o que é copiado é o *endereço*. Como a função conhece o endereço, consegue alterar o original.

## 2. O clássico: troca de valores

```c
void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 1, y = 2;
    troca(&x, &y);          /* passa os ENDEREÇOS */
    printf("%d %d", x, y);  /* 2 1 */
}
```

Se `troca` recebesse `int a, int b`, só as cópias seriam trocadas.

## 3. Devolvendo vários resultados

`return` devolve um único valor. Para devolver vários, use parâmetros de saída:

```c
void divide(int a, int b, int *quociente, int *resto) {
    *quociente = a / b;
    *resto     = a % b;
}
```

## 4. Vetores como parâmetros

Quando você passa um vetor, a função recebe o **endereço do primeiro elemento** (nenhuma cópia do vetor é feita). Por isso:

- a função **altera o vetor original**
- é preciso passar o **tamanho** como outro parâmetro (dentro da função, `sizeof(v)` dá o tamanho do ponteiro, não do vetor)

```c
void dobra(int *v, int n) {     /* int v[] é equivalente */
    for (int i = 0; i < n; i++)
        v[i] *= 2;
}
```

## 5. `const` protege os dados

Se a função só **lê** o vetor, marque `const`; o compilador impede alterações acidentais:

```c
int soma(const int *v, int n);
```

## 6. `scanf` e o `&`

`scanf("%d", &n)` precisa do **endereço** de `n` para gravar o valor lido nele. É chamada por referência!  
Com vetores de `char` não precisa do `&`, pois o nome do vetor já é um endereço.

## 7. Erros comuns

- Esquecer o `&` na chamada (`troca(x, y)`)
- Esquecer o `*` dentro da função (`a = b` em vez de `*a = *b`)
- Passar um vetor sem o tamanho
- Devolver o endereço de uma variável local (ela deixa de existir ao fim da função)

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
