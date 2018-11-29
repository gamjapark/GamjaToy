#include <iostream>
#include <fstream>
using namespace std;

#define HEIGHT 512
#define WIDTH 512

void Prewise_LinearContrastStretching(float** Pixel, int nHeight, int nWidth);
void DisplayHistogram(int * Hist, const char* fileName);
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

	int* HistR = new int[256];
	memset(HistR, 0, sizeof(int) * 256);
	int* HistG = new int[256];
	memset(HistG, 0, sizeof(int) * 256);
	int* HistB = new int[256];
	memset(HistB, 0, sizeof(int) * 256);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			HistR[outputImage[(i*WIDTH + j) * 3]]++;
			HistG[outputImage[(i*WIDTH + j) * 3 + 1]]++;
			HistB[outputImage[(i*WIDTH + j) * 3 + 2]]++;
		}
	}

	DisplayHistogram(HistR, "HistR.raw");
	DisplayHistogram(HistG, "HistG.raw");
	DisplayHistogram(HistB, "HistB.raw");

	delete[] inputImage;
	delete[] outputImage;

	delete[] R;
	delete[] G;
	delete[] B;

	delete[] HistR;
	delete[] HistG;
	delete[] HistB;

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

void DisplayHistogram(int * Hist, const char* fileName)
{
	int nMax = 0;

	for (int n = 0; n < 256; n++) {
		if (nMax < Hist[n]) nMax = Hist[n];
	}

	double dNormalizeFactor = 255.0 / nMax;
	unsigned char* HistDisp = new unsigned char[256 * 256];
	memset(HistDisp, 0, sizeof(unsigned char) * 256 * 256);

	for (int w = 0; w < 256; w++) {
		int nNormalizeValue = (int)Hist[w] * dNormalizeFactor;
		for (int h = 255; h > 255 - nNormalizeValue; h--) {
			HistDisp[h * 256 + w] = 255;
		}
	}

	ofstream writefile;
	writefile.open(fileName, ios::binary | ios::out);
	writefile.write((char *)HistDisp, 256 * 256);
	writefile.close();

	delete[] HistDisp;
}

