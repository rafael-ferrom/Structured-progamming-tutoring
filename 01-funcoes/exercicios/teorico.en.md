🌐 [Português](teorico.md) · **English**

# Module 01 · Theory exercises

**1.** What is the difference between a function's **prototype** and its **definition**? Why is the prototype needed when the function is defined after `main`?

**2.** What is the output of the program?

```c
#include <stdio.h>
int f(int x) { x = x * 2; return x; }
int main(void) {
    int a = 5;
    int b = f(a);
    printf("%d %d", a, b);
    return 0;
}
```

**3.** Choose the correct option. In C, when we pass an `int` variable as an argument to a function:

- a) the function receives the variable itself and can change it
- b) the function receives a copy of the value
- c) the function receives the address of the variable
- d) the compiler prevents the function from changing the value

**4.** Find the error and explain what happens:

```c
int dobro(int x) {
    x * 2;
}
```

**5.** What is the output of the program? Explain.

```c
#include <stdio.h>
int x = 10;
void f(void) { int x = 20; printf("%d ", x); }
int main(void) {
    f();
    printf("%d", x);
    return 0;
}
```
