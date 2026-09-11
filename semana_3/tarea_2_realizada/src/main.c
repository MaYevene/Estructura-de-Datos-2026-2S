#include "person.h"

int main(void) {
    printf("=== INICIO PROGRAMA TAREA 2: ESTRUCTURA PERSONA ===\n\n");

    int capacidad = 5;
    int cantidad = 0;

    Persona** grupo = crear_arreglo_personas(capacidad);
    if (grupo == NULL) {
        fprintf(stderr, "Error al inicializar el grupo de personas.\n");
        return EXIT_FAILURE;
    }

    // Creacion de instancias de prueba
    Persona* p1 = crear_persona("Matias", "Yevenes", 19, "12.345.678-k");
    Persona* p2 = crear_persona("Eban", "Delgado", 1, "12.345.678-k");
    Persona* p3 = crear_persona("Carlos", "Cofre", 19, "12.345.678-k");
    Persona* p4 = crear_persona("Pablo", "Seron", 67, "12.345.678-k");

    agregar_persona(grupo, &cantidad, capacidad, p1);
    agregar_persona(grupo, &cantidad, capacidad, p2);
    agregar_persona(grupo, &cantidad, capacidad, p3);
    agregar_persona(grupo, &cantidad, capacidad, p4);

    printf("1. Lista original:\n");
    imprimir_lista_personas(grupo, cantidad);

    printf("\n2. Ordenando por edad...\n");
    ordenar_personas_por_edad(grupo, cantidad);
    imprimir_lista_personas(grupo, cantidad);

    printf("\n3. Liberando memoria dinamicamente asignada...\n");
    liberar_lista_personas(grupo, cantidad);

    printf("\n=== PROGRAMA FINALIZADO CON EXITO ===\n");
    return EXIT_SUCCESS;
}