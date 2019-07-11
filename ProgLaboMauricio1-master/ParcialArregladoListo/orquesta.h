#ifndef ORQUESTA_H
#define ORQUESTA_H

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char lugar[51];
    int tipo;

}Orquesta;

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int inicializarArrayOrquesta(Orquesta *arrayOrquesta, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscarElVacioOrquesta(Orquesta *arrayOrquesta,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int altaOrquesta(Orquesta *arrayOrquesta,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscaIdOrquesta (Orquesta *array, int cant, int *idEncontrado);

/**\brief recorre el array de orquestas
 *\param y los muestra
 * \return void
 */
void imprimirOrquestas(Orquesta *array, int cant);
#endif
