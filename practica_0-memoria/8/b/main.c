#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void ApplyIn(int (*f)(int), int* n);
int Cuadrado(int n);
int MitadEntera(int n);


int main(void) {
    int a = 10;

    printf("Numero sin modificar: %d\n", a);
    ApplyIn(Cuadrado, &a);
    printf("Numero después de aplicar potencia: %d\n", a);
    ApplyIn(MitadEntera, &a);
    printf("Mitad del numero: %d\n", a);

    return 0;
}


void ApplyIn(int (*f)(int), int* n) {
    *n = ( f(*n) );
}

int Cuadrado(int n) {
    return n * n * n;
}

int MitadEntera(int n) {
    return n / 2;
}
