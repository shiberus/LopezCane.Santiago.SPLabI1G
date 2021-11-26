#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Movie.h"


int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovie)
{
	int todoOk = -1;
	Movie* pMovie;
	char* idAux = (char*) malloc(sizeof(char) * 256);
	char* tituloAux = (char*) malloc(sizeof(char) * 256);
	char* generoAux = (char*) malloc(sizeof(char) * 256);
	char* ratingAux = (char*) malloc(sizeof(char) * 256);

	if(idAux != NULL && tituloAux != NULL && generoAux != NULL && ratingAux != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, tituloAux, generoAux, ratingAux);

		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, tituloAux, generoAux, ratingAux))
			{
				pMovie = movie_newParametros(idAux, tituloAux, generoAux, ratingAux);
				if(pMovie != NULL)
				{
					ll_add(pArrayListMovie,pMovie);
					todoOk = 0;
				}
				else
				{
					movie_delete(pMovie);
					todoOk = -1;
					break;
				}
			}
			else
			{
				movie_delete(pMovie);
				break;
			}
		}
		while(!feof(pFile));
	}
	free(idAux);
	free(tituloAux);
	free(generoAux);
	free(ratingAux);

    return todoOk;
}

int parser_MovieToText(FILE* pFile , LinkedList* pArrayListMovie)
{
	int todoOk = -1;
	int* tam = (int*) malloc(sizeof(int));
	int* id = (int*) malloc(sizeof(int));
	float* rating = (float*) malloc(sizeof(float));
	char* titulo = (char*) malloc(sizeof(char) * 256);
	char* genero = (char*) malloc(sizeof(char) * 256);
	Movie* pMovie;

	if (pFile != NULL && pArrayListMovie != NULL && tam != NULL && id != NULL &&
	genero != NULL && rating != NULL && titulo != NULL)
	{
		*tam = ll_len(pArrayListMovie);

		fprintf(pFile,"id,titulo,genero,rating\n");

		for(int i = 0; i < *tam; i++)
		{
			pMovie = (Movie*) ll_get(pArrayListMovie, i);

			if(!movie_getId(pMovie,id) &&
			!movie_getTitulo(pMovie,titulo) &&
			!movie_getGenero(pMovie,genero) &&
			!movie_getRating(pMovie,rating))
			{
				fprintf(pFile,"%d,%s,%s,%f\n", *id, titulo, genero, *rating);
			}
		}
		todoOk = 0;
	}
	free(tam);
	free(id);
	free(genero);
	free(rating);
	free(titulo);

	return todoOk;
}
