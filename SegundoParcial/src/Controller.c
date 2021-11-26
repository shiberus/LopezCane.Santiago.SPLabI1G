#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Util.h"
#include "Movie.h"


int controller_loadFromText(char* path , LinkedList* pArrayListMovie)
{
	int todoOk = -1;
	int* fail = (int*) malloc(sizeof(int));
	
	FILE* pFile;
	
	if(path != NULL && pArrayListMovie != NULL && fail != NULL)
	{
		*fail = 1;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			*fail = parser_MovieFromText(pFile, pArrayListMovie);

			if (!(*fail))
			{
				todoOk = 0;
			}
		}
		fclose(pFile);
	}
	free(fail);

	return todoOk;
}

int controller_ListMovie(LinkedList* pArrayListMovie)
{
	int todoOk = -1;
	int* tam = (int*) malloc(sizeof(int));

	Movie* pMovie;

	if(pArrayListMovie != NULL && tam != NULL)
	{
		*tam = ll_len(pArrayListMovie);

		printf("   id  |       nombre       | horas |  sueldo \n");
		printf("----------------------------------------------- \n");
		for(int i = 0; i < *tam; i++)
		{
			pMovie = (Movie*) ll_get(pArrayListMovie, i);

			if(pMovie != NULL)
			{
				movie_print(pMovie);
			}
		}
		todoOk = 0;
	}
	free(tam);

	return todoOk;
}

int controller_sortMovie(LinkedList* pArrayListMovie)
{
    int todoOk = -1;
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListMovie)
{
    int todoOk = -1;
	int* fail = (int*) malloc(sizeof(int));

	if(path != NULL && pArrayListMovie != NULL && fail != NULL)
	{
		*fail = 1;
		FILE* f = fopen(path,"w");
		if(f != NULL)
		{
			*fail = parser_MovieToText(f, pArrayListMovie);

			if(!(*fail))
			{
				todoOk = 0;
			}

			fclose(f);
		}
	}
	free(fail);

    return todoOk;
}

int controller_compareGeneros(void* first, void* second)
{
	int resultado = 0;
	char* firstGenero = (char*) malloc(sizeof(char) * 128);
	char* secondGenero = (char*) malloc(sizeof(char) * 128);

	Movie* firstMovie;
	Movie* secondMovie;

	if(first != NULL && second != NULL && firstGenero != NULL && secondGenero != NULL)
	{
		firstMovie = (Movie*) first;
		secondMovie = (Movie*) second;
		 
		if(!movie_getGenero(firstMovie, firstGenero) && !movie_getGenero(secondMovie, secondGenero))
		{
			resultado = strcmp(firstGenero, secondGenero);
		}
	}
	free(firstGenero);
	free(secondGenero);

	return resultado == 0 ? 0 : resultado > 0 ? 1 : -1;
}

int controller_compareRatings(void* first, void* second)
{
	int resultado = 0;
	float* firstRating = (float*) malloc(sizeof(float));
	float* secondRating = (float*) malloc(sizeof(float));

	Movie* firstMovie;
	Movie* secondMovie;

	if(first != NULL && second != NULL && firstRating != NULL && secondRating != NULL)
	{
		firstMovie = (Movie*) first;
		secondMovie = (Movie*) second;

		if(!movie_getRating(firstMovie, firstRating) && !movie_getRating(secondMovie, secondRating))
		{
			resultado = firstRating - secondRating;
		}
	}
	free(firstRating);
	free(secondRating);

	return resultado == 0 ? 0 : resultado > 0 ? 1 : -1;	
}
