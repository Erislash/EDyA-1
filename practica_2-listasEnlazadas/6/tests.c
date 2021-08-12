#include "slist.h"
#include "tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


// static void imprimir_entero(int dato) {
//   printf("%d ", dato);
// }

typedef struct __contact {
    char* firstName;
    char* lastName;
    unsigned int age;
} Contact;


void valuesTest(GList list, void* values[], int valuesLen, CompareFunction compare){
    GNodo* node = list;
    for (int i = 0; i < valuesLen; ++i) {
        assert(compare(node->dato, values[i]));
        node = node->sig;
    }
}


void* copyInt(void* data){
    int* output = malloc(sizeof(int));
    *output = *((int*)data);
    return output;
}

void printInt(void* data){
    printf("%d\n", *((int*)data));
}

void cleanInt(void* data){
    free((int*)data);
}

Bool compareInt(void* val1, void* val2){
    return *((int*)val1) == *((int*)val2);
}



void* copyString(void* data){
    int len = strlen(((char*)data)) + 1;
    char* output = malloc(sizeof(char) * len);
    strcpy(output, ((char*)data));
    
    return output;
}

void printString(void* data){
    printf("%s\n", ((char*)data));
}

void cleanString(void* data){
    free((char*)data);
}

Bool compareStr(void* val1, void* val2){
    // printf("Comparing val1: %s and val2: %s\n", (char*)val1, (char*)val2);
    return strcmp((char*)val1, (char*)val2) == 0;
}



void* copyStruct(void* data){
    Contact contact = *((Contact*)data);
    Contact* newContact = malloc(sizeof(Contact));
    
    newContact->age = contact.age;
    
    newContact->firstName = malloc(strlen(contact.firstName) + 1);
    strcpy(newContact->firstName, contact.firstName);

    newContact->lastName = malloc(strlen(contact.lastName) + 1);
    strcpy(newContact->lastName, contact.lastName);
    return newContact;
}

void printStruct(void* data){
   Contact contact = *((Contact*)data);
   printf("======================\n");
   printf("Name: %s\n", contact.firstName);
   printf("Surname: %s\n", contact.lastName);
   printf("Age: %d\n", contact.age);
   printf("======================\n");
}

void cleanContact(void* data){
    free(((Contact*)data)->firstName);
    free(((Contact*)data)->lastName);
    free((Contact*)data);
}

Bool compareContact(void* val1, void* val2){
    // printf("Comparing val1: %s and val2: %s\n", ((Contact*)val1)->firstName, ((Contact*)val2)->firstName);
    return strcmp(((Contact*)val1)->firstName, ((Contact*)val2)->firstName) == 0;
}



void glistTestInt(void) {
    printf("Running glistTest tests...\n");
    GList listInt = glist_crear();
    assert(glist_vacia(listInt) == 1);
    int n = 1;
    int m = 2;
    int k = 3;
    int r = 0;

    listInt = glist_agregar_final(listInt, &n, copyInt);
    listInt = glist_agregar_final(listInt, &m, copyInt);
    listInt = glist_agregar_final(listInt, &k, copyInt);
    listInt = glist_agregar_inicio(listInt, &r, copyInt);

    // glist_recorrer(listInt, printInt);
    valuesTest(listInt, (void*[]){&r, &n, &m, &k}, 4, compareInt);

    listInt = glist_destruir(listInt, cleanInt);
    printf("...glistTestInt finished\n\n");
}


void glistTestStr(void) {
    printf("Running glistTestStr tests...\n");
    GList listStr = glist_crear();
    assert(glist_vacia(listStr) == 1);
    char* c1 = "Mundo";
    char* c2 = "Hello";
    char* c3 = "World";
    char* c0 = "Hola";

    listStr = glist_agregar_final(listStr, c1, copyString);
    listStr = glist_agregar_final(listStr, c2, copyString);
    listStr = glist_agregar_final(listStr, c3, copyString);
    listStr = glist_agregar_inicio(listStr, c0, copyString);

    // glist_recorrer(listStr, printString);
    valuesTest(listStr, (void*[]){"Hola", "Mundo", "Hello", "World"}, 4, compareStr);

    listStr = glist_destruir(listStr, cleanString);

    printf("...glistTestStr finished\n\n");
}


void glistTestStruct(void) {
    printf("Running glistTestStruct tests...\n");

    GList listStruct = glist_crear();
    assert(glist_vacia(listStruct) == 1);

    Contact contact1; contact1.firstName = "Marcos"; contact1.lastName = "Regalia"; contact1.age = 20;
    Contact contact2; contact2.firstName = "Nicolas"; contact2.lastName = "Latiffi"; contact2.age = 25;
    Contact contact3; contact3.firstName = "Marco"; contact3.lastName = "Miller"; contact3.age = 23;


    listStruct = glist_agregar_final(listStruct, &contact1, copyStruct);
    listStruct = glist_agregar_inicio(listStruct, &contact2, copyStruct);
    listStruct = glist_agregar_final(listStruct, &contact3, copyStruct);


    // glist_recorrer(listStruct, printStruct);
    valuesTest(listStruct, (void*[]){&contact2, &contact1, &contact3}, 3, compareContact);

    listStruct = glist_destruir(listStruct, cleanContact);

    printf("...glistTestStruct finished\n\n");
}


// void slist_longitud_test(void) {
//     printf("Running slist_longitud tests...\n");
//     SList lista = slist_crear();
//     assert(slist_longitud(lista) == 0);

//     lista = slist_agregar_inicio(lista, 3);
//     assert(slist_longitud(lista) == 1);

//     lista = slist_agregar_inicio(lista, 2);
//     assert(slist_longitud(lista) == 2);

//     lista = slist_agregar_inicio(lista, 1);
//     assert(slist_longitud(lista) == 3);

//     slist_destruir(lista);
//     printf("slist_longitud_test finished\n\n");
// }



// void slist_concatenar_test(void) {
//     printf("Running slist_concatenar tests...\n");
//     SList list1 = slist_crear();
//     slist_values_test(list1, (int[]){}, 0);

//     list1 = slist_agregar_final(list1, 1);
//     list1 = slist_agregar_final(list1, 2);
//     list1 = slist_agregar_final(list1, 3);

//     SList list2 = slist_crear();
//     list2 = slist_agregar_final(list2, 10);

//     SList list3 = slist_crear();
//     list3 = slist_agregar_final(list3, 90);
//     list3 = slist_agregar_final(list3, 5);


//     slist_values_test(list1, (int[]){1,2,3}, 3);

//     list1 = slist_concatenar(list1, list2);
//     slist_values_test(list1, (int[]){1, 2, 3, 10}, 4);

//     list1 = slist_concatenar(list1, list3);
//     slist_values_test(list1, (int[]){1, 2, 3, 10, 90, 5}, 6);

//     slist_destruir(list1);
//     slist_destruir(list2);
//     slist_destruir(list3);
//     printf("slist_concatenar_test finished\n\n");
// }

// void slist_insertar_test(void) {
//     printf("Running slist_insertar tests...\n");
//     SList list = slist_crear();
//     list = slist_insertar(list, 30, 10);
//     slist_values_test(list, (int[]){30}, 1);

//     list = slist_insertar(list, 1, 10000);
//     slist_values_test(list, (int[]){30, 1}, 2);

//     list = slist_insertar(list, 19, 0);
//     slist_values_test(list, (int[]){19, 30, 1}, 3);

//     list = slist_insertar(list, 909, -10);
//     slist_values_test(list, (int[]){909, 19, 30, 1}, 4);

//     list = slist_insertar(list, 4, 2);
//     slist_values_test(list, (int[]){909, 19, 4, 30, 1}, 5);

//     slist_destruir(list);
//     printf("slist_insertar_test finished\n\n");
// }

void runTests(void) {
    printf("======================\n");
    // slist_longitud_test();
    // slist_concatenar_test();
    // slist_insertar_test();

    glistTestInt();
    glistTestStr();
    glistTestStruct();
    printf("...All tests finished\n");
    printf("======================\n");
}
