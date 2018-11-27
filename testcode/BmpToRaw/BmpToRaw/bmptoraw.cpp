#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void BmpToRaw(const char * inputFilePath, const char* outputFilePath);

int main() {

	BmpToRaw("C:\\Users\\kryj9\\Desktop\\facecccccccccc.bmp", "C:\\Users\\kryj9\\Desktop\\facecccccccccc.raw");
	return 0;
}

void BmpToRaw(const char * inputFilePath, const char* outputFilePath) {

	ifstream readFile;
	readFile.open(inputFilePath, ios::binary | ios::in);
	unsigned char c;
	for (int i = 0; i < 18; i++) {
		//BITMAPFILEHEADER = 14 + biSize = 4 => 1
		readFile.read((char*)&c, 1);
	}

	int nWidth = 0;
	for (int i = 0; i < 4; i++) {	//biWidth
		readFile.read((char*)&c, 1);
		nWidth += c * pow(256, i);
	}
	int nHeight = 0;
	for (int i = 0; i < 4; i++) {	//biHeight	
		readFile.read((char*)&c, 1);
		nHeight += c * pow(256, i);
	}

	for (int i = 0; i < 2; i++) {	//biPlanes = 1
		readFile.read((char*)&c, 1);
	}

	int biBitCount = 0;
	for (int i = 0; i < 2; i++) {	//biBitCount
		readFile.read((char*)&c, 1);
		biBitCount += c * pow(256, i);
	}

	for (int i = 0; i < 24; i++) {
		//biCompression + biSizeImage + biXPelsPerMeter
		// + biYPelsPerMeter + biClrUsed + biClrImportant
		readFile.read((char*)&c, 1);
	}
	if (24 == biBitCount) {		//R, G, B
		unsigned char* R = new unsigned char[nWidth * nHeight];
		unsigned char* G = new unsigned char[nWidth * nHeight];
		unsigned char* B = new unsigned char[nWidth * nHeight];

		for (int i = 0; i < nWidth * nHeight; i++) {
			readFile.read((char*)&c, 1);
			B[i] = c;
			readFile.read((char*)&c, 1);
			G[i] = c;
			readFile.read((char*)&c, 1);
			R[i] = c;
		}

		unsigned char* saveImg = new unsigned char[nWidth * nHeight * 3];
		int idx = 0;
		for (int i = nHeight - 1; i >= 0; i--) {
			for (int j = 0; j < nWidth; j++) {
				saveImg[(i * nWidth + j) * 3] = R[idx];
				saveImg[(i * nWidth + j) * 3 + 1] = G[idx];
				saveImg[(i * nWidth + j) * 3 + 2] = B[idx];
				++idx;
			}
		}

		string str(outputFilePath);
		string pathString = str.substr(0, str.size() - 4);
		pathString += to_string(nWidth);
		pathString += "x";
		pathString += to_string(nHeight);
		pathString += ".raw";

		ofstream writeFile;
		writeFile.open(pathString.c_str(), ios::binary | ios::out);
		writeFile.write((char *)saveImg, nHeight * nWidth * 3);
		writeFile.close();
	}

	readFile.close();
}