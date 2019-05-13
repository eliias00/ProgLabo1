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
#include "informes.h"
#define VACIO -1
#define LLENO 1

int informeC(Prestamos *arrayP,Socios *arrayS,int cant)
{
    int i;
    int j;
    char idAut[50];
    int auxID;

    getInt("ingrese el id del libro: ","\nerror,vuelva a intentar",0,20,1,idAut);
    auxID=atoi(idAut);
    for(i=0; i<cant; i++)
    {
        if(auxID==arrayP[i].idLibro && arrayP[i].isEmpty==LLENO )
        {
            for(j=0; j<cant; j++)
            {
                if(arrayP[i].idSocio==arrayS[j].id )
                {
                    printf("\napellido:%s| nombre:%s| id:%d| sexo:%s| telefono:%d| email:%s| fecha(dia:%d,mes:%d,anio:%d)\n",arrayS[j].apellido,arrayS[j].nombre,arrayS[j].id,arrayS[j].sexo,arrayS[j].telefono,arrayS[j].email,arrayS[j].fechaSocio.dia,arrayS[j].fechaSocio.mes,arrayS[j].fechaSocio.anio);

                }
            }
        }
    }
        return 0;
}
int informeD(Prestamos *arrayP,Socios *arrayS,Libros *arrayL,int cant)
{
   int i;
   int j;
   int k;
   int auxID;
   char idAut[50];

    getInt("ingrese el id de socio: ","\nerror,vuelva a intentar",0,20,1,idAut);
    auxID=atoi(idAut);
     for(i=0; i<cant; i++)
    {
        if(auxID==arrayS[i].id && arrayS[i].isEmpty==LLENO)
        {
            for(j=0; j<cant; j++)
            {
                if(arrayS[i].id==arrayP[j].idSocio && arrayP[j].isEmpty==LLENO)
                {
                    for(k=0; k<cant; k++)
                    {
                        if(arrayP[j].idLibro==arrayL[k].id && arrayL[k].isEmpty==LLENO)
                        {
                            printf("titulo:%s id de libro:%d id de autor:%d\n",arrayL[k].titulo,arrayL[k].id,arrayL[k].idAutor);
                        }
                    }
                }
            }
            break;
        }
    }
        return 0;
}
/*void informeE(Libros *arrayL,Prestamos *arrayP,int cant)
{
    int i;
    int j;
    int flag=0;
    Libros minLibro[cant];
    int cantidadDeMinimos = 0;
    int vecesAlquilado;
    int menosVecesAlquilado;

    for(i=0; i<cant; i++)
    {
        if (flag==0 && arrayL[i].isEmpty ==LLENO)
        {
            flag=1;
            minLibro[0] = arrayL[i];
            vecesAlquilado =0;
            for(j=0; j<cant; j++)
            {
                if(arrayP[j].isEmpty == LLENO && arrayP[j].idLibro == arrayL[i].id)
                {
                    vecesAlquilado++;
                }
            }
            menosVecesAlquilado = vecesAlquilado;
            cantidadDeMinimos = 1;
        }
        else if(arrayL[i].isEmpty ==LLENO)
        {
            vecesAlquilado = 0;
            for(j=0; j<cant; j++)
            {
                if(arrayP[j].isEmpty == LLENO )
                {
                    if(arrayP[j].idLibro == arrayL[i].id)
                    {
                        vecesAlquilado++;
                    }
                }

            }
            if(vecesAlquilado < menosVecesAlquilado)
            {
                cantidadDeMinimos = 1;
                menosVecesAlquilado = vecesAlquilado;
                minLibro[0] = arrayL[i];
            }
            else if(vecesAlquilado == menosVecesAlquilado)
            {
                minLibro[cantidadDeMinimos] = arrayL[i];
                cantidadDeMinimos++;
            }
        }
    }
    for(i=0; i<cantidadDeMinimos; i++)
    {
        if(arrayL[i].isEmpty ==LLENO)
           {
             printf("titulo:%s id de libro:%d id de autor:%d\n",arrayL[i].titulo,arrayL[i].id,arrayL[i].idAutor);
           }
    }

}
int informeF(Socios *arrayS,Prestamos *arrayP,int cant)
{
    int i,j;
    int flag=0;
    Socios maxSoc[cant];
    int cantidadDeMax = 0;
    int vecesAlquilado;
    int masVecesAlquilado;

    for(i=0; i<cant; i++)
    {
        if (flag==0 && arrayS[i].isEmpty ==LLENO)
        {
            flag=1;
            maxSoc[0] = arrayS[i];
            vecesAlquilado =0;
            for(j=0; j<cant; j++)
            {
                if(arrayP[j].isEmpty == LLENO &&
                        arrayP[j].idSocio == arrayS[i].id)
                {
                    vecesAlquilado++;
                }

            }
            masVecesAlquilado = vecesAlquilado;
            cantidadDeMax = 1;
        }
        else if(arrayS[i].isEmpty ==LLENO)
        {
            vecesAlquilado = 0;
            for(j=0; j<cant; j++)
            {
                if(arrayP[j].isEmpty == LLENO )
                {
                    if(arrayP[j].idSocio == arrayS[i].id)
                    {
                        vecesAlquilado++;
                    }
                }

            }
            if(vecesAlquilado > masVecesAlquilado)
            {
                cantidadDeMax = 1;
                masVecesAlquilado = vecesAlquilado;
                maxSoc[0] = arrayS[i];
            }
            else if(vecesAlquilado == masVecesAlquilado)
            {
                maxSoc[cantidadDeMax] =  arrayS[i];
                cantidadDeMax++;
            }
        }
    }
    for(i=0; i<cantidadDeMax; i++)
    {
        if(arrayS[i].isEmpty ==LLENO)
        {
            printf("apellido:%s| nombre:%s| id:%d| sexo:%s| telefono:%d| email:%s| fecha(dia:%d,mes:%d,anio:%d)\n",arrayS[i].apellido,arrayS[i].nombre,arrayS[i].id,arrayS[i].sexo,arrayS[i].telefono,arrayS[i].email,arrayS[i].fechaSocio.dia,arrayS[i].fechaSocio.mes,arrayS[i].fechaSocio.anio);
        }
    }
    return 0;
}*/

int informeG(Libros *arrayL,int cant,Prestamos *arrayP)
{

    int i,j;
    FechaPre auxFec;


    printf("Ingrese el dia a buscar: ");
    scanf("%d", &auxFec.dia);
    printf("Ingrese el mes a buscar: ");
    scanf("%d", &auxFec.mes);
    printf("Ingrese el anio a buscar: ");
    scanf("%d", &auxFec.anio);

    for(i=0; i<cant; i++)
    {
        if(auxFec.dia==arrayP[i].fecPre.dia && auxFec.mes==arrayP[i].fecPre.mes && auxFec.anio==arrayP[i].fecPre.anio && arrayP[i].isEmpty==LLENO)
        {
            for(j=0; j<cant; j++)
            {
                if(arrayP[i].idLibro==arrayL[j].id && arrayL[j].isEmpty==LLENO)
                {
                    printf("titulo:%s id de libro:%d id de autor:%d\n",arrayL[i].titulo,arrayL[i].id,arrayL[i].idAutor);
                }
            }
        }
    }
    return 0;
}
int informeH(Socios *arrayS,int cant,Prestamos *arrayP)
{
    FechaPre aux;
    int i,j;

    printf("Ingrese el dia a buscar: ");
    scanf("%d", &aux.dia);
    printf("Ingrese el mes a buscar: ");
    scanf("%d", &aux.mes);
    printf("Ingrese el anio a buscar: ");
    scanf("%d", &aux.anio);
    for(i=0; i<cant; i++)
    {
        if(aux.dia==arrayP[i].fecPre.dia && aux.mes==arrayP[i].fecPre.mes && aux.anio==arrayP[i].fecPre.anio && arrayP[i].isEmpty==LLENO)
        {
            for(j=0; j<cant; j++)
            {
                if(arrayP[i].idSocio==arrayS[j].id && arrayP[j].isEmpty==LLENO)
                {
                    printf("apellido:%s| nombre:%s| id:%d| sexo:%s| telefono:%d| email:%s| fecha(dia:%d,mes:%d,anio:%d)\n",arrayS[i].apellido,arrayS[i].nombre,arrayS[i].id,arrayS[i].sexo,arrayS[i].telefono,arrayS[i].email,arrayS[i].fechaSocio.dia,arrayS[i].fechaSocio.mes,arrayS[i].fechaSocio.anio);
                }
            }
        }
    }
    return 0;
}
void informeI(Libros *array,int cantidad)
{
    int k;
    int flagSwap;
    Libros auxiliarSwap;
    do
    {
        flagSwap=0;
        for(k=0; k<cantidad-1; k++)
        {
            if(strncmp(array[k].titulo,array[k+1].titulo,50)<0)
            {
                     auxiliarSwap=array[k];
                array[k]=array[k+1];
              array[k+1]=auxiliarSwap;
                flagSwap=1;

            }
        }
    }while(flagSwap==0);
}
void informeJ(Socios *array,int cant)
{
    int i;
    int j;
    int d;
    Socios aux;

    for(i = 1; i < cant; i++)
    {
        aux = array[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, array[j - 1].apellido)>0)
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
}
