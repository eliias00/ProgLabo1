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
#define CAPACIDAD 5
#define LLENO 1
#define VACIO -1
int funcionMenu(void)
{
    int opcion;
    char seguir;
    int posLibre1;
    int posLibre2;
    int posLibre3;
    int posLibre4;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    Autores arrayAut[CAPACIDAD];
    Libros ArrayLibros[CAPACIDAD];
    Socios arraySocios[CAPACIDAD];
    Prestamos arrayPrestamos[CAPACIDAD];

    inicializarArrayAuto(arrayAut,CAPACIDAD);
    inicializarArrayLibros(ArrayLibros,CAPACIDAD);
    inicializarArraySocios(arraySocios,CAPACIDAD);
    inicializarArrayprestamo(arrayPrestamos,CAPACIDAD);
    //**********************************************
    strcpy(arrayAut[0].apellido,"troncoso");
    strcpy(arrayAut[0].nombre,"elias");
    arrayAut[0].id=0;
    arrayAut[0].isEmpty=0;
    //**********************************************
    strcpy(ArrayLibros[0].titulo,"boca camp");
    ArrayLibros[0].id=0;
    ArrayLibros[0].isEmpty=LLENO;
    ArrayLibros[0].idAutor=0;
    //**********************************************
    strcpy(ArrayLibros[1].titulo,"riber");
    ArrayLibros[1].id=1;
    ArrayLibros[1].isEmpty=LLENO;
    ArrayLibros[1].idAutor=0;

    strcpy(ArrayLibros[2].titulo,"racing");
    ArrayLibros[2].id=2;
    ArrayLibros[2].isEmpty=LLENO;
    ArrayLibros[2].idAutor=0;
    //**********************************************
    strcpy(arraySocios[0].nombre,"leo");
    strcpy(arraySocios[0].apellido,"sisfdgnifsjnb");
    strcpy(arraySocios[0].email,"eliastroncoso@gmail.com");
    arraySocios[0].fechaSocio.dia=10;
    arraySocios[0].fechaSocio.mes=11;
    arraySocios[0].fechaSocio.anio=2020;
    arraySocios[0].id=0;
    arraySocios[0].isEmpty=LLENO;
    strcpy(arraySocios[0].sexo,"f");
    arraySocios[0].telefono=23455662;

    strcpy(arraySocios[1].nombre,"juan");
    strcpy(arraySocios[1].apellido,"letieri");
    strcpy(arraySocios[1].email,"eliastrfjgiejbfg@gmail.com");
    arraySocios[1].fechaSocio.dia=12;
    arraySocios[1].fechaSocio.mes=9;
    arraySocios[1].fechaSocio.anio=2027;
    arraySocios[1].id=1;
    arraySocios[1].isEmpty=LLENO;
    strcpy(arraySocios[1].sexo,"m");
    arraySocios[1].telefono=63486662;
    //**********************************************
    strcpy(arraySocios[2].nombre,"ailen");
    strcpy(arraySocios[2].apellido,"fjdngknj");
    strcpy(arraySocios[2].email,"trfjgiejbfg@gmail.com");
    arraySocios[2].fechaSocio.dia=5;
    arraySocios[2].fechaSocio.mes=10;
    arraySocios[2].fechaSocio.anio=2068;
    arraySocios[2].id=2;
    arraySocios[2].isEmpty=LLENO;
    strcpy(arraySocios[1].sexo,"m");
    arraySocios[2].telefono=63499962;
    //********************************************
    arrayPrestamos[0].idLibro=1;
    arrayPrestamos[0].idSocio=0;
    arrayPrestamos[0].isEmpty=LLENO;
    arrayPrestamos[0].fecPre.dia=10;
    arrayPrestamos[0].fecPre.mes=11;
    arrayPrestamos[0].fecPre.anio=2020;

    arrayPrestamos[1].idLibro=2;
    arrayPrestamos[1].idSocio=1;
    arrayPrestamos[1].isEmpty=LLENO;
    arrayPrestamos[1].fecPre.dia=10;
    arrayPrestamos[1].fecPre.mes=11;
    arrayPrestamos[1].fecPre.anio=2020;

    arrayPrestamos[2].idLibro=1;
    arrayPrestamos[2].idSocio=2;
    arrayPrestamos[2].isEmpty=LLENO;
    arrayPrestamos[2].fecPre.dia=11;
    arrayPrestamos[2].fecPre.mes=11;
    arrayPrestamos[2].fecPre.anio=2020;

    /* arrayPrestamos[3].idLibro=2;
     arrayPrestamos[3].idSocio=0;
     arrayPrestamos[3].isEmpty=LLENO;*/
    do
    {
        printf(":::::::::::::::::::::::::::::::::\n");
        printf(":          AUTORES              :\n");
        printf(": 1) ALTA      2)MODIFICACION   :\n");
        printf(": 3) BAJA      4)LISTAR         :\n");
        printf(":          LIBROS               :\n");
        printf(": 5) ALTA      6)MODIFICACION   :\n");
        printf(": 7) BAJA      8)LISTAR         :\n");
        printf(":          SOCIOS               :\n");
        printf(": 9) ALTA      10)MODIFICACION  :\n");
        printf(": 11) BAJA     12)LISTAR(D,E,F) :\n");
        printf(":          PRESTAMOS            :\n");
        printf(": 13) ALTA                      :\n");
        printf(":                  14) INFORMES :\n");
        printf(": 1:A   2:B                     :\n");
        printf(":::::::::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("clear");
        switch(opcion)
        {
        case 1:
            if(!buscarElVacioAuto(arrayAut,CAPACIDAD,&posLibre1))
            {
                flag1=1;
                switch(altaAutor(arrayAut,CAPACIDAD,posLibre1))
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
            if(flag1==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {
                modificacion(arrayAut,CAPACIDAD);
            }
            break;
        case 3:
            if(flag1==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {
                baja(arrayAut,CAPACIDAD);
            }
            break;
        case 4:
            if(flag1==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {
                OrdenamientoAutor(arrayAut,CAPACIDAD);
            }
            break;
        case 5:
            if(!buscarElVacioLibros(ArrayLibros,CAPACIDAD,&posLibre2))
            {
                flag2=1;
                switch(altaLibros(ArrayLibros,arrayAut,CAPACIDAD,posLibre2))
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
        case 6:
            if(flag2==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {
                modificacionLibros(ArrayLibros,arrayAut,CAPACIDAD);
            }
            break;
        case 7:
            if(flag2==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {
                bajaLibros(arrayAut,ArrayLibros,CAPACIDAD);
            }
            break;
        case 8:
            if(flag2==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {
                OrdenamientoLibros(ArrayLibros,arrayAut,CAPACIDAD);
            }
            break;

        case 9:
            if(!buscarElVacioSocios(arraySocios,CAPACIDAD,&posLibre3))
            {
                flag3=1;
                switch(altaSocios(arraySocios,CAPACIDAD,posLibre3))
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
        case 10:
            if(flag3==0)
            {
                printf("debe cargar el socio primero");
            }
            else
            {
                modificacionSocios(arraySocios,CAPACIDAD);
            }
            break;
        case 11:
            if(flag3==0)
            {
                printf("debe cargar el socio primero");
            }
            else
            {
                bajaSocios(arraySocios,CAPACIDAD);
            }
            break;
        case 12:
            if(flag3==0)
            {
                printf("debe cargar el socio primero");
            }
            else
            {
                OrdenamientoSocios(arraySocios,CAPACIDAD);
            }
            break;
        case 13:
            if(flag3==0)
            {
                printf("debe cargar las altas primero");
            }
            else
            {
            if(!buscarElVacioPrestamos(arrayPrestamos,CAPACIDAD,&posLibre4))
            {
                //flag=1;
                switch(altaPrestamos(arrayPrestamos,arraySocios,ArrayLibros,CAPACIDAD,posLibre4))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");
                    break;

                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            }
            break;
        case 14:
            // informeC(arrayPrestamos,arraySocios ,CAPACIDAD);
            // informeD(arrayPrestamos,arraySocios,ArrayLibros,CAPACIDAD);
            //   informeE(ArrayLibros,arrayPrestamos,CAPACIDAD);
            //   informeF(arraySocios,arrayPrestamos,CAPACIDAD);
            // informeG(ArrayLibros,CAPACIDAD,arrayPrestamos);
            //  informeH(arraySocios,CAPACIDAD,arrayPrestamos);
            informeI(ArrayLibros,CAPACIDAD);
            informeJ(arraySocios,CAPACIDAD);
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
        system("clear");
    }
    while(seguir =='s');
    return 0;
}
