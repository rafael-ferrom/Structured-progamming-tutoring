🌐 **Português** · [English](teorico.en.md)

# Módulo 04 · Gabarito teórico

**1.** O `'\0'` (caractere nulo, valor 0) marca o **fim** da string; as funções de `<string.h>` andam até encontrá-lo. `char s[] = "ola";` ocupa **4 bytes** (`'o'`, `'l'`, `'a'`, `'\0'`).

**2.**
- `char s[] = "abc";` cria um vetor na pilha com uma **cópia** do texto → pode ser modificado (`s[0] = 'X'`).
- `char *p = "abc";` aponta para um **literal** guardado em memória somente leitura → modificar é comportamento indefinido (normalmente *segmentation fault*). O correto é declarar `const char *p`.

**3.** Saída: `gramacao g`

`"Programacao"` = P(0) r(1) o(2) g(3) r(4) a(5) m(6) a(7) c(8) a(9) o(10). `p = s + 3` aponta para o `'g'`, então `%s` imprime de `g` até o fim ("gramacao") e `*p` é `'g'`.

**4.**
- `gets` não limita o tamanho → *buffer overflow*; foi removida do C11.
- `scanf("%s")` também não limita (a menos que se use `%29s`, por exemplo) e para no primeiro espaço.
- `fgets(s, tam, stdin)` respeita o tamanho e lê a linha inteira, mas **mantém o `'\n'`** no fim da string. Para remover: `s[strcspn(s, "\n")] = '\0';`

**5.**
- `dias[1]` → `"Ter"` (um `const char *`)
- `dias[1][0]` → `'T'`
- `*(dias[2] + 1)` → `'u'` (segundo caractere de `"Qua"`)
