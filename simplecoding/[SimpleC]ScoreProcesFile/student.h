#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BUFFER_SIZE 512
#define ST_INFO_COUNT 6

typedef struct{
	int stNum;
	char* stName;
	int midtermExamScore;
	int finalExamScore;
	int trainingScore;
	int assignmentScore;
	double totalScore;
	char grade;
	double (*funcP1)(int, int, int, int);
	int (*funcP2)(int, double, int);
}StudentInfo;

int GetStInfoFromFile(const char* fileName, StudentInfo** students);
double CalTotalScore(int mid, int fin, int train, int assign);
int GetStandardStCount(int stCount, double ratio, int originStandard);
