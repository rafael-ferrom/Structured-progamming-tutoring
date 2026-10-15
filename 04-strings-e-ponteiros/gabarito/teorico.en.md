🌐 [Português](teorico.md) · **English**

# Module 04 · Theory answer key

**1.** The `'\0'` (null character, value 0) marks the **end** of the string; `<string.h>` functions walk until they find it. `char s[] = "ola";` occupies **4 bytes** (`'o'`, `'l'`, `'a'`, `'\0'`).

**2.**
- `char s[] = "abc";` creates an array on the stack with a **copy** of the text → it can be modified (`s[0] = 'X'`).
- `char *p = "abc";` points to a **literal** stored in read-only memory → modifying it is undefined behavior (usually a *segmentation fault*). The right way is to declare `const char *p`.

**3.** Output: `gramacao g`

`"Programacao"` = P(0) r(1) o(2) g(3) r(4) a(5) m(6) a(7) c(8) a(9) o(10). `p = s + 3` points to the `'g'`, so `%s` prints from `g` to the end ("gramacao") and `*p` is `'g'`.

**4.**
- `gets` doesn't limit the size → *buffer overflow*; it was removed in C11.
- `scanf("%s")` also doesn't limit it (unless you use `%29s`, for example) and stops at the first space.
- `fgets(s, tam, stdin)` respects the size and reads the whole line, but **keeps the `'\n'`** at the end of the string. To remove it: `s[strcspn(s, "\n")] = '\0';`

**5.**
- `dias[1]` → `"Ter"` (a `const char *`)
- `dias[1][0]` → `'T'`
- `*(dias[2] + 1)` → `'u'` (second character of `"Qua"`)
