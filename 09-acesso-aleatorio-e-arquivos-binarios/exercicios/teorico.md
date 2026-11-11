🌐 **Português** · [English](teorico.en.md)

# Módulo 09 · Exercícios teóricos

**1.** Explique os três argumentos de `fseek(f, deslocamento, origem)`. Dê o comando para ir ao **quinto** registro (índice 4) de um arquivo de `Registro`, e o comando para ir ao final do arquivo.

**2.** Por que não devemos gravar com `fwrite` uma estrutura que contém um campo `char *nome`? Como resolver?

**3.** Um arquivo binário tem 1000 bytes e cada registro ocupa `sizeof(Registro) = 40` bytes. Quantos registros ele possui? Escreva o trecho de código que calcula isso usando `fseek` e `ftell`.

**4.** Qual a diferença entre abrir um arquivo com `"wb"` e com `"rb+"` quando queremos alterar um único registro? Por que é necessário um `fseek` antes de regravar o registro lido?

**5.** O que faz `rewind(f)`? Que chamada de `fseek` é equivalente?
