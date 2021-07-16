#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void* vacunas(void* element)
{
    int max1=60;
    int min1=1;
    int max2=40;
    int min2=1;
    ePais* auxVac;
    if(element!=NULL)
    {
        auxVac=(ePais*)element;
        auxVac->vac1Dosis=rand()%(max1-min1+1)+min1;
        auxVac->vac2Dosis= rand()%(max2-min2+1)+min2;
        auxVac->sinVacunar=100-(auxVac->vac1Dosis+auxVac->vac2Dosis);
    }
    return auxVac;
}

int filterPaisesExitosos(void* pElement)
{
    int retorno=0;
    ePais* auxPais;
    if(pElement!=NULL)
    {
        auxPais=(ePais*)pElement;
        if(auxPais->vac2Dosis>30)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filterPaisesAlHorno(void* pElement)
{
    int retorno=0;
    ePais* auxPais;
    int auxSuma;
    if(pElement!=NULL)
    {
        auxPais=(ePais*)pElement;
        auxSuma=auxPais->vac1Dosis+auxPais->vac2Dosis;
        //if(auxPais->sinVacunar>auxPais->vac1Dosis && auxPais->sinVacunar>auxPais->vac2Dosis)
        if(auxPais->sinVacunar>auxSuma)
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_CompareByVac1(void* pos1, void* pos2)
{
    int compare=0;
    ePais* pais1;
    ePais* pais2;
    if(pos1!=NULL && pos2!=NULL)
    {
        pais1=(ePais*)pos1;
        pais2=(ePais*)pos2;
        if(pais1->vac1Dosis>pais2->vac1Dosis)
        {
            compare=1;
        }
        else
        {
            compare=-1;
        }
    }
    return compare;
}

void criterioOrdenamiento(LinkedList* pArrayList)
{
    int opcion;
    if (pArrayList!=NULL)
    {
        do
        {
            system("cls");
            printf("        ***Seleccione el criterio de ordenamiento***     \n");
            printf("1. Por porcentaje con 1 dosis de la vacuna:\n");
            printf("2. Salir\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    printf("Ingrese la opcion si 1(ascendente) o 2(decendente)\n");
                    scanf("%d",&opcion);
                    if(opcion==1)
                    {
                        ll_sort(pArrayList,pais_CompareByVac1,1);
                        controller_ListPaises(pArrayList);
                    }
                    else
                    {
                        ll_sort(pArrayList,pais_CompareByVac1,0);
                        controller_ListPaises(pArrayList);
                    }
                    system("pause");
                    break;
            }
        }while(opcion!=2);
    }
}


int paisMasCastigado(LinkedList* pArrayList)
{
    int len;
    ePais* auxP = NULL;
    char auxPais[20];
    int masCastigado = -1;
    if (pArrayList != NULL)
    {
        len = ll_len(pArrayList);

        for (int i=0; i<len; i++)
        {
            auxP=ll_get(pArrayList, i);
            if (i==0 || auxP->sinVacunar > masCastigado)
            {
                masCastigado = auxP->sinVacunar;
            }
        }
        printf("Pais/es mas castigado/s: \n");
        for (int i = 0; i < len; i++)
        {
            auxP=ll_get(pArrayList, i);
            if (auxP->sinVacunar == masCastigado)
            {
                if (pais_getNombre(auxP, auxPais))
                {
                    printf("%15s\n", auxPais);
                }
            }
        }
        printf("Tuvo: %d de personas sin vacunar\n", masCastigado);
    }
    return masCastigado;
}


