// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

enum _bool {
   false,
   true
};
typedef enum _bool Bool;

typedef struct {
    int* direccion;
    int capacidad;
} ArregloEnteros;



ArregloEnteros* arreglo_enteros_crear(int capacidad) {
    ArregloEnteros* arr = malloc(sizeof(ArregloEnteros));
    assert(arr);
    arr->direccion = malloc(sizeof(int) * capacidad);
    assert(arr->direccion);
    arr->capacidad = capacidad;

    return arr;
}



ArregloEnteros* arreglo_enteros_destruir(ArregloEnteros* arreglo) {
    free(arreglo->direccion);
    free(arreglo);
    return NULL;
}



int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos) {
    if (pos >= arreglo->capacidad || pos < 0) return -1;
    else return arreglo->direccion[pos];
}

void test_leer(void) {
    ArregloEnteros* arr = arreglo_enteros_crear(10);
    arr->direccion[0] = 1;
    arr->direccion[1] = 20;
    arr->direccion[2] = 300;
    arr->direccion[3] = 4000;
    assert(arreglo_enteros_leer(arr, -1) == -1);
    assert(arreglo_enteros_leer(arr, 10) == -1);
    assert(arreglo_enteros_leer(arr, 111) == -1);
    assert(arreglo_enteros_leer(arr, 0) == 1);
    assert(arreglo_enteros_leer(arr, 1) == 20);
    assert(arreglo_enteros_leer(arr, 2) == 300);
    assert(arreglo_enteros_leer(arr, 3) == 4000);

    arr = arreglo_enteros_destruir(arr);

    printf("test_leer passed!\n");
}



Bool arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato) {
    if (pos < 0 || pos >= arreglo->capacidad) {
        printf("Intento de copiar fuera de rango\n");
        return false;
    }
    arreglo->direccion[pos] = dato;
    return true;
}

void test_escribir(void) {
    ArregloEnteros* arr = arreglo_enteros_crear(10);

    assert(arreglo_enteros_escribir(arr, 10, 99) == false);

    assert(arreglo_enteros_escribir(arr, 1, 87) == true);
    assert(arr->direccion[1] == 87);

    assert(arreglo_enteros_escribir(arr, 0, 908) == true);
    assert(arr->direccion[0] == 908);

    assert(arreglo_enteros_escribir(arr, -1, 21) == false);

    arr = arreglo_enteros_destruir(arr);

    printf("test_escribir passed!\n");
}


int arreglo_enteros_capacidad(ArregloEnteros* arreglo) {
    return arreglo->capacidad;
}

void test_capacidad(void) {
    ArregloEnteros* arr1 = arreglo_enteros_crear(10);
    assert(arreglo_enteros_capacidad(arr1) == 10);

    ArregloEnteros* arr2 = arreglo_enteros_crear(1);
    assert(arreglo_enteros_capacidad(arr2) == 1);

    ArregloEnteros* arr3 = arreglo_enteros_crear(20);
    assert(arreglo_enteros_capacidad(arr3) == 20);

    ArregloEnteros* arr4 = arreglo_enteros_crear(65);
    assert(arreglo_enteros_capacidad(arr4) == 65);



    arr1 = arreglo_enteros_destruir(arr1);
    arr2 = arreglo_enteros_destruir(arr2);
    arr3 = arreglo_enteros_destruir(arr3);
    arr4 = arreglo_enteros_destruir(arr4);

    printf("test_capacidad passed!\n");
}



void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for (int i = 0; i < arreglo->capacidad; i++){
        printf("Arreglo[%d] -> %d\n", i, arreglo->direccion[i]);
    }
    
}



Bool arreglo_enteros_ajustar(ArregloEnteros* arr, int capacidad) {
    if (capacidad < 0 || capacidad == arr->capacidad) return false;

    int* newArr = malloc(sizeof(int) * capacidad);
    assert(newArr);
    
    for (int i = 0; i < arr->capacidad && i < capacidad; i++){
        newArr[i] = arr->direccion[i];
    }

    free(arr->direccion);
    arr->direccion = newArr;
    arr->capacidad = capacidad;
    return true;
}

void test_ajustar(void) {
    ArregloEnteros* arr = arreglo_enteros_crear(10);
    assert(arreglo_enteros_capacidad(arr) == 10);

    arreglo_enteros_ajustar(arr, 20);
    assert(arreglo_enteros_capacidad(arr) == 20);

    arreglo_enteros_ajustar(arr, -10);
    assert(arreglo_enteros_capacidad(arr) == 20);

    arr->direccion[0] = 1;
    assert(arr->direccion[0] == 1);
    arr->direccion[1] = 2;
    assert(arr->direccion[1] == 2);
    arr->direccion[2] = 3;
    assert(arr->direccion[2] == 3);
    arr->direccion[3] = 4;
    assert(arr->direccion[3] == 4);
    arr->direccion[4] = 5;

    // arreglo_enteros_imprimir(arr);
    // printf("=======================================\n");
    // printf("=======================================\n");

    arreglo_enteros_ajustar(arr, 10);
    assert(arreglo_enteros_capacidad(arr) == 10);
    assert(arr->direccion[0] == 1);
    assert(arr->direccion[1] == 2);
    assert(arr->direccion[2] == 3);
    assert(arr->direccion[3] == 4);
    assert(arr->direccion[4] == 5);

    // arreglo_enteros_imprimir(arr);


    arreglo_enteros_ajustar(arr, 2);
    assert(arreglo_enteros_capacidad(arr) == 2);
    assert(arr->direccion[0] == 1);
    assert(arr->direccion[1] == 2);
    // printf("=======================================\n");
    // printf("=======================================\n");
    
    // arreglo_enteros_imprimir(arr);


    arr = arreglo_enteros_destruir(arr);
    printf("test_ajustar passed!\n");
}







void test(void){
    test_leer();
    test_escribir();
    test_capacidad();
    test_ajustar();

    printf("All tests were passed!!\n");
}


int main(void) {
    test();

    return 0;
}
