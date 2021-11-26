#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef movie_H_INCLUDED
#define movie_H_INCLUDED

typedef struct
{
    int id;
    char titulo[128];
    char genero[128];
    float rating;
}Movie;

Movie* movie_new();
Movie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);
void movie_delete();

int movie_setId(Movie* this,int id);
int movie_getId(Movie* this,int* id);

int movie_setTitulo(Movie* this,char* titulo);
int movie_getTitulo(Movie* this,char* titulo);

int movie_setGenero(Movie* this,char* genero);
int movie_getGenero(Movie* this,char* genero);

int movie_setRating(Movie* this,float rating);
int movie_getRating(Movie* this,float* rating);

int movie_print(Movie* this);

#endif // movie_H_INCLUDED
