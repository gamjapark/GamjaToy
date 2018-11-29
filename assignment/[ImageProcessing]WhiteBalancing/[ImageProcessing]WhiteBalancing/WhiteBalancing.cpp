#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream readFile;
	readFile.open("C:\\Users\\kryj9\\Desktop\\white376x504.raw", ios::binary | ios::in);

	int nHeight = 504;
	int nWidth = 376;

	unsigned char* inputImage = new unsigned char[nHeight * nWidth * 3];
	readFile.read((char *)inputImage, sizeof(unsigned char) * nHeight * nWidth * 3);
	readFile.close();

	float* R = new float[nHeight * nWidth];
	float* G = new float[nHeight * nWidth];
	float* B = new float[nHeight * nWidth];
	int idx = 0;

	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			R[idx] = (float)inputImage[(i*nWidth + j) * 3];
			G[idx] = (float)inputImage[(i*nWidth + j) * 3 + 1];
			B[idx] = (float)inputImage[(i*nWidth + j) * 3 + 2];
			++idx;
		}
	}

	float whiteR = 255.0 / 137.0, whiteG = 255.0 / 88.0, whiteB = 255.0 / 34.0;
	unsigned char* outputIamge = new unsigned char[nHeight * nWidth * 3];

	idx = 0;
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			if (255 >= whiteR * R[idx]) {
				outputIamge[(i*nWidth + j) * 3] = (unsigned char)whiteR * R[idx];
			}
			else {
				outputIamge[(i*nWidth + j) * 3] = 255;
			}
			if (255 >= whiteG * G[idx]) {
				outputIamge[(i*nWidth + j) * 3 + 1] = (unsigned char)whiteG * G[idx];
			}
			else {
				outputIamge[(i*nWidth + j) * 3 + 1] = 255;
			}
			if (255 >= whiteB * B[idx]) {
				outputIamge[(i*nWidth + j) * 3 + 2] = (unsigned char)whiteB * B[idx];
			}
			else {
				outputIamge[(i*nWidth + j) * 3 + 2] = 255;
			}
			++idx;
		}
	}

	ofstream writeFile;
	writeFile.open("C:\\Users\\kryj9\\Desktop\\whiteoutputimage.raw", ios::binary | ios::out);
	writeFile.write((char *)outputIamge, sizeof(unsigned char) * nHeight * nWidth * 3);
	writeFile.close();

	delete[] inputImage;
	delete[] outputIamge;

	delete[] R;
	delete[] G;
	delete[] B;
	return 0;
}