# include <stdio.h>


int main() {
    int* punt;                  // Inicializa el puntero "punt"
    int x = 7, y = 5;           // Se declaran e inicializan 2 variables "x" e "y"
    
    punt = &x;                  // Se le asigna la posición de memoria de la variable "x" a "punt"
    x = 4;                      // Se le asigna el valor 4 a x
    punt = &y;                  // Se le asigna la posición de memoria de la variable "y" a "punt"
    
    // Se desreferencia "punt", con lo que se consigue el valor que se guardaba en la posición de memoria a la que apuntaba
    printf ("%d %d", *punt, x); // --> 5 4

    return 0;
}