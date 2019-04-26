#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int utn_getString(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* pResultado);

int isValidName(char *cadena);

int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);
#endif
