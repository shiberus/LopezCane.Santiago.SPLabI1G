#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListMovie);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListMovie);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_addMovie(LinkedList* pArrayListMovie, int nextId);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_editMovie(LinkedList* pArrayListMovie);

/** \brief Baja de empleado
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_removeMovie(LinkedList* pArrayListMovie);

/** \brief Listar empleados
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_ListMovie(LinkedList* pArrayListMovie);

/** \brief Ordenar empleados
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_sortMovie(LinkedList* pArrayListMovie);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListMovie);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListMovie);

/** \brief Busca un empleado por su Id.
 *
 * \param pArrayListMovie LinkedList*
 * \param id int
 * \return int indice en que se encuentra el empleado
 *
 */
int controller_findMovieById(LinkedList* pArrayListMovie, int id);

/** \brief Busca el Id mas alto registrado.
 *
 * \param pArrayListMovie LinkedList*
 * \return int el id mas alto
 *
 */
int controller_getMaxId(LinkedList* pArrayListMovie);

/** \brief Compara el id de dos empleados.
 *
 * \param first void* puntero al primer empleado
 * \param second void* puntero al segundo empleado
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareIds(void* first, void* second);

/** \brief Compara el nombre de dos empleados.
 *
 * \param first void* puntero al primer empleado
 * \param second void* puntero al segundo empleado
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareNombres(void* first, void* second);

/** \brief Compara las horas trabajadas de dos empleados.
 *
 * \param first void* puntero al primer empleado
 * \param second void* puntero al segundo empleado
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareHoras(void* first, void* second);

/** \brief Compara el sueldo de dos empleados.
 *
 * \param first void* puntero al primer empleado
 * \param second void* puntero al segundo empleado
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareSueldos(void* first, void* second);

#endif // controller_H_INCLUDED
