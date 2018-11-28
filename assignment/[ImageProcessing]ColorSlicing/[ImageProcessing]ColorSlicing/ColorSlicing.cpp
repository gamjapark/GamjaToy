#include <iostream>
#include <fstream>
using namespace std;

unsigned char* Padding(unsigned char* inputArray, int nHeight, int nWidth);
void SmoothFilter(unsigned char* In_Pad, unsigned char* Out, int* checkArray, int nHeight, int nWidth);

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

	unsigned char* smoothImage = new unsigned char[nHeight * nWidth * 3];

	unsigned char* padR = Padding(faceR, nHeight, nWidth);
	unsigned char* padG = Padding(faceG, nHeight, nWidth);
	unsigned char* padB = Padding(faceB, nHeight, nWidth);

	unsigned char* smoothR = new unsigned char[nHeight * nWidth];
	unsigned char* smoothG = new unsigned char[nHeight * nWidth];
	unsigned char* smoothB = new unsigned char[nHeight * nWidth];

	SmoothFilter(padR, smoothR, checkArray, nHeight, nWidth);
	SmoothFilter(padG, smoothG, checkArray, nHeight, nWidth);
	SmoothFilter(padB, smoothB, checkArray, nHeight, nWidth);


	idx = 0;
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			smoothImage[(i * nWidth + j) * 3] = smoothR[idx];
			smoothImage[(i * nWidth + j) * 3 + 1] = smoothG[idx];
			smoothImage[(i * nWidth + j) * 3 + 2] = smoothB[idx];
			++idx;
		}
	}

	writeFile;
	writeFile.open("C:\\Users\\kryj9\\Desktop\\smoothImage.raw", ios::binary | ios::out);
	writeFile.write((char *)smoothImage, sizeof(unsigned char) * nHeight * nWidth * 3);
	writeFile.close();


	delete[] inputImage;
	delete[] faceImage;
	delete[] smoothImage;

	delete[] R;
	delete[] G;
	delete[] B;

	delete[] faceR;
	delete[] faceG;
	delete[] faceB;

	delete[] padR;
	delete[] padG;
	delete[] padB;

	delete[] smoothR;
	delete[] smoothG;
	delete[] smoothB;

	return 0;
}

unsigned char* Padding(unsigned char* inputArray, int nHeight, int nWidth) {
	int padHeight = nHeight + 2;
	int padWidth = nWidth + 2;
	cout << padHeight << ", " << padWidth << endl;
	unsigned char* pad = new unsigned char[padHeight * padWidth];
	pad[0] = inputArray[0];
	pad[0 * padWidth + (padWidth - 1)] = inputArray[0 * nWidth + nWidth - 1];
	pad[(padHeight - 1) * padWidth + 0] = inputArray[(nHeight - 1) * nWidth + 0];
	pad[(padHeight - 1) * padWidth + (padWidth - 1)] = inputArray[(nHeight - 1) * nWidth + nWidth - 1];

	int idx = 1;
	for (int i = 0; i < nWidth; i++, idx++) {
		pad[0 * padWidth + idx] = inputArray[0 * nWidth + i];
		pad[(padHeight - 1) * padWidth + idx] = inputArray[(nHeight - 1) * nWidth + i];
	}

	idx = 1;
	for (int i = 0; i < nHeight; i++, idx++) {
		pad[idx * padWidth + 0] = inputArray[i * nWidth + 0];
		pad[idx * padWidth + (padWidth - 1)] = inputArray[i * nWidth + (nWidth - 1)];
	}

	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			pad[(i + 1) * padWidth + (j + 1)] = inputArray[i * nWidth + j];
		}
	}
	return pad;
}

void SmoothFilter(unsigned char* In_Pad, unsigned char* Out, int* checkArray, int nHeight, int nWidth) {
	int idx = 0;
	for (int h = 1; h <= nHeight; h++) {
		for (int w = 1; w <= nWidth; w++) {
			if (checkArray[idx] != -1) {	//뽑아온 face공간에만 필터 적용
				double sum = 0.0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						unsigned char value = In_Pad[((h + i) * (nWidth + 2)) + (w + j)];
						if (value == 0) {
							value = In_Pad[h * (nWidth + 2) + w];
						}

						if ((i == -1 || i == 1) && (j == -1 || j == 1)) {
							sum += (double)value * 0.0625;
						}
						else if (i == 0 && j == 0) {
							sum += (double)value * 0.25;
						}
						else {
							sum += (double)value * 0.125;
						}
					}
				}
				if (sum > 255) sum = 255.0;
				Out[(h - 1) *nWidth + (w - 1)] = (unsigned char)sum;
			}
			else {
				Out[(h - 1) *nWidth + (w - 1)] = 0;
			}
			++idx;
		}
	}
}
