#ifndef APELLIDO_H
#define APELLIDO_H

/**\brief recorre el array de caracteres
 *\param valida que sean letras
 * \return retorna si fue correcto o incorrecto
 */
int isValidSurname(char *cadena);

/**\brief valida todas las variables
 *\param guarda la cadena en un buffer
 * \return si dio bien lo copia a resultado si no,no
 */
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);

/**\brief valida todas las variables
 *\param guarda la cadena en un buffer
 * \return si dio bien lo copia a resultado si no,no
 */
int getSurname(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);

#endif

