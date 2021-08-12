#include <stdio.h>
#include "typedefs.h"
#ifndef __ARREGLO_ENTEROS__
#define __ARREGLO_ENTEROS__


/*! \struct ArregloEnteros
 * Un array dinamico de enteros
 */
typedef struct {
    /*! Dirección de memoria donde se guarda el array */
    int* direccion;
    /*! Capacidad actual del array dinámico */
    int capacidad;
} ArregloEnteros;


/**
 * Crea un nuevo arreglo de enteros
 * @param capacidad Capacidad inicial del arreglo
 * @returns Un nuevo arreglo de enteros
 */
ArregloEnteros* crearArreglo(int capacidad);


/**
 *  Libera toda la memoria ocupada por un array de enteros. 
 *  @param arr El array de enteros a limpiar.
 *  @returns Un puntero nulo
*/
ArregloEnteros* destruirArreglo(ArregloEnteros* arr);


/**
 *  Lee una posición del array 
 *  @param arr El array de donde se leerá el índice
 *  @param indice El índice donde se leerá
 *  @returns {number} El contenido del índice indicado
*/
int leerArreglo(ArregloEnteros* arr, int indice);


/**
 *  Escribe en una posición del array
 *  @param arr El array de donde se leerá el índice
 *  @param indice El índice donde se escribirá
 *  @param dato El número a escribir
 *  @returns true si se pudo copiar el dato || false en caso contrario
*/
Bool escribirArreglo(ArregloEnteros* arr, int indice, int dato);



/**
 *  Devuelve la capacidad actual del array
 *  @param arr El array del que se solicita su capacidad
 *  @returns La capacidad del array
*/
int capacidadArreglo(ArregloEnteros* arr);



/**
 *  Imprime los elementos del array.
 *  @param arr El array que se imprimirá.
*/
void imprimirArreglo(ArregloEnteros* arr);



/**
 *  Ajusta el array de enteros pasado como primer parámetro.
 *  @param arr El array que se redimensionará.
 *  @param nuevaCapacidad La nueva capacidad del array de enteros.
 *  @returns Devuelve false en caso de no haber podido redimensionar el array y true en caso de éxito.
*/
Bool ajustarArreglo(ArregloEnteros* arr, int nuevaCapacidad);



/**
 *  Inserta un nuevo elemento en el array
 *  @param arr El array al que se le insertará el nuevo dato.
 *  @param indice El índice donde se insertará un nuevo dato.
 *  @param dato El dato a insertar.
 *  @returns Devuelve false en caso de no haber podido insertar el dato y true en caso de éxito.
*/
Bool insertarArreglo(ArregloEnteros* arr, int indice, int dato);



/**
 *  Elimina un elemento del array
 *  @param arr El array del que se eliminará el dato
 *  @param indice El índice del elemento que se quiere eliminar.
 *  @returns Devuelve false en caso de no haber podido eliminar el dato y true en caso de éxito.
*/
Bool eliminarElementoArreglo(ArregloEnteros* arr, int indice);


#endif // !__ARREGLO_ENTEROS__

