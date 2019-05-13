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
    int telefono;
    char email[31];
    FechaSoc fechaSocio;

}Socios;

int inicializarArraySocios(Socios *array, int cant);
int buscarElVacioSocios(Socios *array,int cant,int *indice);
int altaSocios(Socios *array,int cant,int posLibre);
int buscaIdSocios (Socios *array, int cant, int *idEncontrado);
int modificacionSocios(Socios *array,int cant);
int bajaSocios(Socios *array,int cant);
int OrdenamientoSocios(Socios *array,int cant);

#endif // SOCIOS_H


