🌐 **Português** · [English](teorico.en.md)

# Módulo 01 · Gabarito teórico

**1.** O **protótipo** só informa ao compilador o nome, o tipo de retorno e os tipos dos parâmetros (termina com `;`). A **definição** contém o corpo com o código. O protótipo é necessário porque o compilador lê de cima para baixo: sem ele, ao encontrar a chamada no `main` ele ainda não conhece a função e não consegue verificar a chamada.

**2.** Saída: `5 10`

`f` recebe uma **cópia** de `a`. O `x = x * 2` altera só a cópia; `a` continua 5. O valor devolvido (10) é guardado em `b`.

**3.** Alternativa **b**. A passagem é por valor: a função recebe uma cópia. (Para alterar o original, é preciso passar o endereço — módulo 03.)

**4.** A expressão `x * 2;` calcula o valor mas não o devolve: falta o `return`. A função é `int`, então o valor de retorno fica **indefinido** e usar o resultado é comportamento indefinido. O compilador emite warning (`control reaches end of non-void function`). Correção:

```c
int dobro(int x) {
    return x * 2;
}
```

**5.** Saída: `20 10`

Dentro de `f`, a variável local `x` (20) **esconde** a global `x`. No `main`, não há local `x`, então usa-se a global (10).
