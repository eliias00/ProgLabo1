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


#endif
