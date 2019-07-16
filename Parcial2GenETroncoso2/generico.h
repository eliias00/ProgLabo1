#ifndef Generico_H_INCLUDED
#define Generico_H_INCLUDED
typedef struct
{
    int idLlamada;
    char fecha[128];
    int numCliente;
    int idProblema;
    char solucionado[128];

}Llamada;

Llamada* Llamada_new();
Llamada* Llamada_newParametros(char *idLlamada, char *fecha, char *numCliente,char *idProblema,char *solucionado);

void Llamada_delete(Llamada *auxLlamada);
int Llamada_setidStrL(Llamada* this, char *id);
int Llamada_setidL(Llamada* this,int id);
int Llamada_getid(Llamada* this,int* id);
int Llamada_setNumClienteStr(Llamada* this, char *numCliente);
int Llamada_setnumCliente(Llamada* this,int numCliente);
int Llamada_getnumCliente(Llamada* this,int* numCliente);;
int Llamada_setfecha(Llamada* this,char* fecha);
int Llamada_getfecha(Llamada* this,char* fecha);
int Llamada_setidStrP(Llamada* this, char *id);
int Llamada_setid(Llamada* this,int id);
int Llamada_getidP(Llamada* this,int* id);
int Llamada_setSol(Llamada* this,char* sol);
int Llamada_getsol(Llamada* this,char* sol);


#endif
