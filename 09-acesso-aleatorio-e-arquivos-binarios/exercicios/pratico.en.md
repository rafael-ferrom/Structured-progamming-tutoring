🌐 [Português](pratico.md) · **English**

# Module 09 · Practical exercises

**Ex 1 — Array in binary.** Write an array of 10 integers to the file `vetor.bin` with `fwrite`. Reopen it, read it with `fread` into another array and print it. Print the file size (in bytes) using `fseek`/`ftell` and check it against `10 * sizeof(int)`.

**Ex 2 — Direct record read.** Define `Registro` (RA, nome[30], nota) and write 6 records to `turma.bin`. Write `int le_registro(FILE *f, int indice, Registro *r)` that uses `fseek` to read the requested record **directly** (returns 1 on success). Test with indexes 0, 3, 5 and 9 (the last one doesn't exist).

**Ex 3 — Update a record.** Write `int atualiza_nota(const char *arquivo, int indice, float nova_nota)` that changes only the grade of a record **in place** (`"rb+"`). After updating, reread and print the record to check.

**Ex 4 — Binary address book.** On `agenda.bin`, implement: `adiciona(...)` (appends with `"ab"`), `total_registros(...)` (computed from the file size), `lista(...)` and `busca_por_ra(...)` (returns the index or -1). In `main`, add 4 records, list them, search for an existing RA and a nonexistent one.
