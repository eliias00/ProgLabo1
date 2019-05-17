#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    int tipo;
}Instrumento;

int inicializarArrayIns(Instrumento *array, int cant);
int buscarElVacioIns(Instrumento *array,int cant,int *indice);
int altaIns(Instrumento *array,int cant,int posLibre);
int buscaIdInst (Instrumento *array, int cant, int *idEncontrado);
void imprimirInstrumento(Instrumento *array,int cant);

#endif

