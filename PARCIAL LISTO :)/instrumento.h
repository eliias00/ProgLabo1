#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    int tipo;
}Instrumento;

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int inicializarArrayIns(Instrumento *array, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscarElVacioIns(Instrumento *array,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int altaIns(Instrumento *array,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int buscaIdInst(Instrumento *array, int cant, int *idEncontrado);

/**\brief recorre el array de instrumentos
 *\param y los muestra
 * \return void
 */
void imprimirInstrumento(Instrumento *array,int cant);
#endif
