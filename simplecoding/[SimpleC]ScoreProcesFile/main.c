#include <stdio.h>
#include "student.h"

int main(){

	StudentInfo* students = (StudentInfo*)malloc(sizeof(StudentInfo) * 1024);
	int studentCount = GetStInfoFromFile("data.txt", &students);

	PrintList(students, studentCount,"\t\t\t\t\t < 학생 정보 파일 내용>\n\n");
	
	StudentInfo* sortedStudent = SortStudents(students, studentCount, 1);
	InputGrade(&sortedStudent, 0, (int)studentCount * 0.2, 'A');
	InputGrade(&sortedStudent, (int)studentCount * 0.2 , (int)studentCount * 0.6, 'B');
	InputGrade(&sortedStudent, (int)studentCount * 0.6 , (int)studentCount * 0.9, 'C');
	InputGrade(&sortedStudent, (int)studentCount * 0.9 , (int)studentCount, 'D');
	PrintList(sortedStudent, studentCount,"\t\t\t\t\t < 총점 내림차순 정렬>\n\n");


	sortedStudent = SortStudents(students, studentCount, 0);
	PrintList(sortedStudent, studentCount,"\t\t\t\t\t < 학번 오름차순 정렬>\n\n");

	
	free(students);
	return 0;
}
