🌐 [Português](teorico.md) · **English**

# Module 02 · Theory exercises

**1.** Explain what the `&` and `*` operators do in C. Give an example of each.

**2.** What is the output?

```c
int a = 10;
int *p = &a;
*p = *p + 5;
printf("%d", a);
```

**3.** What is the output?

```c
int v[] = {10, 20, 30};
int *p = v;
p++;
printf("%d %d", *p, *(p + 1));
```

**4.** Why is the snippet below dangerous?

```c
int *p;
*p = 5;
```

**5.** What does `NULL` represent for a pointer? Why is it good practice to initialize pointers with `NULL` and test them before use?
