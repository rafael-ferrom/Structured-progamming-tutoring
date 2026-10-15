/* Ex 2 - Contar vogais e inverter a string no lugar */
/* Ex 2 - Count vowels and reverse the string in place */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int conta_vogais(const char *s) {
    int n = 0;
    for (; *s != '\0'; s++) {
        char c = (char)tolower((unsigned char)*s);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            n++;
    }
    return n;
}

void inverte(char *s) {
    char *ini = s;
    char *fim = s + strlen(s) - 1;
    while (ini < fim) {
        char t = *ini;
        *ini++ = *fim;
        *fim-- = t;
    }
}

int main(void) {
    char linha[100];
    printf("Digite uma frase: ");
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        printf("Nada lido.\n");
        return 1;
    }
    linha[strcspn(linha, "\n")] = '\0';      /* remove o '\n' | removes the '\n' */

    if (linha[0] == '\0') {
        printf("Frase vazia.\n");
        return 0;
    }

    printf("Vogais: %d\n", conta_vogais(linha));
    inverte(linha);
    printf("Invertida: %s\n", linha);
    return 0;
}
