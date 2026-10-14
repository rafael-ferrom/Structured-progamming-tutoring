🌐 [Português](teorico.md) · **English**

# Module 03 · Theory exercises

**1.** Why does the function below **not** swap the values of the variables in `main`? How would you fix it?

```c
void troca(int a, int b) {
    int t = a; a = b; b = t;
}
```

**2.** What is the output?

```c
void incrementa(int *x) { (*x)++; }

int main(void) {
    int n = 5;
    incrementa(&n);
    incrementa(&n);
    printf("%d", n);
    return 0;
}
```

**3.** Why do we use `&` in `scanf("%d", &n)` but not in `scanf("%s", nome)` (with `char nome[30]`)?

**4.** When an array is passed to a function, is it copied? What does `sizeof(v)` return **inside** the function when the parameter is `int v[]`? Therefore, what must be passed along with the array?

**5.** Find the error:

```c
void define_dez(int *p) {
    p = 10;
}
```
