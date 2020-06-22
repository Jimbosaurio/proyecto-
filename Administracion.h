//elaborado por emir mondragon 13 junio 
//modificado por elean jim 16 junio
#pragma once			//Esto solo se usa para que una biblioteca no se use dos veces y cree conflictos
#include "Libro.h"		//Incluimos el .h de las funciones de los libros
#include <string.h>		//Libreria para cadenas

void AltaLibro();		//ESta esla declaracion para añadir nuevos libros
void BajaLibro();		//Declaracion de la funcion para eliminar libros del inventario
void AgregarExistenciasLibro();		//Esto sirve para añadir mas cantidad de libros delos que ya hay
void BuscarLibroPorTitulo();		//Funcion para buscar un libro por su titulo
void BuscarLibroPorAutor();		//Funcion para buscar por autor
void BuscarLibroPorISBN();		//Funcion para buscar por ISBN
