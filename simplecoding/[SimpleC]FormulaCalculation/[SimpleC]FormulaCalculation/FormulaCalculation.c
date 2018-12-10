#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double f1(double k);
double f2(double k);
double formula(double(*pf)(double), int n);

int main(void)
{
	printf("%f\n", formula(f1, 10));
	printf("%f\n", formula(f2, 10));
}
//1) ���� ��� �Լ�
double formula(double(*pf)(double), int n)
{
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		double funcVal = pf(i);
		sum += (funcVal*funcVal + funcVal + 1);
	}
	return sum;
}
//2) ���� ��� �Լ�
double f1(double k)
{
	return 1.0 / k;
}
//3) cosine ��� �Լ�
double f2(double k)
{
	return cos(k);
}