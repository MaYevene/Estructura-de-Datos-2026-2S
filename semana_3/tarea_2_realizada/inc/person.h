#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura que representa a una Persona
typedef struct {
    char nombre[50];
    char apellido[50];
    int edad;
    char rut[15];
} Persona;

// Prototipos de funciones individuales
Persona* crear_persona(const char* nombre, const char* apellido, int edad, const char* rut);
void imprimir_persona(const Persona* p);
void destruir_persona(Persona* p);

// Prototipos para el manejo de una lista o arreglo de personas
Persona** crear_arreglo_personas(int capacidad);
int agregar_persona(Persona** lista, int* cantidad, int capacidad, Persona* p);
void imprimir_lista_personas(Persona** lista, int cantidad);
void ordenar_personas_por_edad(Persona** lista, int cantidad);
void liberar_lista_personas(Persona** lista, int cantidad);

#endif // PERSON_H