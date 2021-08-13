#include "matriz.h"
#include <assert.h>
#include <stdio.h>



/**
 *  \struct Matriz_ matriz.h "matriz.h"
 *  \brief matriz bidimensional.
*/
struct Matriz_ {
    /*! Dirección de memoria de la matriz */
    double** elementos;
    /*! Cantidad de filas de la matriz */
    int filas;
    /*! Cantidad de columnas de la matriz */
    int columnas;
};



Matriz* crearMatriz(int filas, int columnas) {
    assert(filas > 0 && columnas > 0);
    Matriz* matriz = malloc(sizeof(Matriz));
    assert(matriz != NULL);

    matriz->elementos = malloc(sizeof(double) * filas);
    assert(matriz->elementos != NULL);

    for (int i = 0; i < filas; i++) {
        matriz->elementos[i] = malloc(sizeof(double) * columnas);
        assert(matriz->elementos[i] != NULL);
    }
    

    matriz->columnas = columnas;
    matriz->filas = filas;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
           matriz->elementos[i][j] = 0.0;
        }
    }

    return matriz;
}



Matriz* destruirMatriz(Matriz* matriz){
    for (int i = 0; i < matriz->filas; i++) {
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
    free(matriz);
    return NULL;
}



double leerMatriz(Matriz* matriz, int fila, int columna) {
    assert(fila >= 0 && fila < matriz->filas && columna >= 0 && columna < matriz->columnas);
    return matriz->elementos[fila][columna];
}



void escribirMatriz(Matriz* matriz, int fila, int columna, double dato) {
    assert(fila >= 0 && fila < matriz->filas && columna >= 0 && columna < matriz->columnas);
    matriz->elementos[fila][columna] = dato;
}



int numeroFilasMatriz(Matriz* matriz) { return matriz->filas; }
int numeroColumnasMatriz(Matriz* matriz) { return matriz->columnas; }



void imprimirMatriz(Matriz* matriz) {
    int filas = numeroFilasMatriz(matriz);
    int columnas = numeroColumnasMatriz(matriz);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            printf("%0.2lf ", leerMatriz(matriz, i, j));
        }
        printf("\n\n");
    }
}
