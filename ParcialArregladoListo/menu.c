#include <stdio.h>
//#include <stdio_ext.h>
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
#include "informes.h"
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
       strcpy(arrayOrq[0].nombre,"orquesta1");
       strcpy(arrayOrq[0].lugar,"lugar1");
       arrayOrq[0].id=1;
       arrayOrq[0].isEmpty=LLENO;
       arrayOrq[0].tipo=1;

       strcpy(arrayOrq[1].nombre,"orquesta2");
       strcpy(arrayOrq[1].lugar,"lugar1");
       arrayOrq[1].id=2;
       arrayOrq[1].isEmpty=LLENO;
       arrayOrq[1].tipo=2;

       strcpy(arrayOrq[3].nombre,"orquesta3");
       strcpy(arrayOrq[3].lugar,"lugar2");
       arrayOrq[3].id=3;
       arrayOrq[3].isEmpty=LLENO;
       arrayOrq[3].tipo=3;

       strcpy(arrayOrq[4].nombre,"orquesta4");
       strcpy(arrayOrq[4].lugar,"lugar3");
       arrayOrq[4].id=4;
       arrayOrq[4].isEmpty=LLENO;
       arrayOrq[4].tipo=2;

//*******************************************
    /*   strcpy(arrayMus[0].nombre,"mus1");
       strcpy(arrayMus[0].apellido,"mus1");
       arrayMus[0].id=1;
       arrayMus[0].edad=30;
       arrayMus[0].isEmpty=LLENO;
       arrayMus[0].idIns=2;
       arrayMus[0].idOrq=1;

       strcpy(arrayMus[1].nombre,"mus2");
       strcpy(arrayMus[1].apellido,"mus2");
       arrayMus[1].id=2;
       arrayMus[1].edad=20;
       arrayMus[1].isEmpty=LLENO;
       arrayMus[1].idIns=5;
       arrayMus[1].idOrq=1;

        strcpy(arrayMus[2].nombre,"mus3");
       strcpy(arrayMus[2].apellido,"mus3");
       arrayMus[2].id=3;
       arrayMus[2].edad=25;
       arrayMus[2].isEmpty=LLENO;
       arrayMus[2].idIns=2;
       arrayMus[2].idOrq=4;

       strcpy(arrayMus[3].nombre,"mus4");
       strcpy(arrayMus[3].apellido,"mus4");
       arrayMus[3].id=4;
       arrayMus[3].edad=27;
       arrayMus[3].isEmpty=LLENO;
       arrayMus[3].idIns=1;
       arrayMus[3].idOrq=4;

       strcpy(arrayMus[4].nombre,"mus5");
       strcpy(arrayMus[4].apellido,"mus5");
       arrayMus[4].id=5;
       arrayMus[4].edad=22;
       arrayMus[4].isEmpty=LLENO;
       arrayMus[4].idIns=3;
       arrayMus[4].idOrq=1;

       strcpy(arrayMus[5].nombre,"mus6");
       strcpy(arrayMus[5].apellido,"mus6");
       arrayMus[5].id=6;
       arrayMus[5].edad=35;
       arrayMus[5].isEmpty=LLENO;
       arrayMus[5].idIns=4;
       arrayMus[5].idOrq=3;*/
//*********************************************
       strcpy(arrayIns[0].nombre,"inst1");
       arrayIns[0].tipo=1;
       arrayIns[0].id=1;
       arrayIns[0].isEmpty=LLENO;

       strcpy(arrayIns[1].nombre,"inst2");
       arrayIns[1].tipo=2;
       arrayIns[1].id=2;
       arrayIns[1].isEmpty=LLENO;

       strcpy(arrayIns[2].nombre,"inst3");
       arrayIns[2].tipo=2;
       arrayIns[2].id=3;
       arrayIns[2].isEmpty=LLENO;

       strcpy(arrayIns[3].nombre,"inst4");
       arrayIns[3].tipo=3;
       arrayIns[3].id=4;
       arrayIns[3].isEmpty=LLENO;

        strcpy(arrayIns[4].nombre,"inst5");
       arrayIns[4].tipo=4;
       arrayIns[4].id=5;
       arrayIns[4].isEmpty=LLENO;
       strcpy(arrayIns[0].nombre,"cuer1");
       arrayIns[0].tipo=1;
       arrayIns[0].id=1;
       arrayIns[0].isEmpty=LLENO;

       strcpy(arrayIns[1].nombre,"cuer2");
       arrayIns[1].tipo=1;
       arrayIns[1].id=2;
       arrayIns[1].isEmpty=LLENO;

       strcpy(arrayIns[2].nombre,"cuer3");
       arrayIns[2].tipo=1;
       arrayIns[2].id=3;
       arrayIns[2].isEmpty=LLENO;

       strcpy(arrayIns[3].nombre,"cuer4");
       arrayIns[3].tipo=1;
       arrayIns[3].id=4;
       arrayIns[3].isEmpty=LLENO;

       strcpy(arrayIns[4].nombre,"vien1");
       arrayIns[4].tipo=2;
       arrayIns[4].id=5;
       arrayIns[4].isEmpty=LLENO;

       strcpy(arrayIns[5].nombre,"vien2");
       arrayIns[5].tipo=3;
       arrayIns[5].id=6;
       arrayIns[5].isEmpty=LLENO;

       strcpy(arrayIns[6].nombre,"vien3");
       arrayIns[6].tipo=2;
       arrayIns[6].id=7;
       arrayIns[6].isEmpty=LLENO;

       strcpy(arrayIns[7].nombre,"vien4");
       arrayIns[7].tipo=3;
       arrayIns[7].id=8;
       arrayIns[7].isEmpty=LLENO;

       strcpy(arrayIns[8].nombre,"percu1");
       arrayIns[8].tipo=4;
       arrayIns[8].id=9;
       arrayIns[8].isEmpty=LLENO;

        strcpy(arrayMus[0].nombre,"mus1");
       strcpy(arrayMus[0].apellido,"mus1");
       arrayMus[0].id=1;
       arrayMus[0].edad=30;
       arrayMus[0].isEmpty=LLENO;
       arrayMus[0].idIns=1;
       arrayMus[0].idOrq=1;

       strcpy(arrayMus[1].nombre,"mus2");
       strcpy(arrayMus[1].apellido,"mus2");
       arrayMus[1].id=2;
       arrayMus[1].edad=20;
       arrayMus[1].isEmpty=LLENO;
       arrayMus[1].idIns=2;
       arrayMus[1].idOrq=1;

        strcpy(arrayMus[2].nombre,"mus3");
       strcpy(arrayMus[2].apellido,"mus3");
       arrayMus[2].id=3;
       arrayMus[2].edad=25;
       arrayMus[2].isEmpty=LLENO;
       arrayMus[2].idIns=3;
       arrayMus[2].idOrq=1;

       strcpy(arrayMus[3].nombre,"mus4");
       strcpy(arrayMus[3].apellido,"mus4");
       arrayMus[3].id=4;
       arrayMus[3].edad=27;
       arrayMus[3].isEmpty=LLENO;
       arrayMus[3].idIns=4;
       arrayMus[3].idOrq=4;

       strcpy(arrayMus[4].nombre,"mus5");
       strcpy(arrayMus[4].apellido,"mus5");
       arrayMus[4].id=5;
       arrayMus[4].edad=22;
       arrayMus[4].isEmpty=LLENO;
       arrayMus[4].idIns=5;
       arrayMus[4].idOrq=4;

       strcpy(arrayMus[5].nombre,"mus6");
       strcpy(arrayMus[5].apellido,"mus6");
       arrayMus[5].id=6;
       arrayMus[5].edad=35;
       arrayMus[5].isEmpty=LLENO;
       arrayMus[5].idIns=6;
       arrayMus[5].idOrq=4;

       strcpy(arrayMus[6].nombre,"mus7");
       strcpy(arrayMus[6].apellido,"mus7");
       arrayMus[6].id=7;
       arrayMus[6].edad=27;
       arrayMus[6].isEmpty=LLENO;
       arrayMus[6].idIns=7;
       arrayMus[6].idOrq=4;

       strcpy(arrayMus[7].nombre,"mus8");
       strcpy(arrayMus[7].apellido,"mus8");
       arrayMus[7].id=8;
       arrayMus[7].edad=22;
       arrayMus[7].isEmpty=LLENO;
       arrayMus[7].idIns=8;
       arrayMus[7].idOrq=4;

       strcpy(arrayMus[8].nombre,"mus9");
       strcpy(arrayMus[8].apellido,"mus9");
       arrayMus[8].id=9;
       arrayMus[8].edad=35;
       arrayMus[8].isEmpty=LLENO;
       arrayMus[8].idIns=9;
       arrayMus[8].idOrq=4;
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
        printf(":        10) INFORMES           :\n");
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
        case 10:
                informes(arrayOrq,arrayIns,arrayMus,ORQUESTA,MUSICOS,INSTRUMENTO);
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system("clear");
    }
    while(seguir =='s');
    return 0;
}
