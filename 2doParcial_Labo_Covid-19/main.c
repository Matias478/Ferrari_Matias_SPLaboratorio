#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pais.h"
#include "LinkedList.h"
#include "controller.h"
#include "informes.h"

/*
    1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos del mismo.
    2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los países.
    3) Asignar estadísticas: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y
        una función que asignará a cada país un valor de vacunados con una dosis (entre 1% y 60%),
        vacunados con dos dosis (entre 1% y 40%), ambos asignados de manera aleatoria y porcentaje
        sin vacunar que será lo que falte para el 100%.
    4) Filtrar por países exitosos: Se deberá generar un archivo igual al original, pero donde solo
        aparezcan países cuya población este vacunada con dos dosis en un porcentaje mayor al 30%.
    5) Filtrar por países en el horno: Se deberá generar un archivo igual al original, pero donde
        solo aparezcan países donde la cantidad de no vacunados sea mayor a la de vacunados.
    6) Ordenar por nivel de vacunación: Se deberá mostrar por pantalla un listado de los países
        ordenados por cantidad de vacunados con 1 dosis.
    7) Mostrar más castigado: Informar el nombre del país o países con el mayor porcentaje de no
        vacunados. Y cuál es ese número.
    8) Salir.
*/
int main()
{
    char opcion[20];
    int auxOpcion;
    char path[128];
    int flag=0;
    srand(time(NULL));
    LinkedList* listaPais=ll_newLinkedList();

    do{
        system("cls");
        printf("\n\t   *** Paises afectados por el Covid-19 ***  \n");
        printf("\n1. Cargar archivo\n");
        printf("\n2. Imprimir lista\n");
        printf("\n3. Asignar estadisticas\n");
        printf("\n4. Filtrar paises exitosos\n");
        printf("\n5. Filtrar paises en el horno\n");
        printf("\n6. Ordenar por nivel de infeccion\n");
        printf("\n7. Mostrar mas castigado\n");
        printf("\n8. Salir\n");
        do{
            printf("\nIngrese su opcion:");
            fflush(stdin);
            gets(opcion);
            auxOpcion=validNumber(opcion);
            }while(auxOpcion==0);
        auxOpcion=atoi(opcion);
        switch(auxOpcion)
        {
        case 1:
            system("cls");
                printf("Ingrese path(vacunas.csv):");
                fflush(stdin);
                gets(path);
                if(controller_loadFromText(path,listaPais))
                {
                    flag=1;
                }
            system("pause");
            break;
        case 2:
            system("cls");
            if(flag){
                    controller_ListPaises(listaPais);
                }else{
                    printf("Lista vacia\n");
                }
            system("pause");
            break;
        case 3:
            system("cls");
            if(flag){
                 ll_map(listaPais,vacunas);
            }else{
                printf("No se puede acceder a esta opcion sin antes cargar el archivo\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(flag){
                LinkedList* PaisesExitosos=ll_filter(listaPais,filterPaisesExitosos);
                controller_ListPaises(PaisesExitosos);
            }else{
                printf("No se puede acceder a esta opcion sin antes cargar el archivo\n");
            }

            system("pause");
            break;
        case 5:
            system("cls");
            if(flag){
                LinkedList* PaisesAlHorno=ll_filter(listaPais,filterPaisesAlHorno);
                controller_ListPaises(PaisesAlHorno);
            }else{
                printf("No se puede acceder a esta opcion sin antes cargar el archivo\n");
            }

            system("pause");
            break;
        case 6:
            system("cls");
            if(flag){
                    controller_sortEmployee(listaPais);
            }else{
                printf("No se puede acceder a esta opcion sin antes cargar el archivo\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
                if(flag){
                    paisMasCastigado(listaPais);
                }else{
                printf("No se puede acceder a esta opcion sin antes cargar el archivo\n");
                }
            system("pause");
            break;
        case 8:
            printf("Gracias por usar este programa :)\n");
            break;
        }
    }while(auxOpcion!=8);
    return 0;
}
