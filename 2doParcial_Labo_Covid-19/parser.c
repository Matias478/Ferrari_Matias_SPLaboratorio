#include "parser.h"
#include "controller.h"
#include "pais.h"
#include <stdio.h>
#include <stdlib.h>


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ListaFromText(FILE* pFile , LinkedList* pArrayList)
{
    ePais* auxPais;
    char id[5];
    char nombre[128];
    char recuperados[10];
    char infectados[10];
    char muertos[10];
    int retorno=0;
    int cant;
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,recuperados,infectados,muertos);
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,recuperados,infectados,muertos);
            if(cant==5)
            {
                auxPais=pais_newParametros(id,nombre,recuperados,infectados,muertos);
                ll_add(pArrayList,auxPais);
            }
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}



