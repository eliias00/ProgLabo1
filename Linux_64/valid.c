#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno =-1;
    char bufferStr[400];
    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
           __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s",msgError);
            }
            reintentos --;
        }
        while(reintentos>0);
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
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidName(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                    break;
                }
                else
                {

                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}
int isValidFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]<'0' || pStr[i]>'9')&&(pStr[i]!='.'))
        {

            return 0;
        }
        if(pStr[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int getFloat(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr)&&(isValidFloat(bufferStr)))
        {
            strncpy(resultado,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf("%s",mensajeError);
            retorno=-1;
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
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
   char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr)&&(resultado!=NULL)&&(isValidint(bufferStr)))
        {
            strncpy(resultado,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf("%s",mensajeError);
            retorno=-1;
        }
    }
    return retorno;
}
int isValidSexo(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] != 'm' && cadena[i] != 'f') && (cadena[i] != 'M' && cadena[i] != 'F'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getSexo(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidSexo(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                    break;
                }
                else
                {

                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}
int isValidMail(char str[]){

    int i=0;
    int contadorArroba=0;
    int contadorPuntos=0;
    while(str[i] != '\0'){

        if(str[i] == '@'){
            contadorArroba++;
        }
        if(str[i] == '.'){
            contadorPuntos++;
        }
        i++;
    }
    if(contadorArroba==1 && contadorPuntos!=0)
    {
        return 1;
    }
    return 0;
}
int getEmail(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidMail(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                    break;
                }
                else
                {

                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}
int isValidDia(char cadena[])
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getDia(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    int bufferInt;
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidDia(bufferStr))
                {
                    bufferInt=atoi(bufferStr);

                    if(bufferInt < 1  || bufferInt >31)
                    {
                        printf("error de dia");
                    }
                    else
                    {
                    *resultado=bufferInt;
                    retorno = 0;
                    break;
                    }
                }
                else
                {
                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}
int getMes(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    int bufferInt;
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidDia(bufferStr))
                {
                    bufferInt=atoi(bufferStr);

                    if(bufferInt < 1  || bufferInt >12)
                    {
                        printf("error de mes");
                    }
                    else
                    {
                    *resultado=bufferInt;
                    retorno = 0;
                    break;
                    }
                }
                else
                {
                printf("%s",msgError);
                }
            }
        }
    }
    return retorno;
}
int getAnio(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char bufferStr[4000];
    int bufferInt;
    while(retorno ==-1)
    {
        if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidDia(bufferStr))
                {
                    bufferInt=atoi(bufferStr);

                    if(bufferInt < 2019 || bufferInt > 2100)
                    {
                        printf("error de anio");
                    }
                    else
                    {
                    *resultado=bufferInt;
                    retorno = 0;
                    break;
                    }
                }
                else
                {
                printf("%s",msgError);
                }
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
