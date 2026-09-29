🌐 [Português](README.md) · **English**

# 01 · Functions

> **Course plan:** Class 2 (Aug 10) — Functions review

## Goals

- Review the anatomy of a C function (return type, name, parameters, body)
- Understand prototypes, pass by value and variable scope
- Recognize when to use recursion

## How to study this module

1. Read this theory
2. Compile and run `exemplo.c` (read the comments!)
3. Solve `exercicios/teorico.en.md` and `exercicios/pratico.en.md`
4. Only then compare with the `gabarito/` folder (answer key)

---

## 1. What is a function?

A named block of code that performs a task and may return a result. Functions avoid repetition, keep programs organized and make testing easier.

```c
tipo_de_retorno nome(tipo param1, tipo param2) {
    /* corpo */
    return valor;
}
```

| Part | Example | Meaning |
|------|---------|---------|
| Return type | `int` | Type of the returned value (`void` = nothing) |
| Name | `soma` | Function identifier |
| Parameters | `int a, int b` | Values received |
| Body | `{ ... }` | Statements that are executed |

## 2. Prototype (declaration) × definition

The compiler reads the code from top to bottom. If a function is used **before** it is defined, it must be declared earlier with a **prototype**:

```c
int soma(int a, int b);          /* prototype: signature only + ; */

int main(void) {
    printf("%d\n", soma(2, 3));  /* use */
    return 0;
}

int soma(int a, int b) {         /* definition: with the body */
    return a + b;
}
```

## 3. Pass by value

In C, arguments are **copied** into the parameters. Changing the parameter inside the function does **not** change the original variable:

```c
void tenta_alterar(int x) { x = 99; }

int main(void) {
    int n = 10;
    tenta_alterar(n);
    printf("%d\n", n);   /* still 10 */
}
```

> To change the original variable you must pass its **address** — see module 03.

## 4. Scope and lifetime

- **Local:** declared inside the function; exists only while the function runs
- **Global:** declared outside any function; visible in the whole file (use sparingly)
- **`static` local:** keeps its value between calls

If a local variable has the same name as a global one, the local one "hides" the global inside that function.

## 5. Recursion

A function that calls itself. It needs:

1. **Base case** — when to stop
2. **Recursive step** — a call with a smaller problem

```c
long long fatorial(int n) {
    if (n <= 1) return 1;          /* base case */
    return n * fatorial(n - 1);    /* recursive step */
}
```

## 6. Common mistakes

- Forgetting the `return` in a non-`void` function
- Calling the function with the wrong number/type of arguments
- Forgetting the prototype (*implicit declaration* warning)
- Recursion without a base case (stack overflow)
- Thinking the function changes the variable in `main` (it's pass by value!)

## Files in this module

| File | Content |
|------|---------|
| `exemplo.c` | Commented code |
| `exercicios/teorico.en.md` | 5 theory questions |
| `exercicios/pratico.en.md` | 4 practical exercises |
| `gabarito/teorico.en.md` | Answers with explanations |
| `gabarito/pratico/` | Solutions in C |
