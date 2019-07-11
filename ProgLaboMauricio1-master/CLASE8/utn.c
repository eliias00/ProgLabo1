#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"

void functionMenu(sEmpleados array [])
{
    int opcion;
    char seguir;
    int flag=0;

    do
    {
        printf(":::::::::::::::::::::::::::\n");
        printf(": 1) ALTAS    2)MODIFICAR :\n");
        printf(": 3) BAJA     4)INFORMAR  :\n");
        printf(":::::::::::::::::::::::::::\n");

        printf("elija una opcion: ");
        scanf("%d", & opcion);
        switch(opcion)
        {
        case 1:
            //  flag=1;
            if(!buscarEspacioArray(array,EMPLEADOS))
            {
                getName("ingrese nombre: ","Reingrese el nombre:",1,20,5,array);
            }
            else
            {
                printf("no hay lugar");
            }
            break;

        case 2:

         //   funcionMostrarArray(array,EMPLEADOS);
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system ("clear");
    }
    while(seguir =='s');
}



int inicializarArray(sEmpleados array[],int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        array[i].isEmpty=VACIO;
        printf("%d",array[i].isEmpty);
    }
    return 0;
}
int buscarEspacioArray(sEmpleados array[],int limite)
{
    int retorno;
    int i;
    int aux=VACIO;

    for(i=0; i<limite; i++)
    {
        if(array[i].isEmpty==VACIO)
        {
             aux=i;
             retorno=0;
             break;
        }
        else
        {
            retorno =-1;
        }
    }
    return retorno;
}
/*int funcionMostrarArray(sEmpleados array[],int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(!strcmp(array[i], "\0")==0)
        {
            printf("\narray:%s",array[i]);
        }
    }


    return 0;
}*/
