#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "peliculas.h"
#include "utn.h"

int menu();

int main()
{
    int validation;
    int flag1=0;
    char exit='n';
    LinkedList* peliculasList = ll_newLinkedList();
    //LinkedList* copiaList;
    //int contador=0;
    do{
        system("cls");
        switch(menu())
        {
            case 1:
                if(flag1==0)
                {
                    validation=controller_loadFromText("peliculas.csv",peliculasList);
                    if(validation==1)
                    {
                    printf("Se cargaron exitosamente los datos!!!\n");
                    flag1=1;
                    }
                    else
                    {
                    printf("Error al cargar!!!\n");
                    }
                }
                else
                {
                   printf("Los datos ya se encuentran cargados!!!\n");
                }

                system("pause");

                break;
            case 2:
               controller_List(peliculasList);

                system("pause");


                break;
            case 3:
                /*
               if(controller_saveAsText("peliculas2.csv",peliculasList))
               {
                   printf("Archivo Guardado!!\n");
                   system("pause");
               }
*/
                break;
            case 4:
/*
                ll_map(peliculasList,mapearGenero);
                controller_saveAsText("probando map.csv",peliculasList);

*/
                break;
            case 5:/*
                copiaList=ll_filter(peliculasList,filtrarGenero);
                if(controller_saveAsText("probando filter.csv",copiaList))
                {
                    printf("Archivo guardado!!\n");
                    system("pause");
                }*/



                break;
            case 6:/*
                contador=ll_count(peliculasList,filtrarGenero);
                controller_List(peliculasList);
                printf("hay %d",contador);
                system("pause");*/
                break;
            case 7:/*
                ll_reduce(peliculasList,filtrarGenero);
                controller_List(peliculasList);
                system("pause");*/
                break;

            case 10:
                printf("Confirma salir? s/n: \n");
                fflush(stdin);
                scanf("%c",&exit);
                exit=tolower(exit);
                printf("Saliendo...!\n");
                break;
            default:
                {
                    printf("Error, opcion invalida\n");
                }
        }
    }while(exit=='n');
    return 0;
}

int menu()
{
    int opcion;
    printf("1. cargar csv\n");
    printf("2. listar \n");
    printf("3. guardar en csv\n");
    printf("4. mapear\n");
    printf("5. filtrar\n");
    printf("6.\n");
    printf("7.\n");
    printf("10.Salir\n");
    getInt(&opcion,"Ingrese opcion: \n","Reingrese opcion: \n",1,10,3);

    return opcion;
}
