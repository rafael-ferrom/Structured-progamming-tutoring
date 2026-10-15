🌐 [Português](teorico.md) · **English**

# Module 04 · Theory exercises

**1.** What is the role of `'\0'` in a string? How many bytes does `char s[] = "ola";` occupy?

**2.** What is the difference between `char s[] = "abc";` and `char *p = "abc";` regarding whether the contents can be modified?

**3.** What is the output?

```c
char s[] = "Programacao";
char *p = s + 3;
printf("%s %c", p, *p);
```

**4.** Why should we prefer `fgets` over `gets` and `scanf("%s", ...)` for reading text? What does `fgets` do with the typed `'\n'`?

**5.** Given `const char *dias[] = {"Seg", "Ter", "Qua"};`, what are the values of `dias[1]`, `dias[1][0]` and `*(dias[2] + 1)`?
