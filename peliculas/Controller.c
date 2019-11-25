#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* f=NULL;
    int validation=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            validation=parser_FromText(f,pArrayList);
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
        }
    }

    fclose(f);

    return validation;
}
/** \brief Listar
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_List(LinkedList* pArrayList)
{
    int len=ll_len(pArrayList);




    printf("ID          NOMBRE                    GENERO     ESPECTADORES   \n");
    for(int i=0;i<len;i++)
    {
        showOne((ePelicula*)(ll_get(pArrayList,i)));
        /*aux=(ePelicula*) ll_get(pArrayList,i);
        if(aux!=NULL)
        {
           showOne(aux);


            dominio_getId(aux,&id);
            dominio_getDominio(aux,dominio);
            dominio_getAnio(aux,&anio);
            printf("%d %s %d\n",id,dominio,anio);*/



    }


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayList)
{

    FILE* f;
    ePelicula* aux;
    int validation=0;
    int id;
    char nombre[30];
    char genero [30];
    int espectadores;

    int len=ll_len(pArrayList);

    if(pArrayList!=NULL && path!=NULL)
    {
        if(len>0)
        {


            f=fopen(path,"w");
            if(f!=NULL)
            {
                fprintf(f,"id,nombre,genero,espectadores\n");
                 for(int i=0;i<len;i++)
                {

                    aux=(ePelicula*)ll_get(pArrayList,i);
                    pelicula_getId(aux,&id);
                    pelicula_getGenero(aux,genero);
                    pelicula_getEspectadores(aux,&espectadores);
                    pelicula_getNombre(aux,nombre);

                    fprintf(f,"%d,%s,%s,%d\n",id,nombre,genero,espectadores);
                }
                fclose(f);
                validation=1;
            }
        }
    }

    return validation;
}
/*
int controller_sort(LinkedList* pArrayList)
{
    int validation=0;
    int option;

    getInt(&option,"Ingrese orden 1 o 0: \n","Reingrese orden 1 o 0:\n ",0,1,3);

    if(option==0)
    {
        ll_sort(pArrayList,compareByGenero,option);
        validation=1;
    }
    if(option==1)
    {
        ll_sort(pArrayList,compareByGenero,option);
        validation=1;
    }
    return validation;
}



int controller_loadFromBinary(char* path , LinkedList* pArrayList)
{
    FILE* pFile;
    int result=0;

        if(path != NULL && pArrayList!= NULL){

            pFile= fopen(path,"rb");

            if(pFile==NULL)
            {
                result=0;
            }
            else{
                result = parser_FromBinary(pFile,pArrayList);
            }
        }

         fclose(pFile);

    return result;
}

int controller_sort(LinkedList* pArrayList)
{

    int validation=0;
    int order;

    system("cls");
    switch(menuSort())
    {
        case 1:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareById,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareById,order);
                    validation=1;
                }
            }

            break;
        case 2:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareByName,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareByName,order);
                    validation=1;
                }
            }
            break;
        case 3:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareByHours,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareByHours,order);
                    validation=1;
                }
            }
            break;
        case 4:
            if(getInt(&order,"Ingrese orden ascendente(1) o descendente(0): \n","Reingrese orden ascendente(1) o descendente(0): \n",0,1,3)==0)
            {
                if(order==1)
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareBySalary,order);
                    validation=1;
                }
                else
                {
                    printf("Ordenando empleados...\n");
                    ll_sort(pArrayList,compareBySalary,order);
                    validation=1;
                }
            }
            break;
    }




    return validation;
}

int controller_addEmployee(LinkedList* pArrayList)
{
    int validation=-1;

    int auxSueldo=0;
    int auxHorasTrabajadas=0;
    char auxNombre[30];
    int auxId;

    auxId=generateId(pArrayList);

    if(getNameOrLastName(auxNombre,"Ingrese nombre:\n","Reingrese nombre:\n",2,40,3)==0)
    {
        if(getInt(&auxHorasTrabajadas,"Ingrese horas trabajadas:\n","Reingrese horas trabajadas:\n",1,1500,3)==0)
        {
            if(getInt(&auxSueldo,"Ingrese sueldo:\n","Reingrese sueldo:\n",500,500000,3)==0)
            {
                Employee* employee=employee_new();
                employee_setId(employee,auxId);
                employee_setNombre(employee,auxNombre);
                employee_setHorasTrabajadas(employee,auxHorasTrabajadas);
                employee_setSueldo(employee,auxSueldo);

                if(!ll_add(pArrayList,employee))
                {
                    printf("Alta exitosa!!!\n");
                    validation=1;
                    system("pause");
                }

            }
        }
    }

    return validation;
}


int controller_editEmployee(LinkedList* pArrayList)
{
    int validation=0;
    char confirm;
    int id;
    int len;
    int index;
    int option;
    char name[30];
    int hours;
    int salary;

    len=ll_len(pArrayList);
    Employee* employee=employee_new();

    for(int i=0;i<len;i++)
    {
        showOneEmployee((Employee*)ll_get(pArrayList,i));
    }
    if(getInt(&id,"Ingrese ID a modificar:\n","Reingrese ID a modificar:\n",1,2000,3)==0)
    {


        for(int i=0;i<len;i++)
        {
            employee=(Employee*)ll_get(pArrayList,i);
            if(employee->id==id)
            {
                index=i;
                system("cls");
                printf("Empleado a modificar\n");
                printf(" ID     Nombre     Horas    Sueldo\n");
                showOneEmployee(employee);
                break;

            }
        }
    }

    if(index!=-1)
    {
         printf("\n1. Modificar nombre\n");
        printf("2. Modificar horas trabajadas\n");
        printf("3. Modificar sueldo\n");
        if(getInt(&option,"Que desea modificar?: \n","Reingrese opcion: \n",1,3,3)==0)
        {
            switch(option)
            {
                case 1:
                    getNameOrLastName(name,"Ingrese nuevo nombre: \n","Reingrese nuevo nombre: \n",1,30,3);
                    printf("Confirma editar nombre?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    confirm=tolower(confirm);
                    if(confirm=='s')
                    {
                    strcpy(employee->nombre,name);
                    ll_remove(pArrayList,index);
                    ll_push(pArrayList,index,employee);
                    validation=1;
                    printf("Modificacion exitosa!!!!\n");
                    }

                    break;
                case 2:
                    getInt(&hours,"Ingrese nuevas horas trabajadas: \n","Reingrese nuevas horas trabajadas: \n",1,2500,3);
                    printf("Confirma editar horas trabajadas?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    confirm=tolower(confirm);
                    if(confirm=='s')
                    {
                        employee->horasTrabajadas=hours;
                        ll_remove(pArrayList,index);
                        ll_push(pArrayList,index,employee);
                        validation=1;
                        printf("Modificacion exitosa!!!!\n");
                    }

                    break;
                case 3:
                    getInt(&salary,"Ingrese nuevo salario: \n","Reingrese nuevo salario: \n",200,2000000,3);
                    printf("Confirma modificar sueldo?: \n");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    if(confirm=='s')
                    {
                        employee->sueldo=salary;
                        ll_remove(pArrayList,index);
                        ll_push(pArrayList,index,employee);
                        validation=1;
                        printf("Modificacion exitosa!!!!\n");
                    }
                    break;
            }
        }


    }





    return validation;
}


int controller_removeEmployee(LinkedList* pArrayList)
{
    int validation=0;
    int id;
    char confirm;
    int index;

    int len;

    len=ll_len(pArrayList);

    for(int i=0;i<len;i++)
    {
        showOneEmployee((Employee*) ll_get(pArrayList,i));
    }


    if(getInt(&id,"Ingrese ID a dar de baja: \n","Reingrese ID a dar de baja: \n",1,2000,3)==0)
    {
        Employee* employee=employee_new();

        for(int i=0;i<len;i++)
        {
            employee=((Employee*) ll_get(pArrayList,i));
            if(employee->id==id)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
        {
            printf(" ID     Nombre     Horas    Sueldo\n");
            showOneEmployee(employee);
            printf("Confirma baja?:\n");
            fflush(stdin);
            scanf("%c",&confirm);
            confirm=tolower(confirm);

            if(confirm=='s')
            {
                ll_remove(pArrayList,index);
                validation=1;
                printf("Baja exitosa!!!!\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }

    }



    return validation;
}



int controller_saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    Employee* aux;
    int len = ll_len(pArrayList);
    int validation = 0;

    if(path!=NULL && pArrayList!=NULL)
    {
        if(len>0)
        {
            f=fopen(path,"wb");
            if(f!=NULL)
            {
                for(int i=0; i<len;i++)
                {
                    aux=ll_get(pArrayList,i);
                    if(aux!=NULL)
                    {
                        fwrite(aux,sizeof(Employee),1,f);
                    }
                }
            validation=1;
            fclose(f);
            }

        }
    }

    return validation;
}

*/




