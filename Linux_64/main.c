#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
         printf("\ningrese opcion: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                printf("se ha cargado data.csv(txt)");
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                printf("se ha cargado data.csv(binario)");
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                 controller_editEmployee(listaEmpleados);
                break;
            case 6:
                 controller_saveAsBinary("data.csv", listaEmpleados);
                break;
            case 7:
                controller_loadFromText("data.csv", listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
