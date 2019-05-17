#ifndef MUSICO_H
#define MUSICO_H
#include "instrumento.h"
typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char apellido[51];
    int edad;
    int idOrq;
    int idIns;
}Musico;

int inicializarArrayM(Musico *array, int cant);
int buscarElVacioMusico(Musico *array,int cant,int *indice);
int altaMusico(Musico *array,Orquesta *array2,Instrumento *array3,int cant,int posLibre);
int buscaIdMusico (Musico *array, int cant, int *idEncontrado);
int modificacionMusico(Musico *array,Orquesta *array2,int cant);
int bajaMusico(Musico *array,int cant);
void imprimirMusico(Musico *array, Instrumento *array2,int cant1,int cant2);
#endif
