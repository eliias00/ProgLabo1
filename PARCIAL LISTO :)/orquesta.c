#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#define VACIO -1
#define LLENO 1

static int generarIdOrquesta(void)
{
    static int id=0;
    return id++;
}
int inicializarArrayOrquesta(Orquesta *arrayOrquesta, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayOrquesta[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioOrquesta(Orquesta *arrayOrquesta,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayOrquesta[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaOrquesta(Orquesta *arrayOrquesta,int cant,int posLibre)
{
    int ret;
    char tipAut[50];
    int auxTip;
    if (!getName(arrayOrquesta[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
        if (!getDireccion(arrayOrquesta[posLibre].lugar,"ingrese un lugar: ","error, vuelva a ingresar\n\n",5,51,1))
        {
            if(!getInt("ingrese el tipo:\n1:sinfonica\n2:filarmonica\n3:camara: ","\nerror,vuelva a intentar",1,4,1,tipAut))
            {
                auxTip=atoi(tipAut);
                arrayOrquesta[posLibre].tipo=auxTip;
                arrayOrquesta[posLibre].id=generarIdOrquesta();
                printf("el id: %d",arrayOrquesta[posLibre].id);
                arrayOrquesta[posLibre].isEmpty=LLENO;
                ret=0;
            }
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}
int buscaIdOrquesta (Orquesta *array, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Orquesta auxOrc;
    printf("\ningrese id de orquesta a buscar: ");
    scanf("%d", &auxOrc.id);
    for(i=0; i < cant; i++)
    {
        if (array[i].id == auxOrc.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
void imprimirOrquestas(Orquesta *array, int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre:%s lugar:%s tipo:%d\n",array[i].nombre,array[i].lugar,array[i].tipo);
        }
    }
}
