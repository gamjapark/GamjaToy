#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream readFile;
	readFile.open("C:\\Users\\kryj9\\Documents\\카카오톡 받은 파일\\이승기\\이승기.raw", ios::binary | ios::in);

	int nHeight = 81;
	int nWidth = 62;

	unsigned char* inputImage = new unsigned char[nHeight * nWidth * 3];
	for (int i = 0; i < nHeight; i++) {
		readFile.read((char *)inputImage, sizeof(unsigned char) * nHeight * nWidth * 3);
	}
	readFile.close();

	float* R = new float[nHeight * nWidth];
	float* G = new float[nHeight * nWidth];
	float* B = new float[nHeight * nWidth];
	int idx = 0;
	for (int i = 0; i < nHeight; i++)
	{
		for (int j = 0; j < nWidth; j++)
		{
			R[idx] = (float)inputImage[(i*nWidth + j) * 3];
			G[idx] = (float)inputImage[(i*nWidth + j) * 3 + 1];
			B[idx] = (float)inputImage[(i*nWidth + j) * 3 + 2];
			++idx;
		}
	}

	double sumR = 0.0, sumG = 0.0, sumB = 0.0;
	int pixelCount = 0;
	for (int i = 0; i < nHeight * nWidth; i++) {
		if (!(R[i] == 255 && G[i] == 255 && B[i] == 255)) {
			sumR += R[i];
			sumG += G[i];
			sumB += B[i];
			++pixelCount;
		}
	}

	cout << "( R, G, B ) = ( " << sumR / pixelCount << ", " << sumG / pixelCount << ", " << sumB / pixelCount << " )" << endl;

	delete[] inputImage;
	delete[] R;
	delete[] G;
	delete[] B;
	return 0;
}

