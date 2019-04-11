#ifndef BIBLIO_H
#define BIBLIO_H
int getArrayInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *arrayResultado,int limite);

int isValidArrayInt(int numeros,int minimo,int maximo);

int getArrayInt(char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos,int *arrayResultado,int limite);

int mostrarArray(int *arrayResultado , int limite);
#endif
