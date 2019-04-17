#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];


    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}*/
int inicializarArray(char array [][20],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
       strncpy(array[i],"\0", 20);
    //  printf(":%s",array[i]);

    }
    return 0;
}
int buscarEspacioArray(char array [][20],int cant)
{
    int retorno;
    int j;
    for(j=0;j<cant;j++)
    {

        if(strcmp(array[j], "\0")==0)
        {
          //  strncpy(array[j],"a", 20);

          retorno=0;
         //   break;
        }
        else
        {
            retorno =-1;
        }

    }
      return retorno;
}
int agregarNombre(char array[][20],int cant)
{
    if(!buscarEspacioArray(array,cant))
    {
        printf("hay lugar");

    }
    else
    {

     printf("no hay lugar");
    }
return 0;
}


/*int funcionMostrarArray( char array[][20],int cant,char aux)
{
    int i;

    if (!buscarEspacioArray(array[][20],cant,aux))
    {
       for(i=0; i<cant; i++)
       {
        printf("%s",array[i]);
       }
    }

    return 0;
}*/
