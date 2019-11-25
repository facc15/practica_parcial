#include "peliculas.h"
#include "utn.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



/** \brief Crea un tipo de estructura y carga los campos
 *
 * \param  Recibe de parametro cuatro cadenas para cargar
 *
 * \return Retorna la estructura epelicula con los campos cargados
 */
ePelicula* pelicula_newParametros(char* id,char* nombre,char* genero,char* espectadores)
{
    ePelicula* vec=pelicula_new();

    if(vec!=NULL)
    {
        if(pelicula_setId(vec,atoi(id))
           && pelicula_setNombre(vec,nombre)
           && pelicula_setEspectadores(vec,atoi(espectadores))
           && pelicula_setGenero(vec,genero)
           == 0)
        {

            free(vec);
            vec=NULL;

        }

    }

    return vec;

}

/** \brief Crea espacio en memoria y una nueva estructura.
 *
 * \return Devuelve una estructura inicializada.
 */
ePelicula* pelicula_new()
{
    ePelicula* vec= (ePelicula*) malloc(sizeof(ePelicula));

    if(vec != NULL)
    {
        vec->id=0;
        strcpy(vec->nombre," ");
        strcpy(vec->genero," ");
        vec->espectadores=0;
    }

    return vec;
}

/** \brief Carga el ID a la estructura.
 *
 * \param Recibe puntero de  la estructura.
 * \param Toma el valor ID ingresado por el usuario.
 *
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int pelicula_setId(ePelicula* vec,int id)
{
    int validation=0;
    if(vec!=NULL)
    {
        vec->id=id;
        validation=1;
    }

    return validation;
}

/** \brief Toma el valor del ID de una estructura.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a entero.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int pelicula_getId(ePelicula* vec,int* id)
{
    int validation=0;

    if(vec!=NULL)
    {
        *id = vec->id;
        validation=1;
    }


    return validation;
}




/** \brief Carga la cadena en la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe cadena de caracteres.
 *
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int pelicula_setNombre(ePelicula* vec,char* nombre)
{
    int validation=0;

        if(vec!=NULL)
        {
            strcpy(vec->nombre,nombre);
            validation=1;
        }

    return validation;
}

/** \brief Toma el valor del nombre de una estructura.
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a cadena.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int pelicula_getNombre(ePelicula* vec,char* nombre)
{
    int validation=0;
    if(vec!=NULL)
    {
        strcpy(nombre,vec->nombre);
        validation=1;
    }

    return validation;
}

/** \brief Carga la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe un entero a cargar.
 * \return Retorna 1 si no es NULL.0 Si lo es.
 */
int pelicula_setEspectadores(ePelicula* vec,int espectadores)
{
    int validation=0;

        if(vec!=NULL )
        {
            vec->espectadores=espectadores;
            validation=1;
        }

    return validation;
}

/** \brief Toma el valor de int
 *
 * \param Recibe puntero de una estructura.
 * \param Recibe puntero a entero.
 *
 * \return Retorna 0 si es NULL. 1 si no lo es.
 */
int pelicula_getEspectadores(ePelicula* vec,int* espectadores)
{
    int validation=0;

    if(vec!=NULL)
    {
        *espectadores=vec->espectadores;
        validation=1;
    }


    return validation;
}

/** \brief Carga la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe un entero a cargar.
 *
 * \return Retorna 1 si no es NULL. 0 Si lo es.
 */
int pelicula_setGenero(ePelicula* vec,char* genero)
{
    int validation=0;

        if(vec!=NULL)
        {
            strcpy(vec->genero,genero);
            validation=1;
        }

    return validation;
}

/** \brief Toma el valor de la estructura.
 *
 * \param Recibe puntero de estructura.
 * \param Recibe un entero a cargar.
 *
 * \return Retorna 1 si no es NULL. 0 Si lo es.
 */

int pelicula_getGenero(ePelicula* vec,char* genero)
{
    int validation=0;
    if(vec!=NULL)
    {
        strcpy(genero,vec->genero);
        validation=1;
    }

    return validation;
}


/** \brief Muestra un .
 *
 * \param Recibe puntero de una estructura.
 *
 */
void showOne(ePelicula* vec)
{
    if(vec==NULL)
    {
        printf("Error\n");
    }else
    {
        printf("%d  %20s  %20s  %5d  \n",vec->id,vec->nombre,vec->genero,vec->espectadores);

    }
}

/*
void* mapearGenero(void* element)
{

    ePelicula* aux=(ePelicula*) element;
    char nuevoGenero[]="Romance";

    if(aux->genero[0]=='D' && aux->genero[1]=='r')
    {
        pelicula_setGenero(aux,nuevoGenero);
    }


    return aux;
}

int filtrarGenero(void* element)
{
    ePelicula* aux=(ePelicula*) element;
    int validation=0;



    if((aux->genero[0]=='D' && aux->genero[1]=='r') ||  (aux->genero[0]=='A' && aux->genero[1]=='c'))
    {

        validation=1;


    }

    return validation;


}

int compareByGenero(void* e1,void* e2)
{
    int comparison;

    ePelicula* peli1;
    ePelicula* peli2;

    if(e1!=NULL && e2!= NULL)
    {
        peli1=(ePelicula*) e1;
        peli2=(ePelicula*) e2;

        if(strcmp(peli1->genero,peli2->genero)>0)
        {
            comparison=1;
        }
        else if(strcmp(peli1->genero,peli2->genero)<0)
        {
            comparison=-1;
        }
        else
        {
            comparison =0;
        }
    }

    return comparison;
}


*/





/*

int filtrarColor(void* element)
{
    eAuto* aux=(eAuto*) element;
    int validation=0;



    if(aux->color[0]=='G')
    {

        validation=1;


    }

    return validation;


}

void* mapearMarca(void* element)
{

    eAuto* aux=(eAuto*) element;
    char nuevaMarca[]="MAEEAMIIIIII";

    if(aux->marca[0]=='F' && aux->marca[1]=='o')
    {
        auto_setMarca(aux,nuevaMarca);
    }


    return aux;
}

int compareById(void* e1,void* e2)
{
    int comparison;

    ePelicula* peli1;
    ePelicula* peli2;

    if(e1!=NULL && e2!= NULL)
    {
        peli1=(ePelicula*) e1;
        peli2=(ePelicula*) e2;

        if(peli1->id > peli2->id)
        {
            comparison=1;
        }
        else if(peli1->id < peli2->id)
        {
            comparison=-1;
        }
        else
        {
            comparison=0;
        }

    }

    return comparison;
}

int compareByName(void* e1,void* e2)
{
    int comparison;

    ePelicula* peli1;
    ePelicula* peli2;

    if(e1!=NULL && e2!= NULL)
    {
        peli1=(ePelicula*) e1;
        peli2=(ePelicula*) e2;

        if(strcmp(peli1->nombre,peli2->nombre)>0)
        {
            comparison=1;
        }
        else if(strcmp(peli1->nombre,peli2->nombre)<0)
        {
            comparison=-1;
        }
        else
        {
            comparison =0;
        }
    }

    return comparison;
}



*/
