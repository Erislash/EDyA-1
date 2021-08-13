#ifndef __MATRIZ_H__
#define __MATRIZ_H__
#include <stdlib.h>



typedef struct Matriz_ Matriz;



/**
 * Crea una matriz unidimensional con las filas y columnas dadas.
 * @param filas Número de filas de la matriz.
 * @param columnas Número de columnas de la matriz.
 * @returns Una matriz unidimensional.
*/
Matriz* crearMatriz(int filas, int columnas);



/**
 * Libera toda la memoria usada por una matriz dada.
 * @param matriz La matriz cuya memoria será liberada.
 * @returns Un puntero a NULL.
*/
Matriz* destruirMatriz(Matriz* matriz);



/**
 * Lee la posición especificada de una matriz dada.
 * @param matriz La matriz cuya posición quiere leerse.
 * @param fila La fila donde se encuentra el dato a leer.
 * @param columna La columna donde se encuentra el dato a leer.
 * @returns El dato que se encuentra en la posición especificada.
*/



double leerMatriz(Matriz* matriz, int fila, int columna);
/**
 * Escribe la posición especificada de una matriz dada con un dato dado.
 * @param matriz La matriz en la que se va a escribir.
 * @param fila La fila donde se esribirá
 * @param columna La columna donde se esribirá
 * @param dato El dato que se escribirá en la posición especificada.
*/



void escribirMatriz(Matriz* matriz, int fila, int columna, double dato);
/**
 * Imprime una matriz dada
 * @param matriz La matriz a imprimir.
*/



void imprimirMatriz(Matriz* matriz);



#endif /* __MATRIZ_H__ */
