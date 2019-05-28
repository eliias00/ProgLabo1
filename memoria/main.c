#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "valid.h"
int main()
{
    Persona *pArrayPersona[1001];
    char bufferId      [1050];
    char bufferNombre  [1050];
    char bufferApellido[1050];
    char bufferEstado  [1050];
    int i = 0;
    FILE *pFile = NULL;

    pFile = fopen("data.csv","r");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            //printf("Lei: %s %s %s %s\n",bufferId,bufferNombre,bufferApellido,bufferEstado);

            pArrayPersona[i]=pers_new(bufferId,bufferNombre,bufferApellido,bufferEstado);
            if(pArrayPersona[i] != NULL)
            {
                printf("id:%s nombre:%s apellido:%s estado:%s\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            }
            i++;

        }
        while(!feof(pFile));

        fclose(pFile);
    }

    return 0;
}
