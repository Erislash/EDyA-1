#include "arregloEnteros.h"
#include "tests.h"
#include <assert.h>


void testLeer(void) {
    printf("Comenzando testLeer...\n");
    ArregloEnteros* arreglo = crearArreglo(5);
    arreglo->direccion[0] = 10;
    arreglo->direccion[1] = 11;
    arreglo->direccion[2] = 12;
    arreglo->direccion[3] = 13;
    arreglo->direccion[4] = 14;

    assert(leerArreglo(arreglo, 0) == 10);
    assert(leerArreglo(arreglo, 1) == 11);
    assert(leerArreglo(arreglo, 2) == 12);
    assert(leerArreglo(arreglo, 3) == 13);
    assert(leerArreglo(arreglo, 4) == 14);
    // leerArreglo(arreglo, 45);
    // leerArreglo(arreglo, -1);

    destruirArreglo(arreglo);
    printf("...testLeer finalizado\n===\n");
}



void testEscribir(void) {
    printf("Comenzando testEscribir...\n");
    ArregloEnteros* arreglo = crearArreglo(5);
    arreglo->direccion[0] = 10;
    arreglo->direccion[1] = 11;
    arreglo->direccion[2] = 12;
    arreglo->direccion[3] = 13;
    arreglo->direccion[4] = 14;

    assert(leerArreglo(arreglo, 0) == 10);
    assert(leerArreglo(arreglo, 1) == 11);
    assert(leerArreglo(arreglo, 2) == 12);
    assert(leerArreglo(arreglo, 3) == 13);
    assert(leerArreglo(arreglo, 4) == 14);

    // imprimirArreglo(arreglo);

    escribirArreglo(arreglo, 0, 90); assert(leerArreglo(arreglo, 0) == 90);
    escribirArreglo(arreglo, 2, 4); assert(leerArreglo(arreglo, 2) == 4);
    escribirArreglo(arreglo, 3, 121); assert(leerArreglo(arreglo, 3) == 121);

    // imprimirArreglo(arreglo);


    destruirArreglo(arreglo);
    printf("...testEscribir finalizado\n===\n");
}



void testAjustar(void) {
    printf("Comenzando testAjustar...\n");
    ArregloEnteros* arreglo = crearArreglo(5);
    arreglo->direccion[0] = 10;
    arreglo->direccion[1] = 11;
    arreglo->direccion[2] = 12;
    arreglo->direccion[3] = 13;
    arreglo->direccion[4] = 14;
    assert(capacidadArreglo(arreglo) == 5);
    // imprimirArreglo(arreglo);

    ajustarArreglo(arreglo, 10);
    arreglo->direccion[5] = 15;
    arreglo->direccion[6] = 16;
    arreglo->direccion[7] = 17;
    arreglo->direccion[8] = 18;
    arreglo->direccion[9] = 19;
    assert(capacidadArreglo(arreglo) == 10);
    // imprimirArreglo(arreglo);

    ajustarArreglo(arreglo, 2); 
    assert(capacidadArreglo(arreglo) == 2);
    // imprimirArreglo(arreglo);


    destruirArreglo(arreglo);
    printf("...testAjustar finalizado\n===\n");
}



void testInsertar(void) {
    printf("Comenzando testInsertar...\n");
    ArregloEnteros* arreglo = crearArreglo(5);
    arreglo->direccion[0] = 10;
    arreglo->direccion[1] = 11;
    arreglo->direccion[2] = 12;
    arreglo->direccion[3] = 13;
    arreglo->direccion[4] = 14;

    // imprimirArreglo(arreglo);

    insertarArreglo(arreglo, 2, 55);
    assert(leerArreglo(arreglo, 2) == 55);

    insertarArreglo(arreglo, 0, 85);
    assert(leerArreglo(arreglo, 0) == 85);

    // imprimirArreglo(arreglo);

    destruirArreglo(arreglo);
    printf("...testInsertar finalizado\n===\n");
}



void testEliminar(void) {
    printf("Comenzando testEliminar...\n");
    ArregloEnteros* arreglo = crearArreglo(5);
    arreglo->direccion[0] = 10;
    arreglo->direccion[1] = 11;
    arreglo->direccion[2] = 12;
    arreglo->direccion[3] = 13;
    arreglo->direccion[4] = 14;

    eliminarElementoArreglo(arreglo, 1);
    assert(leerArreglo(arreglo, 1) == 12);
    eliminarElementoArreglo(arreglo, 2);
    assert(leerArreglo(arreglo, 2) == 14);

    // imprimirArreglo(arreglo);

    destruirArreglo(arreglo);
    printf("...testEliminar finalizado\n===\n");
}



void correrTests(void) {
    printf("Comenzando tests...\n");
    testLeer();
    testEscribir();
    testAjustar();
    testInsertar();
    testEliminar();

    printf("Todos los tests finalizados...\n");
}

