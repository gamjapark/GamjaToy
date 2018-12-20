#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BUFFER_SIZE 512
#define ST_INFO_COUNT 6

typedef struct StudentInfo{
	int stNum;
	char* stName;
	int midtermExamScore;
	int finalExamScore;
	int trainingScore;
	int assignmentScore;
	double totalScore;
	char grade;

	double (*funcP1)(const struct StudentInfo*);
	void (*funcP2)(const struct StudentInfo*);
	//int (*funcP3)(int, double, int);
}StudentInfo;

int GetStInfoFromFile(const char* fileName, StudentInfo** students);
void SwapStudent(StudentInfo* a, StudentInfo* b);
StudentInfo* SortStudents(StudentInfo* students, int stCount, unsigned char check);

double CalTotalScore(const StudentInfo* student);
//int GetStandardStCount(int stCount, double ratio, int originStandard);
void  PrintStudentInfo(const StudentInfo* student);

