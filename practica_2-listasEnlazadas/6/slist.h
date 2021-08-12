#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef enum _bool{
  false, true
} Bool;

typedef Bool (*CompareFunction) (void *data1, void *data2);
typedef void (*FuncionVisitante) (void *dato);
typedef void (*CleanFunction) (void *dato);
typedef void* (*CopyFunction) (void *data);
typedef void* (*CopyFunction) (void *data);

typedef struct _GNodo {
  void *dato;
  struct _GNodo *sig;
} GNodo;

typedef GNodo *GList;

/**
 * Devuelve una lista vacía.
 */
GList glist_crear();

/**
 * Destruccion de la lista.
 */
GList glist_destruir(GList list, CleanFunction cleanData);

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList list);

/**
 * Agrega un elemento al final de la lista.
 */
GList glist_agregar_final(GList list, void* data, CopyFunction copyData);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList list, void* data, CopyFunction copyData);

// /**
//  * Recorrido de la lista, utilizando la funcion pasada.
//  */
void glist_recorrer(GList list, FuncionVisitante visit);

// /**
//  * Devuelve la longitud de una lista.
//  */
// int slist_longitud(SList list);

// /**
//  * Devuelve la concatenaci´on de dos listas, modificando la primera
//  */
// SList slist_concatenar(SList list1, SList list2);

// /**
//  * Inserta un dato en una lista en una posición arbitraria
//  */
// SList slist_insertar(SList list, int data, int pos);

#endif /* __SLIST_H__ */
