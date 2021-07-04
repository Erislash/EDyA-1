#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int Apply(int(*f)(int), int n);
int Cuadrado(int n);
int MitadEntera(int n);


int main(void) {
    int a = 10;

    printf("Numero sin modificar: %d\n", a);
    printf("Numero aplicando potencia: %d\n", Apply(Cuadrado, a));
    printf("Mitad del numero: %d\n", Apply(MitadEntera, a));

    return 0;
}


int Apply(int(*f)(int), int n) {
    return( f(n) );
}

int Cuadrado(int n) {
    return n * n * n;
}

int MitadEntera(int n) {
    return n / 2;
}
