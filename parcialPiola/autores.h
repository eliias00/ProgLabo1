#ifndef AUTORES_H
#define AUTORES_H

typedef struct
{
    int id;
    int isEmpty;
    char nombre[31];
    char apellido[31];

}Autores;

/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int inicializarArrayAuto(Autores *arrayAuto, int cant);

/**\brief recorre el array
 *\param busca VACIO y devuelve la posicion de ese VACIO
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int buscarElVacioAuto(Autores *arrayAuto,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int altaAutor(Autores *arrayAuto,int cant,int posLibre);

/**\brief ingresa un id
 *\param lo busca y devuelva la posicion donde se encuentra
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int buscaId (Autores *arrayAuto, int cant, int *idEncontrado);

/**\brief se ingresa id para modificar los campos
 *\param si el id es correcto se modifican y si no sale del programa
 * \return retorna 0 si dios bien o -1 si dio mal
 */
int modificacion(Autores *arrayAuto,int cant);


/**\brief se ingresa id para dar de baja a un empleado
 *\param si el id es correcto se da de baja y si no sale del programa
 * \return retorna 0
 */
int baja(Autores *arrayAuto,int cant);

/**\brief se ordena el apellido ascendentemente
 *\param y el nombre
 * \return retorna void
 */
void OrdenamientoAutor(Autores *array,int cant);

#endif // AUTORES_H

