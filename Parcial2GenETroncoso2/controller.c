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

int controller_saveAsText( LinkedList* registro)
{
    int retorno = -1;
    int numero;
    FILE *pFile = NULL;
    LinkedList* registroNuevo = ll_newLinkedList();
    int i;
    int idPart;
    char fecha[128];
    int tipoJue;
    int cantJue;
    int durPart;
    int costo;
    Partida *pAux;

    if(registro != NULL)
    {


            printf("ingrese tipo de juego: ");
            scanf("%d",&numero);
            switch(numero)
            {
            case 0:
                pFile = fopen("pingPong.csv", "w");
                registroNuevo=ll_filter(registro,tipo0);
                break;
            case 1:
                pFile = fopen("pool.csv", "w");
                registroNuevo=ll_filter(registro,tipo1);
                break;
            case 2:
             pFile = fopen("metegol.csv", "w");
                registroNuevo=ll_filter(registro,tipo2);
                break;
            case 3:
             pFile = fopen("dardos.csv", "w");
                registroNuevo=ll_filter(registro,tipo3);
                break;

                default:
                printf("no existe ese tipo");
                retorno=-1;
            }

            for(i=0; i<ll_len(registroNuevo); i++)
            {
                pAux = ll_get(registroNuevo, i);

                  if(     !Partida_getid(pAux,&idPart)&&
                    !Partida_getfecha(pAux,fecha)&&
                    !Partida_gettipoJue(pAux,&tipoJue)&&
                    !Partida_getcantJue(pAux,&cantJue)&&
                    !Partida_getdurPart(pAux,&durPart)&&
                    !Partida_getcosto(pAux,&costo))
                {
                    fprintf(pFile,"%d,%s,%d,%d,%d,%d\n",idPart,fecha,tipoJue,cantJue,durPart,costo);
                    retorno = 0;
                }
            }

        fclose(pFile);
    }
    return 0;
}
int imprimirPartida(LinkedList *lista)
{
    Partida* pAux;

    int idPart;
    char fecha[128];
    int tipoJue;
    int cantJue;
    int durPart;
    int i;

    if(lista != NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            pAux = ll_get(lista, i);

            if(     !Partida_getid(pAux,&idPart)&&
                    !Partida_getfecha(pAux,fecha)&&
                    !Partida_gettipoJue(pAux,&tipoJue)&&
                    !Partida_getcantJue(pAux,&cantJue)&&
                    !Partida_getdurPart(pAux,&durPart))
            {

                if(tipoJue==0)
                {
                    printf("%d,%s,ping pong,%d,%d\n",idPart,fecha,cantJue,durPart);
                }
                else if(tipoJue==1)
                {
                    printf("%d,%s,pool,%d,%d\n",idPart,fecha,cantJue,durPart);
                }
                else if(tipoJue==2)
                {
                    printf("%d,%s,metegol,%d,%d\n",idPart,fecha,cantJue,durPart);
                }
                else if(tipoJue==3)
                {
                    printf("%d,%s,dardos,%d,%d\n",idPart,fecha,cantJue,durPart);
                }
            }
        }
    }
    return 0;


}
int imprimirProm(LinkedList *lista)
{
    Partida* pAux;

    int tipoJue;
    int cantJue;
    int total0=0;
    int total1=0;
    int total2=0;
    int total3=0;

    float cero=0;
    float uno=0;
    float dos=0;
    float tres=0;

    float primero;
    float segundo;
    float tercero;
    float cuarto;



    int i;

    if(lista != NULL)
    {
        total0=ll_count(lista, tipo0);
        cero=cantidad0(lista);

        total1=ll_count(lista, tipo1);
        uno=cantidad1(lista);



        total2=ll_count(lista, tipo2);
        dos=cantidad2(lista);

        total3=ll_count(lista, tipo3);
        tres=cantidad3(lista);

        primero=cero/total0;
       segundo=uno/total1;
        tercero=dos/total2;
        cuarto=tres/total3;


        printf("promedios\n");
        printf("total 0: %f\n",primero);
        printf("total 1: %f\n",segundo);
        printf("total 2: %f\n",tercero);
        printf("total 3: %f\n",cuarto);


    }
    return 0;


}

int tipo0(void* this)
{
    int ret = 0 ;
    int tipo0;

    if (this!= NULL )
    {
        Partida_gettipoJue ((Partida *) this, & tipo0);
        if (tipo0 == 0 )
        {
            ret = 1 ;
        }
    }
    return ret;
}


int tipo1(void* this)
{
    int ret = 0 ;
    int tipo1;

    if (this!= NULL )
    {
        Partida_gettipoJue ((Partida *) this, & tipo1);
        if (tipo1 == 1 )
        {
            ret = 1 ;
        }
    }
    return ret;
}


int tipo2(void* this)
{
    int ret = 0 ;
    int tipo2;

    if (this!= NULL )
    {
        Partida_gettipoJue ((Partida *) this, & tipo2);
        if (tipo2 == 2 )
        {
            ret = 1 ;
        }
    }
    return ret;
}


int tipo3(void* this)
{
    int ret = 0 ;
    int tipo3;

    if (this!= NULL )
    {
        Partida_gettipoJue ((Partida *) this, & tipo3);
        if (tipo3 == 3 )
        {
            ret = 1 ;
        }
    }
    return ret;
}







int cantidad0(LinkedList* pLista)
{
    Partida* pAux;
    float contadorCantidad=0;
    int cantidadActual;
    int i;
    int tipo0;
    if(pLista != NULL)
    {
        for(i=0;i<ll_len(pLista);i++)
        {
            pAux = ll_get(pLista, i);
            Partida_getcantJue(pAux, &cantidadActual);
            Partida_gettipoJue (pAux, &tipo0);
            if(tipo0==0)
            {
                contadorCantidad += cantidadActual;
            }

        }
    }

    return contadorCantidad;
}

int cantidad1(LinkedList* pLista)
{
    Partida* pAux;
    float contadorCantidad=0;
    int cantidadActual;
    int i;
    int tipo1;
    if(pLista != NULL)
    {
        for(i=0;i<ll_len(pLista);i++)
        {
            pAux = ll_get(pLista, i);
            Partida_getcantJue(pAux, &cantidadActual);
            Partida_gettipoJue (pAux, &tipo1);
            if(tipo1==1)
            {
                contadorCantidad += cantidadActual;
            }

        }
    }

    return contadorCantidad;
}

int cantidad2(LinkedList* pLista)
{
    Partida* pAux;
    float contadorCantidad=0;
    int cantidadActual;
    int i;
    int tipo2;
    if(pLista != NULL)
    {
        for(i=0;i<ll_len(pLista);i++)
        {
            pAux = ll_get(pLista, i);
            Partida_getcantJue(pAux, &cantidadActual);
            Partida_gettipoJue (pAux, &tipo2);
            if(tipo2==2)
            {
                contadorCantidad += cantidadActual;
            }

        }
    }

    return contadorCantidad;
}

int cantidad3(LinkedList* pLista)
{
    Partida* pAux;
    float contadorCantidad=0;
    int cantidadActual;
    int i;
    int tipo3;
    if(pLista != NULL)
    {
        for(i=0;i<ll_len(pLista);i++)
        {
            pAux = ll_get(pLista, i);
            Partida_getcantJue(pAux, &cantidadActual);
            Partida_gettipoJue (pAux, &tipo3);
            if(tipo3==3)
            {
                contadorCantidad += cantidadActual;
            }

        }
    }

    return contadorCantidad;
}

int controller_costos(void* p)
{
    int ret=0;
    int duracion;
    int tipo;
    int costo;
    if(p!=NULL)
    {

        Partida_getdurPart((Partida*)p,&duracion);
        Partida_gettipoJue((Partida*)p,&tipo);
        if(tipo==0)
        {
            costo=150*duracion;
            ret=1;
        }
        if(tipo==1)
        {
           costo=120*duracion;
            ret=1;
        }
        if(tipo==2)
        {
           costo=60*duracion;
            ret=1;
        }
        if(tipo==3)
        {
           costo=90*duracion;
            ret=1;
        }
        Partida_setcosto((Partida*)p,costo);
    }
    return 1;
}
