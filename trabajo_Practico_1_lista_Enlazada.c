#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct structNodo {
    int valor;
    struct structNodo *proximo;
} Nodo;

// Crear e inicializar la lista
Nodo* crearLista() {
    return NULL;
}

// Agregar un elemento al final de la lista
Nodo* agregar(Nodo *lista, int valor) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;
    if (lista == NULL) {
        return nuevoNodo;
    } else {
        Nodo *cursor = lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    return lista;
}

// Obtener el largo de la lista
int obtenerLargo(Nodo *lista) {
    int largo = 0;
    Nodo *cursor = lista;
    while (cursor != NULL) {
        largo++;
        cursor = cursor->proximo;
    }
    return largo;
}

// Obtener el elemento N de la lista
int obtenerElemento(Nodo *lista, int n) {
    Nodo *cursor = lista;
    int contador = 0;
    while (cursor != NULL) {
        if (contador == n) {
            return cursor->valor;
        }
        contador++;
        cursor = cursor->proximo;
    }
    return -1; // Retornar -1 si el elemento no se encuentra
}

// Eliminar el elemento N de la lista
Nodo* eliminarElemento(Nodo *lista, int n) {
    if (lista == NULL) return NULL;
    if (n == 0) {
        Nodo *temp = lista;
        lista = lista->proximo;
        free(temp);
        return lista;
    }
    Nodo *cursor = lista;
    for (int i = 0; cursor != NULL && i < n-1; i++) {
        cursor = cursor->proximo;
    }
    if (cursor == NULL || cursor->proximo == NULL) return lista;
    Nodo *temp = cursor->proximo;
    cursor->proximo = cursor->proximo->proximo;
    free(temp);
    return lista;
}

// Imprimir la lista
void imprimirLista(Nodo *lista) {
    Nodo *cursor = lista;
    while (cursor != NULL) {
        printf("%d -> ", cursor->valor);
        cursor = cursor->proximo;
    }
    printf("NULL\n");
}

int main(void) {
    Nodo *lista = crearLista();
    lista = agregar(lista, 1);
    lista = agregar(lista, 2);
    lista = agregar(lista, 3);
    lista = agregar(lista, 4);

    printf("Lista: ");
    imprimirLista(lista);

    printf("Largo de la lista: %d\n", obtenerLargo(lista));
    printf("Elemento en la posición 2: %d\n", obtenerElemento(lista, 2));

    lista = eliminarElemento(lista, 2);
    printf("Lista después de eliminar el elemento en la posición 2: ");
    imprimirLista(lista);

    return 0;
}
