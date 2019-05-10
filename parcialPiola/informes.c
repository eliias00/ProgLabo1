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
#include "informes.h"º
#define VACIO -1
#define LLENO 0


int informeC(Prestamos *arrayP,Socios *arrayS,int cant)
{
    int i;
    int j;
    int auxID;

    printf("Ingrese el Id de libro");
    scanf("%d", &auxID);

    for(i=0; i<cant; i++)
    {
        if(auxID==arrayP[i].idLibro && arrayP[i].isEmpty == LLENO)
        {
            for(j=0; j<cant; j++)
            {
                if(arrayP[i].idLibro!=arrayP[j].idSocio && arrayS[i].isEmpty == LLENO)
                {    printf("___%d",arrayP[i].idSocio);
                    printf("apellido:%s| nombre:%s| id:%d| sexo:%s| telefono:%d| email:%s| fecha(dia:%d,mes:%d,anio:%d)\n",arrayS[j].apellido,arrayS[j].nombre,arrayS[j].id,arrayS[j].sexo,arrayS[j].telefono,arrayS[j].email,arrayS[j].fechaSocio.dia,arrayS[j].fechaSocio.mes,arrayS[j].fechaSocio.anio);
                }
            }

        }

    }
        return 0;
}
