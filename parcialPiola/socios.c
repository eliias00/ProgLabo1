#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "autores.h"
#include "validaciones.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#include "informes.h"
#define VACIO -1
#define LLENO 1

static int generarIdSocios(void)
{
    static int id3=0;
    return id3++;
}
int inicializarArraySocios(Socios *array, int cant)
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
int buscarElVacioSocios(Socios *array,int cant,int *indice)
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
int altaSocios(Socios *array,int cant,int posLibre)
{
    int ret;
    char telefono[16];
    int auxTel;
    int posicion;
    FechaSoc auxFecha;

    if (!getName(array[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,31,1))
    {
        if (!getName(array[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,31,1))
        {
            if(!getSexo(array[posLibre].sexo,"ingrese un sexo(F/M): ","error,vuelva a ingresar\n\n",0,2,1))
            {
                if(!getInt("ingrese el telefono: ","\nerror,vuelva a intentar",6,16,1,telefono))
                {
                    auxTel=atoi(telefono);
                    array[posLibre].telefono=auxTel;
                    if(!getEmail(array[posLibre].email,"ingrese un email: ","error, vuelva a ingresar\n\n",6,31,1))
                    {
                        if (!getDia(&auxFecha.dia,"ingrese un dia: ","error, vuelva a ingresar\n\n",0,3,1))
                        {
                            if (!getMes(&auxFecha.mes,"ingrese un mes: ","error, vuelva a ingresar\n\n",0,3,1))
                            {
                                if (!getAnio(&auxFecha.anio,"ingrese un anio: ","error, vuelva a ingresar\n\n",0,6,1))
                                {

                                    array[posLibre].fechaSocio.dia=auxFecha.dia;
                                    array[posLibre].fechaSocio.mes=auxFecha.mes;
                                    array[posLibre].fechaSocio.anio=auxFecha.anio;

                                    array[posLibre].id=generarIdSocios();
                                    array[posLibre].isEmpty=LLENO;
                                    ret=0;
                                }
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
int buscaIdSocios (Socios *array, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Socios auxSoc;
    printf("\ningrese id de socio a buscar: ");
    scanf("%d", &auxSoc.id);
    for(i=0; i < cant; i++)
    {
        if (array[i].id == auxSoc.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modificacionSocios(Socios *array,int cant)
{
    int aceptar;
    char modificacion;
    int ret=-1;
    int posId3;
    int i;
    int posPrueba=0;
    int posicion;

    char idAut[50];
    int auxAut;

    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",array[i].id);
        }
    }
    if(!buscaIdSocios(array,cant,&posId3))
    {
        do
        {
            //      system("clear");
            printf("----------------\n");
            printf("- 1) APELLIDO  -\n");
            printf("- 2) NOMBRE    -\n");
            printf("- 3) SEXO      -\n");
            printf("- 4) TELEFONO  -\n");
            printf("- 5) EMAIL     -\n");
            printf("----------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar);
            //a      system("clear");
            switch(aceptar)
            {
            case 1:
                getName(array[posPrueba].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,31,1);
                break;
            case 2:
                getName(array[posPrueba].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,31,1);
                break;
            case 3:
                getSexo(array[posPrueba].sexo,"ingrese un sexo(F/M): ","error,vuelva a ingresar\n\n",0,2,1);
                break;
            case 4:
                getInt("ingrese el telefono: ","\nerror,vuelva a intentar",6,16,1,array[posPrueba].telefono);
                break;
            case 5:
                getEmail(array[posPrueba].email,"ingrese un email: ","error, vuelva a ingresar\n\n",6,31,1);
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
int bajaSocios(Socios *array,int cant)
{
    int posId1;
    char resp;
    int posBaja=0;
    int i;

    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",array[i].id);
        }
    }
    if(!buscaIdSocios(array,cant,&posId1))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja este socio");
            array[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
int OrdenamientoSocios(Socios *array,int cant)
{
    ///NO ME DEJA MOSTRAR LA FECHA
    int i;
    int j;
    int d;
    Socios aux;

    printf("  ordenado alfabeticamente ascendente por apellido:\n");
    for(i = 1; i < cant; i++)
    {
        aux = array[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, array[j - 1].apellido)<0)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(array[d].isEmpty!=VACIO)
        {
            printf("apellido:%s| nombre:%s| id:%d| sexo:%s| telefono:%d| email:%s| fecha(dia:%d,mes:%d,anio:%d)\n",array[d].apellido,array[d].nombre,array[d].id,array[d].sexo,array[d].telefono,array[d].email,array[d].fechaSocio.dia,array[d].fechaSocio.mes,array[d].fechaSocio.anio);
        }
    }

    return 0;
}

