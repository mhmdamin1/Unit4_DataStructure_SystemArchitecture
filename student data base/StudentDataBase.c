#include "StudentDataBase.h"

#include <string.h>

static int Records = 0;

void ErrorPrint(Linkedlist_statue state)
{
	switch(state)
	{
	case LINKEDLIST_NULL:
		DPRINTF("\n Null Linked list")
		break;
	case LINKEDLIST_MEMORY_ERROR:
		DPRINTF("\n Memory Error ")
		break;
	case LINKEDLIST_EMPTY:
		DPRINTF("\n Linked list Empty")
		break;
	case LINKEDLIST_INNER_LOOP:
		DPRINTF("\n Inner loop in linked list")
		break;
	case LINKEDLIST_NO_INNER_LOOP:
		DPRINTF("\n NO Inner loop in linked list")
		break;
	case LINKEDLIST_OUT_OF_INDEX:
		DPRINTF("\n Out of Index")
		break;
	case LINKEDLIST_NO_ERROR:
		break;
	}
}


void gpStudentsInit(LinkedList_t* gpStudents)
{
	LinkedList_Init(gpStudents);
}

void fill_the_record(List_Element_Type*  gpStudents)
{

	char temp_text[40];
	DPRINTF("\n Enter the ID : ")
	fgets(temp_text, 40, stdin);
	gpStudents->ID = atoi(temp_text);

	DPRINTF("\n Enter Student Full Name : ")
	fgets(gpStudents->name, 40, stdin);
	gpStudents->name[strlen(gpStudents->name) - 1] = 0;

	DPRINTF("\n Enter Student Height : ")
	fgets(temp_text, 40, stdin);
	gpStudents->height = atoi(temp_text);

	Records ++;
	gpStudents->recordNumber = Records;

}

void AddStudent(LinkedList_t*  gpStudents)
{
	List_Element_Type newStudent;
	fill_the_record(&newStudent);
	ErrorPrint(LinkedList_Insert(gpStudents, gpStudents->size, newStudent));
}


int Delete_Student(LinkedList_t*  gpStudents)
{
	char temp_text[40];
	int selected_ID, i;
	DPRINTF("\n Enter the ID : ")
	fgets(temp_text, 40, stdin);
	selected_ID = atoi(temp_text);

	for(i = 0; i < gpStudents->size; i++)
	{
		List_Element_Type temp_Student ;
		ErrorPrint(LinkedList_RetrieveList(gpStudents, i, &temp_Student));
		if(temp_Student.ID == selected_ID)
		{
			ErrorPrint(LinkedList_Delete(gpStudents, i, &temp_Student));
			return 1;
		}
	}
	return 0;

}

void Display(List_Element_Type *e)
{
	DPRINTF("\n Record Number : %d", e->recordNumber)
	DPRINTF("\n ID : %d", e->ID)
	DPRINTF("\n Name : %s", e->name)
	DPRINTF("\n Height : %0.2f", e->height)
}

void view_students(LinkedList_t*  gpStudents)
{
	ErrorPrint(LinkedList_Traverse(gpStudents, Display));
}


void DeleteAll(LinkedList_t*  gpStudents)
{
	ErrorPrint(LinkedList_Destroy(gpStudents));
}

void GetNth_Student(LinkedList_t*  gpStudents)
{
	char temp_text[40];
	int Index;
	List_Element_Type temp_Student;
	DPRINTF("\n Enter the Index : ")
	fgets(temp_text, 40, stdin);
	Index = atoi(temp_text);
	ErrorPrint(LinkedList_RetrieveList(gpStudents, Index, &temp_Student));
	Display(&temp_Student);

}


void GetNth_Student_Back(LinkedList_t*  gpStudents)
{
	char temp_text[40];
	int Index;
	List_Element_Type temp_Student;
	DPRINTF("\n Enter the Index From Back : ")
	fgets(temp_text, 40, stdin);
	Index = atoi(temp_text);
	ErrorPrint(LinkedList_RetrieveList_FromBack(gpStudents, Index, &temp_Student));
	Display(&temp_Student);
}


void GetLength_Students(LinkedList_t*  gpStudents)
{
	char temp_text[40];
	int select, length;
	DPRINTF("\n Enter the Length Iterative ( 0 ) Or Recursive ( 1 ): ")
	fgets(temp_text, 40, stdin);
	select = atoi(temp_text);
	switch(select)
	{
	case 0:
		length = Linkedlist_Length_Iterative(gpStudents);
		DPRINTF("\n Length : %d", length);
		break;
	case 1:
		length = Linkedlist_Length_Recursive(gpStudents->head);
		DPRINTF("\n Length : %d", length);
		break;
	default:
		DPRINTF("\n Entered a wrong Choose ")
	}

}


void GetMiddle_Student(LinkedList_t*  gpStudents)
{
	List_Element_Type e;

	DPRINTF("\n Middle Student: ")
	ErrorPrint(Linkedlist_MiddleList(gpStudents, &e));
	Display(&e);

}

void Is_loop_Inside(LinkedList_t*  gpStudents)
{
	ErrorPrint(Linkedlist_InnerLoop(gpStudents));
}


void Reverse_Students(LinkedList_t* gpStudents)
{
	ErrorPrint(Linkedlist_Reverse(gpStudents));
}
