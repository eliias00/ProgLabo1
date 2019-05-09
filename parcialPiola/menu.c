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

int funcionMenu(void)
{
    int opcion;
    char seguir;
    int posLibre1;
    int posLibre2;
    int posLibre3;
    int posLibre4;
    int posLibreLlam;
    int flag=0;

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
    strcpy(ArrayLibros[0].titulo,"b");
    ArrayLibros[0].id=0;
    ArrayLibros[0].isEmpty=0;
    ArrayLibros[0].idAutor=0;
    strcpy(ArrayLibros[1].titulo,"a");
    ArrayLibros[1].id=1;
    ArrayLibros[1].isEmpty=0;
    ArrayLibros[1].idAutor=0;
    //**********************************************
    strcpy(arraySocios[0].nombre,"leo");
    strcpy(arraySocios[0].apellido,"sisfdgnifsjnb");
    strcpy(arraySocios[0].email,"eliastroncoso@gmail.com");
    arraySocios[0].fechaSocio.dia=10;
    arraySocios[0].fechaSocio.mes=11;
    arraySocios[0].fechaSocio.anio=2020;
    arraySocios[0].id=0;
    arraySocios[0].isEmpty=0;
    strcpy(arraySocios[0].sexo,"f");
    strcpy(arraySocios[0].telefono,"42345566");
    //**********************************************
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
        printf(":::::::::::::::::::::::::::::::::\n");
        printf("elija una opcion: ");
        scanf("%d", &opcion);
    //    system("clear");
        switch(opcion)
        {
        case 1:
            if(!buscarElVacioAuto(arrayAut,CAPACIDAD,&posLibre1))
            {
             //   flag=1;
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
          /*  if(flag==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {*/
                modificacion(arrayAut,CAPACIDAD);
      //      }
            break;
        case 3:
         /*   if(flag==0)
            {
                printf("debe cargar al autor primero");
            }
            else
            {*/
                baja(arrayAut,CAPACIDAD);
        //   }
            break;
        case 4:
               OrdenamientoAutor(arrayAut,CAPACIDAD);
            break;
        case 5:
            if(!buscarElVacioLibros(ArrayLibros,CAPACIDAD,&posLibre2))
            {
//flag=1;
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
           // else
            //{
             //   printf("lleno");
           // }
            break;
        case 6:
           /* if(flag==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {*/
                modificacionLibros(ArrayLibros,arrayAut,CAPACIDAD);
          //  }
            break;
        case 7:
         /*   if(flag==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {*/
                bajaLibros(arrayAut,ArrayLibros,CAPACIDAD);
          //  }
            break;
        case 8:
               OrdenamientoLibros(ArrayLibros,arrayAut,CAPACIDAD);
            break;

             case 9:
            if(!buscarElVacioSocios(arraySocios,CAPACIDAD,&posLibre3))
            {
//flag=1;
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
           // else
            //{
             //   printf("lleno");
           // }
            break;
        case 10:
           /* if(flag==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {*/
                modificacionSocios(arraySocios,CAPACIDAD);
          //  }
            break;
        case 11:
         /*   if(flag==0)
            {
                printf("debe cargar al libro primero");
            }
            else
            {*/
               bajaSocios(arraySocios,CAPACIDAD);
          //  }
            break;
        case 12:
               OrdenamientoSocios(arraySocios,CAPACIDAD);
            break;
        case 13:
              if(!buscarElVacioPrestamos(arrayPrestamos,CAPACIDAD,&posLibre4))
            {   //flag=1;
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
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        scanf("%s",&seguir);
          system("clear");
    }
    while(seguir =='s');
    return 0;
}
