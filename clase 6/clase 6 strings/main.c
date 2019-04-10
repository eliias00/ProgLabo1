#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nombre.h"
#define NOMBRE 20
#define BUFFER 20

int main()
{
     char nombre[NOMBRE];
     char nombreValidar[BUFFER];

     muestroNombre(nombre, nombreValidar);

    /*    strncpy(nombre,nombre2,sizeof(nombre));

        printf("\n%s",nombre);

        fgets(nombre,sizeof(nombre),stdin);

        printf("\n%s",nombre);

        strlen();
        strcmp();

    */
    return 0;
}
