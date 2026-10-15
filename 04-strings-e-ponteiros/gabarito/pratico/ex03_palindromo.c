/* Ex 3 - Palindromo ignorando caixa e caracteres nao alfanumericos */
/* Ex 3 - Palindrome ignoring case and non-alphanumeric characters */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eh_palindromo(const char *s) {
    const char *ini = s;
    const char *fim = s + strlen(s);        /* aponta para o '\0' | points to the '\0' */

    while (ini < fim) {
        while (ini < fim && !isalnum((unsigned char)*ini))
            ini++;
        while (ini < fim && !isalnum((unsigned char)*(fim - 1)))
            fim--;
        if (ini >= fim)
            break;
        if (tolower((unsigned char)*ini) != tolower((unsigned char)*(fim - 1)))
            return 0;
        ini++;
        fim--;
    }
    return 1;
}

int main(void) {
    const char *testes[] = {
        "Socorram-me, subi no onibus em Marrocos",
        "Programacao",
        "A base do teto desaba",
        "Anotaram a data da maratona",
        "abc"
    };
    int n = (int)(sizeof(testes) / sizeof(testes[0]));

    for (int i = 0; i < n; i++)
        printf("\"%s\" -> %s\n", testes[i],
               eh_palindromo(testes[i]) ? "palindromo" : "nao e palindromo");
    return 0;
}
