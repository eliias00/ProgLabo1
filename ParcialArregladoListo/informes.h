#ifndef INFORMES_H
#define INFORMES_H

/**\brief muestra las opciones de informes
 *\param ingresa a la opcion que ejecute el usuario
 * \return retorna void
 */
void informes(Orquesta *arrayOrq,Instrumento *arrayIns,Musico *arrayMus,int cantOrq,int cantMus,int cantIns);

/**\brief se ingresa el lugar de la orquesta
 *\param y se compara el lugar que esta guardado en el array con el recien ingresado
 * \return retorna void
 */
void informeA(Orquesta *arrayOrq,int cantOrq);

/**\brief se recorren los arrays
 *\param y se filtran los musicos menores a 25
 * \return retorna void
 */
void informeB(Musico *arrayMus,int cantMus,Instrumento *arrayIns,Orquesta *arrayOrq,int cantOrq,int cantIns);

/**\brief se recorre orquestas y se cuentan los musicos que tengas los mismos id
 *\param se muentran las que tengas menos de 6 musicos
 * \return retorna void
 */
void informeC(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus);

/**\brief se recorren los arrays
 *\param se van filtrando los instrumentos
 * \return retorna void
 */
void informeD(Orquesta *arrayOrq,int cantOrq,Instrumento *arrayIns,int cantIns,Musico *arrayMus,int cantMus);

/**\brief se recorren los arrays
 *\param se  cuentan los intrumentos y se muentras con la condicion
 * \return retorna void
 */
void informeE(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus,Instrumento *arrayIns,int cantIns);

/**\brief se crea un auxiliar orquesta y un contador para cada ves que machean los id
 *\param y se comparan para saber cual es el menor
 * \return retorna void
 */
void informeF(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus);

/**\brief se cuentas los intrumentos y orquestas
 *\param se saca el promedio
 * \return retorna void
 */
void informeG(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus, Instrumento *arrayIns,int cantIns);

/**\brief se ordena por apellido el array
 *\param se filtran los muscos que no tocan intrumentos de viento
 * \return retorna void
 */
void informeH(Musico *arrayMus,int cantMus,Instrumento *arrayIns,int cantIns);

#endif
