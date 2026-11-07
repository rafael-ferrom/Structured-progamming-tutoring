🌐 [Português](teorico.md) · **English**

# Module 08 · Theory exercises

**1.** Explain the difference between the modes `"r"`, `"w"` and `"a"`. What happens to an existing file opened in `"w"` mode?

**2.** Why should we always check the value returned by `fopen`? In which situations does it return `NULL`?

**3.** What is the relation between `printf` and `fprintf`? What is `stdout`?

**4.** Explain why the loop below may process the last line twice or use garbage. Rewrite it correctly.

```c
while (!feof(f)) {
    fscanf(f, "%d", &x);
    printf("%d\n", x);
}
```

**5.** What is the difference between a text file and a binary file? Why must the return value of `fgetc` be stored in an `int` and not a `char`?
