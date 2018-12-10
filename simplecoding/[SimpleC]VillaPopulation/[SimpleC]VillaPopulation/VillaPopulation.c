#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int villa[4][2]; //4개층, 층별 2개 가구 존재
	int popu, i, j;

	//1) 가구별 거주 인원 입력 받기
	for (i = 0; i < 4; i++){
		for (j = 0; j < 2; j++) {
			printf("%d층 %d번 가구의 인원수를 입력하세요 : ", i + 1, j + 1); scanf("%d", &villa[i][j]);
		}
		printf("\n");
	}
	//2) 층별 인구수 출력
	for (i = 0; i < 4; i++){
		popu = 0;
		for (j = 0; j < 2; j++) {
			popu += villa[i][j];
		}
		printf("%d층 인구 수 : %d\n", i + 1, popu);
	}
	return 0;
}