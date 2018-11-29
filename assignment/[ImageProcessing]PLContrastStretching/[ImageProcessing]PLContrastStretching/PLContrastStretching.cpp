#include <iostream>
#include <fstream>
using namespace std;

#define HEIGHT 512
#define WIDTH 512

void Prewise_LinearContrastStretching(float** Pixel, int nHeight, int nWidth);
int main() {

	unsigned char* inputImage = new unsigned char[HEIGHT * WIDTH * 3];
	unsigned char* outputImage = new unsigned char[HEIGHT * WIDTH * 3];

	ifstream readFile;
	readFile.open("lena512.rgb", ios::binary | ios::in);
	readFile.read((char *)inputImage, sizeof(unsigned char) * HEIGHT * WIDTH * 3);
	readFile.close();

	float* R = new float[HEIGHT * WIDTH];
	float* G = new float[HEIGHT * WIDTH];
	float* B = new float[HEIGHT * WIDTH];

	int idx = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			R[idx] = (float)inputImage[(i*WIDTH + j) * 3];
			G[idx] = (float)inputImage[(i*WIDTH + j) * 3 + 1];
			B[idx] = (float)inputImage[(i*WIDTH + j) * 3 + 2];
			++idx;
		}
	}

	Prewise_LinearContrastStretching(&R, HEIGHT, WIDTH);
	Prewise_LinearContrastStretching(&G, HEIGHT, WIDTH);
	Prewise_LinearContrastStretching(&B, HEIGHT, WIDTH);

	idx = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			outputImage[(i*WIDTH + j) * 3] = (unsigned char)R[idx];
			outputImage[(i*WIDTH + j) * 3 + 1] = (unsigned char)G[idx];
			outputImage[(i*WIDTH + j) * 3 + 2] = (unsigned char)B[idx];
			++idx;
		}
	}

	ofstream writeFile;
	writeFile.open("lena512.raw", ios::binary | ios::out);
	writeFile.write((char *)outputImage, sizeof(unsigned char) * HEIGHT * WIDTH * 3);
	writeFile.close();

	delete[] inputImage;
	delete[] outputImage;

	delete[] R;
	delete[] G;
	delete[] B;
	return 0;
}

void Prewise_LinearContrastStretching(float** Pixel, int nHeight, int nWidth) {

	for (int i = 0; i < nHeight * nWidth; i++) {
		float value = (*Pixel)[i];
		if (150 > value) {
			(*Pixel)[i] = value * (2.0 / 15.0);
		}
		else if (150 <= value && 200 > value) {
			(*Pixel)[i] = value * 4.0 - 580.0;
		}
		else if (200 <= value && 256 > value) {
			(*Pixel)[i] = (value - 200.0) * (7.0 / 11.0) + 220.0;
		}
	}
}