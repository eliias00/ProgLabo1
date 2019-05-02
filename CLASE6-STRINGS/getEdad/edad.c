#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidAge (char* cadena)
{
    int retorno = 0;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            retorno= -1;
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
                break;
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
int getAge(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    int retorno= -1;
    char bufferStr[4000];
    int bufferInt;

    if(msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(!isValidAge(bufferStr))
            {
                bufferInt = atoi(bufferStr);
               if(bufferInt >= minimo && bufferInt <= maximo)
                {
                    *resultado = bufferInt;
                    retorno = 0;
                    printf("r%d",resultado);
                }

            }
        }
    }
    return retorno;
}
