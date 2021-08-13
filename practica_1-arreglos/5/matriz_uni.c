#include "matriz.h"
#include <assert.h>
#include <stdio.h>



/**
 *  \struct Matriz_ matriz.h "matriz.h"
 *  \brief matriz unidimensional.
*/
struct Matriz_ {
    /*! Dirección de memoria de la matriz */
    double* elementos;
    /*! Cantidad de filas de la matriz */
    int filas;
    /*! Cantidad de columnas de la matriz */
    int columnas;
};



Matriz* crearMatriz(int filas, int columnas) {
    assert(filas > 0 && columnas > 0);
    Matriz* matriz = malloc(sizeof(Matriz));
    assert(matriz != NULL);

    matriz->elementos = malloc(sizeof(double) * (filas * columnas));
    assert(matriz->elementos != NULL);

    matriz->columnas = columnas;
    matriz->filas = filas;

    for (int i = 0; i < (filas * columnas); ++i) {
        matriz->elementos[i] = 0.0;
    }

    return matriz;
}



Matriz* destruirMatriz(Matriz* matriz){
    free(matriz->elementos);
    free(matriz);
    return NULL;
}



double leerMatriz(Matriz* matriz, int fila, int columna) {
    assert(fila >= 0 && fila < matriz->filas && columna >= 0 && columna < matriz->columnas);
    return matriz->elementos[fila * matriz->columnas + columna];
}



void escribirMatriz(Matriz* matriz, int fila, int columna, double dato) {
    assert(fila >= 0 && fila < matriz->filas && columna >= 0 && columna < matriz->columnas);
    matriz->elementos[fila * matriz->columnas + columna] = dato;
}



int numeroFilasMatriz(Matriz* matriz) { return matriz->filas; }
int numeroColumnasMatriz(Matriz* matriz) { return matriz->columnas; }



void imprimirMatriz(Matriz* matriz) {
    int filas = numeroFilasMatriz(matriz);
    int columnas = numeroColumnasMatriz(matriz);

    for (int i = 0; i < filas * columnas; ++i) {
        printf("%0.2lf ", matriz->elementos[i]);
        if ((i + 1) % columnas == 0){
            // printf("\nColumnas: %d\nI: %d\nModulo: %d", columnas, i, i % columnas);
            printf("\n\n");
        }
    }
}
