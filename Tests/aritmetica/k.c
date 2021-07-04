#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Tamaño de un float: %d\n", (int)sizeof(float));
    float i = 10.0;
    float* p = &i;
    printf("La dirección a la que apunta p es: %p\n", p);
    p += 2;
    printf("La dirección a la que apunta p ahora es: %p\n", p);


    return 0;
}
