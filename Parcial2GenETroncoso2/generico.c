#include <stdio.h>
#include <stdlib.h>
#include "generico.h"
#include "valid.h"
#include <string.h>

Partida* Partida_new()
{
    return (Partida*) malloc(sizeof(Partida));
}
Partida* Partida_newParametros(char *idPart, char *fecha, char *tipoJue,char *cantJue,char *durPart)
{
    Partida *retorno = NULL;
    Partida *auxPartida;
    if(idPart != NULL && fecha!=NULL && tipoJue!=NULL && cantJue!=NULL && durPart!=NULL)
    {
        auxPartida=Partida_new();
        if(auxPartida!=NULL)
        {
            if(!Partida_setidStr(auxPartida,idPart)&&
               !Partida_setfecha(auxPartida,fecha)&&
               !Partida_settipoJuegoStr(auxPartida,tipoJue)&&
               !Partida_settipocantJueStr(auxPartida,cantJue)&&
               !Partida_setdurPartstr(auxPartida,durPart))
            {

                retorno=auxPartida;


            }
            else
            {
                Partida_delete(auxPartida);
            }
        }
    }
    return retorno;
}
void Partida_delete(Partida *auxPartida)
{
    if(auxPartida != NULL)
    {
        free(auxPartida);
    }
}

int Partida_setidStr(Partida* this, char *id)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        retorno = Partida_setid(this, atoi(id));
    }
    return retorno;
}
int Partida_setid(Partida* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->idPart = id;
        retorno = 0;
    }
    return retorno;
}
int Partida_getid(Partida* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idPart;
        retorno = 0;
    }
    return retorno;
}






int Partida_setfecha(Partida* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && isValidFecha(fecha))
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int Partida_getfecha(Partida* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(fecha, this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}


int Partida_settipoJuegoStr(Partida* this, char *tipoJue)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(tipoJue))
    {
        retorno = Partida_settipoJue(this, atoi(tipoJue));
    }
    return retorno;
}
int Partida_settipoJue(Partida* this,int tipoJue)
{
    int retorno = -1;
    if(this != NULL  && tipoJue >=0)
    {
        this->tipoJue = tipoJue;
        retorno = 0;
    }
    return retorno;
}
int Partida_gettipoJue(Partida* this,int* tipoJue)
{
    int retorno = -1;
    if(this != NULL && tipoJue != NULL)
    {
        *tipoJue = this->tipoJue;
        retorno = 0;
    }
    return retorno;
}




int Partida_settipocantJueStr(Partida* this, char *cantJue)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(cantJue))
    {
        retorno = Partida_setcantJue(this, atoi(cantJue));
    }
    return retorno;
}
int Partida_setcantJue(Partida* this,int cantJue)
{
    int retorno = -1;
    if(this != NULL  && cantJue >=0)
    {
        this->cantJue = cantJue;
        retorno = 0;
    }
    return retorno;
}
int Partida_getcantJue(Partida* this,int* cantJue)
{
    int retorno = -1;
    if(this != NULL && cantJue != NULL)
    {
        *cantJue = this->cantJue;
        retorno = 0;
    }
    return retorno;
}







int Partida_setdurPartstr(Partida* this, char *durPart)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(durPart))
    {
        retorno = Partida_setdurPart(this, atoi(durPart));
    }
    return retorno;
}
int Partida_setdurPart(Partida* this,int durPart)
{
    int retorno = -1;
    if(this != NULL  && durPart >=0)
    {
        this->durPart = durPart;
        retorno = 0;
    }
    return retorno;
}
int Partida_getdurPart(Partida* this,int* durPart)
{
    int retorno = -1;
    if(this != NULL && durPart != NULL)
    {
        *durPart = this->durPart;
        retorno = 0;
    }
    return retorno;
}




int Partida_setcosto(Partida* this,int costo)
{
    int retorno = -1;
    if(this != NULL  && costo >=0)
    {
        this->costo = costo;
        retorno = 0;
    }
    return retorno;
}
int Partida_getcosto(Partida* this,int* costo)
{
    int retorno = -1;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        retorno = 0;
    }
    return retorno;
}
