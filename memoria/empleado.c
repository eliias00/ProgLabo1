#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

Persona* Emp_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Emp_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}
void archivo (void)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];
    FILE *pFile=NULL;

    pFile = fopen("data.csv","r");

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                   bufferId,bufferNombre,bufferApellido,bufferEstado);
        }
        fclose(pFile);
    }
}
Persona *pers_new(char *id,char *nom,char *ape,char *est)
{
    Persona *retorno = NULL;
    Persona *auxPers;
    if(id != NULL && nom!=NULL && ape!=NULL && est!=NULL &&)
    {
        auxPers=Emp_new();
        if(auxPers!=NULL)
        {
          if(!Emp_setNombre(auxPers,nom)&& !Emp_setApellido(auxPers,ape)&&
             !Emp_setIdStr(auxPers,id)&& !Emp_setEstadoStr(auxPers,Est))
          {
            retorno=auxPers;
          }
          else
          {
            Emp_delete(auxPers);
          }
        }
    }
}
int Emp_setIdStr(Persona* this, char *id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !isvalidNamber(id))
    {
        retorno = Emp_setId(this, atoi(id));
    }
    return retorno;
}
int Emp_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Emp_getId(this,&bufferInt);
        sprintf(resultado,"%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}





int Emp_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL )
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}
int Emp_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado, this->nombre);
        retorno = 0;
    }
    return retorno;
}







int Emp_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL )
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}
int Emp_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado, this->apellido);
        retorno = 0;
    }
    return retorno;
}





int Emp_setEstado(Persona* this, char estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}
int Emp_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}


