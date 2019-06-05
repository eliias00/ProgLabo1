#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee *auxEmp;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras,bufferSueldo);
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras,bufferSueldo);
            auxEmp=employee_newParametros(bufferId, bufferName, bufferHoras,bufferSueldo);
             ll_add(pArrayListEmployee, auxEmp);
        }
    }
    return 1;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[50];
    char bufferName[50];
    char bufferHoras[50];
    char bufferSueldo[50];
    Employee *auxEmp;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras,bufferSueldo);
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras,bufferSueldo);
            auxEmp=employee_newParametros(bufferId, bufferName, bufferHoras,bufferSueldo);
             ll_add(pArrayListEmployee, auxEmp);
        }

    }
    return 1;
}
