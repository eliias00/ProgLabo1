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
    float costo=0;

    if(path != NULL && pArrayListEnvio != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {

            for(i=0; i<ll_len(pArrayListEnvio); i++)
            {
                auxEnvio = ll_get(pArrayListEnvio,i);
                if(auxEnvio != NULL)
                {
                    Envio_getid(auxEnvio, &id);
                    Envio_getNombre(auxEnvio,nombre);
                    Envio_getkm(auxEnvio,&kilometros);
                    Envio_gettipo(auxEnvio, &tipoDeEntrega);
                    Envio_getprecio(auxEnvio,&precio);
                    printf("%f",precio);
                    fprintf(pFile,"%d,%s,%d,%d,%.2f\n",id,nombre,kilometros,tipoDeEntrega,precio);

                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}
/*
int costoTipoEntrega(void* p)
{
    int tipo;
    int costo;
    float precio=0;
    float valor;
    if(p!=NULL)
    {
//        precio=aumentoPorKilometros(p);

        Envio_gettipo((Envio*)p,&tipo);

        if(tipo==1)
        {
            valor=precio+330;
        }
        else if(tipo==2)
        {
            valor=precio+ 560;

        }
        else if(tipo==3)
        {
            valor=precio+80;

        }
    }
    // printf(":%f",valor);

    return valor;
}*/
int controller_aumentoPorKilometros(void* p)
{
    int ret=0;
    float precio=0;
    float kilometros;
    if(p!=NULL)
    {

        Envio_getprecio((Envio*)p,&precio);
        Envio_getkm(p,&kilometros);
        if(kilometros<50)
        {
            precio=67;
            precio=precio*kilometros;
            ret=1;
        }
        else
        {
            precio = 80;
            precio=precio*kilometros;
            ret=1;
        }
        Envio_setprecio((Envio*)p,precio);
        printf("%f",precio);
    }
    return ret;
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
                    printf("%d  |%s  |%f  |normal\n",idEnvio,nombrePro,km);
                }
                else if(tipoEnt==2)
                {
                    printf("%d  |%s  |%f  |express\n",idEnvio,nombrePro,km);
                }
                else if(tipoEnt==3)
                {
                    printf("%d  |%s  |%f  |segun disponibilidad\n",idEnvio,nombrePro,km);
                }

            }
        }
    }
    return 0;
}
