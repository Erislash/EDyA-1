#include "slist.h"
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}




void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList list) {
  int count = 0;
  SList node = list;

  while (node != NULL) {
    ++count;
    node = node->sig;
  }
  
  return count;
}

SList slist_concatenar(SList list1, SList list2) {
  SList node = list2;
  while (node != NULL) {
    list1 = slist_agregar_final(list1, node->dato);
    node = node->sig;
  }
  return list1;
}

SList slist_insertar(SList list, int data, int pos) {
  if (pos <= 0) return slist_agregar_inicio(list, data);
  if (pos >= slist_longitud(list)) return slist_agregar_final(list, data);

  SNodo* nodo = list;
  SNodo* prev = list;
  int i = 0;
  while (i < pos) {
    prev = nodo;
    nodo = nodo->sig;
    ++i;
  }

  SNodo* nuevo = malloc(sizeof(SNodo));
  nuevo->dato = data;
  prev->sig = nuevo;
  nuevo->sig = nodo;
  return list;
}


