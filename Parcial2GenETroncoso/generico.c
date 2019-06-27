#include <stdio.h>
#include <stdlib.h>
#include "generico.h"
#include "valid.h"
#include <string.h>

Generico* Generico_new()
{
    return (Generico*) malloc(sizeof(Generico));
}
Generico* Generico_newParametros(char* dato1,char* dato2,char* dato3,char* dato4)
{
    Generico *retorno = NULL;
    Generico *auxGenerico;
    if(dato1 != NULL && dato2!=NULL && dato3!=NULL && dato4!=NULL )
    {
        auxGenerico=Generico_new();
        if(auxGenerico!=NULL)
        {
            if(!Generico_setdato2(auxGenerico,dato2)&&
               !Generico_setdato3Str(auxGenerico,dato3)&&
               !Generico_setdato1Str(auxGenerico,dato1)&&
               !Generico_setdato4Str(auxGenerico,dato4))
            {
                retorno=auxGenerico;
            }
            else
            {
                Generico_delete(auxGenerico);
            }
        }
    }
    return retorno;
}
void Generico_delete(Generico *auxGenerico)
{
    if(auxGenerico != NULL)
    {
        free(auxGenerico);
    }
}
int Generico_setdato1Str(Generico* this, char *dato1)
{
    int retorno = -1;
    if(this != NULL && dato1 >=0)
    {
        retorno = Generico_setdato1(this, atoi(dato1));
    }
    return retorno;
}
int Generico_setdato1(Generico* this,int dato1)
{
    int retorno = -1;
    if(this != NULL  && dato1 >=0)
    {
        this->dato1 = dato1;
        retorno = 0;
    }
    return retorno;
}
int Generico_getdato1(Generico* this,int* dato1)
{
    int retorno = -1;
    if(this != NULL && dato1 != NULL)
    {
        *dato1 = this->dato1;
        retorno = 0;
    }
    return retorno;
}
int Generico_setdato2(Generico* this,char* dato2)
{
    int retorno = -1;
    if(this != NULL && isValidName(dato2))
    {
        strncpy(this->dato2,dato2,sizeof(this->dato2));
        retorno = 0;
    }
    return retorno;
}
int Generico_getdato2(Generico* this,char* dato2)
{
    int retorno = -1;
    if(this != NULL && dato2 != NULL)
    {
        strncpy(dato2, this->dato2,sizeof(this->dato2));
        retorno = 0;
    }
    return retorno;
}
int Generico_setdato3Str(Generico* this, char *dato3)
{
    int retorno = -1;
    if(this != NULL && dato3>=0)
    {
        retorno = Generico_setdato3(this,atoi(dato3));
    }
    return retorno;
}
int Generico_setdato3(Generico* this,int dato3)
{
    int retorno = -1;
    if(this != NULL && dato3>=0)
    {
        this->dato3 = dato3;
        retorno = 0;
    }
    return retorno;
}
int Generico_getdato3(Generico* this,int* dato3)
{
    int retorno = -1;
    if(this != NULL && dato3 != NULL)
    {
        *dato3 = this->dato3;
        retorno = 0;
    }
    return retorno;
}
int Generico_setdato4Str(Generico* this, char *dato4)
{
    int retorno = -1;
    if(this != NULL && dato4 >=0)
    {
        retorno = Generico_setdato4(this,atof(dato4));
    }
    return retorno;
}
int Generico_setdato4(Generico* this,float dato4)
{
    int retorno = -1;
    if(this != NULL && dato4 >=0)
    {
        this->dato4 = dato4;
        retorno = 0;
    }
    return retorno;
}
int Generico_getdato4(Generico* this,float* dato4)
{
    int retorno = -1;
    if(this != NULL && dato4 != NULL)
    {
        *dato4 = this->dato4;
        retorno = 0;
    }
    return retorno;
}
int Generico_compararPorNombre(void *this1,void *this2)
{
    char auxStrA[4096];
    char auxStrB[4096];
    int retorno;
    Generico_getdato2((Generico*)this1, auxStrA);
    Generico_getdato2((Generico*)this2, auxStrB);
    if(strcmp(auxStrA,auxStrB)>0)
    {
      retorno=1;
    }
    else if(strcmp(auxStrA,auxStrB)<0)
    {
      retorno=-1;
    }
      return retorno;
}
int Generico_filtrarGold(void* this)
{
    int retorno = 0;
    char auxTipo[4096];

    if(this != NULL)
    {
        Generico_getdato2(((Generico*)this),auxTipo);
        if(!strcmp("GOLD", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}


int Generico_filtrarPlus(void* this)
{
   int retorno = 0;
    char auxTipo[4096];

    if(this != NULL)
    {
        Generico_getdato2(((Generico*)this),auxTipo);
        if(!strcmp("PLUS", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int Generico_filtrarRegular(void* this)
{
    int retorno = 0;
    char auxTipo[4096];

    if(this != NULL)
    {
        Generico_getdato2(((Generico*)this),auxTipo);
        if(!strcmp("REGULAR", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}
