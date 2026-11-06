🌐 [Português](teorico.md) · **English**

# Module 07 · Theory answer key

**1.**

```c
p->idade = 30;
(*p).idade = 30;
```

`*p.idade` is read as `*(p.idade)`, because the `.` operator has **higher precedence** than `*`. That tries to access `.idade` of a pointer (compile error). Hence the parentheses in `(*p).idade`, or, better, the arrow `->`.

**2.** By value, the **entire** struct is copied on every call (time and memory cost, large if the struct has arrays) and the function only changes the copy. By pointer, only the address (8 bytes) is copied and the function can change the original. `const` guarantees to the compiler (and to the reader) that the function won't modify the data.

**3.** `a` is an **uninitialized** pointer: it points to garbage. `a->ra = 1001` writes to an invalid address (undefined behavior). Fix: point it to an existing struct (`Aluno x; Aluno *a = &x;`) or allocate (`a = malloc(sizeof(*a));`).

**4.** Correct order: first `free(c->nome);` and then `free(c);`.

If we did `free(c)` first, we'd lose the only path to `c->nome` (the pointer was inside the freed block): the name's block becomes a **leak**, and accessing `c->nome` after `free(c)` would be use of freed memory.

**5.** Option **c**.
- a) `malloc(n)` reserves `n` bytes: far too little.
- b) `sizeof(Produto *)` is the size of a **pointer** (8 bytes), not of the struct.
- c) `n * sizeof(Produto)` (or `n * sizeof(*v)`) reserves exactly the space for `n` structs.
