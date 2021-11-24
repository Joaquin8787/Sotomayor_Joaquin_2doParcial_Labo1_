#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "joaquin.h"
#include "libro.h"

/** \brief Carga los datos de los libros desde un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pListaLibros)
{
	int retorno = 0;
	FILE* auxP;
	if(path != NULL && pListaLibros != NULL){
		auxP = fopen(path,"r");//LO LEO
		if(auxP != NULL){

			parser_libroFromText(auxP ,pListaLibros);
			retorno = 1;
		}
		else{

			printf("No se pudo leer el archivo");
		}
		fclose(auxP);
	}

	return retorno;
}

/** \brief Listar libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */
int controller_Listlibro(LinkedList* pListaLibros)
{
	int retorno = 0;
	eLibro* libro;
	if(pListaLibros != NULL){
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("                       LISTA DE LIBROS                                                                                                      \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID          TITULO                                                              AUTOR                        PRECIO       EDITORIAL         \n");
		for(int i= 0; i<ll_len(pListaLibros);i++){
			libro = (eLibro*)ll_get(pListaLibros,i);
			mostrarUnLibro(libro, i);
		}
		retorno = 1;
	}
	return retorno;
}

/** \brief Ordenar libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */

int controller_sortlibro(LinkedList* pListaLibros)
{
	int retorno = -1;
	int order;
	if(pListaLibros != NULL){
		order = menuOrder();
		printf("ORDENANDO...\n");
		if(!ll_sort(pListaLibros,libro_compareByAutor,order)){
			retorno = 0;
			printf("Lista ordenada!!!\n");
		}
		else{
			printf("Hubo algun problema al ordenar la lista\n");
		}


	}
	return retorno;
}

/** \brief Mapear Libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */
int controller_ll_map(char* path , LinkedList* pListaLibros){
	int retorno = 0;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	char editorial[128];

	LinkedList* listaMapeada;
	FILE* pFile;
	eLibro* auxLibro;
	if(pListaLibros != NULL)
	{
		listaMapeada = ll_map(pListaLibros,calcularDescuento);
		if(listaMapeada != NULL){
			pFile  = fopen(path,"w");
			if(pFile != NULL)
			{
				//Escritura fantasma
				fprintf(pFile,"id,Titulo,Autor,Precio,Editorial\n");

				for(int i = 0;i<ll_len(listaMapeada);i++)
				{
					auxLibro = (eLibro*) ll_get(listaMapeada,i);
					if(auxLibro != NULL)
					{
						if(libro_getId(auxLibro,&id) &&
								libro_getTitulo(auxLibro,titulo)&&
								libro_getAutor(auxLibro,autor)&&
								libro_getPrecio(auxLibro,&precio) &&
								libro_getEditorial(auxLibro,editorial))
						{
							fprintf(pFile,"%d,%s,%s,%d,%s\n",id,titulo,autor,precio,editorial);
							retorno = 1;
						}
					}
				}
			}
			else
			{
				printf("No se pudo escribir en el archivo \n");
			}
			fclose(pFile);
		}

	}
	return retorno;
}

