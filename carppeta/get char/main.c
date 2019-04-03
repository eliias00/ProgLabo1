#include <stdio.h>
#include <stdlib.h>
char isValid(char letra, char minimo,char maximo);
char getChar(char *mensaje,char *mensajeDeError,char maximo,char minimo,char reintentos,char *respuesta);
int main()
{
    char respuesta;
    getChar("ingrese una letra: ","error",122,97,3,&respuesta);

    return 0;
}
char isValid(char letra, char minimo,char maximo)
{
    if(letra<minimoletra>maximo)
    {
        return 1;
    }
    return 0;

}
char getChar(char *mensaje,char *mensajeDeError,char maximo,char minimo,char reintentos,char *respuesta)
{
    int retorno=-1;
    char buffer;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&buffer);
        if(isValid(buffer,minimo,maximo))
        {
            *respuesta=buffer;
            retorno=0;
            break;
        }
        else
        {
            printf("%s",mensajeDeError);
        }







        reintentos --;
    }
    while(reintentos>=0);
    return retorno;

}
