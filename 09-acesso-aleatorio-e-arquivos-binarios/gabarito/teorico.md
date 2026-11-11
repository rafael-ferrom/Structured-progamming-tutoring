🌐 **Português** · [English](teorico.en.md)

# Módulo 09 · Gabarito teórico

**1.** `fseek(f, deslocamento, origem)`:
- `f`: o arquivo;
- `deslocamento`: quantos **bytes** andar (pode ser negativo);
- `origem`: de onde contar — `SEEK_SET` (início), `SEEK_CUR` (posição atual) ou `SEEK_END` (fim).

```c
fseek(f, 4L * (long)sizeof(Registro), SEEK_SET);   /* quinto registro (indice 4) */
fseek(f, 0, SEEK_END);                             /* final do arquivo */
```

**2.** O campo `char *nome` guarda apenas um **endereço de memória**. `fwrite` grava esse número no arquivo, não o texto. Na próxima execução o endereço não vale mais (e o texto não está no arquivo). Solução: usar um vetor de tamanho fixo dentro da struct (`char nome[30]`), assim os caracteres fazem parte da própria estrutura e são gravados junto.

**3.** `1000 / 40 = 25` registros.

```c
fseek(f, 0, SEEK_END);
long total = ftell(f) / (long)sizeof(Registro);
```

**4.** `"wb"` **apaga** o conteúdo do arquivo ao abrir — perderíamos todos os outros registros. `"rb+"` abre para leitura e escrita **preservando** o conteúdo. Após `fread`, a posição do arquivo já avançou para o **próximo** registro; se gravarmos sem voltar, o `fwrite` sobrescreveria o registro seguinte. Por isso fazemos `fseek` de volta ao início do registro lido antes do `fwrite` (o `fseek` também é exigido ao alternar leitura/escrita).

**5.** `rewind(f)` reposiciona o arquivo no **início** e limpa os indicadores de erro/fim de arquivo. É equivalente a `fseek(f, 0, SEEK_SET)`.
