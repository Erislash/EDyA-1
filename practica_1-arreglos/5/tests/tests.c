#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../matriz.h"
#include "tests.h"



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
    // imprimirMatriz(matriz);
    escribirMatriz(matriz, 2, 3, 92);
    escribirMatriz(matriz, 0, 0, 422);
    escribirMatriz(matriz, 1, 3, 12.23);

    assert(leerMatriz(matriz, 2, 3) == 92.00);
    assert(leerMatriz(matriz, 0, 0) == 422.00);
    assert(leerMatriz(matriz, 1, 3) == 12.23);
    // printf("\n\n==================================\n\n");
    // imprimirMatriz(matriz);

    matriz = destruirMatriz(matriz);
    printf("\n...Test: testEscribirLeerMatriz Finalizado\n");
}



void testIntercambio(void) {
    printf("Test: testIntercambio iniciado...\n");
    Matriz* matriz = crearMatriz(3, 4);
    escribirMatriz(matriz, 0, 0, 0);
    escribirMatriz(matriz, 0, 1, 1);
    escribirMatriz(matriz, 0, 2, 2);
    escribirMatriz(matriz, 0, 3, 3);
    escribirMatriz(matriz, 1, 0, 4);
    escribirMatriz(matriz, 1, 1, 5);
    escribirMatriz(matriz, 1, 2, 6);
    escribirMatriz(matriz, 1, 3, 7);
    escribirMatriz(matriz, 2, 0, 8);
    escribirMatriz(matriz, 2, 1, 9);
    escribirMatriz(matriz, 2, 2, 10);
    escribirMatriz(matriz, 2, 3, 11);
    // // imprimirMatriz(matriz);

    // printf("\n\n==================================\n\n");
    
    // intercambiarFilas(matriz, 0, 2);
    
    // // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");

    // intercambiarFilas(matriz, 0, 1);

    // // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");

    matriz = destruirMatriz(matriz);
    printf("\n...Test: testIntercambio Finalizado\n");
}



void testAgregar(void) {
    printf("Test: testAgregar iniciado...\n");
    Matriz* matriz = crearMatriz(4, 3);
    
    escribirMatriz(matriz, 0, 0, 0);
    escribirMatriz(matriz, 0, 1, 1);
    escribirMatriz(matriz, 0, 2, 2);

    escribirMatriz(matriz, 1, 0, 3);
    escribirMatriz(matriz, 1, 1, 4);
    escribirMatriz(matriz, 1, 2, 5);

    escribirMatriz(matriz, 2, 0, 6);
    escribirMatriz(matriz, 2, 1, 7);
    escribirMatriz(matriz, 2, 2, 8);

    escribirMatriz(matriz, 3, 0, 9);
    escribirMatriz(matriz, 3, 1, 10);
    escribirMatriz(matriz, 3, 2, 11);
    
    // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");
    

    insertarFila(matriz, 1);
    // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");
    
    insertarFila(matriz, 0);
    // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");
    
    insertarFila(matriz, 6);
    // imprimirMatriz(matriz);
    // printf("\n\n==================================\n\n");

    matriz = destruirMatriz(matriz);
    printf("\n...Test: testAgregar Finalizado\n");
}



void correrTests(void) {
    printf("Iniciando tests...\n");
    testCrearMatriz();
    testEscribirLeerMatriz();
    testIntercambio();
    testAgregar();
    printf("...Todos los tests finalizados\n");

}
