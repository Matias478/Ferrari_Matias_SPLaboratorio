#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pais.h"
#include "LinkedList.h"
#include "controller.h"
#include "informes.h"

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
        printf("\n\t   *** Paises afectados por el covid-19 ***  \n");
        printf("\n1. Cargar archivo\n");
        printf("\n2. Imprimir lista\n");
        printf("\n3. Asignar estadisticas\n");
        printf("\n4. Filtrar paises exitosos\n");
        printf("\n5. Filtrar paises en el horno\n");
        printf("\n6. Ordenar por nivel de infeccion\n");
        printf("\n7. Mostrar mas castigado\n");
        printf("\n8. Salir\n");
        do{fflush(stdin);
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
