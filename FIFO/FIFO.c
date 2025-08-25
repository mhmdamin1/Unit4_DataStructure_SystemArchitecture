#include "FIFO.h"


Buffer_status FIFO_Init (FIFO_Buff_t *pBuff, FIFO_Element_t* Buffer, unsigned int BufferSize)
{
	if(!pBuff || !Buffer)
		return FIFO_NULL;

	pBuff->Base = Buffer;
	pBuff->Head = Buffer;
	pBuff->Tail = Buffer;
	pBuff->count = 0;
	pBuff->Length = BufferSize;

	return FIFO_NO_ERROR;
}


Buffer_status FIFO_Enqueue(FIFO_Buff_t *pBuff, FIFO_Element_t e)
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	if(FIFO_Is_Full(pBuff))
		return FIFO_FULL;

	*(pBuff->Head) = e;
	pBuff->count ++;

	if(pBuff->Head == (pBuff->Base + (pBuff->Length * sizeof(FIFO_Element_t))))
		pBuff->Head = pBuff->Base;
	else
		pBuff->Head ++;

	return FIFO_NO_ERROR;
}



Buffer_status FIFO_Dequeue(FIFO_Buff_t *pBuff, FIFO_Element_t *pe)
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	if(FIFO_Is_Empty(pBuff))
		return FIFO_EMPTY;

	*pe = *(pBuff->Tail);
	pBuff->count--;

	if(pBuff->Tail == (pBuff->Base + (pBuff->Length * sizeof(FIFO_Element_t))))
		pBuff->Tail = pBuff->Base;
	else
		pBuff->Tail ++;

	return FIFO_NO_ERROR;
}


int FIFO_Is_Empty (FIFO_Buff_t *pBuff)
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	return pBuff->count == 0;
}



int FIFO_Is_Full (FIFO_Buff_t *pBuff)
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	return pBuff->count == pBuff->Length;
}


int FIFO_Size(FIFO_Buff_t *pBuff)
{
	return pBuff->count;
}



Buffer_status FIFO_Clear (FIFO_Buff_t *pBuff)
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	pBuff->Head = pBuff->Base ;
	pBuff->Tail = pBuff->Base ;
	pBuff->count = 0;

	return FIFO_NO_ERROR;
}



Buffer_status FIFO_Traverse (FIFO_Buff_t *pBuff, void (*pf) (FIFO_Element_t))
{
	if(!pBuff || !pBuff->Base || !pBuff->Head || !pBuff->Tail)
		return FIFO_NULL;

	if(FIFO_Is_Empty(pBuff))
		return FIFO_EMPTY;

	int i;
	FIFO_Element_t *temp = pBuff->Tail;

	for(i = 0; i < pBuff->count; i++)
	{
		(*pf)(*temp);
		if(temp == (pBuff->Base + (pBuff->Length * sizeof(FIFO_Element_t))))
			temp = pBuff->Base;
		else
			temp ++;
	}

	return FIFO_NO_ERROR;

}
