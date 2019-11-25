#ifndef UTN_C_INCLUDED
#define UTN_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



/** \brief Verifica si es valor es numerico
 * \param recibe int para guardar, mensaje, mensaje de error, minimo y maximo, y reintentos.
 * \return 0 si es numerico. -1 si no lo es.
 */
int getInt(int *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    int buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%d",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = 0;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}


float getFloat(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    float buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%f",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = EXIT_SUCCESS;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}

/** \brief Verifica si es sexo
 * \param recibe int para guardar, mensaje, mensaje de error, minimo y maximo, y reintentos.
 * \return 0 si es sexo. -1 si no lo es.
 */
int getChar(  char *pResultado,
			  char *pMensaje,
			  char *pMensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(scanf("%c",&buffer)==1)
			{
				if(buffer == 'f' || buffer == 'm')
				{
					retorno = 0;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Verifica si es string
 * \param recibe int para guardar, mensaje, mensaje de error, minimo y maximo, y reintentos.
 * \return 0 si es numerico. -1 si no lo es.
 */
int getString(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);
               //retorna cadena si es realizada con éxito.
               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
               {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;
               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}





/** \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numérico y 0 si no lo es
 */
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9');
        return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        //va a retornar 0 cuando:
        //si NO es un espacio y que no sea algo que este entra la a y z
        //y algo que no este entre la A y la Z
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido tiene letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros . 0 si no lo es
 *
 */
int esAlfanumerico(char str[])
{

    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si es valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo números, espacios y UN guión
 */
int esTelefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] != '-')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        if(str[i] == '-')
            contadorDeGuiones ++;
        i++;
    }
    return 1;
}

/** \brief Verifica si es un telefono
 * \param str Array con la cadena a ser analizada
 * \return 0 si es telefono. -1 si no lo es.
 */
int getPhone(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);
               //retorna cadena si es realizada con éxito.
               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo )
               {
                   if(esNumerico(buffer)!=1)
                   {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;

                   }

               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}

/** \brief Verifica si es nombre o apellido
 * \param char donde se guarda, mensaje, mensaje de error, minimo y maximo y los reintentos.
 * \return 0 si es nombre. -1 si no lo es.
 */
int getNameOrLastName(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);
               //retorna cadena si es realizada con éxito.
               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo )
               {
                   if(esSoloLetras(buffer)==1)
                   {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;

                   }

               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;

}








#endif // UTN_C_INCLUDED
