/**
 * @file main.c
*/
#include "person.h"
#include <stdio.h>

void persons_to_csv(Persona p[]);

int main()
{
	int i;
	// Creamos un arreglo de personas
	Persona Personas[3];
	Personas[0] = crear_persona("Juan", 25);
	Personas[1] = crear_persona("Pedro", 30);
	Personas[2] = crear_persona("Carlos", 35);

	// Imprimimos su contenido por pantalla
	for (i = 0; i < 3; i++)
	{
		print_persona(Personas[i]);
		printf("\n");
	}

	// Guardamos la información en un archivo CSV
	persons_to_csv(Personas);
	printf("Archivo guardado en build/personas.csv\n");

	// Eliminamos la memoria asignada a cada persona
	for (i = 0; i < 3; i++) eliminar_persona(Personas[i]);

	return 0;
}

/**
 * @brief Función que crea un CSV a partir de un arreglo de Personas
*/
void persons_to_csv(Persona p[])
{
	int i;
	FILE* archivo;
	archivo = fopen("build/personas.csv", "w");
	if (archivo == NULL)
	{
		printf("Error: No se pudo abrir el archivo\n");
		exit(1);
	}
	fprintf(archivo, "Nombre,Edad\n");
	for (i = 0; i < 3; i++)
	{
		fprintf(archivo, "%s,%d\n", p[i].nombre, p[i].edad);
	}
	fclose(archivo);
}