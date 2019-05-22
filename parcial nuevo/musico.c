#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "informes.h"
#define VACIO -1
#define LLENO 1

static int generarIdM(void)
{
    static int id=0;
    return id++;
}
int inicializarArrayM(Musico *array, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        array[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioMusico(Musico *array,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaMusico(Musico *array,Orquesta *array2,Instrumento *array3,int cant,int posLibre)
{
    int ret;
    char edad[50];
    int auxEdad;
    int posicion;
    char idAut[50];
    int auxAut;
    char idIns[50];
    int auxIns;

    if (!getName(array[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
        if (!getName(array[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",5,51,1))
        {
            if(!getInt("ingrese edad: ","\nerror,vuelva a intentar",1,3,1,edad))
            {
                auxEdad=atoi(edad);
                array[posLibre].edad=auxEdad;
                if(!buscaIdOrquesta(array2,cant,&posicion))
                {
                    printf("se encontro");
                    if(!getInt("ingrese el id de la orquesta: ","\nerror,vuelva a intentar",0,20,1,idAut))
                    {
                        auxAut=atoi(idAut);
                        array[posLibre].idOrq=auxAut;
                        if(!buscaIdInst(array3,cant,&posicion))
                        {
                            printf("se encontro");
                            if(!getInt("ingrese el id del instrumento: ","\nerror,vuelva a intentar",0,20,1,idIns))
                            {
                                auxIns=atoi(idIns);
                                array[posLibre].idIns=auxIns;
                                array[posLibre].id=generarIdM();
                                array[posLibre].isEmpty=LLENO;
                                ret=0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}
int buscaIdMusico (Musico *array, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Musico auxMus;
    printf("\ningrese id de musico a buscar: ");
    scanf("%d", &auxMus.id);
    for(i=0; i < cant; i++)
    {
        if (array[i].id == auxMus.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modificacionMusico(Musico *array,Orquesta *array2,int cant)
{
    int aceptar;
    char modificacion;
    int ret=-1;
    int posId2;
    int i;
    int posPrueba=0;
    int posicion;
    char idAut[50];
    int auxAut;
    char edad[50];
    int auxEdad;

    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre:%s apellido:%s id:%d\n",array[i].nombre,array[i].apellido,array[i].id);
        }
    }
    if(!buscaIdMusico(array,cant,&posId2))
    {
        do
        {
            system("clear");
            printf("------------------\n");
            printf("- 1) EDAD           -\n");
            printf("- 2) ID DE ORQUESTA -\n");
            printf("------------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar);
            system("clear");
            switch(aceptar)
            {
            case 1:
                getInt("ingrese edad: ","\nerror,vuelva a intentar",0,3,1,edad);
                auxEdad=atoi(edad);
                array[posPrueba].edad=auxEdad;
                break;
            case 2:
                if(!buscaIdOrquesta(array2,cant,&posicion))
                {
                    getInt("modifique el id de la orquesta: ","\nerror,vuelva a intentar",0,2,1,idAut);
                    auxAut=atoi(idAut);
                    array[posPrueba].idOrq=auxAut;
                }
                break;
            }
            printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
            scanf("%s",&modificacion);
            system("clear");
        }
        while(modificacion=='s');
        ret=0;
    }
    else
    {
        printf("no se encontro id");
    }
    return ret;
}
int bajaMusico(Musico *array,int cant)
{
    int posId1;
    char resp;
    int posBaja=0;
    int i;

    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre:%s apellido:%s id:%d\n",array[i].nombre,array[i].apellido,array[i].id);
        }
    }
    if(!buscaIdMusico(array,cant,&posId1))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja esta Orquesta");
            array[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
void imprimirMusico(Musico *array, Instrumento *array2,int cant1,int cant2)
{
    int i;
    int j;
    for(i=0; i<cant1; i++)
    {
        if(array[i].isEmpty==LLENO )
        {
            for(j=0; j<cant2; j++)
            {
                if(array2[j].isEmpty==LLENO)
                {
                    if(array[i].idIns==array2[j].id)
                    {
                        printf("nombre:%s apellido:%s id:%d nombre:%s tipo:%d\n",array[i].nombre,array[i].apellido,array[i].id,array2[i].nombre,array2[i].tipo);
                    }
                }
            }
        }
    }
}
int bajaOrquesta(Orquesta *arrayOrq,Musico *arrayMus,int cantOrq,int cantMus)
{
    int posId1;
    char resp;
    int posBaja=0;
    int i;
    int j;

    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayOrq[i].id);
        }
    }
    if(!buscaIdOrquesta(arrayOrq,cantOrq,&posId1))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            for(j=0; j<cantMus; j++)
            {
                if(arrayMus[j].idOrq==arrayOrq[i].id)
                {
                    arrayOrq[posBaja].isEmpty=VACIO;
                    arrayMus[j].isEmpty=VACIO;
                }
            }
            printf("se ah dado de baja esta Orquesta y a los musicos que la componen");
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
