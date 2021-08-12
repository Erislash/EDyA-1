#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arregloEnteros.h"



ArregloEnteros* crearArreglo(int capacidad) {
    ArregloEnteros* arr = (ArregloEnteros*)malloc(sizeof(ArregloEnteros));
    assert(arr != NULL);
    arr->direccion = malloc(sizeof(int) * capacidad);
    assert(arr->direccion != NULL);
    arr->capacidad = capacidad;

    return arr;
}



ArregloEnteros* destruirArreglo(ArregloEnteros* arr) {
    free(arr->direccion);
    free(arr);
    return NULL;
}



int leerArreglo(ArregloEnteros* arr, int indice) {
    if (indice >= arr->capacidad || indice < 0) {
        printf("Indice fuera de rango");
        assert(0);
    }else {
        return arr->direccion[indice];
    }
}



Bool escribirArreglo(ArregloEnteros* arr, int indice, int dato) {
if (indice >= arr->capacidad || indice < 0) {
        printf("Indice fuera de rango");
        return false;
    }else {
        arr->direccion[indice] = dato;
        return true;
    }
}



int capacidadArreglo(ArregloEnteros* arr) {
    return arr->capacidad;
}



void imprimirArreglo(ArregloEnteros* arr) {
    printf("==========\n");
    printf("Arreglo de capacidad %d:\n\n", arr->capacidad);
    for (int i = 0; i < arr->capacidad; ++i) {
        printf("Arreglo[%d] = %d\n", i, arr->direccion[i]);
    }
    printf("==========\n");
}



Bool ajustarArreglo(ArregloEnteros* arr, int nuevaCapacidad) {
    int* arrTemporal = realloc(arr->direccion, sizeof(int) * (nuevaCapacidad));

    if (arrTemporal == NULL) {
        printf("No se puede redimensionar el arreglo.\n");
        return false;
    }

	arr->direccion = arrTemporal;
    arr->capacidad = nuevaCapacidad;
    return true;
}



Bool insertarArreglo(ArregloEnteros* arr, int indice, int dato) {
    if (!ajustarArreglo(arr, arr->capacidad + 1)){
        printf("No se ha podido insertar un nuevo elemento");
        return false;
    }

    int prevVal = arr->direccion[indice];
    arr->direccion[indice] = dato;

    for (int i = indice + 1; i < arr->capacidad; ++i) {
        int temp = arr->direccion[i];
        arr->direccion[i] = prevVal;
        prevVal = temp;
    }

    return true;
}



Bool eliminarElementoArreglo(ArregloEnteros* arr, int indice) {
    if (indice >= arr->capacidad - 1){
        return ajustarArreglo(arr, capacidadArreglo(arr) - 1);
    }

    for (int i = indice + 1; i < arr->capacidad; ++i) {
        arr->direccion[i - 1] = arr->direccion[i];
    }
    return ajustarArreglo(arr, capacidadArreglo(arr) - 1);
}
