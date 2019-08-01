#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envios.h"
#include "parser.h"
#include "validaciones.h"

int controller_loadFromText(char* path, LinkedList* pLista)
{
    int retorno = -1;
    FILE *pFile = NULL;

    if( path != NULL && pLista != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parser_EnviosFromText(pFile,pLista);
            retorno=0;
        }
        fclose(pFile);
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEnvios)
{
    int retorno = -1;
    Envios* auxEnvios;
    FILE* pFile;
    int i;
    int id;
    char nombre[4096];
    int kilometros;
    int tipoDeEntrega;
    float precio;
    int costo;

    if(path != NULL && pArrayListEnvios != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {

            for(i=0; i<ll_len(pArrayListEnvios); i++)
            {
                auxEnvios = ll_get(pArrayListEnvios,i);
                if(auxEnvios != NULL)
                {
                    envios_getId(auxEnvios, &id);
                    envios_getNombre(auxEnvios,nombre);
                    envios_getKilometros(auxEnvios,&kilometros);
                    envios_getTipoDeEntrega(auxEnvios, &tipoDeEntrega);
                    envios_getPrecio(auxEnvios,&precio);
                    envios_getCosto(auxEnvios,&costo);

                    fprintf(pFile,"%d,%s,%d,%d,%.2f,%d\n",id,nombre,kilometros,tipoDeEntrega,precio,costo);

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
    int costo=0;
    float precio=0;
    if(p!=NULL)
    {
        envios_getPrecio((Envios*)p,&precio);
        envios_getTipoDeEntrega((Envios*)p,&tipo);
        if(tipo==1)
        {
            costo=precio+330;
        }
        else if(tipo==2)
        {
            costo=precio+ 560;
        }
        else if(tipo==3)
        {
            costo=precio+80;
        }
        envios_setCosto((Envios*)p,costo);
     //   printf("costo:%d\n",costo);
    }
    return 1;
}
int controller_aumentoPorKilometros(void* p)

{
    int ret=0;
    float precio=0;
    int kilometros;
    if(p!=NULL)
    {

        envios_getPrecio((Envios*)p,&precio);
        envios_getKilometros(p,&kilometros);
        if(kilometros<=50)
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
        envios_setPrecio((Envios*)p,precio);
    }
    return ret;
}

int imprimirTipo(LinkedList *lista)
{
    Envios* pAux;

    int idEnvios;
    char nombrePro[4096];
    float km;
    int tipoEnt;

    int i;

    if(lista != NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            pAux = ll_get(lista, i);

            envios_getId(pAux,&idEnvios);
            envios_getKilometros(pAux,&km);
            envios_getTipoDeEntrega(pAux,&tipoEnt);
            envios_getNombre(pAux,nombrePro);
            {

                if(tipoEnt==1)
                {
                    printf("%d  |%s  |%f  |normal\n",idEnvios,nombrePro,km);
                }
                else if(tipoEnt==2)
                {
                    printf("%d  |%s  |%f  |express\n",idEnvios,nombrePro,km);
                }
                else if(tipoEnt==3)
                {
                    printf("%d  |%s  |%f  |segun disponibilidad\n",idEnvios,nombrePro,km);
                }

            }
        }
    }
    return 0;
}
