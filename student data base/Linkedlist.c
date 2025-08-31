// by mohamed amin

#include "Linkedlist.h"

Linkedlist_statue LinkedList_Init (LinkedList_t *pl)
{

	pl->head = NULL;
	pl->size = 0;

	return LINKEDLIST_NO_ERROR;
}


int LinkedList_Is_Empty (LinkedList_t *pl)
{
	return pl->size == 0;
}


int LinkedList_Is_Full (LinkedList_t *pl)
{
	if(!pl)
		return LINKEDLIST_NULL;
	return 0;
}


int LinkedList_Size (LinkedList_t *pl)
{
	return pl->size;
}


Linkedlist_statue LinkedList_Destroy (LinkedList_t *pl)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	while(pl->head)
	{
		SDataNode* temp = pl->head;
		pl->head = pl->head->next;
		free(temp);
	}
	pl->size = 0;

	return LINKEDLIST_NO_ERROR;
}


Linkedlist_statue LinkedList_Insert (LinkedList_t *pl, unsigned int position, List_Element_Type e)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(position > pl->size)
		return LINKEDLIST_OUT_OF_INDEX;

	SDataNode* NewElement = (SDataNode*) malloc(sizeof(SDataNode));

	if(!NewElement)
		return LINKEDLIST_MEMORY_ERROR;

	NewElement->entry = e;
	NewElement->next = NULL;

	if(position == 0)
	{
		NewElement->next = pl->head;
		pl->head = NewElement;
	}
	else
	{
		int i;
		SDataNode* temp;

		for(i = 0,temp = pl->head; i < position - 1; i++)
		{
			temp = temp->next;
		}

		NewElement->next = temp->next;
		temp->next = NewElement;
	}
	pl->size ++;

	return LINKEDLIST_NO_ERROR;
}


Linkedlist_statue LinkedList_Delete(LinkedList_t *pl, unsigned int position, List_Element_Type *pe)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	if(position >= pl->size)
		return LINKEDLIST_OUT_OF_INDEX;

	SDataNode *current, *perv;
	int i;

	if(position == 0)
	{
		*pe = (pl->head->entry);
		current = pl->head;
		pl->head = pl->head->next;
		free(current);
	}
	else
	{
		for(i = 0, current = pl->head; i < position - 1; i++)
		{
			current = current->next;
		}
		perv = current;
		current = current->next;
		perv->next = current->next;
		free(current);
	}
	pl->size --;


	return LINKEDLIST_NO_ERROR;
}


Linkedlist_statue LinkedList_Traverse (LinkedList_t* pl, void (*pf) (List_Element_Type* e) )
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	SDataNode* temp;
	for(temp = pl->head; temp ; temp = temp->next)
	{
		(*pf)(&(temp->entry));
	}

	return LINKEDLIST_NO_ERROR;

}


Linkedlist_statue LinkedList_RetrieveList (LinkedList_t *pl, unsigned int position, List_Element_Type *pe)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	if(position >= pl->size)
		return LINKEDLIST_OUT_OF_INDEX;

	int i;
	SDataNode* temp;

	for(i = 0,temp = pl->head; i < position; i++)
	{
		if(!temp)
			return LINKEDLIST_NULL;

		temp = temp->next;
	}
	*pe = (temp->entry);


	return LINKEDLIST_NO_ERROR;
}


Linkedlist_statue LinkedList_ReplaceListElement (LinkedList_t *pl, unsigned int position, List_Element_Type e)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	if(position >= pl->size)
		return LINKEDLIST_OUT_OF_INDEX;

	int i;
	SDataNode* temp;

	for(i = 0,temp = pl->head; i < position; i++)
	{
		if(!temp)
			return LINKEDLIST_NULL;

		temp = temp->next;
	}
	(temp->entry) = e;

	return LINKEDLIST_NO_ERROR;
}

Linkedlist_statue LinkedList_RetrieveList_FromBack (LinkedList_t *pl, unsigned int position, List_Element_Type *pe)
{
	if(!pl)
		return LINKEDLIST_NULL;

	if(LinkedList_Is_Empty(pl))
		return LINKEDLIST_EMPTY;

	if(position >= pl->size)
		return LINKEDLIST_OUT_OF_INDEX;

	/*
	// Method 1
	unsigned int new_position = pl->size - position - 1;

	LinkedList_RetrieveList(pl, new_position, pe);
	*/

	// Method 2
	unsigned int i = 0;
	SDataNode *selected = pl->head, *iterator = pl->head;

	for(i = 0; iterator; i++)
	{
		if(i <= position)
		{
			iterator = iterator->next;
		}
		else
		{
			iterator = iterator->next;
			selected = selected->next;
		}
	}

	*(pe) = (selected->entry);


	return LINKEDLIST_NO_ERROR;
}


int Linkedlist_Length_Iterative(LinkedList_t *pl)
{

	unsigned int count = 0;
	SDataNode *selected = pl->head;

	while(selected)
	{
		selected = selected->next;
		count ++;
	}

	return count;
}

int Linkedlist_Length_Recursive(SDataNode *pl)
{
	if(!pl)
	{
		return 0;
	}

	return (1 + (Linkedlist_Length_Recursive(pl->next)));
}


Linkedlist_statue Linkedlist_MiddleList(LinkedList_t *pl, List_Element_Type *pe)
{
	if(!pl)
		return LINKEDLIST_NULL;

	SDataNode *fastpp, *slowpp;
	fastpp = pl->head;
	slowpp = pl->head;
	while(fastpp)
	{
		fastpp = fastpp->next;
		if(!fastpp)
			break;
		fastpp = fastpp->next;
		slowpp = slowpp->next;
	}
	*(pe) = (slowpp->entry);

	return LINKEDLIST_NO_ERROR;
}

Linkedlist_statue Linkedlist_InnerLoop(LinkedList_t *pl)
{
	SDataNode *fastpp, *slowpp;
	fastpp = pl->head;
	slowpp = pl->head;
	while(fastpp)
	{
		fastpp = fastpp->next;
		if(!fastpp)
			break;
		fastpp = fastpp->next;
		slowpp = slowpp->next;

		if(fastpp == slowpp)
			return LINKEDLIST_INNER_LOOP;
	}

	return LINKEDLIST_NO_INNER_LOOP;
}

Linkedlist_statue Linkedlist_Reverse(LinkedList_t *pl)
{
	if(!pl)
		return LINKEDLIST_NULL;

	SDataNode *perv = NULL, *current = pl->head, *next = NULL;

	while (current)
	{
		next = current->next;
		current->next = perv;
		perv = current;
		current = next;
	}

	pl->head = perv;

	return LINKEDLIST_NO_ERROR;
}
