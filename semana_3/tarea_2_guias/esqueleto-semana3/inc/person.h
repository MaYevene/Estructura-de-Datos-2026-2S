/**
 * @file person.h
 * @brief Archivo de cabecera para la estructura Persona
*/
#ifndef PERSON
#define PERSON
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Estructura que define una persona
*/
typedef struct _persona
{
	char* nombre; /**< Nombre de la persona */
	int edad; /**< Edad de la persona */
} Persona;

Persona crear_persona(char* nombre, int edad);
void print_persona(Persona p);
void eliminar_persona(Persona p);

#endif