#ifndef PRESTAMOS_H
#define PRESTAMOS_H

typedef struct
{
    int dia;
    int mes;
    int anio;
}FechaPre;

typedef struct
{
    int id;
    int isEmpty;
    int idLibro;
    int idSocio;
    FechaPre fecPre;
}Prestamos;
int inicializarArrayprestamo(Prestamos *array, int cant);
int buscarElVacioPrestamos(Prestamos *array,int cant,int *indice);
int altaPrestamos(Prestamos *array,Socios *array1,Libros *array2,int cant,int posLibre);
#endif
