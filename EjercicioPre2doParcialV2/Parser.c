#include "linkedlist.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, Linkedlist* listaEmpleados)
{
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    Employee* auxEmp;

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        auxEmp=employee_newParametros(bufferId, bufferName, bufferHoras);
        if(auxEmp != NULL)
        {
            ll_add(listaEmpleados, auxEmp);
        }
    }
    return 1; // OK
}

