# include <stdio.h>


int main() {
    int* punt, i;                           // Se inicializa un puntero "punt" y un entero "i" (recordar que
                                            // el simbolo "*" del puntero solo afecta a la primera
                                            // declaración cuando se hacen varias en una sola
                                            // línea)
    
    int x[] = {1, 2, 3, 4, 5};              // Se declara e inicializa un array de 5 enteros

    punt = x;                               // Se le asigna a "punt" la posición del
                                            // primer elemento del array
    
    *punt = 9;                              // Se desreferencia "punt" y se el valor al que apunta

    for (i = 0; i < 5; i++)
        printf("%d, ", x[i]);
    // --> 9, 2, 3, 4, 5,

    printf("\n");

    return 0;
}
