#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1) ����ü ���� (�̸�, ��ȭ��ȣ, ����)
struct person
{
	char name[20];
	char phoneNum[30];
	int age;
};

int main(void)
{
	struct person man1;
	//2) �̸�, ��ȭ��ȣ, ���̸� �Է�
	printf("---���� ���� �Է�---\n");
	printf("�̸��� �Է��ϼ��� : "); scanf("%s", man1.name);
	printf("��ȭ��ȣ�� �Է��ϼ��� : "); scanf("%s", man1.phoneNum);
	printf("���̸� �Է��ϼ��� : "); scanf("%d", &man1.age);

	//3) �̸�, ��ȭ��ȣ, ���̸� ���
	printf("\n---���� ���� ���---\n");
	printf("�̸��� �Է��ϼ��� : %s\n", man1.name);
	printf("��ȭ��ȣ�� �Է��ϼ���: %s\n", man1.phoneNum);
	printf("���̸� �Է��ϼ��� : %d\n", man1.age);
	return 0;
}