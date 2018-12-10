#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void menu(void);
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
//1) menu 출력하는 함수 작성
void menu() {
	printf("=====================\n");
	printf("0. 덧셈\n");
	printf("1. 뺄셈\n");
	printf("2. 곱셈\n");
	printf("3. 종료\n");
	printf("=====================\n");
}
//2) 덧셈 출력하는 함수 작성
int add(int x, int y) {
	return x + y;
}
//3) 뺄셈 출력 함수
int sub(int x, int y) {
	return x - y;
}
//4) 곱셈 출력 함수
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
		printf("메뉴를 선택하시오:");
		scanf("%d", &choice);
		if (choice < 0 || choice >= 3)
			break;
		//5) 2개 정수 입력 후 함수 포인터를 이용하여 함수 호출
		printf("2개의 정수를 입력하시오:");
		scanf("%d %d", &x, &y);
		result = pf[choice](x, y);
		printf("연산 결과 = %d\n", result);
	}
	return 0;
}