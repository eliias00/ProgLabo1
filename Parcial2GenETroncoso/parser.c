
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"

int parserFromText(FILE* pFile , LinkedList* pLista)
{
    int retorno = -1;
    int flag=0;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferImporte[4096];

    Generico* pGen;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pGen = Generico_newParametros(bufferId, bufferTipo, bufferCantidad, bufferImporte);
        if(pGen != NULL)
        {
            ll_add(pLista, pGen);
            retorno = 0;
        }
    }
    return retorno;
}
