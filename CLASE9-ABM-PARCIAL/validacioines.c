#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"

int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno =-1;
    char bufferStr[4000];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
            fflush(stdin);
            scanf("%s",&bufferStr);
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
        }while(reintentos>0);
    }
    return retorno;
}
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
int isValidDireccion(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getDireccion(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidDireccion(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}
int isValidFloat(char* cadena)
{
    int retorno = 1;
    int i;
    float buffer;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' && cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getFloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{
    int retorno = -1;
    char bufferStr [4096];
    float buffer;
     if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidFloat(bufferStr))
            {
                 buffer = atof(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}
int isValidint(char* cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' && cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int retorno = -1;
    char bufferStr [4096];
    int buffer;
     if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidint(bufferStr))
            {
                buffer = atoi(bufferStr);
                if(buffer== 2 || buffer==1)
                {
                *resultado = buffer;
                retorno = 0;
                }
                else
                {
                    printf("error de tipo");
                }
            }
        }
    }
    return retorno;
}
int isValidCuit(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' && cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getCuit(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    int buffer;
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidCuit(bufferStr))
            {
                buffer=atoi(bufferStr);
                *resultado=buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}
int isValidDias(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' && cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getDias(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    int buffer;
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidDias(bufferStr))
            {
                buffer=atoi(bufferStr);
                *resultado=buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}
