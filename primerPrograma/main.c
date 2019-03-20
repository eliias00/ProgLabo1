#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
int ingresarDatos(void);

int main()
{
    ingresarDatos();
      return 0;
}
int ingresarDatos(void)
{
    int numeros;
    int resul;
    int i;
    int cant=0;
    int num;

    for(i=0;i<CANTIDAD;i++)
    {
        printf("ingrese 5 numeros: ");
        scanf("%d", &numeros);
        numeros+=numeros;
        cant++;
    }

   printf("numeros:%d",numeros);



    return 0;
}
int promedio(int numeros,int cant)
{
    int promedio;

    promedio=numeros/cant;






}
