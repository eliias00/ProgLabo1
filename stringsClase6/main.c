#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nombre.h"
#include <ctype.h>
#define NOMBRE 20
#define BUFFER 20

int main()
{
     char nombre[NOMBRE];


     getNumber("ingrese numeros: ","error",1,9,3,nombre);

    /*    strncpy(nombre,nombre2,sizeof(nombre));

        printf("\n%s",nombre);

        fgets(nombre,sizeof(nombre),stdin);

        printf("\n%s",nombre);

        strlen();
        strcmp();

    */
    return 0;
}
