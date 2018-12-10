#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int mean = 0, i, j;
	int record[3][3][2] = {
		//1) 학생의 성적 입력 (배열의 초기화)
		{	{70, 80},
			{94, 90},
			{70, 85} },
		{	{83, 90},
			{95, 60},
			{90, 82} },
		{	{98, 89},
			{99, 94},
			{91, 87}}
	};
	//2) A 학급 평균 성적 계산
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			mean += record[0][i][j];
		}
	}
	printf("A 학급 전체 평균: %g \n", (double)mean / 6);
	//3) B 학급 평균 성적 계산
	mean = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			mean += record[1][i][j];
		}
	}
	printf("B 학급 전체 평균: %g \n", (double)mean / 6);
	//4) C 학급 평균 성적 계산
	mean = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			mean += record[2][i][j];
		}
	}
	printf("C 학급 전체 평균: %g \n", (double)mean / 6);
	return 0;
}