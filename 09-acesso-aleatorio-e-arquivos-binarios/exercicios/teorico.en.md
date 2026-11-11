🌐 [Português](teorico.md) · **English**

# Module 09 · Theory exercises

**1.** Explain the three arguments of `fseek(f, offset, origin)`. Give the statement to go to the **fifth** record (index 4) of a `Registro` file, and the statement to go to the end of the file.

**2.** Why shouldn't we use `fwrite` on a struct that contains a `char *nome` field? How can it be solved?

**3.** A binary file has 1000 bytes and each record takes `sizeof(Registro) = 40` bytes. How many records does it hold? Write the code that computes this using `fseek` and `ftell`.

**4.** What is the difference between opening a file with `"wb"` and with `"rb+"` when we want to change a single record? Why is an `fseek` needed before rewriting the record we read?

**5.** What does `rewind(f)` do? Which `fseek` call is equivalent?
