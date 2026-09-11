/**
 * @file persona.c
 * @brief Funciones relacionadas con la estructura Persona
*/
#include "person.h"

/**
 * @brief Función que crea una estructura Persona
 * 
 * @param nombre Cadena de caracteres con el nombre de la persona
 * @param edad Edad de la persona
 * @return Persona Estructura Persona
 */
Persona crear_persona(char* nombre, int edad)
{
	Persona p;
	p.nombre = (char*)malloc(strlen(nombre) + 1);
	if (p.nombre == NULL)
	{
		printf("Error: No se pudo asignar memoria para el nombre\n");
		exit(1);
	}
	strcpy(p.nombre, nombre);
	
	if (edad < 0) edad = 0;
	p.edad = edad;
	
	return p;
}

/**
 * @brief Imprime información de una estructura Persona
 * 
 * @param p Estructura Persona a imprimir
*/
void print_persona(Persona p)
{
	printf("Nombre: %s\n", p.nombre);
	printf("Edad:   %d\n", p.edad);
}

/**
 * @brief Elimina la memoria asignada a una estructura Persona
 * 
 * @param p Estructura Persona a eliminar
*/
void eliminar_persona(Persona p)
{
	free(p.nombre);
}