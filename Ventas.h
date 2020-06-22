//creado el 14 de junio por Jim Martínez
//modificado por Luis Mendez el 20 de Junio

#pragma once

#include "List.h"		//Añadimos nuestra libreria de listas
#include "Inventario.h"		//Añadimos nuestra libreria de inventario
#include "Administracion.h"		//Añanimos todas las funciones del administrador

Stack *carrito;//   crea un apuntador a una pila llamada carrito 

void SistemaBusqueda();  // Funcion para buscar dependiendo de que tengamos
void Venta();   //Funcion que hara la venta final
void GenerarTicket();  //imprime ticket de compra