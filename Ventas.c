//Hecho por Jim Martinez el 14 de Junio
//Modificado por Luis Mendez el 20 de Junio

#include "Ventas.h"
#include <stdio.h>   //biblioteca basica 
#include <stdlib.h>  //funciones para memoria dinamica 

void SistemaBusqueda()		//Funcion para buscar los libros
{
	int a = 0;

	do
	{
		system("cls");//limpia pantalla
		puts("Servicio de busqueda");   //Imprime pantalla 
		puts("Selecciona el tipo de busqueda que quieres realizar");   // Imprime pantalla 
		puts("1) Busqueda por titulo");   //Imprime pantalla 
		puts("2) Busqueda por autor");				//Menu para busqueda
		puts("3) Busqueda por isbn");   //Imprime pantalla 
		puts("4) Regresar a ventas");// Imprime pantalla 
		printf("Seleccion: ");
		scanf("%d", &a);		//Scanfpara la ocpcion
		switch (a)
		{
		case 1:
			BuscarLibroPorTitulo();		//funcion de buscar libro por titulo
			break;
		case 2:
			BuscarLibroPorAutor();		//funcion de buscar libro por autor
			break;
		case 3:
			BuscarLibroPorISBN();		//funcion de buscar libro por isbn
			break;
		case 4:
			break;
		default:
			system("cls");
			puts("Opcion de busqueda no valida");		//Opcion invalida
			break;
		}
	} while (a != 4);	//Se repite shasta que le digan que ya no
	return;
}

void Venta()		//Funcion para vender libros
{
	int a;
	char buffer[14];		//Almacenara temporlmente el ISBN
	Node* porAgregar;
	Libro agregado; 
	carrito = createStack();//crea una pila llamada carrito 
	do
	{
		system("cls");//limpia pantalla 
		puts(":::::::Carrito de compras:::::::::");

		if (isEmpty(carrito))//verifica estado del carrito 
			puts("Carrito vacio");		//Mensaje de CArrito vacio
		else
			traverse(carrito);		//Atravieza el carrito y lo imprime

		puts("\nSelecciona la accion que deseas realizar");
		puts("1) Agregar libro al carrito");
		puts("2) Finalizar compra");		//Menu para añadir al carrito o finalizar la compra
		printf("Seleccion: ");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			puts("Introduce el ISBN del libro que desees agregar al carrito");
			printf("ISBN: ");
			scanf_s("%s", buffer, 14);//escanea isbn del usuario 
			porAgregar = BuscarLibro(buffer);//busca libro y alamacena su resultado 
			
			if (porAgregar == NULL)
			{
				puts("Libro invalido");		//Si el isbn no coincide entonces se corta
				break;
			}

			if (porAgregar->data.existencias <= 0)  //funcion if
			{
				printf("El libro %s: %s no esta disponible por el momento",porAgregar->data.isbn, porAgregar->data.titulo);  //imprime pantalla 
				break;
			}
			push(carrito, porAgregar->data);//agrega el libro a la lista 
			DisminuirExistenciasLibro(buffer);  //disminuye en uno el libro que hayas elegido 

			break;
		case 2:		//Opcion Salir
			break;
		default:
			puts("Opcion no valida");		//Opcion invalida
			break;
		}
	} while (a != 2);

	GenerarTicket();//imprime ticket 
}

void GenerarTicket()	//Funcion generadora de ticket
{
	Libro iter;//variable tipo libro 
	float total = 0.0f;	//Declaramo el total en 0
	puts("Generar tickets");
	while (!isEmpty(carrito))//ciclo de impresion de elementos del carrito 
	{
		iter = dequeue(carrito);
		printf("%s\t%s\t\t$%.2f\n", iter.isbn, iter.titulo, iter.precio);  //imprime pantalla 
		total += iter.precio;
	}
	printf("Total de compra: %.2f\n", total);  //imprime pantalla 
	system("pause");  //pausa programa hasta que el usuario quiera 
	GuardarArchivoBD("InventarioLibros.txt");
}


