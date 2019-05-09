#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "autores.h"
#include "validaciones.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#define CAPACIDAD 3
#define VACIO -1
#define LLENO 1

static int generarIdPrestamo(void)
{
    static int id4=0;
    return id4++;
}
int inicializarArrayprestamo(Prestamos *array, int cant)
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
int buscarElVacioPrestamos(Prestamos *array,int cant,int *indice)
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
int altaPrestamos(Prestamos *array,Socios *array1,Libros *array2,int cant,int posLibre)
{
    int ret;
    char idAut[50];
    int auxAut;
    char idSoc[50];
    int auxSoc;
    int posicion;
    FechaPre auxFec;

    if(!buscaIdLibros(array2,cant,&posicion))
    {
        printf("se encontro");
        if(!getInt("ingrese el id del libro: ","\nerror,vuelva a intentar",0,20,1,idAut))
        {
            auxAut=atoi(idAut);
            array2[posLibre].idAutor=auxAut;

            if(!buscaIdSocios(array1,cant,&posicion))
            {
                printf("se encontro");
                if(!getInt("ingrese el id del socio: ","\nerror,vuelva a intentar",0,20,1,idSoc))
                {
                    auxSoc=atoi(idSoc);
                    array1[posLibre].id=auxAut;
                    if (!getDia(&auxFec.dia,"ingrese un dia: ","error, vuelva a ingresar\n\n",0,3,1))
                    {
                        if (!getMes(&auxFec.mes,"ingrese un mes: ","error, vuelva a ingresar\n\n",0,3,1))
                        {
                            if (!getAnio(&auxFec.anio,"ingrese un anio: ","error, vuelva a ingresar\n\n",0,6,1))
                            {
                                array[posLibre].fecPre.dia=auxFec.dia;
                                array[posLibre].fecPre.mes=auxFec.mes;
                                array[posLibre].fecPre.anio=auxFec.anio;
                                array[posLibre].id=generarIdPrestamo();
                                array[posLibre].isEmpty=0;
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
