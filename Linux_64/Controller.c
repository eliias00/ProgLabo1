#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);

    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int bufferId;
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee *auxEmp=employee_new();

    if (!getName(bufferName,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
        if(!getInt("ingrese las horas: ","\nerror,vuelva a intentar",1,4,1,bufferHoras))
        {
            if(!getInt("ingrese el sueldo: ","\nerror,vuelva a intentar",1,9,1,bufferSueldo))
            {
                bufferId=generadorId(pArrayListEmployee);
                ll_add(pArrayListEmployee,auxEmp);
                printf("empleado ingresado correctamente");
            }

        }
    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int cant;
    int auxId;
    int id;
    int posId;
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee* auxiliar;
    int opcionM;

    cant=ll_len(pArrayListEmployee);

    for(i=0; i<cant+1; i++)
    {
        printf("id disponibles:%d\n",i);
    }
    if(!buscaId(pArrayListEmployee, &posId))
    {
        printf("Elija que campo desea modificar:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n");
        scanf("%d", &opcionM);
      /*  switch(opcionM)
        {
      /  case 1:
            if(!getName(bufferName,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
            {
                if(!employee_setName(empleado, nombre))
                {
                    retorno = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        case 2:
            if(!getInt(&horasTrabajadas,"Ingrese las nuevas horas: ","Reingrese un numero valido",0,99999,2))
            {
                if(!employee_setHours(empleado, horasTrabajadas))
                {
                    retorno=0;
                    break;
                }
            }
            else
            {
                break;
            }
        case 3:
            if(!getInt(&sueldo,"Ingrese el nuevo sueldo: ","Reingrese un numero valido",0,99999,2))
            {
                if(!employee_setSalary(empleado, sueldo))
                {
                    retorno=0;
                    break;
                }
            }
            else
            {
                break;
            }
        default:
            printf("Opcion invalida");
        }
    }
}
}

}*/


}

return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;
    int i;
    int cant;
    Employee *auxEmp=NULL;
    cant=ll_len(pArrayListEmployee);
    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0;i<cant;i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                printf("%s\n",auxEmp->nombre);
                fwrite(auxEmp,sizeof(Employee),1,pFile);
            }


        }
        fclose(pFile);
    }
    return 1;
}
