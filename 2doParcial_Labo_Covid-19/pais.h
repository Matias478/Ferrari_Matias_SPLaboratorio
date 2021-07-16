#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{
    int id;
    char nombre[51];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
}ePais;

ePais* new_Pais();
ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr,char* muertosStr);
void lista_delete(ePais* this);

int pais_listarUnPais(ePais* this);
int validNumber(char* number);

int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);

int pais_setVac1Dosis(ePais* this,int recu);
int pais_getVac1Dosis(ePais* this,int* recu);
int pais_setVac2Dosis(ePais* this,int infec);
int pais_getVac2Dosis(ePais* this,int* infec);
int pais_setSinVacunar(ePais* this,int dead);
int pais_getSinVacunar(ePais* this,int* dead);



#endif // PAIS_H_INCLUDED
