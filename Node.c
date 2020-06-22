//Hecho por Emir Mondragon el 9 de Junio
//Modificado por Luis Mendez el 10 de Junio

#include <stdlib.h>  //funciones para memoria dinamica 
#include "Node.h"
#include <string.h>

Node* createNode(Data data)   //reserva de memoria 
{
	Node* new = (Node*)malloc(sizeof(Node));  //Reserva de memoria 
	new->next = NULL;		//apunta next a null 
	new->prev = NULL;		//apunta prev a null
	new->data = data;
	return new;
}

void deleteNode(Node* useless)// borra un nodo 
{
	free(useless);//libera memoria 
}