#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
}Empleado;

int inicializarArray(Empleado *array,int len);
int buscarLibre(Empleado *array,int len,int* pIndex);
int buscarNombre(char* pNombre,Empleado auxEmpleado[],int len,int* pIndex);

int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

#endif // UTN_H_INCLUDED
