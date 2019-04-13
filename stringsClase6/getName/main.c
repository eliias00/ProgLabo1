#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nombre.h"
#define CARACTERES 500

int main()
{
    char auxName[CARACTERES];
    if(!getName("ingrese nombre: ","error",2,5,2,auxName))
    {
        printf("\nok:%s",auxName);
    }
    else
    {
        printf("\nerror:%s",auxName);
    }
    return 0;
}
