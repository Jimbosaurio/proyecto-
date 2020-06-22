//creado el 14 de junio por Jim Mart�nez
//modificado por Luis Mendez el 20 de Junio

#pragma once

#include "List.h"		//A�adimos nuestra libreria de listas
#include "Inventario.h"		//A�adimos nuestra libreria de inventario
#include "Administracion.h"		//A�animos todas las funciones del administrador

Stack *carrito;//   crea un apuntador a una pila llamada carrito 

void SistemaBusqueda();  // Funcion para buscar dependiendo de que tengamos
void Venta();   //Funcion que hara la venta final
void GenerarTicket();  //imprime ticket de compra