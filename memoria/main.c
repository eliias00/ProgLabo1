#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "valid.h"
int main()
{
    Persona *pArrayPersona[2000];
    int i = 0;
    int flag=0;
    char bufferId[50];
    char bufferName[50];
    char bufferApellido[50];
    char bufferEstado[50];

    FILE *pFile = NULL;
    pFile = fopen("data.csv", "r");

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferApellido, bufferEstado);
            if(flag == 0)
            {
                flag++;

            }
            pArrayPersona[i] = pers_new(bufferId, bufferName, bufferApellido, bufferEstado);
            i++;
      //  Emp_getApellido(pArrayPersona[50], bufferApellido);
        printf("nombre:%s | Apellido:%s\n",bufferName,bufferApellido);
        }
        fclose(pFile);
    }

    return 0;
}
