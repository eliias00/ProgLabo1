#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ambu.h"
#include "valid.h"
#define CAPACIDAD 3
#define VACIO -1
#define LLENO 1
int functionMenu(void)
{
    int opcion;
    char seguir;
    int posLibre;
    int flag=0;
    int informe;
    Asociado arrayAsociado [CAPACIDAD];
    Llamada arrayLlamada [CAPACIDAD];
    inicializarArray(arrayAsociado,CAPACIDAD);

    do
    {
        printf(":::::::::::::::::::::::::::\n");
        printf(": 1) ALTA    2)MODIFICAR  :\n");
        printf(": 3) BAJA     4)INFORMAR  :\n");
        printf(":::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("clear");
        switch(opcion)
        {
        case 1:
            if(!buscarElVacio(arrayAsociado,CAPACIDAD,&posLibre))
            {
                flag=1;
                switch(altaAsociado(arrayAsociado,CAPACIDAD,posLibre))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");
                    break;

                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            else
            {
                printf("lleno");
            }
            break;
        case 2:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
               modificacion(arrayAsociado,CAPACIDAD);
            }
            break;
        case 3:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
                baja(arrayAsociado,CAPACIDAD);
            }
            break;
        case 4:
            mostrarArray(arrayAsociado,CAPACIDAD);
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system("clear");
    }
    while(seguir =='s');
    return 0;
}
static int generarId(void)
{
    static int id=0;
    return id++;
}
int inicializarArray(Asociado *arrayAsociado, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayAsociado[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacio(Asociado *arrayAsociado,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayAsociado[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaAsociado(Asociado *arrayAsociado,int cant,int posLibre)
{
    int ret;
    char dni[50];
    int auxDni;
    char edad[50];
    int auxEdad;

    if(!getInt("ingrese dni: ","error, vuelva a ingresar",8,9,1,dni))
    {
        auxDni=atoi(dni);
        arrayAsociado[posLibre].dni=auxDni;
        if (!getName(arrayAsociado[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
        {
            if (!getName(arrayAsociado[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,20,1))
            {
                if(!getInt("ingrese una edad: ","\nerror,vuelva a intentar",1,10,1,edad))
                {
                    auxEdad=atoi(edad);
                    arrayAsociado[posLibre].edad=auxEdad;
                    arrayAsociado[posLibre].id=generarId();
                    arrayAsociado[posLibre].isEmpty=0;
                    ret=0;
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
int buscaId (Asociado *arrayAsociado, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Asociado auxAso;
    printf("\ningrese id a buscar: ");
    scanf("%d", &auxAso.id);
    for(i=0; i < cant; i++)
    {
        if (arrayAsociado[i].id == auxAso.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modificacion(Asociado *arrayAso,int cant)
{
    int aceptar2;
    char modificacion;
    int ret=-1;
    int posId;
    int i;
    int posPrueba=0;
    for(i=0;i<cant;i++)
    {
        if(arrayAso[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayAso[i].id);
        }
    }
    if(!buscaId(arrayAso,cant,&posId))
    {
        do
        {
            system("clear");
            printf("--------------\n");
            printf("-5) NOMBRE   -\n");
            printf("-6) APELLIDO -\n");
            printf("--------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar2);
            system("clear");
            switch(aceptar2)
            {
            case 5:
                getName(arrayAso[posPrueba].nombre,"modifique el nombre: ","error, vuelva a ingresar\n\n",2,20,1);
                break;
            case 6:
                getName(arrayAso[posPrueba].apellido,"modifique el apellido: ","error, vuelva a ingresar\n\n",2,20,1);
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
int baja(Asociado *array,int cant)
{
    int posId;
    char resp;
    int posBaja=0;
    int i;
    for(i=0;i<cant;i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",array[i].id);
        }
    }
    if(!buscaId(array,cant,&posId))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja este empleado");
            array[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
int mostrarArray(Asociado *array,int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre: %s\napellido: %s\nedad: %d\ndni: %d\n",array[i].nombre,array[i].apellido,array[i].edad,array[i].dni);
        }
    }
    return 0;
}
static int generarId2(void)
{
    static int id2=0;
    return id2++;
}
int inicializarArrayLlam(Llamada *array, int cant)
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
int buscarElVacioLlam(Llamada *array,int cant,int *indice)
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
int altaLlamada(Llamada *array,int cant,int posLibre)
{
    int ret;
    char estado[50];
    int auxEstado;

        if (!getName(array[posLibre].asociado,"ingrese un asociado: ","error, vuelva a ingresar\n\n",2,20,1))
        {
            if (!getName(array[posLibre].motivo,"ingrese un motivo: ","error, vuelva a ingresar\n\n",2,20,1))
            {
                printf("el estado es pendiente:1");
                array[posLibre].estado=1;
                    array[posLibre].isEmpty=0;
                    ret=0;
            }
        }
    else
    {
        ret=1;
    }
    return ret;
}
int asignarAmbu(Llamada *array,int cant,int posLibre)
{
    int ret;
    char tiempo[50];
    int auxTiempo;

    if(!getInt("ingrese tiempo insumido: ","\nerror,vuelva a intentar",1,10,1,tiempo))
    {
        auxTiempo=atoi(tiempo);
        array[posLibre].tiempo=auxTiempo;
        printf("el estado es cumplido:2");
                array[posLibre].estado=2;
        array[posLibre].id=generarId();
        array[posLibre].isEmpty=0;
        ret=0;
    }
    else
    {
        ret=1;
    }
    return ret;
}
