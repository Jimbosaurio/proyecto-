//creado el 10 de junio del 2020 por Emir mondragón  
//Modificado por Luis el 12 de junio del 2020 
#pragma once
#include "Libro.h"
#include <string.h>		//Biblioteca para las cadenas

typedef struct Node Node;
typedef struct _Libro Data;//renomabramos estructura libro como Data

struct Node {
	Node* prev;			//Estructura de lo que tendra un nodo
	Data data;
	Node* next;
};

Node* createNode(Data data);		//Funcion para crear los nodos
void deleteNode(Node* useless);		//funcion que elimina nodos