#include <stdio.h>
#include <stdlib.h>
char isValid(char letra, char minimo1,char maximo1,char minimo2,char maximo2);
char getChar(char *mensaje,char *mensajeDeError,char minimoMin,char maximoMin,char minimoMay,char maximoM,char reintentos,char *respuesta);
int main()
{
    char respuesta;
    getChar("ingrese una letra:\n ","\nerror\n",97,122,65,90,3,&respuesta);

    return 0;
}
char isValid(char letra, char minimo1,char maximo1,char minimo2,char maximo2)
{
    if((letra>minimo1&&letra<maximo1) || (letra>minimo2&&letra<maximo2))
    {
        return 1;
    }
    return 0;

}
char getChar(char *mensaje,char *mensajeDeError,char minimoMin,char maximoMin,char minimoMay,char maximoM,char reintentos,char *respuesta)
{
    int retorno=-1;
    char buffer;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&buffer);
        if(isValid(buffer,minimoMin,maximoMin,minimoMay,maximoM))
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
