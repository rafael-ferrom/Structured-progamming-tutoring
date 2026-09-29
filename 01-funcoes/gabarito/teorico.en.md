🌐 [Português](teorico.md) · **English**

# Module 01 · Theory answer key

**1.** The **prototype** only tells the compiler the name, the return type and the parameter types (it ends with `;`). The **definition** contains the body with the code. The prototype is needed because the compiler reads top to bottom: without it, when it reaches the call in `main` it doesn't know the function yet and can't check the call.

**2.** Output: `5 10`

`f` receives a **copy** of `a`. `x = x * 2` changes only the copy; `a` stays 5. The returned value (10) is stored in `b`.

**3.** Option **b**. Arguments are passed by value: the function receives a copy. (To change the original you must pass its address — module 03.)

**4.** The expression `x * 2;` computes the value but doesn't return it: the `return` is missing. The function is `int`, so its return value is **indeterminate**, and using it is undefined behavior. The compiler warns (`control reaches end of non-void function`). Fix:

```c
int dobro(int x) {
    return x * 2;
}
```

**5.** Output: `20 10`

Inside `f`, the local `x` (20) **hides** the global `x`. In `main` there is no local `x`, so the global one (10) is used.
