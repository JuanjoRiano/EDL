#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Mateo 20:16

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* tope;
    int tamaño;
} Pila;

Pila* crearPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    if (pila == NULL) {
        printf("Error: No se pudo asignar memoria para la pila.\n");
        return NULL;
    }
    pila->tope = NULL;
    pila->tamaño = 0;
    return pila;
}

void push(Pila* pila, void* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
    pila->tamaño++;
}

void* pop(Pila* pila) {
    if (pila->tope == NULL) {
        printf("Error: La pila está vacía.\n");
        return NULL;
    }
    Nodo* nodoAEliminar = pila->tope;
    void* dato = nodoAEliminar->dato;
    pila->tope = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    pila->tamaño--;
    return dato;
}

void* cima(Pila* pila) {
    if (pila->tope == NULL) {
        printf("Error: La pila está vacía.\n");
        return NULL;
    }
    return pila->tope->dato;
}

bool estaVacia(Pila* pila) {
    return pila->tope == NULL;
}

int tamaño(Pila* pila) {
    return pila->tamaño;
}

void liberarPila(Pila* pila) {
    while (!estaVacia(pila)) {
        pop(pila);
    }
    free(pila);
}

