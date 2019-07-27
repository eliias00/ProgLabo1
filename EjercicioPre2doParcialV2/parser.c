#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si no se pudo completar la operacion.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int flag=0;
     char bufferId[50];
    char bufferTipo[128];
    char bufferCantidad[50];
    char bufferImporte[50];
    Employee* auxEmp;

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        auxEmp=employee_newParametros(bufferId,bufferTipo,bufferCantidad,bufferImporte);
        if(auxEmp != NULL)
        {
            ll_add(pArrayListEmployee, auxEmp);
        }
    }
    return 1;
}
