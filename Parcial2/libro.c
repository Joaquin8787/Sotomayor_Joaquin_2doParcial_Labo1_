#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"
#include "parser.h"
#include "joaquin.h"

int libro_delete(eLibro* this)
{
	int retorno=0;
	if(this!=NULL)
	{
		free(this);
		retorno=1;
	}
	return retorno;
}
eLibro* libro_new(){
	eLibro* nuevoLibro = NULL;
	nuevoLibro = (eLibro*)malloc(sizeof(eLibro));
	if(nuevoLibro != NULL){
		libro_setId(nuevoLibro, 0);
		libro_setTitulo(nuevoLibro," ");
		libro_setAutor(nuevoLibro," ");
		libro_setPrecio(nuevoLibro,0);
		libro_setEditorial(nuevoLibro," ");
	}

	return nuevoLibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* editorialStr){
	eLibro* nuevoLibro = NULL;
	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL){

		nuevoLibro = libro_new();

		if(nuevoLibro != NULL){
			if(!libro_setId(nuevoLibro, atoi(idStr))||
					!libro_setTitulo(nuevoLibro,tituloStr)||
					!libro_setAutor(nuevoLibro,autorStr)||
					!libro_setPrecio(nuevoLibro,atoi(precioStr))||
					!libro_setEditorial(nuevoLibro,editorialStr)){
				libro_delete(nuevoLibro);
				nuevoLibro = NULL;

			}

		}
	}
	return nuevoLibro;
}

//COMPARACION
int libro_compareByAutor(void* libro1, void* libro2)
{
	int retorno;
	char autor1[128];
	char autor2[128];
	if(libro1 != NULL && libro2 != NULL){
		libro_getAutor((eLibro*)libro1,autor1);
		libro_getAutor((eLibro*)libro2,autor2);
		if(strcmp(autor1,autor2)>0){
			retorno = -1;
		}
		else if(strcmp(autor1,autor2)<0){
			retorno = 1;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
//MAP
//* Planeta: 20% (si el monto es mayor o igual a $300)
//* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
int calcularDescuento(void* this)
{

	int retorno = -1;
	char editorial[128];
	int precio;
	if(this != NULL){

		libro_getEditorial((eLibro*)this,editorial);
		libro_getPrecio((eLibro*)this,&precio);

		if(strcmp(editorial,"Planeta") == 0)
		{
			if(precio >= 300){
				precio -= (precio * 0.20);
				libro_setPrecio(this,precio);
			}

		}
		else if(strcmp(editorial,"SIGLO XXI EDITORES") == 0)
		{
			if(precio <= 200){
				precio -= (precio * 0.10);
				libro_setPrecio(this,precio);
			}
		}

	}
	return retorno;
}

//MOSTRAR auxLibro
int mostrarUnLibro(eLibro* libro, int indice){
	int retorno = 1;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	char editorial[128];

	if(libro != NULL && indice >=0){
		libro_getId(libro,&id);
		libro_getTitulo(libro,titulo);
		libro_getAutor(libro,autor);
		libro_getPrecio(libro,&precio);
		libro_getEditorial(libro,editorial);
		printf("%-10d  %-50s                  %-20s         %-5d        %-5s \n",id,titulo,autor,precio,editorial);
		retorno = 0;
	}
	return retorno;
}

//SETTERS Y GETTERS
int libro_setId(eLibro* this, int id)
{
	int retorno=0;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int libro_getId(eLibro* this, int* id)
{
	int retorno=0;
	if(this!=NULL)
	{
		*id = this->id;
		retorno=1;
	}
	return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno=0;
	if(this!=NULL && titulo!=NULL && strlen(titulo)>1 && strlen(titulo)<128)
	{
		strcpy(this->titulo,titulo);

		retorno=1;
	}
	return retorno;
}
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno=0;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		retorno=1;
	}
	return retorno;
}

int libro_setAutor(eLibro* this,char* autor)
{
	int retorno=0;
	if(this!=NULL &&  autor!=NULL && strlen( autor)>1 && strlen( autor)<30)
	{
		strcpy(this->autor, autor);

		retorno=1;
	}
	return retorno;
}
int libro_getAutor(eLibro* this,char*  autor)
{
	int retorno=0;
	if(this!=NULL &&  autor!=NULL)
	{
		strcpy( autor,this-> autor);
		retorno=1;
	}
	return retorno;
}

int libro_setPrecio(eLibro* this, int precio)
{
	int retorno=0;
	if(this!=NULL && precio>0)
	{
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}

int libro_getPrecio(eLibro* this, int* precio)
{
	int retorno=0;
	if(this!=NULL)
	{
		*precio = this->precio;
		retorno=1;
	}
	return retorno;
}

int libro_setEditorial(eLibro* this,char* editorial)
{
	int retorno=0;
	if(this!=NULL &&  editorial!=NULL && strlen( editorial)>1 && strlen( editorial)<30)
	{
		strcpy(this->editorial, editorial);

		retorno=1;
	}
	return retorno;
}
int libro_getEditorial(eLibro* this,char*  editorial)
{
	int retorno=0;
	if(this!=NULL &&  editorial!=NULL)
	{
		strcpy(editorial,this-> editorial);
		retorno=1;
	}
	return retorno;
}
