#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main()
{
    Persona *pArrayPersona[1000];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    int auxEstado;

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Emp_new();


    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if(!Emp_setId(pArrayPersona[indiceActual],14))
        {
            Emp_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
         if(!Emp_setNombre(pArrayPersona[indiceActual],"elias"))
        {
            Emp_getNombre(pArrayPersona[indiceActual], aux);
            printf("\n El nombre es %s",aux);

        }
        if(!Emp_setApellido(pArrayPersona[indiceActual],"troncoso"))
        {
            Emp_getApellido(pArrayPersona[indiceActual], aux1);
            printf("\n El nombre es %s",aux1);

        }
        if(!Emp_setEstado(pArrayPersona[indiceActual],1))
        {
            Emp_getEstado(pArrayPersona[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);

        }

    }


    return 0;
}
