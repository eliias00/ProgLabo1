#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "autores.h"
#include "validaciones.h"
#define CAPACIDAD 3

int funcionMenu(void)
{
    int opcion;
    char seguir;
    int posLibre1;
    int posLibreLlam;
    int flag=0;

    Autores arrayAut[CAPACIDAD];

    inicializarArrayAuto(arrayAut,CAPACIDAD);

    //**********************************************
   /* strcpy(arrayAsociado[0].apellido,"troncoso");
    arrayAsociado[0].isEmpty=0;
    strcpy(arrayAsociado[0].nombre,"elias");
    arrayAsociado[0].dni=42367509 ;
    arrayAsociado[0].edad=19;
    arrayAsociado[0].id=0;
    //**********************************************
    strcpy(arrayAsociado[1].apellido,"perez");
    arrayAsociado[1].isEmpty=0;
    strcpy(arrayAsociado[1].nombre,"laura");
    arrayAsociado[1].dni=42456789 ;
    arrayAsociado[1].edad=21;
    arrayAsociado[1].id=1;*/
    //***********************************************
    do
    {
        printf(":::::::::::::::::::::::::::::::\n");
        printf(":          AUTORES            :\n");
        printf(": 1) NOMBRE      2)APELLIDO   :\n");
        printf(":::::::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("clear");
        switch(opcion)
        {
        case 1:
            if(!buscarElVacioAuto(arrayAut,CAPACIDAD,&posLibre1))
            {
                flag=1;
                switch(altaAutor(arrayAut,CAPACIDAD,posLibre1))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");
                    break;

                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            else
            {
                printf("lleno");
            }
            break;
        case 2:
            if(flag==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {
                modificacion(arrayAut,CAPACIDAD);
            }
            break;
        case 3:
            if(flag==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {
                baja(arrayAut,CAPACIDAD);
            }
            break;
        case 4:
               OrdenamientoAutor(arrayAut,CAPACIDAD);
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
          system("clear");
    }
    while(seguir =='s');
    return 0;
}
