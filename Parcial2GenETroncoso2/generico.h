#ifndef Generico_H_INCLUDED
#define Generico_H_INCLUDED
typedef struct
{
    int idEnvio;
    char nombrePro[128];
    float km;
    int tipoEnt;

}Envio;

Envio* Envio_new();
Envio* Envio_newParametros(char *idEnvio, char *nombrePro, char *km,char *tipoEnt);

Envio_setkm(Envio* this,float km);
Envio_getid(Envio* this,int* idEnvio);
Envio_getkm(Envio* this,float* km);
Envio_gettipo(Envio* this,int* tipoEnt);
Envio_getNombre(Envio* this,char* nombrePro);

int calcular(void* p);

#endif
