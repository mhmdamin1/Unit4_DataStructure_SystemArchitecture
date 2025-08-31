
#ifndef STUDENTDATABASE_H_
#define STUDENTDATABASE_H_

#include "Linkedlist.h"
#include <stdio.h>

#define DPRINTF(...) {fflush(stdin);fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);fflush(stdout);}

void gpStudentsInit(LinkedList_t* gpStudents);

void fill_the_record(List_Element_Type* gpStudents);


void AddStudent(LinkedList_t*  gpStudents);


int Delete_Student(LinkedList_t*  gpStudents);


void view_students(LinkedList_t*  gpStudents);


void DeleteAll(LinkedList_t*  gpStudents);


void GetNth_Student(LinkedList_t*  gpStudents);


void GetNth_Student_Back(LinkedList_t*  gpStudents);


void GetLength_Students(LinkedList_t*  gpStudents);


void GetMiddle_Student(LinkedList_t*  gpStudents);


void Is_loop_Inside(LinkedList_t*  gpStudents);


void Reverse_Students(LinkedList_t* gpStudents);





#endif /* STUDENTDATABASE_H_ */
