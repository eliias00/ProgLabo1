#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"
#include "parser.h"
#include "valid.h"
#include "controller.h"

int generadorId(LinkedList* pLista)
{
    Generico* auxiliar;
    int cant;
    int auxId;
    int maxID = -1;
    int i;
    if(pLista != NULL)
    {
        cant = ll_len(pLista);
        for(i=0;i<cant;i++)
        {
            auxiliar = ll_get(pLista, i);
            Generico_getdato1(auxiliar, &auxId);
            if(auxId > maxID)
            {
                maxID = auxId;
            }
        }
    }
    maxID += 1;
    return maxID;
}
int buscaId (LinkedList* pLista, int *idEncontrado)
{
    int i;
    int retorno = -1;
    int id;
    Generico *pGen;
    int auxid;
    int cant;

    printf("\ningrese id a buscar: ");
    scanf("%d", &auxid);
    cant = ll_len(pLista);
    for(i=0; i < cant; i++)
    {
        pGen = ll_get(pLista, i);
        Generico_getdato1(pGen,&id);
        if (id == auxid)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int controller_cantidadGenericoda(LinkedList* pLista)
{
    Generico* pAux;
    int length;
    int contadorCantidad = 0;
    int cantidadActual;
    int i;
    if(pLista != NULL)
    {
        length = ll_len(pLista);
        for(i=0; i<length; i++)
        {
            pAux = ll_get(pLista, i);
            if(!Generico_getdato3(pAux, &cantidadActual))
            {
                contadorCantidad += cantidadActual;
            }
        }
    }

    return contadorCantidad;
}

int controller_importeGenericodo(LinkedList* pLista)
{
    Generico* pAux;
    int length;
    float contadorImporte = 0;
    float importeActual;
    int i;
    if(pLista != NULL)
    {
        length = ll_len(pLista);
        for(i=0; i<length; i++)
        {
            pAux = ll_get(pLista, i);
            if(!Generico_getdato4(pAux, &importeActual))
            {
                contadorImporte += importeActual;
            }
        }
    }
    return contadorImporte;
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

    int cantidadDeGenericos;
    int cantidadDeBultos = 0;
    int totalRegular, totalPlus, totalGold;
    float promedioDeBultos = 0;
    float importeTotal = 0;
    float promedioDeImporte = 0;

    LinkedList* registroGold = ll_newLinkedList();
    LinkedList* registroPlus = ll_newLinkedList();
    LinkedList* registroRegular = ll_newLinkedList();
    Generico *Genericos;
    int auxId;
    char auxNombre[1000];
    int auxHorasTrabajadas;
    float auxSueldo;
    FILE *pFile = NULL;
    int i;
    if(path != NULL && registro != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            cantidadDeGenericos = ll_len(registro);

            totalGold = ll_len(registroGold);
            totalPlus = ll_len(registroPlus);
            totalRegular = ll_len(registroRegular);
            totalGold = ll_count(registro, Generico_filtrarGold);
            totalPlus = ll_count(registro, Generico_filtrarPlus);
            totalRegular = ll_count(registro, Generico_filtrarRegular);
            cantidadDeBultos = controller_cantidadGenericoda(registro);
            promedioDeBultos = (float)cantidadDeBultos / cantidadDeGenericos;
            importeTotal = controller_importeGenericodo(registro);
            promedioDeImporte = importeTotal / cantidadDeGenericos;
            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de Genericos: %d\n", cantidadDeGenericos);
            fprintf(pFile, "- Cantidad de Genericos por Tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n", totalGold, totalRegular, totalPlus);
            fprintf(pFile, "- Cantidad Total de Bultos Genericodos: %d\n", cantidadDeBultos);
            fprintf(pFile, "- Promedio de Bultos por Generico: %.2f\n", promedioDeBultos);
            fprintf(pFile, "- Importe promedio por Generico: %.2f\n", promedioDeImporte);
            fprintf(pFile, "*****************************");
            if(!controller_sort(registro))
            {
                if(pFile != NULL && registro != NULL)
                {
                        fprintf(pFile,"\nsort");
                    for(i=0; i<ll_len(registro); i++)
                    {
                        Genericos = ll_get(registro,i);
                        Generico_getdato1(Genericos,&auxId);
                        Generico_getdato2(Genericos,auxNombre);
                        Generico_getdato3(Genericos,&auxHorasTrabajadas);
                        Generico_getdato4(Genericos,&auxSueldo);
                        fprintf(pFile,"\n%d,%s,%d,%f\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                    }
                }
            }
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
int controller_sort(LinkedList* pLista)
{
    int retorno=-1;
    if(pLista != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pLista,Generico_compararPorNombre,1))
        {
            retorno=0;
        }
    }
    return retorno;
}
