#include <stdio.h>
#include <stdlib.h>
float getFloat(char *mensaje,char *mensajeDeError,float maximo,float minimo,float reintentos,float *resultado);
int main()
{
    float numero;
    getFloat("\nINGRESE UN NUMERO: ","\nERROR",10.00,0.00,3.00,&numero);
    return 0;
}
float isValidFloat(float numero,float minimo,float maximo)
{
    if(numero<=maximo&&numero>=minimo)
    {
        return 1;
    }
    return 0;

}
float getFloat(char *mensaje,char *mensajeDeError,float maximo,float minimo,float reintentos,float *resultado)
{
    float baffer;
    float retorno=-1;
    if(mensaje!=NULL&&mensajeDeError!=NULL&&maximo>=minimo&&reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&baffer);
            if(isValidFloat(baffer,minimo,maximo))
            {
                *resultado=baffer;
                retorno=0;
                break;
            }
            else
            {
             printf("%s",mensajeDeError);

            }
            reintentos--;
        }
        while(reintentos>=0);
    }
        return retorno;
}
