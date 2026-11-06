🌐 **Português** · [English](teorico.en.md)

# Módulo 07 · Gabarito teórico

**1.**

```c
p->idade = 30;
(*p).idade = 30;
```

`*p.idade` é lido como `*(p.idade)`, porque o operador `.` tem **precedência maior** que `*`. Isso tenta acessar `.idade` de um ponteiro (erro de compilação). Por isso os parênteses em `(*p).idade`, ou, melhor, a seta `->`.

**2.** Por valor, a estrutura **inteira** é copiada a cada chamada (custo de tempo e memória, grande se a struct tiver vetores) e a função só altera a cópia. Por ponteiro, apenas o endereço (8 bytes) é copiado e a função pode alterar o original. O `const` garante ao compilador (e a quem lê) que a função não vai modificar os dados.

**3.** `a` é um ponteiro **não inicializado**: aponta para lixo. `a->ra = 1001` escreve em endereço inválido (comportamento indefinido). Correção: apontar para uma struct existente (`Aluno x; Aluno *a = &x;`) ou alocar (`a = malloc(sizeof(*a));`).

**4.** Ordem correta: primeiro `free(c->nome);` e depois `free(c);`.

Se fizermos `free(c)` antes, perdemos o único caminho para chegar em `c->nome` (o ponteiro estava dentro do bloco liberado): o bloco do nome vira **vazamento**, e acessar `c->nome` depois do `free(c)` seria uso de memória liberada.

**5.** Alternativa **c**.
- a) `malloc(n)` reserva `n` bytes: pouco demais.
- b) `sizeof(Produto *)` é o tamanho de um **ponteiro** (8 bytes), não da struct.
- c) `n * sizeof(Produto)` (ou `n * sizeof(*v)`) reserva exatamente o espaço de `n` estruturas.
