# include <stdio.h>

int main () {
    int* punt;          // Se crea un puntero
    int x = 7, y = 5;   // Se declaran e inicializan 2 variables "x" e "y"

    punt = &x;          // Se le asigna la posición de memoria de la variable "x" a "punt"
    *punt = 4;          // Se desreferencia "punt" y se modifica el valor al que apuntaba. Ahora x = 4
    
    printf("%d %d\n", x, y);  // --> 4 5


    return 0;
}