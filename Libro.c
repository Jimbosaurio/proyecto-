
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Libro.h"
///
//Each book comes as 
//Titulo$Autor$Editorial$ISBN$Formato$Cantidad$Precio
///
Libro crearLibro(char *datosLibro) {
	// Extract the first token
	char *dato;
	Libro *nuevoLibro = (Libro*)malloc(sizeof(Libro));

	//Corta incluyendo \0
	dato = strtok(datosLibro, "|\0\n");
	//Crea el espacio de memoria en la structura 
	//                                  longitud    +\0
	nuevoLibro->titulo = (char*)malloc(strlen(dato) + 1);
	//Sin el +1, esta copia se desborda con el \0
	strcpy(nuevoLibro->titulo, dato);

	dato = strtok(NULL, "|\0\n");
	nuevoLibro->autor = (char*)malloc(strlen(dato) + 1);
	strcpy(nuevoLibro->autor, dato);

	dato = strtok(NULL, "|\0\n");
	nuevoLibro->editorial = (char*)malloc(strlen(dato) + 1);
	strcpy(nuevoLibro->editorial, dato);

	dato = strtok(NULL, "|\0\n");
	strcpy(nuevoLibro->isbn, dato);

	dato = strtok(NULL, "|\0\n");
	//Convierte cadena a entero
	nuevoLibro->formato = strtol(dato,NULL,10);

	dato = strtok(NULL, "|\0\n");
	nuevoLibro->existencias = strtol(dato, NULL, 10);
		
	dato = strtok(NULL, "|\0\n");
	//Convierte cadena a float
	nuevoLibro->precio = strtof(dato, NULL);

	//Regresa toda la estructura
	return *nuevoLibro;
}

void mostrarLibro(Libro *libro)
{
	printf("Titulo: %s\nAutor: %s\nEditorial: %s\nISBN: %s\n",libro->titulo,libro->autor,libro->editorial,libro->isbn);
	if (libro->formato == TAPA_BLANDA)
		puts("Formato: Tapa blanda");
	else
		puts("Formato: Tapa dura");
	printf("Cantidad en existencia: %d\nPrecio: %.2f", libro->existencias, libro->precio);
	puts("\n:::::::::::::::::::::::::::::::::::::::::");
}

void mostrarLibroSimplificado(Libro* libro)
{
	printf("%s\t%s\t\t%.2f\n", libro->isbn,libro->titulo,libro->precio);
}

const char* condensarLibro(Libro* l)
{
	char strFormato[2];
	char strExistencia[5];
	char strPrecio[10];
	int tamanoCadena;
	char* datosLibro;

	//Pasa de numeros a cadenas
	sprintf(strFormato, "%d", l->formato);
	sprintf(strExistencia, "%d", l->existencias);
	sprintf(strPrecio, "%.2f", l->precio);

	//Tama�o final = todo el titulo  +  todo el autor   +  toda la editorial   +ISBN + Formato  + numero en existencia  + numero del precio + espacio para las separaciones (6)                
	tamanoCadena = strlen(l->titulo) + strlen(l->autor) + strlen(l->editorial) + 13  +    1     + strlen(strExistencia) + strlen(strPrecio) + 6;
 	//                             cadena   +\0
	datosLibro = (char*)malloc((tamanoCadena + 1)*sizeof(char));

	snprintf(datosLibro,tamanoCadena+1,"%s|%s|%s|%s|%s|%s|%s", l->titulo,
																l->autor,
																l->editorial,
																l->isbn,
																strFormato,
																strExistencia,
																strPrecio);

	return datosLibro;
}