#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

GList glist_crear() {
  return NULL;
}



GList glist_destruir(GList list, CleanFunction clearData) {
  GNodo* nodo = list;
  while (nodo != NULL){
    GNodo* sig = nodo->sig;
    clearData(nodo->dato);
    free(nodo);
    nodo = sig;
  }
  return NULL;
}



int glist_vacia(GList list) {
  return list == NULL;
}



GList glist_agregar_final(GList list, void* data, CopyFunction copyData) {
  GNodo* newNode = malloc(sizeof(GNodo));
  newNode->dato = copyData(data);
  newNode->sig = NULL;
  if (list == NULL) {
    list = newNode;
    newNode->sig = NULL;
  }else {
    GNodo* last = list;
    while (last->sig != NULL) { last = last->sig; }
    last->sig = newNode;
  }

  return list;
}



GList glist_agregar_inicio(GList list, void* data, CopyFunction copyData) {
  GNodo* newNode = malloc(sizeof(GNodo));
  newNode->dato = copyData(data);
  newNode->sig = list;
  return newNode;
}



void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNodo* node = list; node != NULL; node = node->sig)
    visit(node->dato);
}



// int slist_longitud(SList list) {
//   int count = 0;
//   SList node = list;

//   while (node != NULL) {
//     ++count;
//     node = node->sig;
//   }
  
//   return count;
// }

// SList slist_concatenar(SList list1, SList list2) {
//   SList node = list2;
//   while (node != NULL) {
//     list1 = slist_agregar_final(list1, node->dato);
//     node = node->sig;
//   }
//   return list1;
// }

// SList slist_insertar(SList list, int data, int pos) {
//   if (pos <= 0) return slist_agregar_inicio(list, data);
//   if (pos >= slist_longitud(list)) return slist_agregar_final(list, data);

//   SNodo* nodo = list;
//   SNodo* prev = list;
//   int i = 0;
//   while (i < pos) {
//     prev = nodo;
//     nodo = nodo->sig;
//     ++i;
//   }

//   SNodo* nuevo = malloc(sizeof(SNodo));
//   nuevo->dato = data;
//   prev->sig = nuevo;
//   nuevo->sig = nodo;
//   return list;
// }


