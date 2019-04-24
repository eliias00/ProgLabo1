#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

typedef struct
{
    char nombre[50];
    int  idEmpleado;
    int  isEmpty;
}Empleado;

int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

//a partir de esta funcion puedo crear muchas otras de validacion
int utn_isValidIntNumber(char* cadena);

int utn_getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

int inicializarArray(Empleado *array,int len);


#endif // UTN_H_INCLUDED
