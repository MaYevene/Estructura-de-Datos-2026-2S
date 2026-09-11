#include "person.h"

Persona* crear_persona(const char* nombre, const char* apellido, int edad, const char* rut) {
    if (nombre == NULL || apellido == NULL || rut == NULL) {
        return NULL;
    }

    Persona* p = (Persona*)malloc(sizeof(Persona));
    if (p == NULL) {
        perror("Error al asignar memoria para Persona");
        return NULL;
    }

    strncpy(p->nombre, nombre, sizeof(p->nombre) - 1);
    p->nombre[sizeof(p->nombre) - 1] = '\0';

    strncpy(p->apellido, apellido, sizeof(p->apellido) - 1);
    p->apellido[sizeof(p->apellido) - 1] = '\0';

    p->edad = edad;

    strncpy(p->rut, rut, sizeof(p->rut) - 1);
    p->rut[sizeof(p->rut) - 1] = '\0';

    return p;
}

void imprimir_persona(const Persona* p) {
    if (p == NULL) {
        printf("Persona vacia (NULL)\n");
        return;
    }
    printf("RUT: %-12s | Nombre: %-12s | Apellido: %-12s | Edad: %d\n",
           p->rut, p->nombre, p->apellido, p->edad);
}

void destruir_persona(Persona* p) {
    if (p != NULL) {
        free(p);
    }
}

Persona** crear_arreglo_personas(int capacidad) {
    if (capacidad <= 0) return NULL;

    Persona** lista = (Persona**)malloc(sizeof(Persona*) * capacidad);
    if (lista == NULL) {
        perror("Error al asignar memoria para el arreglo");
        return NULL;
    }

    for (int i = 0; i < capacidad; i++) {
        lista[i] = NULL;
    }

    return lista;
}

int agregar_persona(Persona** lista, int* cantidad, int capacidad, Persona* p) {
    if (lista == NULL || cantidad == NULL || p == NULL) return 0;
    if (*cantidad >= capacidad) {
        printf("Error: Capacidad maxima alcanzada (%d personas).\n", capacidad);
        return 0;
    }

    lista[*cantidad] = p;
    (*cantidad)++;
    return 1;
}

void imprimir_lista_personas(Persona** lista, int cantidad) {
    if (lista == NULL || cantidad == 0) {
        printf("La lista de personas esta vacia.\n");
        return;
    }

    printf("=========================================================================\n");
    printf("                        LISTA DE PERSONAS (%d)                           \n", cantidad);
    printf("=========================================================================\n");
    for (int i = 0; i < cantidad; i++) {
        printf("[%d] ", i + 1);
        imprimir_persona(lista[i]);
    }
    printf("=========================================================================\n");
}

void ordenar_personas_por_edad(Persona** lista, int cantidad) {
    if (lista == NULL || cantidad <= 1) return;

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (lista[j]->edad > lista[j + 1]->edad) {
                Persona* temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void liberar_lista_personas(Persona** lista, int cantidad) {
    if (lista == NULL) return;

    for (int i = 0; i < cantidad; i++) {
        destruir_persona(lista[i]);
    }
    free(lista);
}