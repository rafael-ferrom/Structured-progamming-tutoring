🌐 **Português** · [English](teorico.en.md)

# Módulo 03 · Gabarito teórico

**1.** Porque `a` e `b` são **cópias** de `x` e `y`. A troca acontece nas cópias, que somem ao fim da função. Correção: receber ponteiros e chamar com endereços.

```c
void troca(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
/* troca(&x, &y); */
```

**2.** Saída: `7`

`incrementa` recebe o endereço de `n` e faz `n++` através do ponteiro, duas vezes (5 → 6 → 7).

**3.** `scanf` precisa do **endereço** onde gravar o valor lido. `n` é um `int` comum, então passamos `&n`. Já `nome` é um vetor, e o nome de um vetor **já é** o endereço do seu primeiro elemento; colocar `&` seria redundante.

**4.** **Não** é copiado: a função recebe apenas o endereço do primeiro elemento. Dentro da função, `sizeof(v)` devolve o tamanho de um **ponteiro** (8 bytes em 64 bits), não do vetor. Por isso o tamanho `n` precisa ser passado como parâmetro adicional.

**5.** `p = 10` tenta atribuir um `int` ao **ponteiro** (o compilador avisa/erro). A intenção era alterar o valor apontado: `*p = 10;`.
