
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"

int parserFromText(FILE* pFile , LinkedList* pLista)
{
    int retorno = -1;
    int flag=0;
    char idLlamada[4096];
    char fecha[4096];
    char numCliente[4096];
    char idProblema[4096];
    char solucionado[4096];

    Llamada* pGen;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idLlamada, fecha, numCliente,idProblema,solucionado);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pGen = Llamada_newParametros(idLlamada, fecha, numCliente,idProblema,solucionado);

        if(pGen != NULL)
        {
            ll_add(pLista, pGen);
            retorno = 0;
        }
    }
    return retorno;
}
