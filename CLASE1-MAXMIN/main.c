#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int ingresarDatos(void);
int calcularPromedio(int acumulador,float cantidad,float *promedio);
int main()
{
    ingresarDatos();
    return 0;
}

int ingresarDatos(void)
{
    int flag=1;
    int numeros;
    int i;
    int acum=0;
    float promedio;
    int primer;
    int mayor;
    int menor;
    for(i=0; i<CANTIDAD; i++)
    {
        printf("ingrese 5 numeros: ");
        scanf("%d", &numeros);
        acum+=numeros;
        if(flag==1)
        {
            mayor=numeros;
            menor=numeros;
            flag=0;
        }
        if(mayor<numeros)
        {
            mayor=numeros;
        }
        if(menor>numeros)
        {
            menor=numeros;
        }
    }
    printf("mayor: %d\n",mayor);
    printf("menor: %d\n",menor);
    if (!calcularPromedio(acum,CANTIDAD,&promedio))
    {
        printf("promedio: %.2f\n", promedio);
    }
    else
    {
        printf("error");
    }
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

