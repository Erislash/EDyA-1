#include "slist.h"
#include "tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// static void imprimir_entero(int dato) {
//   printf("%d ", dato);
// }


void slist_longitud_test(void) {
    printf("Running slist_longitud tests...\n");
    SList lista = slist_crear();
    assert(slist_longitud(lista) == 0);

    lista = slist_agregar_inicio(lista, 3);
    assert(slist_longitud(lista) == 1);

    lista = slist_agregar_inicio(lista, 2);
    assert(slist_longitud(lista) == 2);

    lista = slist_agregar_inicio(lista, 1);
    assert(slist_longitud(lista) == 3);

    slist_destruir(lista);
    printf("slist_longitud_test finished\n\n");
}


void slist_values_test(SList list, int values[], int valuesLen) {
    SList node = list;
    for (int i = 0; i < valuesLen; ++i) {
        assert(node->dato == values[i]);
        node = node->sig;
    }
}

void slist_concatenar_test(void) {
    printf("Running slist_concatenar tests...\n");
    SList list1 = slist_crear();
    slist_values_test(list1, (int[]){}, 0);

    list1 = slist_agregar_final(list1, 1);
    list1 = slist_agregar_final(list1, 2);
    list1 = slist_agregar_final(list1, 3);

    SList list2 = slist_crear();
    list2 = slist_agregar_final(list2, 10);

    SList list3 = slist_crear();
    list3 = slist_agregar_final(list3, 90);
    list3 = slist_agregar_final(list3, 5);


    slist_values_test(list1, (int[]){1,2,3}, 3);

    list1 = slist_concatenar(list1, list2);
    slist_values_test(list1, (int[]){1, 2, 3, 10}, 4);

    list1 = slist_concatenar(list1, list3);
    slist_values_test(list1, (int[]){1, 2, 3, 10, 90, 5}, 6);

    slist_destruir(list1);
    slist_destruir(list2);
    slist_destruir(list3);
    printf("slist_concatenar_test finished\n\n");
}

void slist_insertar_test(void) {
    printf("Running slist_insertar tests...\n");
    SList list = slist_crear();
    list = slist_insertar(list, 30, 10);
    slist_values_test(list, (int[]){30}, 1);

    list = slist_insertar(list, 1, 10000);
    slist_values_test(list, (int[]){30, 1}, 2);

    list = slist_insertar(list, 19, 0);
    slist_values_test(list, (int[]){19, 30, 1}, 3);

    list = slist_insertar(list, 909, -10);
    slist_values_test(list, (int[]){909, 19, 30, 1}, 4);

    list = slist_insertar(list, 4, 2);
    slist_values_test(list, (int[]){909, 19, 4, 30, 1}, 5);

    slist_destruir(list);
    printf("slist_insertar_test finished\n\n");
}

void runTests(void) {
    printf("======================\n");
    slist_longitud_test();
    slist_concatenar_test();
    slist_insertar_test();

    printf("...All tests finished\n");
    printf("======================\n");
}
