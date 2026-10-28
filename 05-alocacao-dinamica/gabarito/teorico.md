🌐 **Português** · [English](teorico.en.md)

# Módulo 05 · Gabarito teórico

**1.** `malloc(bytes)` reserva a quantidade de bytes pedida **sem inicializar** (o conteúdo é lixo). `calloc(n, tam)` reserva `n * tam` bytes e os **zera**. O `calloc` recebe dois argumentos e evita o cálculo manual do tamanho total.

**2.** `malloc(5)` reserva **5 bytes**, mas 5 inteiros precisam de `5 * sizeof(int)` (20 bytes numa máquina típica). Escrever além dos 5 bytes corrompe a memória. Correção:

```c
int *v = malloc(5 * sizeof(int));   /* ou 5 * sizeof(*v) */
```

**3.** É reservar memória e **perder o ponteiro** sem liberá-la; a memória fica ocupada até o programa terminar.

```c
int *p = malloc(100 * sizeof(int));
p = malloc(50 * sizeof(int));   /* o primeiro bloco foi perdido! */
```

Correção: `free(p);` antes de reatribuir (e sempre um `free` para cada `malloc`).

**4.** O ponteiro continua guardando o endereço antigo (**ponteiro pendente**). Usar `*p` é comportamento indefinido: pode ler lixo, corromper dados ou travar. Boa prática: após `free(p)`, fazer `p = NULL;` (assim um uso errado falha de forma previsível e um novo `free(NULL)` é inofensivo).

**5.** Se `realloc` falha, devolve `NULL`, mas o bloco original **continua alocado**. Em `v = realloc(v, ...)`, o `NULL` sobrescreveria `v` e perderíamos o endereço do bloco original (vazamento). Com `novo = realloc(v, ...)` podemos testar `novo` e ainda liberar/usar `v`.
