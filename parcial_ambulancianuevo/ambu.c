#include <stdio.h>
//#include <stdio_ext.h>
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
    int posLibreLlam;
    int flag=0;
    Asociado arrayAsociado [CAPACIDAD];
    Llamada arrayLlamada [CAPACIDAD];

    inicializarArray(arrayAsociado,CAPACIDAD);
    inicializarArrayLlam(arrayLlamada,CAPACIDAD);
    //**********************************************
    strcpy(arrayAsociado[0].apellido,"troncoso");
    arrayAsociado[0].isEmpty=0;
    strcpy(arrayAsociado[0].nombre,"elias");
    arrayAsociado[0].dni=42367509 ;
    arrayAsociado[0].edad=19;
    arrayAsociado[0].id=0;
    //**********************************************
    strcpy(arrayAsociado[1].apellido,"perez");
    arrayAsociado[1].isEmpty=0;
    strcpy(arrayAsociado[1].nombre,"laura");
    arrayAsociado[1].dni=42456789 ;
    arrayAsociado[1].edad=21;
    arrayAsociado[1].id=1;
    //***********************************************
    do
    {
        printf(":::::::::::::::::::::::::::::::\n");
        printf(": 1) ALTA        2)MODIFICAR  :\n");
        printf(": 3) BAJA        4)LLAMADA    :\n");
        printf(": 5)AMBULANCIA   6)INFORMES   :\n");
        printf(":::::::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        //    system("clear");
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
            if(!buscarElVacioLlam(arrayLlamada,CAPACIDAD,&posLibreLlam))
            {
                //  flag=1;
                switch(altaLlamada(arrayAsociado,arrayLlamada,CAPACIDAD,posLibreLlam))
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
        case 5:
            asignarAmbu(arrayLlamada,CAPACIDAD,posLibreLlam);
            break;

        case 6:
            //  mostrarArray(arrayAsociado,arrayLlamada,CAPACIDAD);
            informe(arrayAsociado,arrayLlamada,CAPACIDAD);
            break;

        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        //  system("clear");
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
    for(i=0; i<cant; i++)
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
            //     system("clear");
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
            // system("clear");
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
    for(i=0; i<cant; i++)
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
int mostrarArray(Asociado *array,Llamada *arrayLla,int cant)
{
    int i;
    int j;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre: %s\napellido: %s\nedad: %d\ndni: %d\n",array[i].nombre,array[i].apellido,array[i].edad,array[i].dni);
        }
    }
    for(j=0; j<cant; j++)
    {
        if(arrayLla[j].isEmpty!=VACIO)
        {
            printf("asociado: %d\nmotivo: %d\nestado: %d\ntiempo: %d\n",arrayLla[j].asociado,arrayLla[j].motivo,arrayLla[j].estado,arrayLla[j].tiempo);
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
int altaLlamada(Asociado *arrayAso,Llamada *array,int cant,int posLibre)
{
    int ret;
    char asociado[20];
    int auxAso;
    char motivo[50];
    int auxMot;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayAso[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayAso[i].id);
        }
    }
    if (!getInt("ingrese el id del asociado: ","error, vuelva a ingresar\n\n",1,20,1,asociado))
    {
        auxAso=atoi(asociado);
        array[posLibre].asociado=auxAso;
        if (!getInt("ingrese un motivo(1:INFARTO 2:ACV 3:GRIPE): ","error, vuelva a ingresar\n\n",1,4,1,motivo))
        {
            auxMot=atoi(motivo);
            array[posLibre].motivo=auxMot;

            printf("el estado es pendiente:1\n");
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
        printf("\nel estado es cumplido:2\n");
        array[posLibre].estado=2;
        array[posLibre].id=generarId2();
        array[posLibre].isEmpty=0;
        ret=0;
    }
    else
    {
        ret=1;
    }
    return ret;
}
int informe(Asociado *arrayAs,Llamada *arrayLl,int cant)
{
    int i;
    int posLibre;
    int cont1=0;
    int cont2=0;
    int cont3=0;
    for(i=0; i<cant; i++)
    {
        if(arrayAs[i].id==arrayLl[i+1].asociado && arrayAs[i].isEmpty!=VACIO)
        {
            printf("nombre: %s\napellido: %s\n",arrayAs[i].nombre,arrayAs[i].apellido);
        }
    if(arrayLl[i].motivo=1)
    {
        cont1++;
        printf("%d",cont1);
            break;
    }
    if(arrayLl[i].motivo=2)
    {
        cont2++;
         printf("%d",cont2);
            break;
    }
    if(arrayLl[i].motivo=3)
    {
        cont3++;
         printf("%d",cont3);
         break;
    }
    }

   return 0;
}
