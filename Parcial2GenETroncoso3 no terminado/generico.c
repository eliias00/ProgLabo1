#include <stdio.h>
#include <stdlib.h>
#include "generico.h"
#include "valid.h"
#include <string.h>

Envio* Envio_new()
{
    return (Envio*) malloc(sizeof(Envio));
}
Envio* Envio_newParametros(char *idEnvio, char *nombrePro, char *km,char *tipoEnt)
{
    Envio *retorno = NULL;
    Envio *auxEnvio;
    if(idEnvio != NULL && nombrePro!=NULL && km!=NULL && tipoEnt!=NULL)
    {
        auxEnvio=Envio_new();
        if(auxEnvio!=NULL)
        {
            if(!Envio_setidStr(auxEnvio,idEnvio)&&
               !Envio_setNombre(auxEnvio,nombrePro)&&
               !Envio_setkmStr(auxEnvio,km)&&
               !Envio_setTipoStr(auxEnvio,tipoEnt))
            {
                retorno=auxEnvio;
            }
            else
            {
                Envio_delete(auxEnvio);
            }
        }
    }
    return retorno;
}
void Envio_delete(Envio *auxEnvio)
{
    if(auxEnvio != NULL)
    {
        free(auxEnvio);
    }
}



int Envio_setidStr(Envio* this, char *idEnvio)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(idEnvio))
    {
        retorno = Envio_setid(this, atoi(idEnvio));
    }
    return retorno;
}
int Envio_setid(Envio* this,int idEnvio)
{
    int retorno = -1;
    if(this != NULL  && idEnvio >=0)
    {
        this->idEnvio = idEnvio;
        retorno = 0;
    }
    return retorno;
}

int Envio_getid(Envio* this,int* idEnvio)
{
    int retorno = -1;
    if(this != NULL && idEnvio != NULL)
    {

        *idEnvio = this->idEnvio;

        retorno = 0;
    }
    return retorno;
}



int Envio_setkmStr(Envio* this, char *km)
{
    int retorno = -1;
    if(this != NULL && isValidFloatNumber(km))
    {
        retorno = Envio_setkm(this,atof(km));
    }
    return retorno;
}

int Envio_setkm(Envio* this,float km)
{
    int retorno = -1;
    if(this != NULL && km >=0)
    {
        this->km = km;
        retorno = 0;
    }
    return retorno;
}
int Envio_getkm(Envio* this,float* km)
{
    int retorno = -1;
    if(this != NULL && km != NULL)
    {
        *km = this->km;
        retorno = 0;
    }
    return retorno;
}


int Envio_setTipoStr(Envio* this, char *tipoEnt)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(tipoEnt))
    {
        retorno = Envio_settipo(this, atoi(tipoEnt));
    }
    return retorno;
}
int Envio_settipo(Envio* this,int tipoEnt)
{
    int retorno = -1;
    if(this != NULL  && tipoEnt >=0)
    {
        this->tipoEnt = tipoEnt;
        retorno = 0;
    }
    return retorno;
}
int Envio_gettipo(Envio* this,int* tipoEnt)
{
    int retorno = -1;
    if(this != NULL && tipoEnt != NULL)
    {
        *tipoEnt = this->tipoEnt;
        retorno = 0;
    }
    return retorno;
}




int Envio_setNombre(Envio* this,char* nombrePro)
{
    int retorno = -1;
    if(this != NULL && isValidAlphanumeric(nombrePro))
    {
        strncpy(this->nombrePro,nombrePro,sizeof(this->nombrePro));
        retorno = 0;
    }
    return retorno;
}

int Envio_getNombre(Envio* this,char* nombrePro)
{
    int retorno = -1;
    if(this != NULL && nombrePro != NULL)
    {
        strncpy(nombrePro, this->nombrePro,sizeof(this->nombrePro));
        retorno = nombrePro;
    }
    return retorno;
}



int Envio_setprecio(Envio* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio >=0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int Envio_getprecio(Envio* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int Envio_setcosto(Envio* this,int costo)
{
    int retorno = -1;
    if(this != NULL  && costo >=0)
    {
        this->costo = costo;
        retorno = 0;
    }
    return retorno;
}
int Envio_getcosto(Envio* this,int* costo)
{
    int retorno = -1;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        retorno = 0;
    }
    return retorno;
}
