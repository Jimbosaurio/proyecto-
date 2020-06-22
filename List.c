//Hecho por Luis Mendez el 10 de Junio

#include "List.h"

List* createList()
{
	List *l = (List*)malloc(sizeof(List));//reserva memoria para estructura list 
	l->head = NULL;				//hace que head apunte a NULL
	l->tail = NULL;				//hace que tail  apunte a NULL
	l->count = 0;				//iguala en contador a cero 
	return l;
}

List* createStack()//crea pila a base de crear lista 
{
	return createList();
}

List* createQueue()//crea cola  a base de crear lista 
{
	return createList();		//Usara la misma funcion de crar una lista
}

int isEmpty(List * list) //Te dira si esta lista esta vacia
{
	return list->head == NULL;
}

Data* peek(List * list)
{
	return &list->head->data;		//Te dara el ultimo alto qie entro a la lista
}

void push(List* list, Data new)//introduce un elemento a pila 
{
	Node* newNode = createNode(new);//se crea el nodo 

	if (isEmpty(list))
	{
		list->tail = newNode;		//Si la lista esta vacia entonces hara esto
		list->head = newNode;
		return;
	}

	newNode->next = list->head;		//Apuntara las cosas a donde deban
	list->head = newNode;
}

Data pop(List* list)   //Elimina nodo de hastaarriba de la pila
{
	Data out = list->head->data;
	list->head = list->head->next;
	return out;
}


void enqueue(List* list, Data new)//agrega un nuevo elemento a la cola 
{
	Node* newNode = createNode(new);  //apuntador 
	if (isEmpty(list))
		list->head = newNode;		//La cabeza sera el nuevo nodo
	else
		list->tail->next = newNode;
	
	list->tail = newNode;
}

Data dequeue(List* list)//elimna un elemento de la cola
{
	Data out = list->head->data;
	list->head = list->head->next;
	if (isEmpty(list))  //funcion if 
		list->tail = NULL;
	return out;
}

void traverse(List* list)//recorre la lista 
{
	Node* iterator = list->head;
	if (list->head == NULL)  //funcion if 
		return;
	while (iterator != list->tail)
	{
		mostrarLibroSimplificado(&(iterator->data));
		iterator = iterator->next;
	}
	mostrarLibroSimplificado(&(list->tail->data));
}
