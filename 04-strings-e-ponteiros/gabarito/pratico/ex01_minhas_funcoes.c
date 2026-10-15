/* Ex 1 - strlen, strcpy e strcmp implementadas com ponteiros */
/* Ex 1 - strlen, strcpy and strcmp implemented with pointers */
#include <stdio.h>
#include <string.h>

int meu_strlen(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}

void meu_strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++) != '\0')
        ;                               /* copia inclusive o '\0' | copies the '\0' too */
}

int meu_strcmp(const char *a, const char *b) {
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

static int sinal(int x) { return (x > 0) - (x < 0); }

int main(void) {
    const char *pares[][2] = {
        {"casa", "casa"}, {"casa", "caso"}, {"zebra", "abelha"}, {"", "a"}
    };

    for (int i = 0; i < 4; i++) {
        const char *a = pares[i][0];
        const char *b = pares[i][1];
        printf("\"%s\" x \"%s\": meu_strcmp=%d strcmp=%d | meu_strlen(a)=%d strlen(a)=%lu\n",
               a, b, sinal(meu_strcmp(a, b)), sinal(strcmp(a, b)),
               meu_strlen(a), (unsigned long)strlen(a));
    }

    char copia[30];
    meu_strcpy(copia, "Programacao");
    printf("copia = \"%s\"\n", copia);
    return 0;
}
