#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"

#define VACIO -1

int inicializarArray(Empleado *auxEmpleado, int cant)
{
    int ret;
    int i;
    for (i=0; i<cant;i++)
    {
        auxEmpleado[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
/*void empleado_mostrarArray(Empleado* empleados, int cantidad)
{

    for (int i=0; i<cantidad;i++)
    {
        if(empleados[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, empleados[i].isEmpty);
            printf("posicion %d :nombre %s\n", i, empleados[i].nombre);
            printf("posicion %d :apellido %s\n", i, empleados[i].apellido);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}
*/
int buscarLibre(Empleado *auxEmpleado, int cant, int *indice)
{
    int ret;
    int i;
    for (i=0; i<cant;i++)
    {
        if (auxEmpleado[i].isEmpty==VACIO)
        {
            *indice=i;
             ret=0;
             break;
        }
            ret=-1;
    }
    return ret;
}
int Alta(Empleado *auxEmpleado, int cant, int posLibre)
{
    int ret=1;
    if (!getName(auxEmpleado[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
    {
//        if (!getString(empleados[posLibre].apellido,"Ingrese el apellido:","error, vuelva a intentar\n\n",2,20,2))
 //       {
            auxEmpleado[posLibre].isEmpty=0;
            ret=0;
  /*      }
        else
        {
            ret=1;
        }*/
    }

    return ret;
}

int empleado_buscarEnArray (Empleado* empleados, int cantidad, int* empleadoEncontrado)
{
    int ret=1;
    Empleado auxEmpleados;

    if (getString(auxEmpleados.nombre,"ingrese el nombre del empleado que quiera eliminar: ","Vuelva a ingresar",2,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        ret=-1;
        for(int i=0;i<cantidad;i++)
        {
            //empleados[i].nombre=tolower(empleados[i].nombre);
            if (strcmp(empleados[i].nombre, auxEmpleados.nombre)==0)
            {
                ret=0;
                *empleadoEncontrado=i;
                break;
            }
        }
    }
    return ret;
}

int empleado_baja(Empleado* empleados, int cantidad)
{

    int posEmpleado;
    switch (empleado_buscarEnArray(empleados, cantidad,&posEmpleado))
    {
    case 0:
        if (empleados[posEmpleado].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            empleados[posEmpleado].isEmpty=1;
            printf("El empleado borrado es: %s\n\n",empleados[posEmpleado].nombre);

        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}
