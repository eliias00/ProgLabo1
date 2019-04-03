#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 3

int ingresarDatos(void);
int calcularPromedio(int acumulador,float cantidad,float *promedio);

int main()
{
    ingresarDatos();
    return 0;
}

int ingresarDatos(void)
{
    int flag=0;
    int numeros;
    int i;
    int acum=0;
    float promedio;
    int primer;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("ingrese 5 numeros: ");
        scanf("%d", &numeros);
        acum+=numeros;
        flag=1;
        if(flag==1)
        {
        primer=numeros
        if(primer>numeros)
        {
            printf("mayor: %d",primer);
        }
        if(primer<numeros)
        {
            printf("menor: %d",primer);
        }

        }
    }
      printf("menor: %d",primer);
    if (!calcularPromedio(acum,CANTIDAD,&promedio))
    {
        printf("promedio: %.2f", promedio);
    }
    else
    {
        printf("error");
    }
  //  calcularMaximoyMinimo(numeros);

    return 0;
}

int calcularPromedio(int acumulador,float cantidad,float *promedio)
{
    int retorno = -1;

    if(cantidad > 0 && promedio!= NULL)
    {
        *promedio=(float)acumulador/cantidad;

        retorno =0;
    }
    return retorno;

}

/*int calcularMaximoyMinimo(int numeros)
{
    int j;
    int flag=0;
    int primerValor;
    for(j=0;j<numeros;j++)
    {
        flag=1;
        primerValor=numeros;

    }
        if(primerValor>numeros)
        {
            printf("mayor:%d",primerValor);
        }
        if(primerValor<numeros)
        {
            printf("menor:%d",primerValor);
        }
   return 0;

}*/

