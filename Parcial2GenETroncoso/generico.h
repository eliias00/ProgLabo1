#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED
typedef struct
{
    int dato1;
    char dato2[128];
    int dato3;
    float dato4;
}Generico;

Generico* Generico_new();
Generico* Generico_newParametros(char* dato1,char* dato2,char* dato3,char* dato4);
void Generico_delete(Generico *auxGenerico);
int Generico_setdato1Str(Generico* this, char *dato1);
int Generico_setdato1(Generico* this,int dato1);
int Generico_getdato1(Generico* this,int* dato1);
int Generico_setdato2(Generico* this,char* dato2);
int Generico_getdato2(Generico* this,char* dato2);
int Generico_setdato3Str(Generico* this, char *dato3);
int Generico_setdato3(Generico* this,int dato3);
int Generico_getdato3(Generico* this,int* dato3);
int Generico_setdato4Str(Generico* this, char *dato4);
int Generico_setdato4(Generico* this,float dato4);
int Generico_getdato4(Generico* this,float* dato4);
int Generico_compararPorNombre(void *this1,void *this2);
int Generico_filtrarGold(void* this);
int Generico_filtrarPlus(void* this);
int Generico_filtrarRegular(void* this);

#endif
