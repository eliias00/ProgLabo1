#ifndef EDAD_H
#define EDAD_H

int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);

int getAge(char *msg,char *msgError,int minimo,int maximo,int reintentos,int *resultado);

int isValidAge(char* cadena);

#endif
