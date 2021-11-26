#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovie);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MovieToText(FILE* pFile , LinkedList* pArrayListMovie);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MovieFromBinary(FILE* pFile , LinkedList* pArrayListMovie);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MovieToBinary(FILE* pFile , LinkedList* pArrayListMovie);

#endif /* PARSER_H_ */
