#include <iostream>
#include <fstream>
using namespace std;


int main() {

	ifstream readFile;
	readFile.open("C:\\Users\\kryj9\\Desktop\\test520x678.raw", ios::binary | ios::in);

	int nHeight = 678;
	int nWidth = 520;

	unsigned char* inputImage = new unsigned char[nHeight * nWidth * 3];
	readFile.read((char *)inputImage, sizeof(unsigned char) * nHeight * nWidth * 3);
	readFile.close();

	unsigned char* R = new unsigned char[nHeight * nWidth];
	unsigned char* G = new unsigned char[nHeight * nWidth];
	unsigned char* B = new unsigned char[nHeight * nWidth];
	int idx = 0;
	for (int i = 0; i < nHeight; i++){
		for (int j = 0; j < nWidth; j++){
			R[idx] = inputImage[(i*nWidth + j) * 3];
			G[idx] = inputImage[(i*nWidth + j) * 3 + 1];
			B[idx] = inputImage[(i*nWidth + j) * 3 + 2];
			++idx;
		}
	}

	double centerR = 227.486, centerG = 191.125, centerB = 169.29;
	unsigned char* faceImage = new unsigned char[nHeight * nWidth * 3];
	int* checkArray = new int[nHeight * nWidth];
	for (int i = 0; i < nHeight * nWidth; i++) {
		checkArray[i] = -1;
	}

	unsigned char* faceR = new unsigned char[nHeight * nWidth];
	unsigned char* faceG = new unsigned char[nHeight * nWidth];
	unsigned char* faceB = new unsigned char[nHeight * nWidth];

	idx = 0;
	for (int i = 0; i < nHeight; i++){
		for (int j = 0; j < nWidth; j++){
			if ((((R[idx] - centerR) * (R[idx] - centerR)) + 
				((G[idx] - centerG) * (G[idx] - centerG)) + 
				((B[idx] - centerB) * (B[idx] - centerB))) > (0.1878 * 255 * 0.1878 * 255)) {
				faceR[idx] = 0;
				faceG[idx] = 0;
				faceB[idx] = 0;
			}
			else {
				faceR[idx] = R[idx];
				faceG[idx] = G[idx];
				faceB[idx] = B[idx];
				checkArray[idx] = 0;
			}
			++idx;
		}
	}

	idx = 0;
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			faceImage[(i * nWidth + j) * 3] = faceR[idx];
			faceImage[(i * nWidth + j) * 3 + 1] = faceG[idx];
			faceImage[(i * nWidth + j) * 3 + 2] = faceB[idx];
			++idx;
		}
	}

	ofstream writeFile;
	writeFile.open("C:\\Users\\kryj9\\Desktop\\faceImage.raw", ios::binary | ios::out);
	writeFile.write((char *)faceImage, sizeof(unsigned char) * nHeight * nWidth * 3);
	writeFile.close();


	delete[] inputImage;
	delete[] faceImage;

	delete[] R;
	delete[] G;
	delete[] B;

	delete[] faceR;
	delete[] faceG;
	delete[] faceB;

	return 0;
}

