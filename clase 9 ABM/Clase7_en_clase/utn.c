#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define VACIO 1
#define LEN_LISTA  3



int isValidName(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno =-1;
    char bufferStr[4000];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
            else
            {
                printf("\n%s",msgError);
            }
            reintentos --;
        }while(reintentos>=0);
    }
    return retorno;
}
int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int inicializarArray(Empleado *array,int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        array[i].isEmpty=VACIO;

    }
    return 0;
}
int buscarLibre(Empleado *array,int len,int* pIndex)
{
    int i;
    int retorno=-1;
    for(i=0; i<len ; i++)
    {
        if(array[i].isEmpty==VACIO)
        {
            *pIndex = i;
             retorno=0;
             break;
        }
    }
    return retorno;
}
int buscarNombre(char* pNombre,Empleado auxEmpleado[],int len,int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(strcmp(pNombre,auxEmpleado[i].nombre)==0)
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;
}
