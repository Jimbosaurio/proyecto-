//Hecho por Emir mondragón el 11 de junio del 2020
//Modificado por Jim el 12 de junio del 2020 
#pragma once
#include <stdlib.h>  // incluye las funciones para la memoria dinamica 
#include "Node.h"


typedef struct List List;		//La estructura lista sera una lista, luego una pila y finalmente una cola
typedef struct List Stack;		
typedef struct List Queue;

struct List    //estructura de lista 
{
	Node* head;
	Node* tail;
	int count;
};

List* createList();		//Funcion para crear la lista
List* createStack();	//Funcion para crear la cola
List* createQueue();		//Funcion para Crear una cola
int isEmpty(List *);		//Esta funcion nos dira si la lista esta vacia
Data* peek(List *);			//Nos dara el ultimo valor de la pila
void push(List *,Data);		//funcion que introduce elemento 
Data pop(List*);   //Funcion para eliminar un nodo 
void enqueue(List*,Data);	//Funcion de encolar 
Data dequeue(List*);       // Sacar datos de la cola (desencolar)
void traverse(List*);		//Funcion que atraviesa toda la lista y guardara datos 
