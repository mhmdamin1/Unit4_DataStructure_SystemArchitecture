// by mohamed amin 

#include <stdio.h>
#include "StudentDataBase.h"



int main()
{
	char temp_text[5];
	LinkedList_t gpStudents;
	gpStudentsInit(&gpStudents);
	while(1)
	{
		DPRINTF("\n=================================");
		DPRINTF("\n\t Choose on of the following Options \n");
		DPRINTF("\n 1: Add Student ");
		DPRINTF("\n 2: Delete Student ");
		DPRINTF("\n 3: View Student ");
		DPRINTF("\n 4: Delete All Students ");
		DPRINTF("\n 5: GetNth_Student ");
		DPRINTF("\n 6: GetNth_Student from Back ");
		DPRINTF("\n 7: GetLength_Students ");
		DPRINTF("\n 8: GetMiddle_Student ");
		DPRINTF("\n 9: Is_loop_Inside ");
		DPRINTF("\n 10: Reverse_Students ");
		DPRINTF("\n Enter option Number: ");
		fgets(temp_text, 5, stdin);
		DPRINTF("\n=================================");

		switch(atoi(temp_text))
		{
		case 1:
			AddStudent(&gpStudents);
			break;
		case 2:
			Delete_Student(&gpStudents);
			break;
		case 3:
			view_students(&gpStudents);
			break;
		case 4:
			DeleteAll(&gpStudents);
			break;
		case 5:
			GetNth_Student(&gpStudents);
			break;
		case 6:
			GetNth_Student_Back(&gpStudents);
			break;
		case 7:
			GetLength_Students(&gpStudents);
			break;
		case 8:
			GetMiddle_Student(&gpStudents);
			break;
		case 9:
			Is_loop_Inside(&gpStudents);
			break;
		case 10:
			Reverse_Students(&gpStudents);
			break;
		default:
			DPRINTF("\n Wrong option");
		}
	}
	return 0;

}
