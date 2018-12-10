#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[3][4];
	int i, j;
	int tot;
	double avg;
	//1) 3명 학생의 4과목 점수를 키보드로부터 입력
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d번 학생의 %d번 과목 점수를 입력하세요 : ", i + 1, j + 1); scanf("%d", &score[i][j]);
		}
		printf("\n");
	}
	//2) 학생당 평균 계산 및 출력
	for (i = 0; i < 3; i++) {
		tot = 0;
		for (j = 0; j < 4; j++) {
			tot += score[i][j];
		}
		avg = (double)(tot / 4);
		printf("%d번 학생의 평균 : %lf\n", i + 1, avg);
	}
	return 0;
}
