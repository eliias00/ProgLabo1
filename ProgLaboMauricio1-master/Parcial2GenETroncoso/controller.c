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
    int total;
    FILE *pFile = NULL;
    LinkedList* id1 = ll_newLinkedList();
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


           // funcionID(registro);
            id1 = ll_filter(registro,filtro1);

              total=ll_len(id1);

            for(i=0; i<ll_len(registro); i++)
            {
                pAux = ll_get(registro, i);

                if(!Llamada_getsol(pAux,solu)&&
                        !Llamada_getidP(pAux,&idp)&&
                        !Llamada_getfecha(pAux,fecha)&&
                        !Llamada_getid(pAux,&idl)&&
                        !Llamada_getnumCliente(pAux,&numCli))
                {

                    fprintf(pFile,"%d\n",total);
                    //                    fprintf(pFile,"%d,%s,%d,%d,%s\n",idl,fecha,numCli,idp,solu);

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
int funcionID(Llamada *this)
{
    int retorno = -1;
    int numero;
    int *numero1;
    Llamada* pAux;
    int idp;
    int i;
    int total;

    printf("ingrese id del problema: ");
    scanf("%d",&numero);

            return numero;
}

int filtro1(Llamada *this)
{
      int idp;
      int retorno=-1,
    funcionid();

    if(!Llamada_getidP(this,&idp))
            {
                if(funcionid()==idp)
                {
                // *numero1=numero;
                 retorno=0;
                }
            }

return retorno;

}
/*
int filtr(void* this)
{
    int retorno = -1;
//    Llamada* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "PLUS");
    if(!comparison)
        retorno = 1;

    return retorno;
}
*/
