#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1) ����ü ����
struct point
{
	int xpos;
	int ypos;
};
int main(void)
{
	//2) ����ü �迭 ����
	struct point arr[3];
	//3) Ű����κ��� ��ǥ 3�� �Է�
	printf("---3�� ��ǥ �Է�---");
	for (int i = 0; i < 3; i++)
	{
		printf("\n%d�� x��ǥ : ", i + 1); scanf("%d", &arr[i].xpos);
		printf("%d�� y��ǥ : ", i + 1); scanf("%d", &arr[i].ypos);
	}

	printf("\n---3�� ��ǥ ���---\n");
	for (int j = 0; j < 3; j++)
		printf("[%d, %d] ", arr[j].xpos, arr[j].ypos);
	return 0;
}