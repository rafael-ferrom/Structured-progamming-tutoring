🌐 [Português](teorico.md) · **English**

# Module 03 · Theory answer key

**1.** Because `a` and `b` are **copies** of `x` and `y`. The swap happens on the copies, which vanish when the function ends. Fix: receive pointers and call with addresses.

```c
void troca(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
/* troca(&x, &y); */
```

**2.** Output: `7`

`incrementa` receives the address of `n` and does `n++` through the pointer, twice (5 → 6 → 7).

**3.** `scanf` needs the **address** where it stores the value read. `n` is an ordinary `int`, so we pass `&n`. `nome`, however, is an array, and an array's name **already is** the address of its first element; adding `&` would be redundant.

**4.** It is **not** copied: the function receives only the address of the first element. Inside the function, `sizeof(v)` returns the size of a **pointer** (8 bytes on 64 bits), not of the array. That's why the size `n` must be passed as an extra parameter.

**5.** `p = 10` tries to assign an `int` to the **pointer** (the compiler warns/errors). The intent was to change the pointed-to value: `*p = 10;`.
