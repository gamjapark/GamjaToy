#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// StudentID : 20116117033
// Name : Park Yeonji

typedef struct record {
	unsigned char stNum;
	unsigned char scoreNum0;
	unsigned char scoreNum1;
	unsigned char scoreNum2;
	double avgNum;
}Record;

void SortRecord(Record* record, unsigned char check);
void SwapRecord(Record* a, Record *b);
void PrintRecord(Record* a, const char* printString);

int main() {

	Record* student = (Record*)malloc(sizeof(Record) * 50);

	for (int i = 0; i < 50; i++) {		//Step1. give rand socre
		student[i].stNum = i + 1;
		student[i].scoreNum0 = rand() % 101;
		student[i].scoreNum1 = rand() % 101;
		student[i].scoreNum2 = rand() % 101;
		student[i].avgNum = (double)(student[i].scoreNum0 + student[i].scoreNum1 + student[i].scoreNum2) / 3.0;
	}

	PrintRecord(student, "< 학번 순 출력 >");		//Step2. print record card order by student num

	int scoreNum;				//Step3. input num & print sorted record
	printf("\n과목 번호를 입력하세요.(0, 1, or 2) :"); scanf("%d", &scoreNum);
	printf("\n");
	SortRecord(student, scoreNum);

	return 0;
}

void SortRecord(Record* record, unsigned char check) {
	if (check != 0 && check != 1 && check != 2) {
		printf("과목 번호가 잘못되었습니다.");
		return;
	}
	
	switch (check)
	{
	case 0:
		for (int i = 0; i < 50; i++) {
			int min = i;
			for (int j = i + 1; j < 50; j++) {
				if (record[min].scoreNum0 > record[j].scoreNum0) {
					min = j;
				}
			}
			SwapRecord(&record[min], &record[i]);
		}
		break;
	case 1:
		for (int i = 0; i < 50; i++) {
			int min = i;
			for (int j = i + 1; j < 50; j++) {
				if (record[min].scoreNum1 > record[j].scoreNum1) {
					min = j;
				}
			}
			SwapRecord(&record[min], &record[i]);
		}
		break;
	case 2:
		for (int i = 0; i < 50; i++) {
			int min = i;
			for (int j = i + 1; j < 50; j++) {
				if (record[min].scoreNum2 > record[j].scoreNum2) {
					min = j;
				}
			}
			SwapRecord(&record[min], &record[i]);
		}
		break;
	}
	PrintRecord(record, "< 정렬 순 출력 >");
}

void SwapRecord(Record* a, Record *b) {
	Record temp = *a;
	*a = *b;
	*b = temp;
}

void PrintRecord(Record* a, const char* printString) {
	printf(printString);			//orint string
	for (int i = 0; i < 50; i++) {
		printf("\n");
		printf("학 번 :%3d\n", a[i].stNum);
		printf("과목 0 점수 :%4d\n", a[i].scoreNum0);
		printf("과목 1 점수 :%4d\n", a[i].scoreNum1);
		printf("과목 2 점수 :%4d\n", a[i].scoreNum2);
		printf("평균 점수 :%4.2lf\n", a[i].avgNum);
	}
}
