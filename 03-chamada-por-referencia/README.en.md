🌐 [Português](README.md) · **English**

# 03 · Call by reference

> **Course plan:** Class 5 (Aug 24) — Call by Reference

## Goals

- Tell **pass by value** apart from **pass by reference**
- Write functions that change the caller's variables
- Return **more than one result** from a function
- Understand why arrays "are changed" inside functions

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c`
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Compare with `gabarito/`

---

## 1. By value × by reference

| | By value | By reference |
|---|---|---|
| What the function receives | a **copy** of the value | the variable's **address** |
| Changes the original? | no | **yes** |
| Syntax | `void f(int x)` | `void f(int *x)` |
| Call | `f(a)` | `f(&a)` |

> Technically, C **only** has pass by value: in "reference" passing, what gets copied is the *address*. Since the function knows the address, it can change the original.

## 2. The classic: swapping values

```c
void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 1, y = 2;
    troca(&x, &y);          /* passes the ADDRESSES */
    printf("%d %d", x, y);  /* 2 1 */
}
```

If `troca` received `int a, int b`, only the copies would be swapped.

## 3. Returning several results

`return` gives back a single value. To return several, use output parameters:

```c
void divide(int a, int b, int *quociente, int *resto) {
    *quociente = a / b;
    *resto     = a % b;
}
```

## 4. Arrays as parameters

When you pass an array, the function receives the **address of the first element** (no copy of the array is made). Therefore:

- the function **changes the original array**
- you must pass the **size** as another parameter (inside the function, `sizeof(v)` gives the pointer size, not the array size)

```c
void dobra(int *v, int n) {     /* int v[] is equivalent */
    for (int i = 0; i < n; i++)
        v[i] *= 2;
}
```

## 5. `const` protects the data

If the function only **reads** the array, mark it `const`; the compiler prevents accidental changes:

```c
int soma(const int *v, int n);
```

## 6. `scanf` and the `&`

`scanf("%d", &n)` needs the **address** of `n` to store the value it reads. It's a call by reference!  
With `char` arrays you don't need `&`, since the array name is already an address.

## 7. Common mistakes

- Forgetting the `&` in the call (`troca(x, y)`)
- Forgetting the `*` inside the function (`a = b` instead of `*a = *b`)
- Passing an array without its size
- Returning the address of a local variable (it ceases to exist when the function ends)

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
