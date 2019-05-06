#ifndef AMBU_H
#define AMBU_H

typedef struct
{
    int id;
    int isEmpty;
    int dni;
    char nombre[50];
    char apellido[50];
    int edad;

}Asociado;

typedef struct
{
    int id;
    int isEmpty;
    char asociado[50];
    char motivo[50];
    int estado;
    int tiempo;

}Llamada;


/**\brief muestra las opciones del menu
 *\param ingresa a la opcion que ejecute el usuario
 * \return retorna 0
 */
int functionMenu(void);

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int inicializarArray(Asociado *arrayAsociado, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int buscarElVacio(Asociado *arrayAsociado,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int altaAsociado(Asociado *arrayAsociado,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dios bien o -1 si dio mal
 */
#endif
