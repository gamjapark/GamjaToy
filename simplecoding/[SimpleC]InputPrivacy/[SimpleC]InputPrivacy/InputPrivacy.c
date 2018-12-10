#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1) 구조체 정의 (이름, 전화번호, 나이)
struct person
{
	char name[20];
	char phoneNum[30];
	int age;
};

int main(void)
{
	struct person man1;
	//2) 이름, 전화번호, 나이를 입력
	printf("---개인 정보 입력---\n");
	printf("이름을 입력하세요 : "); scanf("%s", man1.name);
	printf("전화번호를 입력하세요 : "); scanf("%s", man1.phoneNum);
	printf("나이를 입력하세요 : "); scanf("%d", &man1.age);

	//3) 이름, 전화번호, 나이를 출력
	printf("\n---개인 정보 출력---\n");
	printf("이름을 입력하세요 : %s\n", man1.name);
	printf("전화번호를 입력하세요: %s\n", man1.phoneNum);
	printf("나이를 입력하세요 : %d\n", man1.age);
	return 0;
}