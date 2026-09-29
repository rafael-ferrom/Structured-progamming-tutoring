🌐 **Português** · [English](README.en.md)

# 01 · Funções

> **Plano de aprendizagem:** Aula 2 (10/08) — Revisão de Funções

## Objetivos

- Revisar a anatomia de uma função em C (tipo de retorno, nome, parâmetros, corpo)
- Entender protótipos, passagem por valor e escopo de variáveis
- Reconhecer quando usar recursão

## Como estudar este módulo

1. Leia esta teoria
2. Compile e rode o `exemplo.c` (leia os comentários!)
3. Resolva `exercicios/teorico.md` e `exercicios/pratico.md`
4. Só depois compare com a pasta `gabarito/`

---

## 1. O que é uma função?

Um bloco de código com nome que executa uma tarefa e pode devolver um resultado. Funções evitam repetição, deixam o programa organizado e facilitam testes.

```c
tipo_de_retorno nome(tipo param1, tipo param2) {
    /* corpo */
    return valor;
}
```

| Parte | Exemplo | Significado |
|-------|---------|-------------|
| Tipo de retorno | `int` | Tipo do valor devolvido (`void` = nada) |
| Nome | `soma` | Identificador da função |
| Parâmetros | `int a, int b` | Valores recebidos |
| Corpo | `{ ... }` | Instruções executadas |

## 2. Protótipo (declaração) × definição

O compilador lê o código de cima para baixo. Se a função é usada **antes** de ser definida, é preciso declará-la antes com um **protótipo**:

```c
int soma(int a, int b);          /* protótipo: só a assinatura + ; */

int main(void) {
    printf("%d\n", soma(2, 3));  /* uso */
    return 0;
}

int soma(int a, int b) {         /* definição: com o corpo */
    return a + b;
}
```

## 3. Passagem de parâmetros por valor

Em C, os argumentos são **copiados** para os parâmetros. Alterar o parâmetro dentro da função **não** altera a variável original:

```c
void tenta_alterar(int x) { x = 99; }

int main(void) {
    int n = 10;
    tenta_alterar(n);
    printf("%d\n", n);   /* continua 10 */
}
```

> Para alterar a variável original é preciso passar o **endereço** dela — assunto do módulo 03.

## 4. Escopo e tempo de vida

- **Local:** declarada dentro da função; só existe enquanto a função executa
- **Global:** declarada fora de qualquer função; visível em todo o arquivo (use com moderação)
- **`static` local:** mantém o valor entre chamadas

Se uma local tem o mesmo nome de uma global, a local "esconde" a global dentro daquela função.

## 5. Recursão

Uma função que chama a si mesma. Precisa de:

1. **Caso base** — quando parar
2. **Passo recursivo** — chamada com um problema menor

```c
long long fatorial(int n) {
    if (n <= 1) return 1;          /* caso base */
    return n * fatorial(n - 1);    /* passo recursivo */
}
```

## 6. Erros comuns

- Esquecer o `return` em função que não é `void`
- Chamar a função com o número/tipo errado de argumentos
- Esquecer o protótipo (warning de *implicit declaration*)
- Recursão sem caso base (estouro de pilha)
- Achar que a função altera a variável do `main` (passagem por valor!)

## Arquivos deste módulo

| Arquivo | Conteúdo |
|---------|----------|
| `exemplo.c` | Código comentado |
| `exercicios/teorico.md` | 5 questões teóricas |
| `exercicios/pratico.md` | 4 exercícios práticos |
| `gabarito/teorico.md` | Respostas comentadas |
| `gabarito/pratico/` | Soluções em C |
