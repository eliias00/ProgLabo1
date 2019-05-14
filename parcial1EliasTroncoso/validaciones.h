#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/**\brief toma por teclado lo que ingrese el usuario
 *\param valida
 * \return retorna 0 si dio bien o -1 si dio mal
 */
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);

/**\brief valida que sea letra
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidName(char *cadena);

/**\brief valida
 *\param llama a getString y isValidName y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

/**\brief valida que sea numero
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidFloat (char* pStr);

/**\brief valida
 *\param llama a getString y isValidFloat y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getFloat(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);

/**\brief valida que sea numero
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidint(char* cadena);

/**\brief valida
 *\param llama a getString y isValidFloat y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);

/**\brief valida que sea f o m o M o F
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidSexo(char *cadena);

/**\brief valida
 *\param llama a getString y isValidSexo y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getSexo(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

/**\brief valida que tenga un @ y un . despues
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidMail(char str[]);

/**\brief valida
 *\param llama a getString y isValidMail y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getEmail(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

/**\brief valida que sea un numero
 * \return retorna 0 si dio bien o 1 si dio mal
 */
int isValidDia(char cadena[]);

/**\brief valida
 *\param llama a getString y isValidDia,hace una validacion entre 1 y 31 y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */

int getDia(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

/**\brief valida
 *\param llama a getString y isValidDia,hace una validacion entre 1 y 12 y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getMes(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

/**\brief valida
 *\param llama a getString y isValidDia,hace una validacion entre que sea un año valido y si dieron bien copia el resultado
 * \return retorna 0 dio bien o -1 si dio mal
 */
int getAnio(int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);

#endif
