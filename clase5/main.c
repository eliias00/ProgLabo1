#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#define CANTIDAD_ALUMNOS 5
int main()
{
    int aEdades[CANTIDAD_ALUMNOS];
    getArrayInt("\ningrese numeros: ","\nerror",0,15,5,aEdades,CANTIDAD_ALUMNOS);
  //  mostrarArray(aEdades,CANTIDAD_ALUMNOS);
    acomodamientoArray(aEdades,CANTIDAD_ALUMNOS);
    /*  aEdades[100]=22;
      bufferEdad = aEdades [100];
     /// pEdades = aEdades; es lo mismo de lo de abajo;
         pEdades = &aEdades[0];
     /// pEdades[88]=11; es lo mimsmo de lo de abajo;
         *(pEdades+88) = 11;
     /// bufferEdad =pEdades[88]; es lo mimsmo de lo de abajo;
         bufferEdad = *(pEdades+88);*/
}
