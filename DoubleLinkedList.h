//Hecho 8 de Junio - Emir Mondragon
//Modificado el 20 de Junio - Luis Méndez

#pragma once		//Esto hara que solo se repita una vez las librerias
#include "Libro.h"		//Incluimos todas las funciones de los libros
#include "Node.h"		//Incluimos las funciones para poder trabajar los nodos
#include <string.h>				//Se incluyen las cadenas 

typedef struct Doubly_Linked_List DLL;

struct Doubly_Linked_List
{
	Node* head;
	Node* tail;			//Va a usar una estructura del tipo nodo con cabeza y cola
	int count;			
};

DLL* createDLL();		//Funcion para crear la lista doble
void add_front(DLL *,Libro);//Agrega al principio de l lista 
void add_after(DLL *, int index, Data);		//Añadir despues de un nodo
void add_before(DLL *, int index, Data);//agrega antes de un nodo 
void add_end(DLL*, Libro);//agrega al final de la lista 
void delete_index(DLL*, int index);//borra un nodo    
void delete_node(DLL*, Node* node);   //Borra el nodo 
void forward_traverse(DLL*);    //El que atraviesa 
void backward_traverse(DLL*);//recorre la lista comenzando desde el final hasta el principio 
