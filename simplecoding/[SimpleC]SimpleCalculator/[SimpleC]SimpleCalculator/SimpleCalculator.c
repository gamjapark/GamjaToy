#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void menu(void);
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
//1) menu ����ϴ� �Լ� �ۼ�
void menu() {
	printf("=====================\n");
	printf("0. ����\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("=====================\n");
}
//2) ���� ����ϴ� �Լ� �ۼ�
int add(int x, int y) {
	return x + y;
}
//3) ���� ��� �Լ�
int sub(int x, int y) {
	return x - y;
}
//4) ���� ��� �Լ�
int mul(int x, int y) {
	return x * y;
}
int main(void)
{
	int choice, result, x, y;
	int(*pf[3])(int, int) = { add, sub, mul };
	while (1)
	{
		menu();
		printf("�޴��� �����Ͻÿ�:");
		scanf("%d", &choice);
		if (choice < 0 || choice >= 3)
			break;
		//5) 2�� ���� �Է� �� �Լ� �����͸� �̿��Ͽ� �Լ� ȣ��
		printf("2���� ������ �Է��Ͻÿ�:");
		scanf("%d %d", &x, &y);
		result = pf[choice](x, y);
		printf("���� ��� = %d\n", result);
	}
	return 0;
}