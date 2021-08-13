#include "matriz.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



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

    matriz->elementos = malloc(sizeof(double*) * filas);
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



void intercambiarFilas(Matriz* matriz, int fila1, int fila2) {
    assert(fila1 >= 0 && fila2 >= 0 && fila1 < matriz->filas && fila2 <= matriz->filas);
    int columnas = matriz->columnas;
    for (int i = 0; i < columnas; ++i) {
        int temp = leerMatriz(matriz, fila1, i);
        escribirMatriz(matriz, fila1, i, leerMatriz(matriz, fila2, i));
        escribirMatriz(matriz, fila2, i, temp);
    }
}



void insertarFila(Matriz* matriz, int posicion) {
    assert(posicion >= 0 && posicion <= matriz->filas);
    int filas = (matriz->filas) + 1;
    int columnas = matriz->columnas;
    double** nuevaMatriz = malloc(sizeof(double*) * filas);
    assert(nuevaMatriz != NULL);


    for (int i = 0; i < filas; i++) {
        nuevaMatriz[i] = malloc(sizeof(double) * columnas);
        assert(nuevaMatriz[i] != NULL);
    }
    
    int iteradorOriginal = 0;
    int iteradorNuevo = 0;

    for (; iteradorNuevo < filas; ++iteradorNuevo) {
        for (int j = 0; j < columnas; ++j) {
            if (iteradorNuevo == posicion) {
                nuevaMatriz[iteradorNuevo][j] = 0.0;
            }else {
                nuevaMatriz[iteradorNuevo][j] = matriz->elementos[iteradorOriginal][j];
            }
        }
        if (iteradorNuevo != posicion){
            ++iteradorOriginal;
        }
    }

    for (int i = 0; i < filas - 1; i++) {
        free(matriz->elementos[i]);
    }

    free(matriz->elementos);
    matriz->filas += 1;
    matriz->elementos = nuevaMatriz;
}
