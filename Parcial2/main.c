#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "joaquin.h"
#include "libro.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int main()
{
	setbuf(stdout,NULL);

	int option = 0;
	int flag1=0;

	char confirmar;
	char sobreescribir;

	LinkedList* listaEmpleados = ll_newLinkedList();
	do{
		switch(menuOpciones())
		{
		case 1:
			if (!ll_isEmpty(listaEmpleados))
			{
				joaquin_getCaracter(&sobreescribir,"La lista que tiene ya esta cargada, si sigue sobreescribira la lista. Desea seguir? (s/n): ","ERROR!!! \n", 'n', 's', 5);
				if (sobreescribir == 's')
				{
					ll_clear(listaEmpleados);
				}
				else{
					break;
				}

			}
			if (controller_loadFromText("Datos.csv", listaEmpleados))
			{
				printf("Se cargaron los datos de los libros con exito!!! \n");

			} else
			{
				printf("No se puedieron cargar los datos de los libros... \n");
			}
			getchar();
			break;
		case 2:
			if(flag1){
				if (!ll_isEmpty(listaEmpleados))
				{
					joaquin_getCaracter(&sobreescribir,"La lista que tiene ya esta cargada, si sigue sobreescribira la lista. Desea seguir? (s/n): ","ERROR!!! \n", 'n', 's', 5);
					if (sobreescribir == 's')
					{
						ll_clear(listaEmpleados);
					}
					else{
						break;
					}

				}
				if (controller_loadFromText("mapeado.csv", listaEmpleados))
				{
					printf("Se cargaron los datos de los libros con exito!!! \n");

				} else
				{
					printf("No se puedieron cargar los datos de los libros... \n");
				}
			}
			else
			{
				printf("Primero debe aplicar los descuentos!!!\n");
			}

			getchar();
			break;
		case 3:
			if(!ll_isEmpty(listaEmpleados)){
				controller_Listlibro(listaEmpleados);
			}
			else{
				printf("Debe tener a los libros cargados para poder listarlos...\n");
			}
			getchar();
			break;
		case 4:
			if(!ll_isEmpty(listaEmpleados)){
				controller_sortlibro(listaEmpleados);
			}
			else{
				printf("Debe tener a los libros cargados para poder ordenarlos...\n");
			}
			getchar();
			break;
		case 5:
			if(controller_ll_map("mapeado.csv",listaEmpleados)){
				printf("Descuentos aplicados con exito!!!\n");
				flag1 = 1;
			}
			else{
				printf("No se pudieron aplicar los descuentos...\n");
			}
			break;
		case 6:
			joaquin_getCaracter(&confirmar,"Esta seguro que quiere salir del programa? (s/n): ","ERROR!!! \n",'n','s',5);
			if(confirmar == 's'){
				option = 6;
			}
			break;
		}
	}while(option != 6);
	ll_deleteLinkedList(listaEmpleados);
	printf("Usted ha salido del programa...\n");
	return 0;
}


