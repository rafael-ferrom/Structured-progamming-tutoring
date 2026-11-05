🌐 [Português](teorico.md) · **English**

# Module 06 · Theory answer key

**1.**

```c
typedef struct {
    char  titulo[61];    /* 60 characters + '\0' */
    int   ano;
    float preco;
} Livro;
```

Advantage of `typedef`: it creates a short name for the type. Without it you would have to write `struct Livro l;`; with it, `Livro l;` is enough.

**2.** Output: `1 99`

`p2 = p1` **copies** the fields. Changing `p2.x` doesn't affect `p1`.

**3.** Array: a collection of elements of the **same type**, accessed by index (e.g. 30 `float` grades). Struct: a collection of fields of **different types**, accessed by name (e.g. a student with name, RA and grade).

**4.** `strcpy(c.end.cidade, "Salto");`

Strings can't be assigned with `=` (it's an array); you use `strcpy`. Nested fields are accessed by chaining the `.` operator.

**5.** It **does not change.** The function receives a **copy** of the whole struct (pass by value). To change the original you need to receive a pointer (`Produto *p`) — module 07 — or return the modified struct.
