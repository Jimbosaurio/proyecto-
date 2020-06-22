//HEchopor Luis Mendez el 15 de Junio
//Modificado el 20 por Luis Mendez


#include <stdio.h>   //Biblioteca basica 
#include <string.h>  //
#include <stdlib.h>  // Agrega funciones para memoria dinamica 
#include <string.h>  // 
#include "Inventario.h"
#include "Administracion.h"


void AltaLibro()		//Funcion para dar de alta un libro
{
	char dummy;		//Este se usara para guardarel enter que se pones
	char buffer[200] ;		//Restringimos el tamaño de buffer
	Libro nuevo;
	fflush(stdin);//limpia el buffer 
	scanf("%c", &dummy); //Guarda el ultimo enter que se pone
	puts("Agregando un nuevo libro");
	printf("Titulo: ");
	gets_s(buffer, 200);		//Lector de la linea de titulo que ponemos
	nuevo.titulo = (char*)malloc(strlen(buffer) + 1);//reserva memoria para el titilo ingresado 
	strcpy_s(nuevo.titulo, strlen(buffer) + 1, buffer);//traslada el texto 
	printf("Autor: ");   // imprime en pantalla
	gets_s(buffer, 200);   //Lee cadenas de cadena de caracteres
	nuevo.autor = (char*)malloc(strlen(buffer) + 1);//  reserva memoria para el autor
	strcpy_s(nuevo.autor, strlen(buffer) + 1, buffer);
	printf("Editorial: ");   // imprime en pantalla 
	gets_s(buffer, 200);  //Lee una cadena de caracteres 
	nuevo.editorial = (char*)malloc(strlen(buffer) + 1);   //Reserva espacio de memoria 
	strcpy_s(nuevo.editorial, strlen(buffer) + 1, buffer);   //Traslada el texto hacia la estructura //traslada el texto hacia la estructura

	printf("ISBN: ");  //Imprime en pantalla 
	gets_s(buffer, 200);
	while (strlen(buffer) != 13)	//Te asegura que el ISBN sea de 13 caracteres
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");  //Imprime en pantalla 
		gets_s(buffer, 200); //Mensaje de que pusiste mas o menos numeros
	}
	strcpy_s(nuevo.isbn, 14, buffer);		//Son 14 porque ademas guarda el carater nulo

	printf("Formato (tapa): ");  //Imprime en pantalla 
	gets_s(buffer, 200);   // Lee una cadena de caracteres //captura la numeracion 
	if (buffer[0] == '0')    //elige que formato es y lo guarda en estructura 
		nuevo.formato = TAPA_BLANDA;// Si detecta que es un 0 entonces lo va a guardar como de tapa blanda
	else
		nuevo.formato = TAPA_DURA; //Si no lo guardara como de tapa dura

	printf("Cantidad en existencia: ");  //Funcion de imprimir en pantalla 
	gets_s(buffer, 200);  //lee cadena de caracter 
	nuevo.existencias = strtol(buffer, NULL, 10);

	printf("Precio: ");   //Imprime en antalla 
	gets_s(buffer, 200);   //Lee cadena de caracteres
	nuevo.precio = strtof(buffer, NULL);

	AgregarLibro(nuevo); //Llamamos a la funcion agrear libro y le ados el nuevo
}

void BajaLibro()		//Funcion para eliminar un libro del inventario
{
	char query_isbn[15];		//Usa unaconsulta del isbn para saer cual buscamos
	printf("Introduce el ISBN del libro que quieres dar de baja:");  //Imprime en pantalla 
	gets_s(query_isbn, 15);//captura el ISBN
	while (strlen(query_isbn) != 13)//se asegura que el isbn sea de solo 13 digitos 
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");   //Imprime en pantalla 
		gets_s(query_isbn, 15);   //Lee ISBN / Cadena de caracteres 
	}
	EliminarLibro(query_isbn); //Busca el libro por su isbn y lo elimina con la funcion
}

void AgregarExistenciasLibro()		//Funcion para agregar la existencia de nuevos libros
{
	char dummy;		//Guardara el ultimo enter antes de leeer ISBN
	char query_isbn[15];		//Restringe a 15 los numeros
	fflush(stdin);//limpia buffer
	scanf("%c", &dummy);   //Lee en pantalla 
	int n;
	printf("Introduce el ISBN del libro que quieres modificar:");   //Imprime en pantalla 
	gets_s(query_isbn, 15);
	while (strlen(query_isbn) != 13)//sea asegura de validar el ISBN
	{
		printf("ISBN invalido. Debe contener 13 numeros. Ingresa de nuevo: ");  //imprime en pantalla 
		gets_s(query_isbn, 15);//guarda el ISBN
	}
	printf("Introduce la cantidad de unidades nuevas:");   //imprime en pantalla 
	scanf("%d", &n);
	CambiarExistenciasLibro(query_isbn,n);//cambia la cantidad de existancias
}

void BuscarLibroPorTitulo()		//Funcion parabuscar un libro por su titulo
{
	List* resultado;		//TE devolvera un apuntador a lista
	char dummy;		//Guardara el ultimo enter
	char query_titulo[100];		//Limita a 100 tus caracteres
	fflush(stdin);
	scanf("%c", &dummy);
	printf("Introduce el titulo del libro que deseas:");   // imprime pantalla 
	gets_s(query_titulo,100);		//Lee el tituo que hayas escrito
	resultado  = Buscar(TITULO, query_titulo);		//TE devuelve el libro y lo guarda en resultado
	if (resultado->head == NULL)   //funcion if para ver si exite el libro
		puts("0 resultados coinciden con este titulo");
	traverse(resultado);		//Atraviesa todos los resutads y los imprime
	system("pause");  //pausa el sistema 
}

void BuscarLibroPorAutor()
{
	List* resultado;//apuntador tipo lista 
	char dummy;
	char query_autor[100];
	fflush(stdin);
	scanf("%c", &dummy);
	printf("Introduce el autor que deseas buscar:");  //imprime en pantalla 
	gets_s(query_autor,100);//captura autor 
	resultado = Buscar(AUTOR, query_autor);//devuelve y alamacena resultado 
	if (resultado->head == NULL)//se asegura que ese resultado no sea invalido 
		puts("0 resultados coinciden con este autor");
	traverse(resultado);//recorre la lista hasta encontrar el libro 
	system("pause");   //pausa el sistema hasta que el usuario presione una tecla 
}

void BuscarLibroPorISBN()
{
	List* resultado;   //apuntador tipo lista 
	char dummy;		//Guarda el ultimo enter
	char query_isbn[100];		//Lo limita a 100 caracteres
	fflush(stdin);
	scanf("%c", &dummy);
	printf("Introduce el ISBN del libro que deseas:");
	gets_s(query_isbn,100);		
	resultado = Buscar(ISBN, query_isbn);//captura el resultado y lo almacena 
	if (resultado->head == NULL)//se asegura de que el resultado no sea invalido 
		puts("0 resultados coinciden con este isbn");
	traverse(resultado);//recorre la lista hasta encontrar resultado 
	system("pause");
}
