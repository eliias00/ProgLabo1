
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"

int parserFromText(FILE* pFile , LinkedList* pLista)
{
    int retorno = -1;
    int flag=0;
    char idPart[4096];
    char fecha[4096];
    char tipoJue[4096];
    char cantJue[4096];
    char durPart[4096];

    Partida* pGen;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idPart, fecha, tipoJue,cantJue,durPart);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pGen = Partida_newParametros(idPart, fecha, tipoJue,cantJue,durPart);


        if(pGen != NULL)
        {
            ll_add(pLista, pGen);
            retorno = 0;
        }
    }
    return retorno;
}
