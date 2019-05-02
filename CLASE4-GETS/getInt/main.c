#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *resultado);
int isValidInt(int numero,int minimo,int maximo);
int main()
{
    int numero;
    getInt("\nINGRESE NUMERO: ","\nERROR",1,9,3,&numero);
    return 0;
}
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
    int baffer;
    int retorno =-1;
    if( mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos >=0 && maximo >= minimo)
    {
        do{
        printf("%s",mensaje);
            scanf("%d",& baffer);
            if (isValidInt(baffer,minimo,maximo))
            {
                *resultado=baffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
               reintentos--;
          }while(reintentos>=0);

    }

    return 0;
}
