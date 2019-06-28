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

int Venta_setprecio(Venta* this,float precio);

int Venta_mayor150(void* this);
int Venta_filtrarPolaroid(void* this);
#endif
