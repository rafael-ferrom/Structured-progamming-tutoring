🌐 **Português** · [English](erros-comuns.en.md)

# Erros comuns em C e como resolver

## Erros de compilação

| Mensagem | Causa provável | Solução |
|----------|----------------|---------|
| `implicit declaration of function 'x'` | função usada antes de ser declarada, ou faltou `#include` | criar o protótipo / incluir o cabeçalho (`<string.h>`, `<stdlib.h>`...) |
| `expected ';' before ...` | faltou `;` na linha anterior | conferir a linha anterior |
| `undefined reference to 'x'` | função declarada mas não definida (ou faltou arquivo no comando) | implementar a função / compilar todos os `.c` |
| `assignment to expression with array type` | `nome = "Ana"` com vetor | usar `strcpy(nome, "Ana")` |
| `incompatible pointer type` | ponteiro do tipo errado (ex.: `int*` × `int**`) | revisar os tipos |
| `control reaches end of non-void function` | faltou `return` | devolver um valor em todos os caminhos |
| `format '%d' expects argument of type 'int'` | formato do `printf`/`scanf` não bate com a variável | usar `%f` para `float`, `%lf` no `scanf` de `double`... |

## Erros de execução

| Sintoma | Causa provável |
|---------|----------------|
| `Segmentation fault` | ponteiro nulo/não inicializado, vetor estourado, uso após `free`, modificar literal de string |
| Valores estranhos ("lixo") | variável não inicializada ou leitura fora dos limites |
| Programa "pula" leituras de `fgets` | sobrou `'\n'` no buffer depois de um `scanf` |
| `while (!feof(f))` repete a última linha | usar o retorno de `fscanf`/`fgets` como condição |
| Arquivo não abre (`fopen` devolve NULL) | executando de outra pasta; caminho errado |
| Vazamento de memória | faltou `free` (um por `malloc`) |

## Boas práticas

- Inicialize todas as variáveis e ponteiros (use `NULL`)
- Sempre teste o retorno de `scanf`, `fopen` e `malloc`
- Depois de `free(p)`, faça `p = NULL`
- Use `sizeof(*p)` no `malloc`
- Compile com `-Wall -Wextra` e **zere os avisos**
- Nomes de variáveis e funções que expliquem o que fazem
