/*
 * LIFO.H
 *
 *  Created on: Aug 13, 2023
 *      Author: Hussein Elsaka
 */

#ifndef LIFO_H_
#define LIFO_H_

typedef unsigned int LIFO_Element_t;

#define  

#ifndef NULL
#define NULL 0
#endif

typedef struct
{
	unsigned int Length;
	unsigned int count;
	LIFO_Element_t* Base;
	LIFO_Element_t* Head;
}LIFO_Buff_t;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
}Buffer_status;


/*
	Function : LIFO_Init
	Description : initialize the Stack

*/
Buffer_status LIFO_Init(LIFO_Buff_t *pBuf, LIFO_Element_t* Buffer, unsigned int LIFO_size);


/*
	Function : LIFO_Push
	Description : Push data into stack
	pre Conditions: stack must be initialized and not Full
	post Conditions: the element will be store at the top of the stack

*/
Buffer_status LIFO_Push(LIFO_Buff_t *pBuf, LIFO_Element_t element);

/*
	Function : LIFO_Pop
	Description : pop data from stack
	pre Conditions: stack must be initialized and not empty
	post Conditions: the element will be removed from the top of the stack, and its value will be in element

*/
Buffer_status LIFO_Pop(LIFO_Buff_t *pBuf, LIFO_Element_t *pElement);

/*
	Function : LIFO_Is_Empty
	Description : Check if the stack is empty
	pre Conditions: stack must be initialized
	post Conditions: return 0 if not empty - 1 if it empty

*/
int LIFO_Is_Empty (LIFO_Buff_t *pBuf);


/*
	Function : LIFO_Is_Full
	Description : Check if the stack is Full
	pre Conditions: stack must be initialized
	post Conditions: return 0 if not Full - 1 if it Full

*/
int LIFO_Is_Full (LIFO_Buff_t *pBuf);


/*
	Function : LIFO_Top
	Description : get the last Element of stack 'stack top element'
	pre Conditions: stack must be initialized and not empty
	post Conditions: get the element value of last value to ps and stack doesnt change

*/
Buffer_status LIFO_Top (LIFO_Buff_t *pBuf, LIFO_Element_t *pElement);

/*
	Function : LIFO_Size
	Description : get the stack size 'number of element'
	pre Conditions: stack must be initialized
	post Conditions: return size of stack

*/
int LIFO_Size (LIFO_Buff_t *pBuf);

/*
	Function : LIFO_clear
	Description : clear all stack elements
	pre Conditions: stack must be initialized
	post Conditions: there will be not an element in stack

*/
Buffer_status LIFO_clear (LIFO_Buff_t *pBuf);

/*
	Function : LIFO_traverse
	Description : applied a function over all stack elemnts
	pre Conditions: stack must be initialized and not empty - function must take stackentry as input
	post Conditions: function will be applied to all elements

*/
Buffer_status LIFO_traverse (LIFO_Buff_t *pBuf, void (*pf) (LIFO_Element_t));

#endif /* LIFO_H_ */
