#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#define ORQUESTA 50
#define MUSICOS 1000
#define INSTRUMENTO 20
#define LLENO 1
#define VACIO -1
int funcionMenu(void)
{
    int opcion;
    char seguir;
    int posLibreOrq;
    int posLibreMus;
    int posLibreIns;
    int flag=0;
    int flag1=0;
    int flag2=0;

    Orquesta arrayOrq[ORQUESTA];
    Musico arrayMus[MUSICOS];
    Instrumento arrayIns[INSTRUMENTO];

    inicializarArrayOrquesta(arrayOrq,ORQUESTA);
    inicializarArrayIns(arrayIns,INSTRUMENTO);
    inicializarArrayM(arrayMus,MUSICOS);
    //**********************************************
    /*   strcpy(arrayOrq[0].nombre,"jajaja");
       strcpy(arrayOrq[0].lugar,"lanus");
       arrayOrq[0].id=0;
       arrayOrq[0].isEmpty=LLENO;
       arrayOrq[0].tipo=1;

       strcpy(arrayMus[0].nombre,"leo");
       strcpy(arrayMus[0].apellido,"tornco");
       arrayMus[0].id=0;
       arrayMus[0].isEmpty=LLENO;
       arrayMus[0].idIns=0;
       arrayMus[0].idOrq=0;

       strcpy(arrayMus[1].nombre,"elias");
       strcpy(arrayMus[1].apellido,"jaja");
       arrayMus[1].id=1;
       arrayMus[1].isEmpty=LLENO;
       arrayMus[1].idIns=1;
       arrayMus[1].idOrq=0;

       strcpy(arrayIns[0].nombre,"cuerda");
       arrayIns[0].tipo=2;
       arrayIns[0].id=0;
       arrayIns[0].isEmpty=LLENO;

       strcpy(arrayIns[1].nombre,"guit");
       arrayIns[1].tipo=2;
       arrayIns[1].id=1;
       arrayIns[1].isEmpty=LLENO;*/
    //**********************************************
    do
    {
        printf(":::::::::::::::::::::::::::::::::\n");
        printf(":          ORQUESTA             :\n");
        printf(": 1) ALTA             2)BAJA    :\n");
        printf(":          3)IMPRIMIR           :\n");
        printf(":::::::::::::::::::::::::::::::::\n");
        printf(":          MUSICOS              :\n");
        printf(": 4) ALTA        5)MODIFICACION :\n");
        printf(": 6)BAJA         7)IMPRIMIR     :\n");
        printf(":::::::::::::::::::::::::::::::::\n");
        printf(":          INSTRUMENTOS         :\n");
        printf(": 8) ALTA            9)IMPRIMIR :\n");
        printf(":::::::::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("clear");
        switch(opcion)
        {
        case 1:
            if(!buscarElVacioOrquesta(arrayOrq,ORQUESTA,&posLibreOrq))
            {
                flag=1;
                switch(altaOrquesta(arrayOrq,ORQUESTA,posLibreOrq))
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
                printf("debe cargar la orquesta primero");
            }
            else
            {
                bajaOrquesta(arrayOrq,arrayMus,ORQUESTA,MUSICOS);
            }
            break;
        case 3:
            if(flag==0)
            {
                printf("debe cargar la orquesta primero");
            }
            else
            {
                imprimirOrquestas(arrayOrq,ORQUESTA);
            }
            break;
        case 4:
            if(flag1!=0 && flag!=0)
            {
                if(!buscarElVacioMusico(arrayMus,MUSICOS,&posLibreMus))
                {
                    flag2=1;
                    switch(altaMusico(arrayMus,arrayOrq,arrayIns,MUSICOS,posLibreMus))
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
            }
            else
            {
                printf("primero ingrese la orquesta y instrumento");
            }
            break;
        case 5:
            if(flag2==0)
            {
                printf("debe cargar el musico primero");
            }
            else
            {
                modificacionMusico(arrayMus,arrayOrq,MUSICOS);
            }
            break;
        case 6:
            if(flag2==0)
            {
                printf("debe cargar el musico primero");
            }
            else
            {
                bajaMusico(arrayMus,MUSICOS);
            }
            break;
        case 7:
            if(flag2==0)
            {
                printf("debe cargar el musico primero");
            }
            else
            {
                imprimirMusico(arrayMus,arrayIns,MUSICOS,INSTRUMENTO);
            }
            break;
        case 8:
            if(!buscarElVacioIns(arrayIns,INSTRUMENTO,&posLibreIns))
            {
                flag1=1;
                switch(altaIns(arrayIns,INSTRUMENTO,posLibreIns))
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
        case 9:
            if(flag1==0)
            {
                printf("debe cargar el instrumento primero");
            }
            else
            {
                imprimirInstrumento(arrayIns,INSTRUMENTO);
            }
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system("clear");
    }
    while(seguir =='s');
    return 0;
}
