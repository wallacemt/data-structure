#include <stdio.h>

int main()
{
    int a = 10;// inicializa a variavel
    int b, c = 0; // inicializa as variaveis

    printf("&a = %p, a = %d\n", &a, a);// mostra o endereço da variavel e o valor dela
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    b = 20;// atribui um novo valor
    c = a + b;// atribui um novo valor

    printf("&a = %p, a = %d\n", &a, a);// mostra o endereço da variavel e o valor dela apos alteração
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);
    return 0;
}
