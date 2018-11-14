#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int HEIGHT = 0;
int WIDTH = 0;

int introtateArray(int** x, int degree);
int** Rotate90(int **x);
int** Alloc2DArray(int mHeigth, int mWidth);
void Free2DArray(int ** Arr, int mHeight);
void Print2DArray(int ** Arr, int mHeight, int mWidth, const char * printString);

// StudentID : 20116117033
// Name : Park Yeonji

int main() {

	int degree;

	printf("배열의 행의 크기를 입력하세요 : "); scanf("%d", &HEIGHT);	//input 2D array col size
	printf("배열의 열의 크기를 입력하세요 : "); scanf("%d", &WIDTH);	//input 2D array row size

	int** myArray = Alloc2DArray(HEIGHT, WIDTH);	//allocate 2D array
	printf("배열을 입력하세요 : \n");					//input 2D array value
	for (int h = 0; h < HEIGHT; h++) 
		for (int w = 0; w < WIDTH; w++) 
			scanf("%d", &myArray[h][w]);

	Print2DArray(myArray, HEIGHT, WIDTH, "입력한 배열 : \n");	//print 2D array

	printf("회전할 각도를 입력하세요 : ");	//input Rotataion angle
	scanf("%d", &degree);

	introtateArray(myArray, degree);		//rotate 2D array 
	Free2DArray(myArray, HEIGHT);			//deallocate 2D array

	return 0;
}

int introtateArray(int** x, int degree) {

	int** rotationArray = NULL;
	int** tmpArray1 = NULL;
	int** tmpArray2 = NULL;

	switch (degree)		//rotation with degree
	{
	case 90:
		rotationArray = Rotate90(x);
		break;
	case 180:
		tmpArray1 = Rotate90(x);				//rotataion with 90 angle
		rotationArray = Rotate90(tmpArray1);	//rotataion with 180 angle
		if(tmpArray1 != NULL) Free2DArray(tmpArray1, WIDTH);	//deallocate temp 2D array
		break;
	case 270:
		tmpArray1 = Rotate90(x);				//rotataion with 90 angle
		tmpArray2 = Rotate90(tmpArray1);		//rotataion with 180 angle
		rotationArray = Rotate90(tmpArray2);	//rotataion with 270 angle
		if(tmpArray1 != NULL) Free2DArray(tmpArray1, HEIGHT);	//deallocate temp 2D array
		if(tmpArray2 != NULL) Free2DArray(tmpArray2, WIDTH);	//deallocate temp 2D array
		break;
	default:
		return 0;
	}

	if (rotationArray != NULL) {
		Print2DArray(rotationArray, HEIGHT, WIDTH, "회전한 배열 : \n");	//회전한 배열 출력
		Free2DArray(rotationArray, HEIGHT);		//회전한 배열 해제
		return 1;
	}
}


int** Rotate90(int **x) {	//rotataion with 90 angle
	int temp = HEIGHT;		//change col & row
	HEIGHT = WIDTH;
	WIDTH = temp;

	int** rotationArray = Alloc2DArray(HEIGHT, WIDTH);
	for (int h = 0; h < WIDTH; h++) 
		for (int w = 0; w < HEIGHT; w++) 
			rotationArray[w][(WIDTH - 1) - h] = x[h][w];
	return rotationArray;
}

int** Alloc2DArray(int mHeigth, int mWidth) {
	int **Arr = (int **)malloc(sizeof(int *) * mHeigth);
	for (int i = 0; i < mHeigth; i++)
		Arr[i] = (int *)malloc(sizeof(int) * mWidth);
	return Arr;
}

void Free2DArray(int ** Arr, int mHeight) {
	for (int i = 0; i < mHeight; i++)
		free(Arr[i]);
	free(Arr);
}

void Print2DArray(int ** Arr, int mHeight, int mWidth, const char * printString) {
	printf(printString);
	for (int h = 0; h < mHeight; h++) {
		for (int w = 0; w < mWidth; w++) 
			printf("%7d", Arr[h][w]);
		printf("\n");
	}
}