#include <stdio.h>
#include <stdlib.h>
#include "generico.h"
#include "valid.h"
#include <string.h>

Llamada* Llamada_new()
{
    return (Llamada*) malloc(sizeof(Llamada));
}
Llamada* Llamada_newParametros(char *idLlamada, char *fecha, char *numCliente,char *idProblema,char *solucionado)
{
    Llamada *retorno = NULL;
    Llamada *auxLlamada;
    if(idLlamada != NULL && fecha!=NULL && numCliente!=NULL && idProblema!=NULL && solucionado!=NULL)
    {
        auxLlamada=Llamada_new();
        if(auxLlamada!=NULL)
        {
            if(!Llamada_setNumClienteStr(auxLlamada,numCliente)&&
               !Llamada_setidStrL(auxLlamada,idLlamada)&&
               !Llamada_setSol(auxLlamada,solucionado)&&
               !Llamada_setfecha(auxLlamada,fecha)&&
               !Llamada_setidStrP(auxLlamada,idProblema))
            {
                retorno=auxLlamada;


            }
            else
            {
                Llamada_delete(auxLlamada);
            }
        }
    }
    return retorno;
}
void Llamada_delete(Llamada *auxLlamada)
{
    if(auxLlamada != NULL)
    {
        free(auxLlamada);
    }
}
int Llamada_setidStrL(Llamada* this, char *id)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        retorno = Llamada_setidL(this, atoi(id));
    }
    return retorno;
}
int Llamada_setidL(Llamada* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->idLlamada = id;
        retorno = 0;
    }
    return retorno;
}
int Llamada_getid(Llamada* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idLlamada;
        retorno = 0;
    }
    return retorno;
}



int Llamada_setNumClienteStr(Llamada* this, char *numCliente)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(numCliente))
    {
        retorno = Llamada_setnumCliente(this, atoi(numCliente));
    }
    return retorno;
}
int Llamada_setnumCliente(Llamada* this,int numCliente)
{
    int retorno = -1;
    if(this != NULL  && numCliente >=0)
    {
        this->numCliente = numCliente;
        retorno = 0;
    }
    return retorno;
}
int Llamada_getnumCliente(Llamada* this,int* numCliente)
{
    int retorno = -1;
    if(this != NULL && numCliente != NULL)
    {
        *numCliente = this->numCliente;
        retorno = 0;
    }
    return retorno;
}





int Llamada_setfecha(Llamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && isValidFecha(fecha))
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int Llamada_getfecha(Llamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(fecha, this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}


int Llamada_setidStrP(Llamada* this, char *id)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        retorno = Llamada_setid(this, atoi(id));
    }
    return retorno;
}
int Llamada_setid(Llamada* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->idProblema = id;
        retorno = 0;
    }
    return retorno;
}
int Llamada_getidP(Llamada* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idProblema;
        retorno = 0;
    }
    return retorno;
}




int Llamada_setSol(Llamada* this,char* sol)
{
    int retorno = -1;
    if(this != NULL && isValidName(sol))
    {
        strncpy(this->solucionado,sol,sizeof(this->solucionado));
        retorno = 0;
    }
    return retorno;
}
int Llamada_getsol(Llamada* this,char* sol)
{
    int retorno = -1;
    if(this != NULL && sol != NULL)
    {
        strncpy(sol, this->solucionado,sizeof(this->solucionado));
        retorno = 0;
    }
    return retorno;
}

