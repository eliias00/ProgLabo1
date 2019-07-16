#ifndef Generico_H_INCLUDED
#define Generico_H_INCLUDED
typedef struct
{
    int id;
    char fecha[128];
    char tipo[128];
    int cantidad;
    float precio;
    char cuit[128];

}Venta;

Venta* Venta_new();
Venta* Venta_newParametros(char* id,char* tipo,char* fecha,char* cantidad,char* cuit,char* precio);
void Venta_delete(Venta *auxVenta);
int Venta_mayor150(void* this);
int Venta_mayor300(void* this);
int Venta_filtrarPolaroid(void* this);

int Venta_getcantidad(Venta* this,int* cantidad);
int Venta_setprecio(Venta* this,float precio);
int Venta_settipo(Venta* this,char* tipo);
int Venta_setcantidadStr(Venta* this, char *cantidad);
int Venta_setidStr(Venta* this, char *id);
int Venta_setprecioStr(Venta* this, char *precio);
int Venta_setfecha(Venta* this,char* fecha);
int Venta_setcuit(Venta* this,char* cuit);
int Venta_setid(Venta* this,int id);
int Venta_setcantidad(Venta* this,int cantidad);
#endif
