
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"

int parserFromText(FILE* pFile , LinkedList* pLista)
{
    int retorno = -1;
    int flag=0;
    char idEnvio[4096];
    char nombrePro[4096];
    char km[4096];
    char tipoEnt[4096];


    Envio* pGen;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idEnvio, nombrePro,km,tipoEnt);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pGen = Envio_newParametros(idEnvio, nombrePro, km,tipoEnt);

        if(pGen != NULL)
        {
            ll_add(pLista, pGen);
            retorno = 0;
        }
    }
    return retorno;
}
