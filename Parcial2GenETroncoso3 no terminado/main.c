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

  /*  printf("ingrese nombre de archivo: ");
    scanf("%s",nombre);*/
    do
    {
        printf("\n1. Cargar archivo");
        printf("\n2. imprimir envios");
        printf("\n3. generar archivo");
        printf("\n4. salir");


        printf("\ningrese opcion: ");
        scanf("%d",&option);
        system("clear");
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",lista);
            printf("se ha cargado data.csv(txt)\n");

            break;
          case 2:
                  imprimirTipo(lista);
              break;
         case 3:
              if(!ll_map(lista,controller_aumentoPorKilometros))
                {
                controller_saveAsText("salida.csv",lista);
                }
              break;
        case 4:

            break;

        }
    }
    while(option != 4);
    return 0;
}
