#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int utn_getString(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* pResultado);

int isValidName(char *cadena);

int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

int isValidFloat(char* cadena);

int getFloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado);

int isValidInt(char* cadena);

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
#endif
