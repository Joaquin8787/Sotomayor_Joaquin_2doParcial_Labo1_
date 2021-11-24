int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_sortlibro(LinkedList* pListaLibros);

int buscarEmpleadoId(int* idABuscar, LinkedList* pArrayListEmployee,int tam);
int controller_ll_map(char* path , LinkedList* pListaLibros);
int controller_Listlibro(LinkedList* pListaLibros);

