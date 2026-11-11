🌐 [Português](teorico.md) · **English**

# Module 09 · Theory answer key

**1.** `fseek(f, offset, origin)`:
- `f`: the file;
- `offset`: how many **bytes** to move (may be negative);
- `origin`: where to count from — `SEEK_SET` (start), `SEEK_CUR` (current position) or `SEEK_END` (end).

```c
fseek(f, 4L * (long)sizeof(Registro), SEEK_SET);   /* fifth record (index 4) */
fseek(f, 0, SEEK_END);                             /* end of the file */
```

**2.** The `char *nome` field stores only a **memory address**. `fwrite` writes that number to the file, not the text. In the next run the address is no longer valid (and the text isn't in the file). Solution: use a fixed-size array inside the struct (`char nome[30]`), so the characters are part of the struct itself and get written with it.

**3.** `1000 / 40 = 25` records.

```c
fseek(f, 0, SEEK_END);
long total = ftell(f) / (long)sizeof(Registro);
```

**4.** `"wb"` **erases** the file's contents on open — we'd lose all the other records. `"rb+"` opens for reading and writing **preserving** the contents. After `fread`, the file position has already advanced to the **next** record; if we wrote without moving back, `fwrite` would overwrite the following record. That's why we `fseek` back to the start of the record before the `fwrite` (an `fseek` is also required when switching between reading and writing).

**5.** `rewind(f)` puts the file back at the **start** and clears the error/end-of-file indicators. It is equivalent to `fseek(f, 0, SEEK_SET)`.
