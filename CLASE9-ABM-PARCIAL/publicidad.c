#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"
#include "publicidad.h"
#define LLENO  1
#define VACIO -1

int pubInicializarArray(Publicidad *auxPublicidad, int cant)
{
    int ret;
    int i;
    for (i=0; i<cant; i++)
    {
        auxPublicidad[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int pubBuscarLibre(Publicidad *auxPublicidad, int cant, int *indice)
{
    int ret;
    int i;
    for (i=0; i<cant; i++)
    {
        if (auxPublicidad[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int pubAlta(Pantalla *auxPantalla,Publicidad *auxPublicidad, int cant, int posLibrePub,int id2)
{
    int i;
    int ret=1;
    int posPantalla;
    printf("pantallas disponibles: ");
    listarPantallas(auxPantalla,cant);
    if(!buscarPantalla(auxPantalla,cant,&posPantalla))
    {
        if (!getCuit(&auxPublicidad[posLibrePub].cuit,"ingrese cuit(ingrese los 11 digitos seguidos):","error,vuelva a intentar",11,12,1))
        {
            if (!getDias(&auxPublicidad[posLibrePub].cantDias,"ingrese los dias de publicacion: ","error,vuelva a intentar",0,10,1))
            {
                if (!getDireccion(auxPublicidad[posLibrePub].nombArch,"Ingrese la nombre de arch:","error, vuelva a intentar\n\n",2,20,1))
                {
                    auxPublicidad[posLibrePub].isEmpty=0;
                    ret=0;
                    auxPublicidad[posLibrePub].id=id2;
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
/*int buscarCuit (Publicidad *auxPublicidad, int cant, int *cuitEncontrado)
{
    int i;
    int retorno = 1;
    Publicidad auxPub;
    printf("ingrese cuit a buscar: ");
    scanf("%d", &auxPub.cuit);
    {
        for(i=0; i < cant; i++)
        {
            if (auxPublicidad[i].cuit == auxPub.cuit)
            {
                retorno=0;
                *cuitEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}*/
int pubModificarPantalla(Pantalla *auxPantalla,Publicidad *auxPublicidad, int cant,int posLibrePub)
{
    int ret=-1;
    int i ;
    int posPublicidad;
    Publicidad auxPub;

    printf("ingrese cuit a buscar: ");
    scanf("%d", &auxPub.cuit);

    for(i=0; i<cant; i++)
    {
        if(auxPublicidad[i].cuit==auxPub.cuit && auxPublicidad!=VACIO)
        {
        printf("\nnombre: %s\ndireccion: %s\nid: %d\nprecio: %f\ntipo: %d",auxPantalla[i].nombre,auxPantalla[i].direccion,auxPantalla[i].id,auxPantalla[i].precio,auxPantalla[i].tipo);

        }
    }
     if(!buscarPantalla(auxPublicidad,cant,&posPublicidad))
     {
         getDias(&auxPublicidad[posLibrePub].cantDias,"ingrese los nuevos dias de publicacion: ","error,vuelva a intentar",0,10,1);

     }
    return 0;
}
int pubBajaPublicidad(Pantalla *auxPantalla,Publicidad *auxPublicidad, int cant,int posLibrePub)
{
    int ret=-1;
    int i ;
    int posPublicidad;
    char resp;
    int posPubBaja;
    Publicidad auxPub;

    printf("ingrese cuit a buscar: ");
    scanf("%d", &auxPub.cuit);

    for(i=0; i<cant; i++)
    {
        if(auxPublicidad[i].cuit==auxPub.cuit && auxPublicidad!=VACIO)
        {
        printf("\nnombre: %s\ndireccion: %s\nid: %d\nprecio: %f\ntipo: %d",auxPantalla[i].nombre,auxPantalla[i].direccion,auxPantalla[i].id,auxPantalla[i].precio,auxPantalla[i].tipo);
        }
    }
     if(!buscarPantalla(auxPublicidad,cant,&posPublicidad))
     {
        printf("esta seguro que quiere dar de baja ese id: \n s|n");
        scanf("%s",&resp);
        if(resp=='s')
        {   printf("se ah dado de baja esta publicidad");
            auxPublicidad[posPubBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
     }
    return 0;
}















