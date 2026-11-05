🌐 **Português** · [English](teorico.en.md)

# Módulo 06 · Exercícios teóricos

**1.** Declare uma estrutura `Livro` com título (até 60 caracteres), ano e preço, usando `typedef`. Qual a vantagem do `typedef`?

**2.** Qual a saída?

```c
typedef struct { int x, y; } Ponto;
Ponto p1 = {1, 2};
Ponto p2 = p1;
p2.x = 99;
printf("%d %d", p1.x, p2.x);
```

**3.** Qual a diferença entre um vetor e uma estrutura? Dê um exemplo de quando usar cada um.

**4.** Dadas as declarações abaixo, escreva o comando que atribui `"Salto"` à cidade do cliente `c`.

```c
typedef struct { char cidade[30]; } Endereco;
typedef struct { char nome[40]; Endereco end; } Cliente;
Cliente c;
```

**5.** Se uma função é declarada como `void reajusta(Produto p)` e altera `p.preco` dentro dela, o preço do produto original no `main` muda? Explique.
