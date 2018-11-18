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

	PrintRecord(student, "< �й� �� ��� >");		//Step2. print record card order by student num

	int scoreNum;				//Step3. input num & print sorted record
	printf("\n���� ��ȣ�� �Է��ϼ���.(0, 1, or 2) :"); scanf("%d", &scoreNum);
	printf("\n");
	SortRecord(student, scoreNum);

	return 0;
}

void SortRecord(Record* record, unsigned char check) {
	if (check != 0 && check != 1 && check != 2) {
		printf("���� ��ȣ�� �߸��Ǿ����ϴ�.");
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
	PrintRecord(record, "< ���� �� ��� >");
}

void SwapRecord(Record* a, Record *b) {
	Record temp = *a;
	*a = *b;
	*b = temp;
}

void PrintRecord(Record* a, const char* printString) {
	printf(printString);			//Step2. print record card order by student num
	for (int i = 0; i < 50; i++) {
		printf("\n");
		printf("�� �� :%3d\n", a[i].stNum);
		printf("���� 0 ���� :%4d\n", a[i].scoreNum0);
		printf("���� 1 ���� :%4d\n", a[i].scoreNum1);
		printf("���� 2 ���� :%4d\n", a[i].scoreNum2);
		printf("��� ���� :%4.2lf\n", a[i].avgNum);
	}
}