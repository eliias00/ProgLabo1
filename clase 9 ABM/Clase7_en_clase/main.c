#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define VACIO 1
#define LEN_LISTA  3

int main()
{
  /// empleado *auxliarEmpleado;
 ///  auxliarEmpleado-> PARA ACCEDER AL ARRAY


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
        scanf("%s",&opcion);
        switch(opcion)
        {
            case 1:
            {
                if(!buscarLibre(auxEmpleado,LEN_LISTA,&posLibre))
                {   printf("netre");
                    getName(&opcion,"\n1)ingresar\n2)listar\n4)eliminar","NO!",1,10,3);
                    printf("1.se encontro lugar en %d\n",posLibre);
                    //utn_getString(buffer,"Ingrese:","No!",0,20,1);
                    fgets(buffer,20,stdin);
                    printf("se ingreso:%s\n",buffer);
                    printf("2. se encontro lugar en %d\n",posLibre);
                    //nombres[posLibre] = buffer;


                       strncpy(auxEmpleado[0].nombre,buffer,20);
                       strncpy(auxEmpleado[1].nombre,buffer,20);


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
    }while(seguir =='s');

    for(j=0;j<LEN_LISTA;j++)
    {
        if(auxEmpleado[j].isEmpty==VACIO)
        {
            printf(":%s",auxEmpleado[j].nombre);
        }
    }

    return 0;
}



