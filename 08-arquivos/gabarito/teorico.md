🌐 **Português** · [English](teorico.en.md)

# Módulo 08 · Gabarito teórico

**1.**
- `"r"` — abre para **leitura**; o arquivo precisa existir.
- `"w"` — abre para **escrita**; cria se não existir e, se existir, **apaga todo o conteúdo** (trunca).
- `"a"` — abre para **acrescentar**; cria se não existir e, se existir, escreve no final sem apagar nada.

**2.** Porque `fopen` devolve `NULL` quando falha, e usar um `FILE *` nulo derruba o programa. Falhas típicas: arquivo inexistente em modo `"r"`, caminho errado (diretório de trabalho diferente do esperado), falta de permissão, disco cheio ou nome inválido.

**3.** `printf(fmt, ...)` equivale a `fprintf(stdout, fmt, ...)`. `stdout` é um `FILE *` predefinido que representa a saída padrão (a tela). Por isso a mesma família de funções serve para tela e arquivos. (Analogamente, `stdin` é a entrada padrão e `stderr` a saída de erros.)

**4.** `feof` só devolve verdadeiro **depois** que uma leitura tentou passar do fim. Na última volta, a condição ainda é falsa, `fscanf` falha (não lê nada) e `x` mantém o valor anterior, que é impresso de novo (ou lixo, se nunca foi lido). Forma correta, usando o retorno de `fscanf`:

```c
while (fscanf(f, "%d", &x) == 1) {
    printf("%d\n", x);
}
```

**5.** Em arquivo de **texto** os dados são caracteres legíveis (o número 123 vira `'1' '2' '3'`), e pode haver conversão de quebra de linha. Em arquivo **binário** os bytes são copiados exatamente como estão na memória (o `int` 123 ocupa 4 bytes), sem conversão; é mais compacto e rápido, mas não legível. `fgetc` devolve um `int` porque precisa representar todos os valores de `char` **mais** o valor especial `EOF` (-1). Em um `char`, `EOF` poderia ser confundido com um caractere válido (ou nunca ser reconhecido, se `char` não tiver sinal).
