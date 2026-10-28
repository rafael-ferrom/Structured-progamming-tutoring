🌐 [Português](teorico.md) · **English**

# Module 05 · Theory exercises

**1.** What is the difference between `malloc` and `calloc`?

**2.** A programmer wants to allocate space for 5 integers and wrote `int *v = malloc(5);`. What is the problem? How can it be fixed?

**3.** What is a memory leak? Show a snippet that causes one and how to fix it.

**4.** What can happen if the program uses `*p` after `free(p)`? Which good practice helps avoid this problem?

**5.** Why is it recommended to use an auxiliary variable when calling `realloc` (instead of `v = realloc(v, ...)`)?
