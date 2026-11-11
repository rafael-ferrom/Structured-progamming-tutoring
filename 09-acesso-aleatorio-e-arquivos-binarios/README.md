🌐 **Português** · [English](README.en.md)

# 09 · Acesso aleatório e estruturas em arquivos

> **Plano de aprendizagem:** Aula 13 (26/10) — Acesso Aleatório com Arquivos · Aulas 14 e 16 — Exercícios com Arquivos  
> Conteúdo programático: *Acesso Aleatório* · *Estruturas e Arquivos em I/O*

## Objetivos

- Gravar e ler **blocos de bytes** com `fwrite` e `fread`
- Navegar dentro do arquivo com `fseek`, `ftell` e `rewind` (acesso aleatório)
- Guardar **estruturas** em arquivos binários
- Ler, alterar e buscar um registro sem percorrer o arquivo inteiro

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c` (cria `alunos.bin` na pasta de execução)
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Arquivos binários

Abrem-se com o modo terminado em `b`: `"rb"`, `"wb"`, `"ab"`, `"rb+"`, `"wb+"`.

```c
FILE *f = fopen("dados.bin", "wb");
```

## 2. `fwrite` e `fread`

```c
size_t fwrite(const void *ptr, size_t tamanho, size_t quantidade, FILE *f);
size_t fread (      void *ptr, size_t tamanho, size_t quantidade, FILE *f);
```

Ambas devolvem **quantos elementos** foram realmente escritos/lidos — compare com o esperado:

```c
int v[5] = {1, 2, 3, 4, 5};
if (fwrite(v, sizeof(int), 5, f) != 5) { /* erro */ }
```

## 3. Estruturas em arquivo

Com `fwrite` gravamos a estrutura inteira de uma vez:

```c
typedef struct {
    int   ra;
    char  nome[30];      /* vetor de tamanho fixo */
    float nota;
} Registro;

Registro r = {1001, "Ana", 8.5f};
fwrite(&r, sizeof(Registro), 1, f);
```

Cada registro ocupa exatamente `sizeof(Registro)` bytes, então o registro de índice `i` começa no byte `i * sizeof(Registro)`.

> ⚠️ **Não grave structs com ponteiros** (`char *nome`): o arquivo guardaria apenas o *endereço*, que não faz sentido na próxima execução. Use vetores de tamanho fixo.  
> O arquivo binário também pode variar entre computadores/compiladores (tamanho de `int`, alinhamento); para uso didático no mesmo ambiente é seguro.

## 4. Acesso aleatório: `fseek`, `ftell`, `rewind`

```c
int  fseek(FILE *f, long deslocamento, int origem);
long ftell(FILE *f);
void rewind(FILE *f);
```

| Origem | Significado |
|--------|-------------|
| `SEEK_SET` | início do arquivo |
| `SEEK_CUR` | posição atual |
| `SEEK_END` | final do arquivo |

Exemplos:

```c
fseek(f, i * sizeof(Registro), SEEK_SET);  /* vai para o registro i */
fseek(f, 0, SEEK_END);                     /* vai para o fim */
long bytes = ftell(f);                     /* posição atual = tamanho, se está no fim */
rewind(f);                                 /* volta ao início */
```

**Quantos registros o arquivo tem?**

```c
fseek(f, 0, SEEK_END);
long total = ftell(f) / (long)sizeof(Registro);
```

## 5. Atualizando um registro no lugar

Use `"rb+"` (lê e escreve **sem apagar**):

```c
fseek(f, i * sizeof(Registro), SEEK_SET);
fread(&r, sizeof(Registro), 1, f);        /* lê */
r.nota = 10.0f;                           /* altera */
fseek(f, i * sizeof(Registro), SEEK_SET); /* volta para o começo do registro! */
fwrite(&r, sizeof(Registro), 1, f);       /* grava por cima */
```

> Depois do `fread`, a posição avançou; é preciso fazer `fseek` de volta antes de regravar. Também é obrigatório um `fseek`/`fflush` ao alternar entre leitura e escrita no mesmo arquivo.

`"wb"` **apagaria** o arquivo — nunca use para atualizar.

## 6. Erros comuns

- Esquecer o `b` no modo (problemas no Windows)
- Gravar struct com ponteiro
- Esquecer o `&` ao gravar/ler uma struct simples (`fwrite(&r, ...)`); já para vetores o nome do vetor é o endereço
- Não voltar a posição antes de regravar
- Trocar `fread` por `fscanf` (formatos diferentes!)
- Ler além do fim: sempre compare o retorno de `fread`

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
