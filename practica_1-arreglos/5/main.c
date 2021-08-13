// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "matriz.h"

void testCrearMatriz(void) {
    printf("Test: testCrearMatriz iniciado...\n");
    Matriz* matriz = crearMatriz(4, 4);
    // imprimirMatriz(matriz);
    matriz = destruirMatriz(matriz);
    printf("\n...Test: testCrearMatriz Finalizado\n");
}

void testEscribirLeerMatriz(void) {
    printf("Test: testEscribirLeerMatriz iniciado...\n");
    Matriz* matriz = crearMatriz(4, 4);
    imprimirMatriz(matriz);
    escribirMatriz(matriz, 2, 3, 92);
    escribirMatriz(matriz, 0, 0, 422);
    escribirMatriz(matriz, 1, 3, 12.23);

    assert(leerMatriz(matriz, 2, 3) == 92.00);
    assert(leerMatriz(matriz, 0, 0) == 422.00);
    assert(leerMatriz(matriz, 1, 3) == 12.23);
    printf("\n\n==================================\n\n");
    imprimirMatriz(matriz);

    matriz = destruirMatriz(matriz);
    printf("\n...Test: testEscribirLeerMatriz Finalizado\n");
}

void correrTests() {
    printf("Iniciando tests...\n");
    testCrearMatriz();
    testEscribirLeerMatriz();
    printf("...Todos los tests finalizados\n");

}

int main (void) {
    correrTests();


    return 0;
}
