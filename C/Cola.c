#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* frente;
    Nodo* fin;
    int tamaño;
} Cola;

Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    if (cola == NULL) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        return NULL;
    }
    cola->frente = NULL;
    cola->fin = NULL;
    cola->tamaño = 0;
    return cola;
}

void push(Cola* cola, void* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (cola->frente == NULL) {
        cola->frente = nuevoNodo;
    } else {
        cola->fin->siguiente = nuevoNodo;
    }
    cola->fin = nuevoNodo;
    cola->tamaño++;
}

void* pop(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Error: La cola está vacía.\n");
        return NULL;
    }
    Nodo* nodoAEliminar = cola->frente;
    void* dato = nodoAEliminar->dato;
    cola->frente = nodoAEliminar->siguiente;

    if (cola->frente == NULL) {
        cola->fin = NULL;
    }

    free(nodoAEliminar);
    cola->tamaño--;
    return dato;
}

void* frente(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Error: La cola está vacía.\n");
        return NULL;
    }
    return cola->frente->dato;
}

bool estaVacia(Cola* cola) {
    return cola->frente == NULL;
}

int tamaño(Cola* cola) {
    return cola->tamaño;
}

void liberarCola(Cola* cola) {
    while (!estaVacia(cola)) {
        pop(cola);
    }
    free(cola);
}

