#include "pais.h"
#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


ePais* new_Pais()
{
    ePais* auxPais;

    auxPais=(ePais*)malloc(sizeof(ePais));
    if(auxPais!=NULL)
    {
        pais_setId(auxPais,0);
        pais_setNombre(auxPais," ");
        pais_setVac1Dosis(auxPais,0);
        pais_setVac2Dosis(auxPais,0);
        pais_setSinVacunar(auxPais,0);
    }
    return auxPais;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1Str,char* vac2Str,char* sinVacStr)
{
    ePais* auxPais;
    auxPais = new_Pais();

    if(auxPais!=NULL)
    {
        if(!(pais_setId(auxPais,atoi(idStr)) &&
             pais_setNombre(auxPais,nombreStr) &&
             pais_setVac1Dosis(auxPais,atoi(vac1Str)) &&
             pais_setVac2Dosis(auxPais,atoi(vac2Str)) &&
             pais_setSinVacunar(auxPais,atoi(sinVacStr))))
        {
            lista_delete(auxPais);
            auxPais=NULL;
        }
    }
    return auxPais;
}
void lista_delete(ePais* this)
{
    free(this);
}

int pais_listarUnPais(ePais* this)
{
    int retorno=0;
    int id;
    char nombre[128];
    int vac1;
    int vac2;
    int sin;

    if(this!=NULL && pais_getId(this, &id)
                  && pais_getNombre(this, nombre)
                  && pais_getVac1Dosis(this,&vac1)
                  && pais_getVac2Dosis(this, &vac2)
                  && pais_getSinVacunar(this, &sin))
    {
        printf(" %4d  %15s\t  \t  %4d\t %4d\t\t %4d\n",
               id,
               nombre,
               vac1,
               vac2,
               sin);
        retorno=1;
    }
    return retorno;
}


int pais_setId(ePais* this,int id)
{
    int retorno = 0;
    if(this != NULL && id >0)
    {
        this->id= id;
        retorno = 1;
    }
    return retorno;
}
int pais_getId(ePais* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        retorno= 1;
    }
    return retorno;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL) //&& strlen(nombre)<30 && strlen(nombre)>2)
    {
        strcpy(this->nombre ,nombre);
        retorno = 1;
    }
    return retorno;
}
int pais_getNombre(ePais* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);//(this->nombre ,nombre);
        retorno= 1;
    }
    return retorno;
}

int pais_setVac1Dosis(ePais* this,int vac1)
{
    int retorno = 0;
    if(this != NULL )//&& recu > 0)
    {
        this->vac1Dosis=vac1;
        retorno = 1;
    }
    return retorno;
}
int pais_getVac1Dosis(ePais* this,int* vac1)
{
    int retorno = 0;
    if(this != NULL && vac1!=NULL)
    {
        *vac1=this->vac1Dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_setVac2Dosis(ePais* this,int vac2)
{
    int retorno = 0;
    if(this != NULL )//&& infec > 0)
    {
        this->vac2Dosis=vac2;
        retorno = 1;
    }
    return retorno;
}
int pais_getVac2Dosis(ePais* this,int* vac2)
{
    int retorno = 0;
    if(this != NULL && vac2!=NULL)
    {
        *vac2=this->vac2Dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_setSinVacunar(ePais* this,int sin)
{
    int retorno = 0;
    if(this != NULL )//&& dead > 0)
    {
        this->sinVacunar=sin;
        retorno = 1;
    }
    return retorno;
}
int pais_getSinVacunar(ePais* this,int* sin)
{
    int retorno = 0;
    if(this != NULL && sin!=NULL)
    {
        *sin=this->sinVacunar;
        retorno = 1;
    }
    return retorno;
}

int validNumber(char* number)
{
    for(int i=0; i<strlen(number); i++)
    {
        if(!(isdigit(*(number+i))))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            //getchar();
            return 0;
        }
    }

    return 1;
}

