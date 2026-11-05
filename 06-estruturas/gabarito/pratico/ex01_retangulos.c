/* Ex 1 - Retangulos: area e perimetro */
/* Ex 1 - Rectangles: area and perimeter */
#include <stdio.h>

typedef struct {
    float largura, altura;
} Retangulo;

float area(Retangulo r) {
    return r.largura * r.altura;
}

float perimetro(Retangulo r) {
    return 2 * (r.largura + r.altura);
}

int main(void) {
    Retangulo a = {5.0f, 3.0f};
    Retangulo b = {4.0f, 4.5f};

    printf("A: %.1f x %.1f | area = %.2f | perimetro = %.2f\n",
           a.largura, a.altura, area(a), perimetro(a));
    printf("B: %.1f x %.1f | area = %.2f | perimetro = %.2f\n",
           b.largura, b.altura, area(b), perimetro(b));

    if (area(a) > area(b))
        printf("O retangulo A tem maior area.\n");
    else if (area(b) > area(a))
        printf("O retangulo B tem maior area.\n");
    else
        printf("As areas sao iguais.\n");
    return 0;
}
