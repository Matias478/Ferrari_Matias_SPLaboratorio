#include "LinkedList.h"
#include "controller.h"
#include "pais.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void* vacunas(void* element);
int filterPaisesExitosos(void* pElement);
int filterPaisesAlHorno(void* pElement);
int pais_CompareByVac1(void* e1, void* e2);
void criterioOrdenamiento(LinkedList* pArrayList);
int paisMasCastigado(LinkedList* pArrayList);

#endif // INFORMES_H_INCLUDED
