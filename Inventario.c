//Hecho por Luis Méndez el 15 de Junio


#include <stdio.h>   //Biblioteca basica 
#include <stdlib.h>  //Biblioteca para memoria dinamica 
#include <string.h>   //Funciones para las cadenas 
#include "Inventario.h"
#include "Libro.h"		//Funciones de los libros
#include "DoubleLinkedList.h"


int LeerArchivoBD(const char* ruta)		//Funcion que leera el archivo de txt
{
	char linea[200];  //Cadena de caracteres restringida a 200
	int i;
	Libro libroActual;		//Libro actutal

	inventario = createDLL();//crea lista para el inventario 
	
	FILE *archivoInventario = fopen(ruta, "r");//abre el archivo en modo lectura 
	if (archivoInventario == NULL) 
	{ 
		fputs("No existe el archivo", stderr); //Imprime en archivo de texto plano 
		return 1;
	}
	i = 0;
	while (feof(archivoInventario) == 0)
	{
		fgets(linea, 200, archivoInventario);  //Lee archivo de texto plano en caracter 
		libroActual = crearLibro(linea);		//Crea una estructura de libro con la info
		add_end(inventario, libroActual);    //Añade el libro al final de la lista
	}
	
	fclose(archivoInventario);		//Cierra el archivo del incentario
	return 0; 
}

int GuardarArchivoBD(char *ruta)
{
	FILE* archivoInventario = fopen(ruta, "w");//abre archivo en modo escritura 
	Node* iter = inventario->head->next;
	while (iter != inventario->tail)  //Funcion while 
	{
		fputs(condensarLibro(&iter->data), archivoInventario);   //Imprime en archivo de texto plano 
		fputc('\n', archivoInventario);		//Salto de linea
		iter = iter->next;	//El iterado se recorre
	}
	fputs(condensarLibro(&inventario->tail->data), archivoInventario);  
	fclose(archivoInventario);//cierra archivo 
	return 0;

}

int ListarInventario()		//Te mostrara los libros que tengas guardados
{
	system("cls");		//Borra la pantalla
	forward_traverse(inventario);//recorre e imprime el inventario 

	return 0;
}

void AgregarLibro(Libro l)		//Agregamos un libro a la lista
{
	add_end(inventario, l);		//Lo añade al final
}

void EliminarLibro(const char* isbn)
{
	Node* resultado = BuscarLibro(isbn);//el apuntador recibe el resultado de la funcion 
	if (resultado == NULL)//se asegura de que el isbn sea valido 
	{
		puts("Ese ISBN no existe en el cat�logo");  //Imprime pantalla 
		return;  //retorna 
	}
	delete_node(inventario, resultado);//borra el libro 
}

void CambiarExistenciasLibro(const char* isbn, int numLibros)
{
	Node* resultado = BuscarLibro(isbn);   //Reserva de memoria 
	if (resultado == NULL)   //Funcion if 
	{
		puts("Ese ISBN no existe en el cat�logo");   //Imprime en pantalla 
		return;
	}
	resultado->data.existencias += numLibros;
}

void DisminuirExistenciasLibro(const char* isbn)		//Funcion para disminuir la cantidad de libros
{
	CambiarExistenciasLibro(isbn, -1);  //Llamamos la funcion para cambiar las existencias
}										//Y restamos solo uno

List* Buscar(enum MODO_BUSQUEDA mode, const char* query)
{
	List* resultado = createList();   //apuntador 
	Node* iterador = inventario->head;   //Apuntador 
	while (iterador != inventario->tail)   //funcion while 
	{
		switch (mode)   //Esto te dara los casos dependiendo de que es lo que buscas
		{
			case TITULO:
				if (!strcmp(query,iterador->data.titulo))		//Casode titulo
					enqueue(resultado, iterador->data);
				break;
			case AUTOR:
				if (!strcmp(query,iterador->data.autor))		//Caso de autor
					enqueue(resultado, iterador->data);
				break;
			case ISBN:
				if (!strcmp(query,iterador->data.isbn))		//Caso de ISBN
					enqueue(resultado, iterador->data);
				break;
		}
		iterador = iterador->next;	//Recorremos el iterador
	}

	//Ultimo elemento
	switch (mode)		//
	{
	case TITULO:
		if (!strcmp(query, iterador->data.titulo))		//Caso del titulo
			enqueue(resultado, iterador->data);
		break;
	case AUTOR:
		if (!strcmp(query, iterador->data.autor))		//Caso de Autor
			enqueue(resultado, iterador->data);
		break;
	case ISBN:											//caso de ISBN
		if (!strcmp(query, iterador->data.isbn))
			enqueue(resultado, iterador->data);
		break;
	}

	return resultado;
}

Node* BuscarLibro(const char* isbn)
{
	Node* iterador = inventario->head;// el apuntador obtiene valor para comparacion
	while (iterador != inventario->tail)//recorre el valor del apuntador 
	{
		if (!strcmp(isbn, iterador->data.isbn))
				return iterador;
		iterador = iterador->next;
	}

	if (!strcmp(isbn, iterador->data.isbn))//cambia valor de iterador al correcto 
			return iterador;

	return NULL;
}

