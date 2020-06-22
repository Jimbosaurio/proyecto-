//Hecho por Mendez Luis  10 de Junio

#pragma once		//Solo se repite una vez las bibliotecas
#include <stdlib.h>   //Incluye las funciones para la gestion de memoria dinamica 
#include "Libro.h"
#include "DoubleLinkedList.h"
#include "List.h"


enum MODO_BUSQUEDA {TITULO, AUTOR, ISBN};		//Esto le da el valores de 0,1 y 2 a los datos

DLL* inventario; //Cambiar por la lista doble

int LeerArchivoBD(const char *ruta);		//Funcion para leer un archivo de txt
int GuardarArchivoBD(char *ruta);//guarda contenido en el archivo txt

int ListarInventario();			//Funcion para recorrer el inventario

//Agregar libros
void AgregarLibro(Libro l);
//Eliminar libros
void EliminarLibro(const char* isbn);
//Cambiar existencias
void CambiarExistenciasLibro(const char* isbn, int numLibros);
void DisminuirExistenciasLibro(const char* isbn);
//Buscar
List* Buscar(enum MODO_BUSQUEDA mode, const char* id);
Node* BuscarLibro(const char* isbn);