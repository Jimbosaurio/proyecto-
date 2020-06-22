//Elaborado por Elean Jim el 18 de junio de 2020 
//Modificado y corregido por Luis Mendez el 21 de Junio

#include <stdio.h>   //Biblioteca basica 
#include <stdlib.h>   //Funciones para memoria dinamica 
#include <string.h>		//Bibllioteca de las cadenas
#include "Inventario.h"		//Funciones del inventario
#include "Administracion.h"		//Funciones del administrador
#include "Ventas.h"		//Duncioes de la venta de libros

int main(int argc, char** argv)   //funcion principal 
{
	int a = 0,b = 0;   //declaracion de variables 
	LeerArchivoBD("InventarioLibros.txt");//lee el archivo de el inventario de libros 


	puts("°°°°°°°°°°°°°°°°°°°°°°°°°LIBRERIAS SCHOPENHAUER°°°°°°°°°°°°°°°°°°°°°°°°°​");   //Imprime en pantalla 
	puts("Bienvenido a nuestra libreria en linea");		//Titulo  e impresion
	do
	{
		puts("Seleccione el modo de operacion");   //Imprime en pantalla 
		puts("1) Administracion");    //Imprime en pantalla 
		puts("2) Ventas");   //Imprime en pantalla 
		puts("3) Salir");				//Opciones del menu
		printf("Seleccion: ");   // Imprime en pantalla 
		scanf("%d", &a);		//Scanf para la opcion del menu principal
		switch (a)		//Switc
		{
			//Administracion
		case 1:
				b = 0;
				system("cls");//limpia la pantalla 
				do
				{
					puts(":::::Administracion:::::");   //Imprime en pantalla 
					puts("Selecciona la accion que deseas realizar: ");
					puts("1) Agregar libros al inventario");		//Menu de Admin
					puts("2) Dar de baja un libro");
					puts("3) Cambiar existencias de un libro");  //imprime en pantalla 
					puts("4) Salir");
					printf("Seleccion: ");   //Imprime en pantalla 
					scanf("%d", &b);		//Scanf del menu secundario
					switch (b)		//Switch case del segundo menu
					{
						//Agregar libros al inventario
					case 1:
						AltaLibro();		//Llamamos a la funcion que da de alta libros
						break;
						//Dar de baja un libro
					case 2:
						BajaLibro();		//Lamamos a la funcio para eliminar libros
						break;
						//Cambiar existencias
					case 3:
						AgregarExistenciasLibro();		//Llamamos la funcion para modificar la existencia
						break;
						//Salir
					case 4:
						break;
					default:
						system("cls");
						puts("Opcion no valida");	//Opcion invalida
						break;
					}
				} while (b != 4);
				break;
			//Ventas
		case 2:
				b = 0;
				do
				{
					system("cls");//limpia la pantalla
					puts("BIENVENIDO AL SISTEMA DE VENTAS");//texto para el usuario 
					puts("Selecciona la accion que deseas realizar: ");
					puts("1) Mostrar todos los libros");
					puts("2) Buscar libro");   // imprime pantalla 
					puts("3) Agregar al carrito");
					puts("4) Salir");  //imprime pantalla 
					printf("Seleccion: ");
					scanf("%d", &b);//lee la variable
					switch (b)
					{
						//Mostrar el listado de libros
					case 1:
						system("cls");
						puts("Mostrando todos los libros");
						ListarInventario();//imprime el inventario al usuario 
						system("pause");//pone al sistema en pausa 
						break;
						//Buscar un libro
					case 2:
						SistemaBusqueda();
						system("pause");
						break;
						//Añadir al carrito
					case 3:
						//nos ingresa alas opciones  de venta de libros 
						Venta();
						break;
					case 4:
						break;
					default:
						system("cls");
						puts("Opcion no valida");
						break;
					}
				} while (b != 4);
		//Salir
		case 3:
			break;
		default:
			puts("Opcion no valida");
		}
		system("cls");
	}while (a != 3);

	GuardarArchivoBD("InventarioLibros.txt");//guarda los cambios hechos por el usuario en el txt

	puts("Gracias por su preferencia");
	return 0;
}