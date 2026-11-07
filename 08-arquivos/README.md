🌐 **Português** · [English](README.en.md)

# 08 · Arquivos em I/O e operações com arquivos

> **Plano de aprendizagem:** Aula 13 (26/10) — Arquivos em I/O · Aulas 14 e 16 (09/11 e 23/11) — Exercícios com Arquivos

## Objetivos

- Abrir, ler, escrever e fechar arquivos de texto
- Escolher o modo de abertura correto
- Ler até o fim do arquivo sem cair nas armadilhas do `feof`
- Persistir dados (guardar em disco para usar depois)

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode `exemplo.c` (ele cria arquivos `.txt` na pasta atual)
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Compare com `gabarito/`

---

## 1. Arquivo em C: `FILE *`

Um arquivo é acessado por um ponteiro do tipo `FILE *`, definido em `<stdio.h>`.

```c
FILE *f = fopen("dados.txt", "r");
if (f == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
}
/* ... usa f ... */
fclose(f);
```

> **Sempre** teste se `fopen` devolveu `NULL` e **sempre** feche com `fclose`.

## 2. Modos de abertura (texto)

| Modo | Significado | Se o arquivo não existe | Se existe |
|------|-------------|--------------------------|-----------|
| `"r"`  | leitura | erro (`NULL`) | lê do início |
| `"w"`  | escrita | cria | **apaga o conteúdo** |
| `"a"`  | acrescentar | cria | escreve no final |
| `"r+"` | leitura e escrita | erro | mantém o conteúdo |
| `"w+"` | leitura e escrita | cria | **apaga o conteúdo** |

Para arquivos binários, acrescente `b`: `"rb"`, `"wb"`, `"ab"` (módulo 09).

## 3. Funções de leitura e escrita (texto)

| Escrita | Leitura | Unidade |
|---------|---------|---------|
| `fprintf(f, fmt, ...)` | `fscanf(f, fmt, ...)` | dados formatados |
| `fputs(s, f)` | `fgets(s, n, f)` | linha |
| `fputc(c, f)` | `fgetc(f)` | caractere |

`printf(...)` é o mesmo que `fprintf(stdout, ...)`; `scanf(...)` equivale a `fscanf(stdin, ...)`.

## 4. Lendo até o fim do arquivo

**Forma correta** — usar o valor de retorno da leitura:

```c
int x;
while (fscanf(f, "%d", &x) == 1) {
    /* usa x */
}
```

```c
char linha[100];
while (fgets(linha, sizeof(linha), f) != NULL) {
    /* usa linha */
}
```

```c
int c;                               /* int, não char! */
while ((c = fgetc(f)) != EOF) {
    /* usa c */
}
```

**Forma errada (bug clássico):**

```c
while (!feof(f)) {          /* feof só vira verdadeiro DEPOIS de tentar ler além do fim */
    fscanf(f, "%d", &x);    /* a última leitura falha, mas x é usado mesmo assim */
    printf("%d\n", x);      /* repete o último valor / imprime lixo */
}
```

## 5. Texto × binário

- **Texto:** legível por humanos (`fprintf`, `fscanf`); números viram caracteres
- **Binário:** bytes copiados da memória (`fwrite`, `fread`); menor, mais rápido, não legível — módulo 09

## 6. Caminho dos arquivos

`"dados.txt"` é relativo ao **diretório de trabalho** de onde o programa é executado (no VS Code, normalmente a pasta do projeto — não necessariamente a do `.c`). Se der `NULL`, confira onde está executando.

## 7. Erros comuns

- Não testar o retorno de `fopen`
- Abrir com `"w"` um arquivo que queria manter (apaga tudo!)
- Esquecer `fclose` (dados podem não chegar ao disco)
- Usar `while (!feof(f))`
- Guardar `fgetc` em `char` (impede detectar `EOF`)
- Ler nomes com espaço usando `%s` no `fscanf`

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
