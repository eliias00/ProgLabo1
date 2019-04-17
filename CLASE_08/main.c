#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

///dejar el ABM echo
/// ordenarlo

int main()
{
//    char auxName[500] = "test";

    char arrayNombres[QTY_EMPLEADOS][20];


  //  funcionMostrarArray(arrayNombres,3);

inicializarArray(arrayNombres,QTY_EMPLEADOS);
buscarEspacioArray(arrayNombres,QTY_EMPLEADOS);
  agregarNombre(arrayNombres,QTY_EMPLEADOS);
    /*if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }*/
    return 0;
}
