#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=0;
    FILE* pArchivo = (FILE*)malloc(sizeof(FILE));
    if(path!=NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo!=NULL)
        {
            retorno=parser_ListaFromText(pArchivo, pArrayList);
        }else{
            printf("Nose pudo abrir el archivo");
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_ListPaises(LinkedList* pArrayList)
{
    int retorno=0;
    ePais* auxPais=NULL;
    //int len;
    if(pArrayList!=NULL)
    {
        printf("    ID\t    Nombre \t   Vac1Dosis\t Vac2Dosis\t Sin Vacunar\n");
        for(int i=0;i<ll_len(pArrayList);i++)
        {
            auxPais=(ePais*)ll_get(pArrayList,i);
            pais_listarUnPais(auxPais);
        }
        printf("\n\n");
        retorno=1;
    }
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayList)
{
    criterioOrdenamiento(pArrayList);

    return 1;
}



