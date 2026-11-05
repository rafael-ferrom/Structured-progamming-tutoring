🌐 **Português** · [English](teorico.en.md)

# Módulo 06 · Gabarito teórico

**1.**

```c
typedef struct {
    char  titulo[61];    /* 60 caracteres + '\0' */
    int   ano;
    float preco;
} Livro;
```

Vantagem do `typedef`: cria um nome curto para o tipo. Sem ele, seria preciso escrever `struct Livro l;`; com ele, basta `Livro l;`.

**2.** Saída: `1 99`

`p2 = p1` **copia** os campos. Alterar `p2.x` não afeta `p1`.

**3.** Vetor: coleção de elementos do **mesmo tipo**, acessados por índice (ex.: 30 notas de tipo `float`). Estrutura: coleção de campos de **tipos diferentes**, acessados por nome (ex.: um aluno com nome, RA e nota).

**4.** `strcpy(c.end.cidade, "Salto");`

Strings não podem ser atribuídas com `=` (é um vetor); usa-se `strcpy`. Os campos aninhados são acessados encadeando o operador `.`.

**5.** **Não muda.** A função recebe uma **cópia** da estrutura inteira (passagem por valor). Para alterar o original é preciso receber um ponteiro (`Produto *p`) — módulo 07 — ou devolver a estrutura modificada.
