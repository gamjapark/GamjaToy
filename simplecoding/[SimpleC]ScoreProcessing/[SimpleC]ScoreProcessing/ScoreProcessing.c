#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[3][4];
	int i, j;
	int tot;
	double avg;
	//1) 3�� �л��� 4���� ������ Ű����κ��� �Է�
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d�� �л��� %d�� ���� ������ �Է��ϼ��� : ", i + 1, j + 1); scanf("%d", &score[i][j]);
		}
		printf("\n");
	}
	//2) �л��� ��� ��� �� ���
	for (i = 0; i < 3; i++) {
		tot = 0;
		for (j = 0; j < 4; j++) {
			tot += score[i][j];
		}
		avg = (double)(tot / 4);
		printf("%d�� �л��� ��� : %lf\n", i + 1, avg);
	}
	return 0;
}
