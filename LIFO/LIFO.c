#include "LIFO.h"



Buffer_status LIFO_Init(LIFO_Buff_t *pBuf, LIFO_Element_t* Buffer, unsigned int LIFO_size)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	pBuf->Length = LIFO_size;
	pBuf->count = 0;
	pBuf->Base = Buffer;
	pBuf->Head = Buffer;

	return LIFO_NO_ERROR;
}


Buffer_status LIFO_Push(LIFO_Buff_t *pBuf, LIFO_Element_t element)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;
	int x = LIFO_Is_Full(pBuf);
	if(LIFO_Is_Full(pBuf))
		return LIFO_FULL;

	*(pBuf->Head) = element;
	pBuf->Head ++;
	pBuf->count ++;

	return LIFO_NO_ERROR;
}


Buffer_status LIFO_Pop(LIFO_Buff_t *pBuf, LIFO_Element_t *pElement)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	if(LIFO_Is_Empty(pBuf))
		return LIFO_EMPTY;

	pBuf->Head --;
	*(pElement) = *(pBuf->Head);
	pBuf->count --;

	return LIFO_NO_ERROR;
}


int LIFO_Is_Empty (LIFO_Buff_t *pBuf)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	return pBuf->count == 0;
}



int LIFO_Is_Full (LIFO_Buff_t *pBuf)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	return pBuf->Length == pBuf->count;
}



Buffer_status LIFO_Top (LIFO_Buff_t *pBuf, LIFO_Element_t *pElement)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	if(LIFO_Is_Empty(pBuf))
		return LIFO_EMPTY;

	pBuf->Head --;
	*(pElement) = *(pBuf->Head);
	pBuf->Head ++;

	return LIFO_NO_ERROR;
}


int LIFO_Size (LIFO_Buff_t *pBuf)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;
	return pBuf->count;
}


Buffer_status LIFO_clear (LIFO_Buff_t *pBuf)
{
	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	pBuf->count = 0;
	pBuf->Head = pBuf->Base;

	return LIFO_NO_ERROR;
}


Buffer_status LIFO_traverse (LIFO_Buff_t *pBuf, void (*pf) (LIFO_Element_t))
{
	LIFO_Element_t *i;

	if(!pBuf || !pBuf->Head || !pBuf->Base)
		return LIFO_NULL;

	for(i = pBuf->Head; i > pBuf->Base;)
	{
		i--;
		(*pf)(*i);
	}
	return LIFO_NO_ERROR;
}
