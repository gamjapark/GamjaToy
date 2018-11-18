#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// StudentID : 20116117033
// Name : Park Yeonji

typedef struct record {
	unsigned char stNum;
	unsigned char scoreNum0;
	unsigned char scoreNum1;
	unsigned char scoreNum2;
	double avgNum;
}Record;

int main() {

	Record student[50];

	for (int i = 0; i < 50; i++) {		//Step1. give rand socre
		student[i].stNum = i + 1;
		student[i].scoreNum0 = rand() % 101;
		student[i].scoreNum1 = rand() % 101;
		student[i].scoreNum2 = rand() % 101;
		student[i].avgNum = (double)(student[i].scoreNum0 + student[i].scoreNum1 + student[i].scoreNum2) / 3.0;
	}

	printf("< 학번 순 출력 >");			//Step2. print record card order by student num
	for (int i = 0; i < 50; i++) {
		printf("\n");
		printf("학 번 :%3d\n", student[i].stNum);
		printf("과목 0 점수 :%4d\n", student[i].scoreNum0);
		printf("과목 1 점수 :%4d\n", student[i].scoreNum1);
		printf("과목 2 점수 :%4d\n", student[i].scoreNum2);
		printf("평균 점수 :%4.2lf\n", student[i].avgNum);
	}

	int scoreNum;
	printf("과목 번호를 입력하세요.(0, 1, or 2) :"); scanf("%d", &scoreNum);
	return 0;
}