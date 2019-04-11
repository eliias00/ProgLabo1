#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NOMBRE 20
#define BUFFER 20

int isValidNumber(char *stri)
{
     if(isdigit(stri))
    {
        return 1;
    }
    return 0;
}
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado)
{
   ??????


    strncpy(resultado,"1234",5);
    return 0;
}
int getNumber(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    int retorno =-1;
    char buffer [18];
    int bufferInt;
    printf("%s",msg);

    if( msg != NULL && msgError != NULL && resultado != NULL && reintentos >=0 && maximo >= minimo)
    {
        if(getString(msg,msgError,1,16,reintentos,buffer))
        {
            if(isValidNumber(buffer))
            {
                 bufferInt = atoi(buffer);
                if(bufferInt >= minimo && bufferInt <= maximo)
                {
                    *resultado = bufferInt;
                    retorno=0;
                }
            }
            else
            {
                printf("%s",msgError);
            }
        }
    }
    return retorno;
}
