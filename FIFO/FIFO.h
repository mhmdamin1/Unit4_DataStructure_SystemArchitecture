/*
 * FIFO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: sonat
 */

#ifndef FIFO_H_
#define FIFO_H_

typedef unsigned int FIFO_Element_t;

#ifndef NULL
#define NULL 0
#endif


typedef struct {
	FIFO_Element_t* Base;
	FIFO_Element_t* Head;
	FIFO_Element_t* Tail;
	unsigned int Length;
	unsigned int count;
}FIFO_Buff_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}Buffer_status;

/*
	Function : FIFO_Init
	Description : initialize the Queue

*/
Buffer_status FIFO_Init (FIFO_Buff_t *pBuff, FIFO_Element_t* Buffer, unsigned int BufferSize);


/*
	Function : FIFO_Enqueue
	Description : Append data into Queue
	pre Conditions: Queue must be initialized and not Full
	post Conditions: the element will be store at the raer of the Queue

*/
Buffer_status FIFO_Enqueue(FIFO_Buff_t *pBuff, FIFO_Element_t e);


/*
	Function : FIFO_Dequeue
	Description : Serve first from Queue 'front'
	pre Conditions: Queue must be initialized and not empty
	post Conditions: the element will be removed from the front of the Queue, and its value will be in element

*/
Buffer_status FIFO_Dequeue(FIFO_Buff_t *pBuff, FIFO_Element_t *pe);


/*
	Function : FIFO_Is_Empty
	Description : Check if the Queue is empty
	pre Conditions: Queue must be initialized
	post Conditions: return 0 if not empty - 1 if it empty

*/
int FIFO_Is_Empty (FIFO_Buff_t *pBuff);


/*
	Function : FIFO_Is_Full
	Description : Check if the Queue is Full
	pre Conditions: Queue must be initialized
	post Conditions: return 0 if not Full - 1 if it Full

*/
int FIFO_Is_Full (FIFO_Buff_t *pBuff);



/*
	Function : FIFO_Size
	Description : get the Queue size 'number of element'
	pre Conditions: Queue must be initialized
	post Conditions: return size of Queue

*/
int FIFO_Size(FIFO_Buff_t *pBuff);


/*
	Function : FIFO_Clear
	Description : clear all Queue elements
	pre Conditions: Queue must be initialized
	post Conditions: there will be not an element in Queue

*/
Buffer_status FIFO_Clear (FIFO_Buff_t *pBuff);


/*
	Function : FIFO_Traverse
	Description : applied a function over all Queue elemnts
	pre Conditions: Queue must be initialized and not empty - function must take Queueentry as input
	post Conditions: function will be applied to all elements

*/
Buffer_status FIFO_Traverse (FIFO_Buff_t *pBuff, void (*pf) (FIFO_Element_t));

#endif /* FIFO_H_ */
