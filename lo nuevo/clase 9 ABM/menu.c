#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "menu.h"
#define LEN_LISTA  3

int menu(void)
{
    char opcion;
    int i;
    int posLibre;
    int posAeliminar;
    char buffer[20];
    int cont=0;
    char seguir;
    int j;

    Empleado auxEmpleado[LEN_LISTA];

    inicializarArray(auxEmpleado,LEN_LISTA);

    do
    {
        printf("\n1)ingresar\n2)listar\n4)eliminar");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            if(!buscarLibre(auxEmpleado,LEN_LISTA,&posLibre))
            {
             //   Alta(auxEmpleado,LEN_LISTA,posLibre);


                switch (Alta(auxEmpleado,LEN_LISTA,posLibre))
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
        }
            /*  case 4:
              {
                  // PIDO NOMBRE
                  //utn_getString(buffer,...)
                  fgets(buffer,20,stdin);
                  buffer[strlen(buffer)-1]='\0';

                  // en buffer esta el nombre
                  buscarNombre(buffer,auxEmpleado.nombre,LEN_LISTA,&posAeliminar);

                  // borro
                //  nombres[posAeliminar][0]='\0';

                  break;
              }*/
        }

        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
    }
    while(seguir =='s');

    for(i=0; i<LEN_LISTA; i++)
    {

        printf(":%s",auxEmpleado[i].nombre);
    }

}



