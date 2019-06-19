#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

/** \brief crea un empleado en memoria
 *
 * \param void
 * \return employee
 *
 */
Empleado* employee_new();

/** \brief retorna el puntero al empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return retorno
 *
 */
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief elimina el empleado en memoria
 *
 * \param auxEmployee Employee*
 * \return void
 *
 */
void employee_delete(Empleado *auxEmployee);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int id
 * \return int
 *
 */
int employee_setId(Empleado* this,int id);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param int* id
 * \return int
 *
 */
int employee_getId(Empleado* this,int* id);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Empleado* this,char* nombre);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param char* nombre
 * \return int
 *
 */
int employee_getNombre(Empleado* this,char* nombre);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int horasTrabajadas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);

/** \brief toma  el valor
 *
 * \param auxEmployee Employee*
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

/** \brief setea el valor
 *
 * \param auxEmployee Employee*
 * \param int sueldo
 * \return int
 *
 */
int employee_setSueldo(Empleado* this,int sueldo);

/** \brief toma el valor
 *
 * \param auxEmployee Employee*
 * \param int* sueldo
 * \return int
 *
 */
int employee_getSueldo(Empleado* this,int* sueldo);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* id
 * \return int
 *
 */
int Employee_setIdStr(Empleado* this, char *id);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* sueldo
 * \return int
 *
 */
int Employee_setSueldoStr(Empleado* this, char *sueldo);

/** \brief setea el valor como char
 *
 * \param auxEmployee Employee*
 * \param char* horasTrabajadas
 * \return int
 *
 */
int Employee_setHorasTrabajadasStr(Empleado* this, char *horasTrabajadas);

/** \brief compara los nombres
 *
 * \param void* this1
 * \param void* this2
 * \return int
 *
 */
int employee_compararPorNombre(void *this1,void *this2);

/** \brief busca el proximo id en la linkedlist
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int generadorId(Linkedlist* pArrayListEmployee);

/** \brief se comparan dos id y se retorna la pocision de donde esta ese id
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int buscaId (Linkedlist* pArrayListEmployee, int *idEncontrado);
#endif // EMPLEADO_H_INCLUDED
