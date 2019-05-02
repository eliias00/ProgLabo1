#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apellido.h"
#define CARACTERES 500

int main()
{
    char auxSurname[CARACTERES];
    if(!getSurname("ingrese apellido: ","error,vuelva a ingresar",2,10,3,auxSurname))
    {
        printf("\nok:%s",auxSurname);
    }
    else
    {
        printf("\nerror%s",auxSurname);
    }
    return 0;
}
