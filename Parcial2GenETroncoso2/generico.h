#ifndef Generico_H_INCLUDED
#define Generico_H_INCLUDED
typedef struct
{
    int idPart;
    char fecha[128];
    int tipoJue;
    int cantJue;
    int durPart;
    int costo;

}Partida;

Partida* Partida_new();
Partida* Partida_newParametros(char *idPart, char *fecha, char *tipoJue,char *cantJue,char *durPart);



#endif
