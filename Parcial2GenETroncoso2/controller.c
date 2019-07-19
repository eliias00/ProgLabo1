#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"
#include "parser.h"
#include "valid.h"
#include "controller.h"


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

int controller_saveAsText(char* path, LinkedList* pArrayListEnvio)
{
    int retorno = -1;
    Envio* auxEnvio;
    FILE* pFile;
    int i;
    int id;
    char nombre[40961];
    int kilometros;
    int tipoDeEntrega;
    float precio;
    float costo;

    if(path != NULL && pArrayListEnvio != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            costo=ll_map(pArrayListEnvio,costoTipoEntrega);

            for(i=0; i<ll_len(pArrayListEnvio); i++)
            {
                auxEnvio = ll_get(pArrayListEnvio,i);
                if(auxEnvio != NULL)
                {
                    Envio_getid(auxEnvio, &id);
                    Envio_getNombre(auxEnvio,nombre);
                    Envio_getkm(auxEnvio,&kilometros);
                    Envio_gettipo(auxEnvio, &tipoDeEntrega);

                    fprintf(pFile,"%d,%s,%d,%d,%f\n",id,nombre,kilometros,tipoDeEntrega,costo);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}


int costoTipoEntrega(void* p)
{
    int tipo;
    int costo;
    float precio;
    if(p!=NULL)
    {
        precio=aumentoPorKilometros(p);

        Envio_gettipo((Envio*)p,&tipo);

        if(tipo==1)
        {
            precio=precio+330;
        }
        else if(tipo==2)
        {
            precio=precio+ 560;

        }
        else if(tipo==3)
        {
            precio=precio+80;

        }
    }

    return precio;
}
int aumentoPorKilometros(void* p)
{
    float precio=0;
    float *retorno;
    int kilometros;
    if(p!=NULL)
    {

        Envio_getkm(p,&kilometros);
        if(kilometros<50)
        {
            precio=67;
            precio=precio*kilometros;
        }
        else
        {
            precio = 80;
            precio=precio*kilometros;
        }
            *retorno=precio;
    }

    return retorno;
}
int imprimirTipo(LinkedList *lista)
{
    Envio* pAux;

    int idEnvio;
    char nombrePro[4096];
    float km;
    int tipoEnt;

    int i;

    if(lista != NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            pAux = ll_get(lista, i);

            Envio_getid(pAux,&idEnvio);
            Envio_getkm(pAux,&km);
            Envio_gettipo(pAux,&tipoEnt);
            Envio_getNombre(pAux,nombrePro);
            {

                if(tipoEnt==1)
                {
                    printf("%d,%s,%f,normal\n",idEnvio,nombrePro,km);
                }
                else if(tipoEnt==2)
                {
                    printf("%d,%s,%f,express\n",idEnvio,nombrePro,km);
                }
                else if(tipoEnt==3)
                {
                    printf("%d,%s,%f,segun disponibilidad\n",idEnvio,nombrePro,km);
                }

            }
        }
    }
    return 0;
}
