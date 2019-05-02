#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"
#define LLENO  1
#define VACIO -1

int inicializarArray(Pantalla *auxPantalla, int cant)
{
    int ret;
    int i;
    for (i=0; i<cant; i++)
    {
        auxPantalla[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarLibre(Pantalla *auxPantalla, int cant, int *indice)
{
    int ret;
    int i;
    for (i=0; i<cant; i++)
    {
        if (auxPantalla[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int Alta(Pantalla *auxPantalla, int cant, int posLibre,int id)
{
    int i;
    int ret=1;
    if (!getName(auxPantalla[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
    {
        if (!getDireccion(auxPantalla[posLibre].direccion,"Ingrese la direccion: ","error, vuelva a intentar\n\n",2,20,1))
        {
            if (!getFloat("ingrese un precio: ","error,vuelva a intentar",0,10,1,&auxPantalla[posLibre].precio))
            {
                if(!getInt("ingrese un tipo:\n1=LCD\n2=LED\n:","\nerror,vuelva a intentar",1,2,1,&auxPantalla[posLibre].tipo))
                {
                    auxPantalla[posLibre].isEmpty=0;
                    ret=0;
                    auxPantalla[posLibre].id=id;
                }
            }
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}
int modificarPantalla(Pantalla *auxPantalla, int cant)
{
    int ret=-1;
    int i ;
    int opcion;
    int posPantalla;
    char modificacion;

    if(!buscarPantalla(auxPantalla,cant,&posPantalla))
        {
                do
                {
                    printf("-----------------\n");
                    printf("-1) NOMBRE      -\n");
                    printf("-2) DIRECCION   -\n");
                    printf("-3) PRECIO      -\n");
                    printf("-----------------\n");
                    printf("ingrese el campo a modificar: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        getName(auxPantalla[posPantalla].nombre,"ingrese el nuevo nombre: ","Vuelva a ingresar",2,20,1);
                        break;
                    case 2:
                        getName(auxPantalla[posPantalla].direccion,"Ingrese la nueva direccion:","error, vuelva a intentar\n",2,20,1);
                        break;
                    case 3:
                        getFloat("ingrese un nuevo precio: ","error,vuelva a intentar",0,10,1,&auxPantalla[posPantalla].precio);
                        break;
                    case 4:
                        getInt("ingrese un nuevo tipo:\n1=LCD\n2=LED\n:","\nerror,vuelva a intentar",1,2,1,&auxPantalla[posPantalla].tipo);
                        break;
                    }
                    printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                    modificacion=getch();
                    system("cls");
                }while(modificacion=='s');
                ret=0;
        }
    return ret;
}
int buscarPantalla (Pantalla *auxPantalla, int cant, int *pantallaEncontrada)
{
    int i;
    int retorno = 1;
    Pantalla auxPantalla2;
    printf("\ningrese id a buscar: ");
    scanf("%d", &auxPantalla2.id);
    {
        for(i=0; i < cant; i++)
        {
            if (auxPantalla[i].id == auxPantalla2.id)
            {
                retorno=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return retorno;
}
int pantallaBaja(Pantalla *auxPantalla, int cant)
{
    int posPanBaja;
    char resp;

    if(!buscarPantalla(auxPantalla,cant,&posPanBaja)&&auxPantalla[posPanBaja].isEmpty!=VACIO)
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n");
        scanf("%s",&resp);
        if(resp=='s')
        {   printf("se ah dado de baja esta pantalla");
            auxPantalla[posPanBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
void listarPantallas(Pantalla *auxPantalla,int cant)
{
    int i;
     for(i=0; i<cant; i++)
                {
                    if(auxPantalla[i].isEmpty!=VACIO)
                    {
                        printf("\nid:%d",auxPantalla[i].id);
                        printf("\nnombre:%s",auxPantalla[i].nombre);
                        printf("\ndireccion:%s",auxPantalla[i].direccion);
                        printf("\nprecio:%f",auxPantalla[i].precio);
                        printf("\ntipo:%d",auxPantalla[i].tipo);
                    }
                }

}
