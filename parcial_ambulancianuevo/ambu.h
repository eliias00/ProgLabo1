#ifndef AMBU_H
#define AMBU_H

typedef struct
{
    int id;
    int isEmpty;
    int dni;
    char nombre[50];
    char apellido[50];
    int edad;

}Asociado;

typedef struct
{
    int id;
    int isEmpty;
    int asociado;
    int motivo;
    int estado;
    int tiempo;

}Llamada;


int inicializarArray(Asociado *arrayAsociado, int cant);
int buscarElVacio(Asociado *arrayAsociado,int cant,int *indice);
int altaAsociado(Asociado *arrayAsociado,int cant,int posLibre);
int buscaId (Asociado *arrayAsociado, int cant, int *idEncontrado);
int modificacion(Asociado *arrayAso,int cant);
int baja(Asociado *array,int cant);
int mostrarArray(Asociado *array,Llamada *arrayLlA,int cant);
int inicializarArrayLlam(Llamada *array, int cant);
int buscarElVacioLlam(Llamada *array,int cant,int *indice);
int altaLlamada(Asociado *arraAso,Llamada *array,int cant,int posLibre);
int asignarAmbu(Llamada *array,int cant,int posLibre);
#endif
