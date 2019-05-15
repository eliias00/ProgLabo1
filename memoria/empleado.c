#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}
int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;
    if(this != NULL && peso>=10.5)
    {
        this->peso =peso;
        retorno = 0;
    }
    return retorno;
}
int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->peso;
        retorno = 0;
    }
    return retorno;
}
int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}
int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado , this->nombre);
        retorno = 0;
    }
    return retorno;
}







int Emp_setEstado(Empleado* this, int estado);
int Emp_getEstado(Empleado* this, int* resultado);

/*int isValidFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]<'0' || pStr[i]>'9')&&(pStr[i]!='.'))
        {

            return 0;
        }
        if(pStr[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}*/
int isValidName(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}



