🌐 **Português** · [English](pratico.en.md)

# Módulo 09 · Exercícios práticos

**Ex 1 — Vetor em binário.** Grave um vetor de 10 inteiros no arquivo `vetor.bin` com `fwrite`. Reabra, leia com `fread` para outro vetor e imprima. Mostre o tamanho do arquivo (em bytes) usando `fseek`/`ftell` e confira com `10 * sizeof(int)`.

**Ex 2 — Leitura direta de registro.** Defina `Registro` (RA, nome[30], nota) e grave 6 registros em `turma.bin`. Escreva `int le_registro(FILE *f, int indice, Registro *r)` que usa `fseek` para ler **diretamente** o registro pedido (devolve 1 se conseguiu). Teste com os índices 0, 3, 5 e 9 (este último não existe).

**Ex 3 — Atualizar registro.** Escreva `int atualiza_nota(const char *arquivo, int indice, float nova_nota)` que altera apenas a nota de um registro **no lugar** (`"rb+"`). Depois de atualizar, releia e mostre o registro para conferir.

**Ex 4 — Agenda binária.** Implemente, sobre `agenda.bin`: `adiciona(...)` (acrescenta com `"ab"`), `total_registros(...)` (calculado pelo tamanho do arquivo), `lista(...)` e `busca_por_ra(...)` (devolve o índice ou -1). No `main`, adicione 4 registros, liste, busque um RA existente e outro inexistente.
