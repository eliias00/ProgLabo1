#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
int isValidInt(int numero,int minimo,int maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return 0;
}
int getInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *resultado)
{
    int buffer;
    int retorno =-1;
    if( mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos >=0 && maximo >= minimo)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",& buffer);
            if (isValidInt(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);

    }

    return 0;
}
int getArrayInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *arrayResultado,int limite)
{
    int i;
    int retorno =-1;
    int bufferEdades;
    if( mensaje != NULL && mensajeError != NULL && arrayResultado != NULL && reintentos >=0 && maximo >= minimo)
    {
        for(i=0; i<limite; i++)
        {
            if(getInt(mensaje,mensajeError,minimo,maximo,reintentos,&bufferEdades)==0)
            {
                *(arrayResultado + i) = bufferEdades;
            }
            else
            {
                break;
            }
        }
    }
}
/*void mostrarArray(int *arrayResultado,int limite)
{
    int j;
    for(j=0; j<limite; j++)
    {
        printf("array: %d\n",arrayResultado[j]);
    }
}*/
void acomodamientoArray(int *arrayResultado,int limite)
{
    int j;
    int k;
    int flagSwap;
    int auxiliarSwap;
    do
    {
        flagSwap=0;
        for(k=0; k<limite-1; k++)
        {
            if(arrayResultado[k]>arrayResultado[k+1])
            {
                auxiliarSwap=arrayResultado[k];
               arrayResultado[k]=arrayResultado[k+1];
                arrayResultado[k+1]=auxiliarSwap;
                flagSwap=1;

            }


        }
    }while(flagSwap==0);

    for(j=0; j<limite;j++)
    {
        printf("array: %d\n",arrayResultado[j]);
    }



}

