#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxFloat;
    char auxChar;
    char aux[15]="hoal";

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Emp_setPeso(pArrayEmpleado[indiceActual],14))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual], &auxFloat);
            printf("\n El peso es %f",auxFloat);

        }
         if(!Emp_setNombre(pArrayEmpleado[indiceActual],&aux))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual], auxChar);
            printf("\n El id es %s",auxChar);

        }


    }


    return 0;
}
