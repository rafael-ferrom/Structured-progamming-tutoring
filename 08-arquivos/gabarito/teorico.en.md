🌐 [Português](teorico.md) · **English**

# Module 08 · Theory answer key

**1.**
- `"r"` — opens for **reading**; the file must exist.
- `"w"` — opens for **writing**; creates the file if it doesn't exist and, if it does, **erases all its contents** (truncates).
- `"a"` — opens for **appending**; creates the file if it doesn't exist and, if it does, writes at the end without erasing anything.

**2.** Because `fopen` returns `NULL` on failure, and using a null `FILE *` crashes the program. Typical failures: nonexistent file in `"r"` mode, wrong path (working directory different from what you expect), lack of permission, full disk or invalid name.

**3.** `printf(fmt, ...)` is equivalent to `fprintf(stdout, fmt, ...)`. `stdout` is a predefined `FILE *` that represents standard output (the screen). That's why the same family of functions works for the screen and for files. (Similarly, `stdin` is standard input and `stderr` is the error output.)

**4.** `feof` only returns true **after** a read has tried to go past the end. In the last iteration the condition is still false, `fscanf` fails (reads nothing) and `x` keeps its previous value, which is printed again (or garbage, if it was never read). Correct form, using `fscanf`'s return value:

```c
while (fscanf(f, "%d", &x) == 1) {
    printf("%d\n", x);
}
```

**5.** In a **text** file the data are readable characters (the number 123 becomes `'1' '2' '3'`), and newline conversion may occur. In a **binary** file the bytes are copied exactly as they are in memory (the `int` 123 takes 4 bytes), with no conversion; it's more compact and faster, but not readable. `fgetc` returns an `int` because it must represent every `char` value **plus** the special value `EOF` (-1). In a `char`, `EOF` could be mistaken for a valid character (or never recognized, if `char` is unsigned).
