🌐 [Português](teorico.md) · **English**

# Module 02 · Theory answer key

**1.**
- `&` (address-of operator): returns the address of a variable. Ex.: `&x`
- `*` (dereference operator): accesses the value at the address stored in the pointer. Ex.: `*p`

```c
int x = 7;
int *p = &x;     /* & : p receives the address of x */
printf("%d", *p); /* * : prints 7 */
```

**2.** Output: `15`

`p` points to `a`; `*p = *p + 5` does `a = 10 + 5`.

**3.** Output: `20 30`

`p++` advances one `int`, so `p` points to `v[1]`. `*p` is 20 and `*(p + 1)` is `v[2]` = 30.

**4.** `p` was not initialized: it holds an arbitrary address ("garbage"). `*p = 5` writes to an unknown memory region — undefined behavior, usually a *segmentation fault* or silent data corruption. Fix: make `p` point to a valid variable (`p = &x;`) or allocate memory (module 05).

**5.** `NULL` is the special value meaning "points to nothing". Initializing with `NULL` avoids pointers holding garbage, and testing (`if (p != NULL)`) prevents dereferencing an invalid pointer. Dereferencing `NULL` crashes the program in a predictable way, which is easier to debug than a random garbage address.
