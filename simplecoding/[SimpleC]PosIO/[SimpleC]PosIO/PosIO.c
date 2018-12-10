#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1) 구조체 정의
struct point
{
	int xpos;
	int ypos;
};
int main(void)
{
	//2) 구조체 배열 선언
	struct point arr[3];
	//3) 키보드로부터 좌표 3개 입력
	printf("---3개 좌표 입력---");
	for (int i = 0; i < 3; i++)
	{
		printf("\n%d번 x좌표 : ", i + 1); scanf("%d", &arr[i].xpos);
		printf("%d번 y좌표 : ", i + 1); scanf("%d", &arr[i].ypos);
	}

	printf("\n---3개 좌표 출력---\n");
	for (int j = 0; j < 3; j++)
		printf("[%d, %d] ", arr[j].xpos, arr[j].ypos);
	return 0;
}