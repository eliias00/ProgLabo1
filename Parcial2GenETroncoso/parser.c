
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"

int parserFromText(FILE* pFile , LinkedList* pLista)
{
    int retorno = -1;
    int flag=0;
    char bufferId[4096];
    char bufferFecha[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPrecio[4096];
    char bufferCuit[4096];

    Venta* pGen;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferFecha, bufferTipo, bufferCantidad,bufferPrecio,bufferCuit);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pGen = Venta_newParametros(bufferId, bufferTipo, bufferCantidad, bufferPrecio,bufferFecha,bufferCuit);
        if(pGen != NULL)
        {
            ll_add(pLista, pGen);
            retorno = 0;
        }
    }
    return retorno;
}
