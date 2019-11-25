#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
    int validation=0;
    char buffer[4][20];
    int max=0;
    ePelicula* aux;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);


    while(!feof(pFile))
    {

        max=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(max<4)
        {
            break;
        }
        else
        {
             //printf("%s %s %s\n",buffer[0],buffer[1],buffer[2] );
            aux=pelicula_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);



            if(aux!=NULL)
            {

            ll_add(pArrayList,aux);
            validation=1;
            }

        }


        /*else
        {
            if(feof(pFile))
            {
                break;
            }else
            {
                validation=0;
                break;
            }
        }*/


    }


    return validation;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
 /*
int parser_FromBinary(FILE* pFile , LinkedList* pArrayList)
{
    int validation=0;
    int max;
    ePelicula* vec;

        while(!feof(pFile))
        {

             vec = pelicula_new();

            if(vec !=NULL)
            {

                max = fread(vec,sizeof(vec),1,pFile);

                    if(max <1)
                    {
                    break;

                    }
                    else
                    {
                        ll_add(pArrayList,vec);
                        validation=1;
                    }

            }

        }

    return validation;
}
*/
