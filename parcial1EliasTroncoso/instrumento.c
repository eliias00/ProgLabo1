#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#define LLENO 1
#define VACIO -1

static int generarIdInstrumento(void)
{
    static int id=0;
    return id++;
}
int inicializarArrayIns(Instrumento *array, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        array[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioIns(Instrumento *array,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaIns(Instrumento *array,int cant,int posLibre)
{
    int ret;
    char tipAux[50];
    int auxTip;
    if (!getName(array[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
        if(!getInt("ingrese el tipo:\n1:CUERDAS\n2:VIENTO-MADERA\n3:VIENTO-METAL\n4:PERCUSION: ","\nerror,vuelva a intentar",1,4,1,tipAux))
        {
            auxTip=atoi(tipAux);
            array[posLibre].tipo=auxTip;
            array[posLibre].id=generarIdInstrumento();
            printf("id:%d",array[posLibre].id);
            array[posLibre].isEmpty=LLENO;
            ret=0;
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}
int buscaIdInst (Instrumento *array, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Instrumento auxI;
    printf("\ningrese id de instrumento a buscar: ");
    scanf("%d", &auxI.id);
    for(i=0; i < cant; i++)
    {
        if (array[i].id == auxI.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
void imprimirInstrumento(Instrumento *array,int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            if(array[i].tipo==1)
            {
                printf("nombre:%s cuerdas:%d id:%d\n",array[i].nombre,array[i].tipo,array[i].id);
            }
            if(array[i].tipo==2)
            {
                printf("nombre:%s viento-madera:%d id:%d\n",array[i].nombre,array[i].tipo,array[i].id);
            }
            if(array[i].tipo==3)
            {
                printf("nombre:%s viento-metal:%d id:%d\n",array[i].nombre,array[i].tipo,array[i].id);
            }
            if(array[i].tipo==4)
            {
                printf("nombre:%s percusion:%d id:%d\n",array[i].nombre,array[i].tipo,array[i].id);
            }
        }
    }
}
