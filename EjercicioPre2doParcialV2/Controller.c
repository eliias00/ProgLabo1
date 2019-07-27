#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"
#include "utn.h"

/** \brief Busca el indice de un ID determinado.
 *
 * \param1 pArrayListEmployee LinkedList* donde buscar.
 * \param2 id int ID a buscar
 * \param3 index int* Indice del LinkedList donde se encuentra el Id buscado.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int controller_findID(LinkedList* pArrayListEmployee, int id, int* index)
{
    Employee* pAux;
    int length = ll_len(pArrayListEmployee);
    int i;
    int retorno = -1;
    int bufferInt;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<length; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            employee_getId(pAux, &bufferInt);
            if(bufferInt == id)
            {
                retorno = 0;
                *index = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Devuelve el array mas alto + 1.
 *
 * \param1 pArrayListEmployee LinkedList* donde buscar.
 * \return maxID int. Devuelve el ID mas alto + 1. -1 si se pasaron parametros nulos o la lista esta vacia.
 *
 */

int controller_arrayMaxID(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int length;
    int currentID;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);
        for(i=0; i<length; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            employee_getId(pAux, &currentID);
            if(currentID > maxID)
            {
                maxID = currentID;
            }
        }
    }
    maxID += 1;
    return maxID;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param1 path char*
 * \param2 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {

            if(parser_EmployeeFromText(pFile, pArrayListEmployee)==1)
            {
                printf("Carga exitosa.");
                retorno = 0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param1 path char*
 * \param2 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile = NULL;
    Employee auxEmpleado;
    Employee* pEmpleado;
    int lastIndex = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                fread(&auxEmpleado,sizeof(Employee),1,pFile);
                pEmpleado = employee_new();
                if( !employee_setId(pEmpleado,auxEmpleado.id) &&
                        !employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                        !employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                        !employee_setSueldo(pEmpleado,auxEmpleado.sueldo))
                {
                    ll_add(pArrayListEmployee,pEmpleado);
                    lastIndex++;
                }
                else
                {
                    employee_delete(pEmpleado);
                }
            }
            retorno = 0;
            ll_remove(pArrayListEmployee, lastIndex - 1); //el ultimo ingreso se repite, asi que se elimina
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("Archivo cargado exitosamente");
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param1 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pAux  = employee_new();
    char bufferChar[128];
    int bufferInt, bufferInt2;
    int id;
    if(pArrayListEmployee != NULL && pAux != NULL)
    {
        id = controller_arrayMaxID(pArrayListEmployee);
        if(id != -1)
        {
            if(utn_getName("\nIngrese el nombre: ", "\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128, 2, bufferChar))
            {
                return retorno;
            }
            if(utn_getUnsignedInt("\nIngrese las horas trabajadas: ", "\nError: Horas invalidas. Ingreselo nuevamente: ", 0, 4, 0, 24, 2, &bufferInt))
            {
                return retorno;
            }
            if(utn_getUnsignedInt("\nIngrese el sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: ", 0, 100, 0, 1000000, 2, &bufferInt2))
            {
                return retorno;
            }
            employee_setId(pAux, id);
            employee_setNombre(pAux, bufferChar);
            employee_setHorasTrabajadas(pAux, bufferInt);
            employee_setSueldo(pAux, bufferInt2);
            ll_add(pArrayListEmployee, pAux);
            printf("\nEmpleado ingresado correctamente\n");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param1 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferInt;
    int opcion;
    int index;
    char bufferChar[128];
    Employee* pAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID: ", "\nError: ID invalida. Ingreselo nuevamente: ", 0, 5, 0, 24, 2, &bufferInt))
        {
            if(!controller_findID(pArrayListEmployee, bufferInt, &index))
            {
                pAux = ll_get(pArrayListEmployee, index);
                if(!utn_getUnsignedInt("\n1) Modificar Nombre\n2) Modificar Horas Trabajadas\n3) Modificar sueldo\n", "\nError: Opcion invalida. Ingresela nuevamente: ", 0, 5, 0, 24, 2, &opcion))
                {
                    switch(opcion)
                    {
                    case 1:
                        if(!utn_getName("\nIngrese el nombre: ", "\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128, 2, bufferChar))
                        {
                            employee_setNombre(pAux, bufferChar);
                            retorno = 0;
                        }
                        break;
                    case 2:
                        if(!utn_getUnsignedInt("\nIngrese las horas trabajadas: ", "\nError: Horas invalidas. Ingreselo nuevamente: ", 0, 4, 0, 24, 2, &bufferInt))
                        {
                            employee_setHorasTrabajadas(pAux, bufferInt);
                            retorno = 0;
                        }
                        break;
                    case 3:
                        if(!utn_getUnsignedInt("\nIngrese el sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: ", 0, 100, 0, 1000000, 2, &bufferInt))
                        {
                            employee_setSueldo(pAux, bufferInt);
                            retorno = 0;
                        }
                        break;
                    default:
                        printf("Opcion invalida.");
                        break;
                    }
                }
            }
        }
        else
        {
            return retorno;
        }
    }
    if(!retorno)
    {
        printf("Empleado ingresado correctamente.");
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param1 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferInt;
    int index;
    Employee* pAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID: ", "\nError: ID invalida. Ingreselo nuevamente: ", 0, 5, 0, 24, 2, &bufferInt))
        {
            if(!controller_findID(pArrayListEmployee, bufferInt, &index))
            {
                retorno = 0;
                //ll_remove(pArrayListEmployee, index);
                pAux = ll_pop(pArrayListEmployee, index);
                employee_delete(pAux);
                printf("Empleado eliminado correctamente.");
            }
        }
        else
        {
            return retorno;
        }
    }
    return retorno;

}

/** \brief Listar empleados
 *
 * \param1 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int auxID, auxSueldo, auxHoras;
    char bufferChar[128];
    int length;
    int i;
    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);
        for(i=0; i<length; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado, &auxID);
            employee_getSueldo(pEmpleado, &auxSueldo);
            employee_getHorasTrabajadas(pEmpleado, &auxHoras);
            employee_getNombre(pEmpleado, bufferChar);
            printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: $%d\n", auxID, bufferChar, auxHoras, auxSueldo);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Ordena los empleados del LinkedList
 *
 * \param1 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_compararPorNombre, 0);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param1 path char*
 * \param2 pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si se pasaron parametros nulos o no se pudo completar la operacion.
 *
 */
int controller_saveAsText(char* path, LinkedList* this)
{
    int retorno = -1;
    int cantidadDeEntregas;
    int cantidadDeBultos = 0;
    int totalRegular, totalPlus, totalGold;
    float promedioDeBultos = 0;
    float importeTotal = 0;
    float promedioDeImporte = 0;
    LinkedList* registroGold = ll_newLinkedList();
    LinkedList* registroPlus = ll_newLinkedList();
    LinkedList* registroRegular = ll_newLinkedList();

    FILE *pFile = NULL;

    if(path != NULL && this != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            //Cantidad total de Entregas
            cantidadDeEntregas = ll_len(this);
            //Calculo de Entregas por Tipo
            registroGold = ll_filter(this, filtroGold);
      //      registroPlus = ll_filter(registro, entrega_filtrarPlus);
       //     registroRegular = ll_filter(registro, entrega_filtrarRegular);
            totalGold = ll_len(registroGold);
            //totalPlus = ll_len(registroPlus);
          /*  totalRegular = ll_len(registroRegular);
            //Cantidad y Promedio de Bultos
            cantidadDeBultos = controller_cantidadEntregada(registro);
            promedioDeBultos = (float)cantidadDeBultos / cantidadDeEntregas;
            //Importe promedio
            importeTotal = controller_importeEntregado(registro);
            promedioDeImporte = importeTotal / cantidadDeEntregas;
            //Carga al archivo*/
            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de Entregas: %d\n", cantidadDeEntregas);
            fprintf(pFile, "- Cantidad de Entregas por Tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n", totalGold/*, totalRegular, totalPlus*/);
          /*  fprintf(pFile, "- Cantidad Total de Bultos Entregados: %d\n", cantidadDeBultos);
            fprintf(pFile, "- Promedio de Bultos por Entrega: %.2f\n", promedioDeBultos);
            fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioDeImporte);
            fprintf(pFile, "*****************************");*/
            retorno = 0;
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("\nInforme generado exitosamente");
    }
    return retorno;
}
int f
{
    int retorno = -1;
    Employee *pEmp;
    int filtro;
    filtro = strcmp(pEmp->nombre, "GOLD");
    if(!filtro)
    {
        retorno = 1;
    }

    return retorno;
}
