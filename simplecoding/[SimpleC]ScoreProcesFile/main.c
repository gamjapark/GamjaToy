#include <stdio.h>
#include "student.h"

int main(){

	StudentInfo* students = (StudentInfo*)malloc(sizeof(StudentInfo) * 1024);
	int studentCount = GetStInfoFromFile("data.txt", &students);

	printf("\t\t\t\t\t < 학생 정보 파일 내용>\n\n");
	printf("\t   학번\t\t이름\t중간시험점수\t기말시험점수\t   실습점수\t   과제점수\t총점\t학점\n");
	for(int i = 0; i < studentCount; i++){
		students[i].funcP2(students + i);
	}

	
	StudentInfo* sortedStudent = SortStudents(students, studentCount, 1);
	printf("\t\t\t\t\t < 총점 내림차순 정렬>\n\n");
	printf("\t   학번\t\t이름\t중간시험점수\t기말시험점수\t   실습점수\t   과제점수\t총점\t학점\n");
	for(int i = 0; i < studentCount; i++){
		sortedStudent[i].funcP2(sortedStudent+ i);
	}

	sortedStudent = SortStudents(students, studentCount, 0);
	printf("\t\t\t\t\t < 학번 오름차순 정렬>\n\n");
	printf("\t   학번\t\t이름\t중간시험점수\t기말시험점수\t   실습점수\t   과제점수\t총점\t학점\n");
	for(int i = 0; i < studentCount; i++){
		sortedStudent[i].funcP2(sortedStudent+ i);
	}

	free(students);
	return 0;
}
