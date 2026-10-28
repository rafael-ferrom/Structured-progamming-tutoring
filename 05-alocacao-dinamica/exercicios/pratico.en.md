🌐 [Português](pratico.md) · **English**

# Module 05 · Practical exercises

**Ex 1 — Dynamic array.** Read `n`, allocate an array of `n` integers, fill it with the squares `1, 4, 9, ...`, print it, compute the average and free the memory.

**Ex 2 — Growing array.** Read integers until the user types `0`. Store them in a dynamic array that starts with capacity 2 and **doubles** when full (`realloc`). At the end, print the count, the sum and the final capacity.

**Ex 3 — Dynamic matrix and transpose.** Read `linhas` and `colunas`, allocate a matrix filled with `1, 2, 3, ...`, allocate its **transpose** and print both. Create the functions `aloca_matriz` and `libera_matriz`.

**Ex 4 — Concatenation.** Write `int *concatena(const int *a, int na, const int *b, int nb, int *ntotal)` that returns a **new** dynamic array with the elements of `a` followed by those of `b`. Test it in `main` and free the memory.
