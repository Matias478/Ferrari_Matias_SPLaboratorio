#include "LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_ListPaises(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayList);

#endif // CONTROLLER_H_INCLUDED
