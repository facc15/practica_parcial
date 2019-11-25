#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char genero[30];
    int espectadores;

}ePelicula;


ePelicula* pelicula_new();
ePelicula* pelicula_newParametros(char* id,char* nombre,char* genero,char* espectadores);

int pelicula_setId(ePelicula* vec,int id);
int pelicula_getId(ePelicula* vec,int* id);

int pelicula_setNombre(ePelicula* vec,char* nombre);
int pelicula_getNombre(ePelicula* vec,char* nombre);

int pelicula_setGenero(ePelicula* vec,char* genero);
int pelicula_getGenero(ePelicula* vec,char* genero);

int pelicula_setEspectadores(ePelicula* vec,int espectadores);
int pelicula_getEspectadores(ePelicula* vec,int* espectadores);


void showOne(ePelicula* vec);

void* mapearGenero(void* element);
int filtrarGenero(void* element);

int compareByGenero(void* e1,void* e2);




#endif // PELICULAS_H_INCLUDED
