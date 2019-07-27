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

int controller_saveAsText(char* path, LinkedList* registro)
{
    int retorno = -1;
    int numero;
    FILE *pFile = NULL;
    LinkedList* registroNuevo = ll_newLinkedList();
    int i;
    char solu[4096];
    int idp;
    char fecha[4096];
    int idl;
    int numCli;
    Llamada* pAux;
    if(path != NULL && registro != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            printf("ingrese id del problema: ");
            scanf("%d",&numero);
            switch(numero)
            {
            case 1:
                registroNuevo=ll_filter(registro,filtro1);
                break;
            case 2:
                registroNuevo=ll_filter(registro,filtro2);
                break;
            case 3:
                registroNuevo=ll_filter(registro,filtro3);
                break;
            case 4:
                registroNuevo=ll_filter(registro,filtro4);
                break;
            case 5:
                registroNuevo=ll_filter(registro,filtro5);
                break;
                default:
                printf("no existe ese id");
                retorno=-1;
            }

            for(i=0; i<ll_len(registroNuevo); i++)
            {
                pAux = ll_get(registroNuevo, i);

                if(!Llamada_getsol(pAux,solu)&&
                        !Llamada_getidP(pAux,&idp)&&
                        !Llamada_getfecha(pAux,fecha)&&
                        !Llamada_getid(pAux,&idl)&&
                        !Llamada_getnumCliente(pAux,&numCli))
                {
                    fprintf(pFile,"%d,%s,%d,%d,%s\n",idl,fecha,numCli,idp,solu);
                    retorno = 0;
                }
            }
        }
        fclose(pFile);
    }
    return retorno;
}
int imprimirLlamada(LinkedList *lista)
{
    Llamada* pAux;
    char solu[4096];
    int idp;
    char fecha[4096];
    int idl;
    int numCli;
    int i;

    if(lista != NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            pAux = ll_get(lista, i);

            if(!Llamada_getsol(pAux,solu)&&
                    !Llamada_getidP(pAux,&idp)&&
                    !Llamada_getfecha(pAux,fecha)&&
                    !Llamada_getid(pAux,&idl)&&
                    !Llamada_getnumCliente(pAux,&numCli))
            {
                if(idp==1)
                {
                    printf("%d,%s,%d,no enciende pc,%s\n",idl,fecha,numCli,solu);
                }
                else if(idp==2)
                {
                    printf("%d,%s,%d,no funciona mouse,%s\n",idl,fecha,numCli,solu);
                }
                else if(idp==3)
                {
                    printf("%d,%s,%d,no funciona teclado,%s\n",idl,fecha,numCli,solu);
                }
                else if(idp==4)
                {
                    printf("%d,%s,%d,no hay internet,%s\n",idl,fecha,numCli,solu);
                }
                else if(idp==5)
                {
                    printf("%d,%s,%d,no funciona telefono,%s\n",idl,fecha,numCli,solu);
                }

            }
        }
    }
    return 0;


}
int filtro1(void* this)
{
    int ret = 0 ;
    int auxProblema;

    if (this!= NULL )
    {
        Llamada_getidP ((Llamada *) this, & auxProblema);
        if (auxProblema == 1 )
        {
            ret = 1 ;
        }
    }
    return ret;
}
int filtro2(void* this)
{
    int ret = 0 ;
    int auxProblema;

    if (this!= NULL )
    {
        Llamada_getidP ((Llamada *) this, & auxProblema);
        if (auxProblema == 2 )
        {
            ret = 1 ;
        }
    }
    return ret;
}
int filtro3(void* this)
{
    int ret = 0 ;
    int auxProblema;

    if (this!= NULL )
    {
        Llamada_getidP ((Llamada *) this, & auxProblema);
        if (auxProblema == 3 )
        {
            ret = 1 ;
        }
    }
    return ret;
}
int filtro4(void* this)
{
    int ret = 0 ;
    int auxProblema;

    if (this!= NULL )
    {
        Llamada_getidP ((Llamada *) this, & auxProblema);
        if (auxProblema == 4 )
        {
            ret = 1 ;
        }
    }
    return ret;
}
int filtro5(void* this)
{
    int ret = 0 ;
    int auxProblema;

    if (this!= NULL )
    {
        Llamada_getidP ((Llamada *) this, & auxProblema);
        if (auxProblema == 5 )
        {
            ret = 1 ;
        }
    }
    return ret;
}
