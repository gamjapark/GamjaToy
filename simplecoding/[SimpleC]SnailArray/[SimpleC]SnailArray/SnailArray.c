#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ary[50][50];
	int n, max, i, j, x = 0, y = -1, z = 1, num = 1;
	scanf("%d", &n);
	max = n;
	//1) n x n 달팽이 배열을 ary에 입력

	while (max > 0) {
		for (i = 0; i < max; i++) {
			y += z;
			ary[x][y] = num;
			num++;
		}
		for (i = 0; i < max - 1; i++) {
			x += z;
			ary[x][y] = num;
			num++;
		}

		z *= -1;
		max--;
	}
	//2) 입력된 n x n 달팽이 배열 출력
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%7d", ary[i][j]);
		}
		printf("\n");
	}

	return 0;
}