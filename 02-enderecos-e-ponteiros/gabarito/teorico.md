🌐 **Português** · [English](teorico.en.md)

# Módulo 02 · Gabarito teórico

**1.**
- `&` (operador de endereço): devolve o endereço de uma variável. Ex.: `&x`
- `*` (operador de desreferência): acessa o valor no endereço guardado no ponteiro. Ex.: `*p`

```c
int x = 7;
int *p = &x;     /* & : p recebe o endereço de x */
printf("%d", *p); /* * : imprime 7 */
```

**2.** Saída: `15`

`p` aponta para `a`; `*p = *p + 5` faz `a = 10 + 5`.

**3.** Saída: `20 30`

`p++` avança um `int`, então `p` aponta para `v[1]`. `*p` é 20 e `*(p + 1)` é `v[2]` = 30.

**4.** `p` não foi inicializado: contém um endereço qualquer ("lixo"). `*p = 5` escreve numa região de memória desconhecida — comportamento indefinido, normalmente um *segmentation fault* ou corrupção silenciosa de dados. Correção: apontar `p` para uma variável válida (`p = &x;`) ou alocar memória (módulo 05).

**5.** `NULL` é o valor especial que significa "não aponta para nada". Inicializar com `NULL` evita ponteiros com lixo, e testar (`if (p != NULL)`) impede desreferenciar um ponteiro inválido. Desreferenciar `NULL` derruba o programa de forma previsível, o que é mais fácil de depurar que um lixo aleatório.
