//Hecho por Luis el 10 de junio de 2020
#include <stdio.h> //biblioteca basica 
#include <stdlib.h>  //biblioteca para memoria dinamica 
#include "DoubleLinkedList.h"
#include <string.h>

DLL* createDLL()
{
	DLL* dll = (DLL*)malloc(sizeof(DLL));//se reserva espacio con el apuntador 
	dll->head = NULL;		//apuntas a null head 
	dll->tail = NULL;		//apuntas a null tail 
	dll->count = 0;
	return dll;
}

void add_before(DLL *list, int index, Data new)
{
	if (index == 0)		//si es el primer nodo solo lo crea 
		add_front(list, new);
	else if (index > 0 && index < list->count)// si hay mas nodos lo agrega antes dela posicion ingresada  
		add_after(list, index - 1, new);
	else							//si el indice es menor que 0 no existe 
		puts("Indice invalido");
}

void add_front(DLL *list, Data new)
{
	Node* newNode = createNode(new);	//se crea nodo 
	if (list->head == NULL)		//en este caso supone que solo hay un nodo existente el que acabamos de crear 
	{							//y sus nodos conexiones se apuntan a si mismas 
		newNode->next = newNode;
		newNode->prev = newNode;
		list->tail = newNode;
	}
	else if (list->head != NULL && list->head == list->tail)//ya hay un nodo existente y se agrega un segundo 
	{														//las conexiones se apuntan al nuevo nodo 
		newNode->next = list->head;
		newNode->prev = list->head;
		list->head->prev = newNode;
		list->head->next = newNode;
	}
	else
	{									//ya hay mas nodos y se cambian las direcciones a este nuevo nodo 
		newNode->next = list->head;
		newNode->prev = list->tail;
		list->head->prev = newNode;
		list->tail->next = newNode;
	}

	list->head = newNode;
	list->count += 1;
}

void add_end(DLL *list, Data new)	//Funcion para añadir nodos al final de la lista 
{
	Node* newNode = createNode(new);   //se crea el noodo 

	if (list->head == NULL)//ocupa el caso de que el nodo creado es el primero en la lista 
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		list->head = newNode;
	}
	else if (list->head != NULL && list->head == list->tail)//
	{
		newNode->next = list->head;
		newNode->prev = list->head;
		list->head->prev = newNode;
		list->head->next = newNode;
	}

	else
	{
		newNode->next = list->head;
		newNode->prev = list->tail;
		list->head->prev = newNode;
		list->tail->next = newNode;
	}
	list->tail = newNode;
	list->count += 1;
}

void add_after(DLL *list, int index, Data new)		//Funcion para añadr unnuevo nododespues
{
	Node* newNode;		//Creamos el nuevo nodo
	Node* mark = list->head;		//Cramos un marcador
	Node* n;		//Cramos a n
	if (index > list->count || index < 0) //Esto te validara poder añadir en esa posicion
	{
		puts("Indice invalido");  //imprime en pantalla 
	}
	else if (index == list->count - 1)   //funcion if 
	{
		add_end(list, new);		//Si solo hay uno pues es mas facil añadir al final
	}
	else
	{
		newNode = createNode(new);		//Creara un nuevo nodo
		for (int i = 0 ; i < index ; i++)
			mark = mark->next;		//La marca se recorrera
		
		n = mark->next;

		n->prev = newNode;
		newNode->next = n;

		mark->next = newNode;
		newNode->prev = mark;
		list->count += 1;
	}
}

void delete_node(DLL *list, Node* node)		//Funcion para borrar un nodo de la lista
{
	Node *next, *prev;		//Nodo siguiente y despues

	if (list->count == 1)  //funcion if
	{
		list->head = NULL;		//Declaracion de que es lo que haran las ligas de cada 
		list->tail = NULL;		//nuevo nodo y su anterior y posterior
		list->count = 0;
		deleteNode(node);  //borrar nodo 
		return;
	}

	next = node->next;
	prev = node->prev;   

	prev->next = next;
	next->prev = prev;

	if (node == list->head)  //funcion if
		list->head = next;
	else if (node == list->tail)
		list->tail = prev;

	list->count -= 1;    
	deleteNode(node);    //Borra nodo 
}

void forward_traverse(DLL* list)		//Atravesara toda la lista
{
	Node* iterator = list->head;  		   //apuntador a la cabeza de la lista
	while (iterator != list->tail)		    
	{
		mostrarLibro(&(iterator->data));	//Mostrara los libros que coinciden con lo que buscaste
		iterator = iterator->next;		//El ierador se recorre
	}
	mostrarLibro(&(list->tail->data));		//Imprime lso libros
}

void backward_traverse(DLL* list)	//Funcion para atravesar la lista desde atras
{
	Node* iterator = list->tail;		//Este nodo esra el que se recorra
	while (iterator != list->head)		//Mientra el iterador sea diferente de la cabeza
	{
		mostrarLibro(&(iterator->data));	//Mostrara el iibro que coincida
		iterator = iterator->prev;		//El iterador e recorre
	}
	mostrarLibro(&(list->head->data));		//Imprime los libros que hayan coincidido
}