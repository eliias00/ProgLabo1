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

#endif
