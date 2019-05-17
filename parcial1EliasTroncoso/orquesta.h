#ifndef ORQUESTA_H
#define ORQUESTA_H

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char lugar[51];
    int tipo;

}Orquesta;

int inicializarArrayOrquesta(Orquesta *arrayOrquesta, int cant);
int buscarElVacioOrquesta(Orquesta *arrayOrquesta,int cant,int *indice);
int altaOrquesta(Orquesta *arrayOrquesta,int cant,int posLibre);
int buscaIdOrquesta (Orquesta *array, int cant, int *idEncontrado);
int bajaOrquesta(Orquesta *array,int cant);
void imprimirOrquestas(Orquesta *array, int cant);
#endif
