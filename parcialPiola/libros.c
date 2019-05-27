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

static int generarIdLibro(void)
{
    static int id2=0;
    return id2++;
}
int inicializarArrayLibros(Libros *arrayLibros, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayLibros[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioLibros(Libros *arrayLibros,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayLibros[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaLibros(Libros *arrayLibros,Autores *arrayAuto,int cant,int posLibre)
{
    int ret;

    char idAut[50];

    int auxAut;

    int posicion;

    if (!getName(arrayLibros[posLibre].titulo,"ingrese un titulo: ","error, vuelva a ingresar\n\n",10,51,1))
    {
        if(!buscaId(arrayAuto,cant,&posicion))
        {
            if(!getInt("ingrese el id del autor: ","\nerror,vuelva a intentar",0,20,1,idAut))
            {
                auxAut=atoi(idAut);
                arrayLibros[posLibre].idAutor=auxAut;
                arrayLibros[posLibre].id=generarIdLibro();
                arrayLibros[posLibre].isEmpty=LLENO;
                ret=0;
            }

        }
    }

    else
    {
        ret=1;
    }
    return ret;
}
int buscaIdLibros (Libros *array, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Libros auxlib;
    printf("\ningrese id de libro a buscar: ");
    scanf("%d", &auxlib.id);
    for(i=0; i < cant; i++)
    {
        if (array[i].id == auxlib.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modificacionLibros(Libros *arrayLibros,Autores *arrayAutores,int cant)
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

    for(i=0; i<cant; i++)
    {
        if(arrayLibros[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayLibros[i].id);
        }
    }
    if(!buscaIdLibros(arrayLibros,cant,&posId2))
    {
        do
        {
            system("clear");
            printf("------------------\n");
            printf("- 1) TITULO      -\n");
            printf("- 2) ID DE AUTOR -\n");
            printf("------------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar);
            system("clear");
            switch(aceptar)
            {
            case 1:
                getName(arrayLibros[posPrueba].titulo,"modifique el titulo: ","error, vuelva a ingresar\n\n",10,51,1);
                break;
            case 2:
                if(!buscaId(arrayAutores,cant,&posicion))
                {
                    getInt("modifique el id del autor: ","\nerror,vuelva a intentar",0,20,1,idAut);
                    auxAut=atoi(idAut);
                    arrayLibros[posPrueba].idAutor=auxAut;
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
int bajaLibros(Autores *arrayAuto,Libros *arrayLibros,int cant)
{
    int posId1;
    char resp;
    int posBaja=0;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayLibros[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayLibros[i].id);
        }
    }
    if(!buscaIdLibros(arrayLibros,cant,&posId1))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja este libro");
            arrayLibros[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
int OrdenamientoLibros(Libros *arrayLibros,Autores *arrayAuto,int cant)
{
    int i;
    int j;
    int d;

    Libros aux;
    printf("  ordenado alfabeticamente ascendente por titulo:\n");

    for(i = 1; i < cant; i++)
    {
        aux = arrayLibros[i];
        j = i;
        while(j > 0 && strcmp( aux.titulo, arrayLibros[j - 1].titulo)<0)
        {
            arrayLibros[j] = arrayLibros[j - 1];
            j--;
        }
        arrayLibros[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(arrayLibros[d].isEmpty!=VACIO)
        {
            printf("titulo:%s id de libro:%d id de autor:%d\n",arrayLibros[d].titulo,arrayLibros[d].id,arrayLibros[d].idAutor);
        }
    }
    return 0;
}
