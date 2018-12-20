#include <stdio.h>
#include "student.h"

int main(){

	StudentInfo* students = (StudentInfo*)malloc(sizeof(StudentInfo) * 1024);
	int studentCount = GetStInfoFromFile("data.txt", &students);
	printf("%d\n",studentCount);
	free(students);
	return 0;
}
