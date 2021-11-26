#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Movie.h"
#include "Util.h"
#include <time.h>

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int* option = (int*) malloc(sizeof(int));
	int* fail = (int*) malloc(sizeof(int));
	char* path = (char*) malloc(sizeof(char) * 20);
	LinkedList* listaMovies = ll_newLinkedList();

	if(option != NULL && fail != NULL && path != NULL && listaMovies != NULL)
	{
		do{
			printf("*** Menu de Opciones ***\n\n");
			printf("1- Cargar los datos de las peliculas\n");
			printf("2- Listar peliculas\n");
			printf("3- Asignar rating\n");
			printf("4- Asignar genero\n");
			printf("5- Filtrar por genero\n");
			printf("6- Ordenar peliculas\n");
			printf("7- Guardar los datos de los peliculas\n");
			printf("8- Finalizar programa\n");
			scanf("%d", option);

			switch(*option)
			{
				case 1:
					if(ll_isEmpty(listaMovies) || preguntar("Ya hay peliculas cargadas, desea sobreescribirlas?"))
					{
						*fail = ingresarNombreArchivo(path);

						if(*fail)
						{
							pausar("Oh oh, hubo un error");
						}
						else
						{
							*fail = controller_loadFromText(path,listaMovies);
							
							if(*fail)
							{
								pausar("Oh oh, hubo un error");
							}
							else
							{
								pausar("Los datos se cargaron exitosamente");
							}
						}
					}
					else
					{
						pausar("Operacion cancelada");
					}
					break;

				case 2:
					if(!ll_isEmpty(listaMovies))
					{
						controller_ListMovie(listaMovies);
						pausar(NULL);
					}
					else
					{
						pausar("No hay peliculas cargadas");
					}
					break;

				case 3:
			
					break;

				case 4:

					break;

				case 5:

					break;

				case 6:
					if(!ll_isEmpty(listaMovies))
					{
						controller_sortMovie(listaMovies);
					}
					else
					{
						pausar("No hay peliculas cargadas");
					}
					break;

				case 7:
					if(!ll_isEmpty(listaMovies))
					{
						*fail = controller_saveAsText("data.csv",listaMovies);

						if(*fail)
						{
							pausar("Oh oh, hubo un error");
						}
						else
						{
							pausar("Los datos se guardaron exitosamente");
						}
					}
					else
					{
						pausar("No hay peliculas cargadas");
					}
					break;

				case 8:
					printf("Apruebeme profe.");
					break;

				default:
					pausar("Opcion invalida");
					break;
			}

		}
		while(*option != 10);
	}
	else
	{
		printf("No se pudo inicializar el programa.");
	}
	free(option);
	free(fail);
	free(path);

    return 0;
}
