#include <stdio.h>
#include <stdlib.h>
#include "edad.h"
#define EDAD 20
int main()
{
    int edad[EDAD];
    if (!getAge("ingrese edad: ","error, vuelva a ingresar edad",1,10,3,edad))
    {
        printf("\nsu edad es: %d", edad);
    }
    else
    {
        printf("\nerror %d",edad);
    }
    return 0;
}
