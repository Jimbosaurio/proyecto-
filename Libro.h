//Hecho por Emir Mondragon el 9 de Junio
//Modificado por Méndez Luis el 10 de Junio

#pragma once

enum FORMATO {TAPA_BLANDA, TAPA_DURA};//Le da el valor de 0 a 1 dependiendo de la tapa  
										//que este tenga

struct _Libro {  //Estructura de libro 
	char* titulo;
	char* autor;
	char* editorial;
	char isbn[14];
	enum FORMATO formato;  //Le da el valor de 0 a 1 
	int existencias;
	float precio;
};
typedef struct _Libro Libro;//renombra la estructura 


Libro crearLibro(char *datosLibro);   //Reserva espacio de memoria y crea el libro
void mostrarLibro(Libro *libro);   //Imprime el libro en tu pantalla junto con todos los datos 
void mostrarLibroSimplificado(Libro *libro);		//Imprime el libro pero solo ISBN, Titulo y precio
const char* condensarLibro(Libro *libro); //Esta es la funcion que se encarga de crear una linea de texto con toda la info del libro