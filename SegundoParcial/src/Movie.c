#include "Movie.h"

Movie* movie_new()
{
	Movie* pMovie = (Movie*) malloc(sizeof(Movie));

	pMovie ->id = 0;
	strcpy(pMovie->titulo, "Sin titulo");
	strcpy(pMovie->genero, "Sin genero");
	pMovie ->rating = 0;

	return pMovie;
}

Movie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr)
{
	int auxId;
	float auxRating;
	Movie* pMovie = NULL;

	if(idStr != NULL && tituloStr != NULL && generoStr != NULL && ratingStr != NULL)
	{
		auxId = atoi(idStr);
		auxRating = atof(ratingStr);

		Movie* auxMovie = movie_new();
		
		if(auxMovie != NULL)
		{
			if(!movie_setId(auxMovie, auxId) &&
			!movie_setTitulo(auxMovie, tituloStr) &&
			!movie_setGenero(auxMovie, generoStr) &&
			!movie_setRating(auxMovie, auxRating))
			{
				pMovie = auxMovie;
			}
		}
	}
	return pMovie;
}

void movie_delete(Movie* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int movie_setId(Movie *this, int id)
{
	int todoOk = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 0;
	}
	return todoOk;
}

int movie_getId(Movie *this, int *id)
{
	int todoOk = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 0;
	}
	return todoOk;
}

int movie_setTitulo(Movie *this, char *titulo)
{
	int todoOk = -1;

	if(this != NULL && titulo != NULL && strlen(titulo) < 128)
	{
		strcpy(this->titulo, titulo);
		todoOk = 0;
	}
	return todoOk;
}

int movie_getTitulo(Movie *this, char *titulo)
{
	int todoOk = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		todoOk = 0;
	}
	return todoOk;
}

int movie_setGenero(Movie *this, char* genero)
{
	int todoOk = -1;

	if(this != NULL && genero != NULL && strlen(genero) < 128)
	{
		strcpy(this->genero, genero);
		todoOk = 0;
	}
	return todoOk;
}

int movie_getGenero(Movie *this, char *genero)
{
	int todoOk = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(genero, this->genero);
		todoOk = 0;
	}
	return todoOk;
}

int movie_setRating(Movie *this, float rating)
{
	int todoOk = -1;

	if(this != NULL && rating > 0)
	{
		this->rating = rating;
		todoOk = 0;
	}
	return todoOk;
}

int movie_getRating(Movie *this, float *rating)
{
	int todoOk = -1;

	if(this != NULL && rating != NULL)
	{
		*rating = this->rating;
		todoOk = 0;
	}
	return todoOk;
}

int movie_print(Movie* this)
{
	int todoOk = -1;
	int* id = (int*) malloc(sizeof(int));
	float* rating = (float*) malloc(sizeof(float));
	char* titulo = (char*) malloc(sizeof(char) * 256);
	char* genero = (char*) malloc(sizeof(char) * 256);

	if(this != NULL && id != NULL && titulo != NULL && rating != NULL && genero != NULL)
	{
		if(!movie_getTitulo(this, titulo) &&
		!movie_getGenero(this, genero) &&
		!movie_getRating(this, rating) &&
		!movie_getId(this, id))
		{
			printf("%4d  %18s      %10s      %.1f \n", *id, titulo, genero, *rating);
		}
		todoOk = 0;
	}
	free(id);
	free(genero);
	free(rating);
	free(titulo);

	return todoOk;
}
