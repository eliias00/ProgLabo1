#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "generico.h"
#include "valid.h"

int main()
{

    LinkedList* lista = ll_newLinkedList();
    int option;
    char nombre[128];
    char *path;

    printf("ingrese nombre de archivo: ");
    scanf("%s",nombre);
    do
    {
        printf("\n1. Cargar archivo");
        printf("\n2. imprimir partidas");
        printf("\n3. imprimir partidas");
        printf("\n4. genera arch nuevo");
        printf("\n4. salir");


        printf("\ningrese opcion: ");
        scanf("%d",&option);
        system("clear");
        switch(option)
        {
        case 1:
            controller_loadFromText(nombre,lista);
            printf("se ha cargado data.csv(txt)\n");

            break;
          case 2:
                  imprimirPartida(lista);
              break;
         case 3:
                imprimirProm(lista);
              break;
        case 4:
             if(!ll_map(lista,controller_costos))
                {
                 controller_saveAsText(lista);
                 }
            break;

        }
    }
    while(option != 4);
    return 0;
}
