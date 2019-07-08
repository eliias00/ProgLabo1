#include <stdio.h>
#include <stdlib.h>
#include "generico.h"
#include "valid.h"
#include <string.h>

Venta* Venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}
Venta* Venta_newParametros(char* id,char* tipo,char* cantidad,char* precio,char* fecha,char* cuit)
{
    Venta *retorno = NULL;
    Venta *auxVenta;
    if(id != NULL && tipo!=NULL && cantidad!=NULL && precio!=NULL )
    {
        auxVenta=Venta_new();
        if(auxVenta!=NULL)
        {
            if(!Venta_settipo(auxVenta,tipo)&&
               !Venta_setcantidadStr(auxVenta,cantidad)&&
               !Venta_setidStr(auxVenta,id)&&
               !Venta_setprecioStr(auxVenta,precio)&&
               !Venta_setfecha(auxVenta,fecha)&&
               !Venta_setcuit(auxVenta,cuit))
            {
                retorno=auxVenta;

            }
            else
            {
                Venta_delete(auxVenta);
            }
        }
    }
    return retorno;
}
void Venta_delete(Venta *auxVenta)
{
    if(auxVenta != NULL)
    {
        free(auxVenta);
    }
}
int Venta_setidStr(Venta* this, char *id)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        retorno = Venta_setid(this, atoi(id));
    }
    return retorno;
}
int Venta_setid(Venta* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int Venta_getid(Venta* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int Venta_settipo(Venta* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && isValidAlphanumeric(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}
int Venta_gettipo(Venta* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strncpy(tipo, this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}



int Venta_setfecha(Venta* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && isValidFecha(fecha))
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int Venta_getfecha(Venta* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(fecha, this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}



int Venta_setcuit(Venta* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && isCuit(cuit))
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}
int Venta_getcuit(Venta* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strncpy(cuit, this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}



int Venta_setcantidadStr(Venta* this, char *cantidad)
{
    int retorno = -1;
    if(this != NULL && isValidNumber(cantidad))
    {
        retorno = Venta_setcantidad(this,atoi(cantidad));
    }
    return retorno;
}
int Venta_setcantidad(Venta* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad>=0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int Venta_getcantidad(Venta* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}



int Venta_setprecioStr(Venta* this, char *precio)
{
    int retorno = -1;
    if(this != NULL && isValidFloatNumber(precio))
    {
        retorno = Venta_setprecio(this,atof(precio));
    }
    return retorno;
}
int Venta_setprecio(Venta* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio >=0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int Venta_getprecio(Venta* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}





int Venta_mayor150(void* this)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (this!=NULL)
    {
        Venta_getprecio(this,&auxImporte);
        Venta_getcantidad(this,&cantidad);
        total= auxImporte*cantidad;
        if (total>150)
        {

            retorno=1;
        }
    }

    return retorno;
}
int Venta_mayor300(void* this)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (this!=NULL)
    {
        Venta_getprecio(this,&auxImporte);
        Venta_getcantidad(this,&cantidad);
        total= auxImporte*cantidad;
        if (total>300)
        {

            retorno=1;
        }
    }

    return retorno;
}

int Venta_filtrarPolaroid(void* this)
{
    int retorno = 0;
    char auxTipo[4096];
    if(this != NULL)
    {
        Venta_gettipo(((Venta*)this),auxTipo);
        if(!strcmp("POLAROID_11x9", auxTipo) || !strcmp("POLAROID_10x10", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}

