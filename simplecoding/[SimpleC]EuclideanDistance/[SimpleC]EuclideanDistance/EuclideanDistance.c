#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
struct point // ����ü point�� ����
{
	int xpos;
	int ypos;
};
int main(void)
{
	struct point pos[2];
	double distance;
	//1) ù ��° ��ǥ�� �ι�° ��ǥ �Է�
	printf("---�� ���� ��ǥ �Է�---");
	for (int i = 0; i < 2; i++) {
		printf("\n%d�� x ��ǥ�� �Է��ϼ��� : ", i + 1); scanf("%d", &pos[i].xpos);
		printf("%d�� y ��ǥ�� �Է��ϼ��� : ", i + 1); scanf("%d", &pos[i].ypos);
	}

	//2) �� ������ �Ÿ� ��� �� ���
	double diffX = (double)(pos[0].xpos - pos[1].xpos);
	double diffY = (double)(pos[0].ypos - pos[1].ypos);
	distance = sqrt(diffX * diffX + diffY * diffY);
	printf("\neuclidean distance: %lf", distance);
	return 0;
}
