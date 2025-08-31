// by mohamed amin 

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include "Linkedlist_Cfg.h"


typedef struct {
	List_Element_Type entry;
	struct SDataNode *next;
}SDataNode;

typedef struct {
	SDataNode *head;
	int size;
}LinkedList_t;

typedef enum
{
	LINKEDLIST_NO_ERROR,
	LINKEDLIST_NULL,
	LINKEDLIST_MEMORY_ERROR,
	LINKEDLIST_EMPTY,
	LINKEDLIST_INNER_LOOP,
	LINKEDLIST_NO_INNER_LOOP,
	LINKEDLIST_OUT_OF_INDEX
}Linkedlist_statue;


Linkedlist_statue LinkedList_Init (LinkedList_t *pl);


int LinkedList_Is_Empty (LinkedList_t *pl);


int LinkedList_Is_Full (LinkedList_t *pl);


int LinkedList_Size (LinkedList_t *pl);


Linkedlist_statue LinkedList_Destroy (LinkedList_t *pl);

Linkedlist_statue LinkedList_Insert (LinkedList_t *pl, unsigned int position, List_Element_Type e);

Linkedlist_statue LinkedList_Delete(LinkedList_t *pl, unsigned int position, List_Element_Type *pe);

Linkedlist_statue LinkedList_Traverse (LinkedList_t* pl, void (*pf) (List_Element_Type* e) );

Linkedlist_statue LinkedList_RetrieveList (LinkedList_t *pl, unsigned int position, List_Element_Type *pe);

Linkedlist_statue LinkedList_ReplaceListElement (LinkedList_t *pl, unsigned int position, List_Element_Type e);

Linkedlist_statue LinkedList_RetrieveList_FromBack (LinkedList_t *pl, unsigned int position, List_Element_Type *pe);

int Linkedlist_Length_Iterative(LinkedList_t *pl);

int Linkedlist_Length_Recursive(SDataNode *pl);

Linkedlist_statue Linkedlist_MiddleList(LinkedList_t *pl, List_Element_Type *pe);

Linkedlist_statue Linkedlist_InnerLoop(LinkedList_t *pl);

Linkedlist_statue Linkedlist_Reverse(LinkedList_t *pl);

#endif /* LINKEDLIST_H_ */
