#include <stdio.h>
#include "student.h"

int main(){

	StudentInfo* students = (StudentInfo*)malloc(sizeof(StudentInfo) * 1024);
	int studentCount = GetStInfoFromFile("data.txt", &students);
	printf("%d\n",studentCount);
	printf("\t   학번\t\t이름\t중간시험점수\t기말시험점수\t   실습점수\t   과제점수\t총점\t학점\n");
	for(int i = 0; i < studentCount; i++){
		PrintStudentInfo(students + i);
	}
	free(students);
	return 0;
}
