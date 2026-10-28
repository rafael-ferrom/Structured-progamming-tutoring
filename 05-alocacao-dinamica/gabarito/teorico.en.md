🌐 [Português](teorico.md) · **English**

# Module 05 · Theory answer key

**1.** `malloc(bytes)` reserves the requested number of bytes **without initializing** them (the content is garbage). `calloc(n, size)` reserves `n * size` bytes and **zeroes** them. `calloc` takes two arguments, which avoids computing the total size by hand.

**2.** `malloc(5)` reserves **5 bytes**, but 5 integers need `5 * sizeof(int)` (20 bytes on a typical machine). Writing beyond those 5 bytes corrupts memory. Fix:

```c
int *v = malloc(5 * sizeof(int));   /* or 5 * sizeof(*v) */
```

**3.** It's reserving memory and **losing the pointer** without freeing it; the memory stays occupied until the program ends.

```c
int *p = malloc(100 * sizeof(int));
p = malloc(50 * sizeof(int));   /* the first block was lost! */
```

Fix: `free(p);` before reassigning (and always one `free` for each `malloc`).

**4.** The pointer still holds the old address (**dangling pointer**). Using `*p` is undefined behavior: it may read garbage, corrupt data or crash. Good practice: after `free(p)`, do `p = NULL;` (so a wrong use fails predictably, and another `free(NULL)` is harmless).

**5.** If `realloc` fails it returns `NULL`, but the original block **remains allocated**. With `v = realloc(v, ...)`, the `NULL` would overwrite `v` and we'd lose the address of the original block (a leak). With `novo = realloc(v, ...)` we can check `novo` and still free/use `v`.
