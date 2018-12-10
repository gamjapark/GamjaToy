#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
struct point // 구조체 point의 정의
{
	int xpos;
	int ypos;
};
int main(void)
{
	struct point pos[2];
	double distance;
	//1) 첫 번째 좌표와 두번째 좌표 입력
	printf("---두 개의 좌표 입력---");
	for (int i = 0; i < 2; i++) {
		printf("\n%d번 x 좌표를 입력하세요 : ", i + 1); scanf("%d", &pos[i].xpos);
		printf("%d번 y 좌표를 입력하세요 : ", i + 1); scanf("%d", &pos[i].ypos);
	}

	//2) 두 점간의 거리 계산 및 출력
	double diffX = (double)(pos[0].xpos - pos[1].xpos);
	double diffY = (double)(pos[0].ypos - pos[1].ypos);
	distance = sqrt(diffX * diffX + diffY * diffY);
	printf("\neuclidean distance: %lf", distance);
	return 0;
}
