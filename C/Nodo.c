#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;


Nodo* crearNodo(void* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}


void* getDato(Nodo* nodo) {
    return nodo->dato;
}


void setDato(Nodo* nodo, void* dato) {
    nodo->dato = dato;
}


Nodo* getSiguiente(Nodo* nodo) {
    return nodo->siguiente;
}


void setSiguiente(Nodo* nodo, Nodo* siguiente) {
    nodo->siguiente = siguiente;
}


void liberarNodo(Nodo* nodo) {
    free(nodo);
}

