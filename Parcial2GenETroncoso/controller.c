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


int controller_importeVentado(LinkedList* pLista)
{
    Venta* pAux;
    int length;
    float contadorImporte = 0;
    float importeActual;
    int count;
    int i;

    count=ll_count(pLista,Venta_mayor150);
    printf("%d",count);
   /* if(pLista != NULL)
    {
        length = ll_len(pLista);
        for(i=0; i<length; i++)
        {
            pAux = ll_get(pLista, i);
            if(!Venta_getdato4(pAux, &importeActual))
            {
                contadorImporte += importeActual;
            }
        }
    }*/
    return count;
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
    int cantidadDeVentas;
    int cantidadFotosRe = 0;
    int totalPola;
    int total;
    LinkedList *lista = ll_newLinkedList;
    Venta *Ventas;
    FILE *pFile = NULL;

    if(path != NULL && registro != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            total = ll_len(lista);

            total = ll_count(registro, Venta_mayor150);

            totalPola = ll_count(registro, Venta_filtrarPolaroid);
            cantidadFotosRe = controller_cantidadVentas(registro);

            controller_importeVentado(registro);

            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad de fotos reveladas: %d\n", cantidadFotosRe);
//            fprintf(pFile, "- Cantidad de Ventas por un monto mayor a $150: %d \n", );
      //      fprintf(pFile, "- Cantidad de Ventas por un monto mayor a $300: %d\n", );
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
