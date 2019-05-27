#ifndef MUSICO_H
#define MUSICO_H
#include "instrumento.h"
typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char apellido[51];
    int edad;
    int idOrq;
    int idIns;
}Musico;

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int inicializarArrayM(Musico *array, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscarElVacioMusico(Musico *array,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int altaMusico(Musico *array,Orquesta *array2,Instrumento *array3,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscaIdMusico (Musico *array, int cant, int *idEncontrado);

/**\brief se ingresa id para modificar los campos
 *\param si el id es correcto se modifican y si no sale del programa
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int modificacionMusico(Musico *array,Orquesta *array2,int cant);

/**\brief se ingresa id para dar de baja a un musico
 *\param si el id es correcto se da de baja y si no sale del programa
 * \return retorna 0
 */
int bajaMusico(Musico *array,int cant);

/**\brief se ingresa id para dar de baja a la orquesta y sus musicos
 *\param si el id es correcto se da de baja y si no sale del programa
 * \return retorna 0
 */
int bajaOrquesta(Orquesta *array,Musico *array2,int cant,int cant2);

/**\brief recorre el array de musicos
 *\param y los muestra
 * \return void
 */
void imprimirMusico(Musico *array, Instrumento *array2,int cant1,int cant2);
#endif
