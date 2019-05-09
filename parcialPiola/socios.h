#ifndef SOCIOS_H
#define SOCIOS_H

typedef struct
{
    int dia;
    int mes;
    int anio;
}FechaSoc;

typedef struct
{
    int id;
    int isEmpty;
    char nombre[31];
    char apellido[31];
    char sexo[1];
    char telefono[16];
    char email[31];
    FechaSoc fechaSocio;

}Socios;

#endif // SOCIOS_H


