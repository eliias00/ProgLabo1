#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "menu.h"
#include "publicidad.h"
#define LEN_LISTA  5
#define PUBLICIDADES 10
#define VACIO -1

int menu(void)
{
    char opcion;
    int i;
    int posLibrePan;
    int posLibrePub;
    char seguir;
    int flag=0;
    int id=0;
    int id2=0;

    Pantalla auxPantalla[LEN_LISTA];
    Publicidad auxPublicidad[LEN_LISTA];

    inicializarArray(auxPantalla,LEN_LISTA);
    pubInicializarArray(auxPublicidad,LEN_LISTA);
    do
    {
        printf("\n1)ALTA\n2)MODIFICACION\n3)LISTAR\n4)BAJA");
        printf("\n******************************************");
        printf("\n5)ALTA PUB\n6)MODIFICACION PUB\n7)BAJA PUB");
        printf("\ningrese una opcion: ");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            if(!buscarLibre(auxPantalla,LEN_LISTA,&posLibrePan))
            {
                flag=1;
                switch (Alta(auxPantalla,LEN_LISTA,posLibrePan,id))
                {
                    case 0:
                    printf("dato ingresado correctamente\n\n");
                    id++;
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
            if(flag==1)
            {
                modificarPantalla(auxPantalla,LEN_LISTA);
            }
            else
            {
                printf("haga un alta primero");
            }
            break;
        case 3:
            if(flag==1)
            {
                listarPantallas(auxPantalla,LEN_LISTA);
            }
            else
            {
                printf("haga un alta primero");
            }
            break;
        case 4:
            if(flag==1)
            {
                pantallaBaja(auxPantalla,LEN_LISTA);
            }
            else
            {
                printf("haga un alta primero");
            }
            break;
            case 5:
            if(!pubBuscarLibre(auxPublicidad,LEN_LISTA,&posLibrePub))
            {
                //flag=1;
                switch (pubAlta(auxPantalla,auxPublicidad,LEN_LISTA,posLibrePub,id2))
                {
                    case 0:
                    printf("dato ingresado correctamente\n\n");
                    id2++;
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
            case 6:
            pubModificarPantalla(auxPantalla,auxPublicidad,LEN_LISTA);
            break;
            case 7:
            pubBajaPublicidad(auxPantalla,auxPublicidad,LEN_LISTA,posLibrePub);
            break;

        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
    }
    while(seguir =='s');
}
