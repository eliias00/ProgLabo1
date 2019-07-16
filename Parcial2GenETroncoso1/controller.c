#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"
#include "parser.h"
#include "valid.h"
#include "controller.h"


int controller_cantidadVentas(LinkedList* pLista)
{
    Venta* pAux;
    int contadorCantidad=0;
    int cantidadActual;
    int i;
    if(pLista != NULL)
    {
        for(i=0;i<ll_len(pLista);i++)
        {
            pAux = ll_get(pLista, i);
            if(!Venta_getcantidad(pAux, &cantidadActual))
            {
                contadorCantidad += cantidadActual;
            }
        }
    }

    return contadorCantidad;
}
int controller_loadFromText(char* path, LinkedList* pLista)
{
    int retorno = -1;
    FILE *pFile = NULL;

    if( path != NULL && pLista != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parserFromText(pFile,pLista);
            retorno=0;
        }
        fclose(pFile);
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* registro)
{
    int retorno = -1;
    int cantidadFotosRe = 0;
    int totalPola;
    int total=0;
    int total2=0;
    FILE *pFile = NULL;

    if(path != NULL && registro != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            total = ll_count(registro, Venta_mayor150);
            total2 = ll_count(registro, Venta_mayor300);
            cantidadFotosRe = controller_cantidadVentas(registro);
            totalPola = ll_count(registro, Venta_filtrarPolaroid);
            printf("\n%d",cantidadFotosRe);
            printf("\n%d",total);
            printf("\n%d",total2);
            printf("\n%d",totalPola);
            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad de fotos reveladas: %d\n", cantidadFotosRe);
            fprintf(pFile, "- Cantidad de Ventas por un monto mayor a $150: %d \n",total );
            fprintf(pFile, "- Cantidad de Ventas por un monto mayor a $300: %d\n", total2 );
            fprintf(pFile, "- Cantidad de fotos polaroids reveladas: %d\n", totalPola);
            fprintf(pFile, "*******************************************************************************");

            retorno = 0;
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("\nInforme generado exitosamente");
    }
    return retorno;
}
