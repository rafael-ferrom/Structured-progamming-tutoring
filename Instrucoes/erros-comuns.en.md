🌐 [Português](erros-comuns.md) · **English**

# Common C errors and how to fix them

## Compilation errors

| Message | Likely cause | Fix |
|---------|--------------|-----|
| `implicit declaration of function 'x'` | function used before being declared, or a missing `#include` | add the prototype / include the header (`<string.h>`, `<stdlib.h>`...) |
| `expected ';' before ...` | missing `;` on the previous line | check the previous line |
| `undefined reference to 'x'` | function declared but not defined (or a file is missing from the command) | implement the function / compile all the `.c` files |
| `assignment to expression with array type` | `nome = "Ana"` with an array | use `strcpy(nome, "Ana")` |
| `incompatible pointer type` | wrong pointer type (e.g. `int*` × `int**`) | review the types |
| `control reaches end of non-void function` | missing `return` | return a value on every path |
| `format '%d' expects argument of type 'int'` | `printf`/`scanf` format doesn't match the variable | use `%f` for `float`, `%lf` in `scanf` for `double`... |

## Runtime errors

| Symptom | Likely cause |
|---------|--------------|
| `Segmentation fault` | null/uninitialized pointer, array overflow, use after `free`, modifying a string literal |
| Strange values ("garbage") | uninitialized variable or out-of-bounds read |
| Program "skips" `fgets` reads | a leftover `'\n'` in the buffer after a `scanf` |
| `while (!feof(f))` repeats the last line | use the return value of `fscanf`/`fgets` as the condition |
| File doesn't open (`fopen` returns NULL) | running from another folder; wrong path |
| Memory leak | missing `free` (one per `malloc`) |

## Good practices

- Initialize all variables and pointers (use `NULL`)
- Always check the return of `scanf`, `fopen` and `malloc`
- After `free(p)`, do `p = NULL`
- Use `sizeof(*p)` in `malloc`
- Compile with `-Wall -Wextra` and **get rid of all warnings**
- Use variable and function names that explain what they do
