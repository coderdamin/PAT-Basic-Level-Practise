//问题描述：
//	对于计算机而言，颜色不过是像素点对应的一个24位的数值。现给定一幅分辨率为MxN的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，
//	并且该点的颜色与其周围8个相邻像素的颜色差充分大。
//输入格式：
//	输入第一行给出三个正整数，分别是M和N（ <= 1000），即图像的分辨率；以及TOL，是所求像素点与相邻点的颜色差阈值，色差超过TOL的点才被考虑。
//	随后N行，每行给出M个像素的颜色值，范围在[0, 224)内。所有同行数字间用空格或TAB分开。
//输出格式：
//	在一行中按照“(x, y): color”的格式输出所求像素点的位置以及颜色值，其中位置x和y分别是该像素在图像矩阵中的列、行编号（从1开始编号）。
//	如果这样的点不唯一，则输出“Not Unique”；如果这样的点不存在，则输出“Not Exist”。
//输入样例1：
//	8 6 200
//	0 	 0 	  0 	   0	    0 	     0 	      0        0
//	65280 	 65280    65280    16711479 65280    65280    65280    65280
//	16711479 65280    65280    65280    16711680 65280    65280    65280
//	65280 	 65280    65280    65280    65280    65280    165280   165280
//	65280 	 65280 	  16777015 65280    65280    165280   65480    165280
//	16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
//输出样例1：
//	(5, 3): 16711680
//
//输入样例2：
//	4 5 2
//	0 0 0 0
//	0 0 3 0
//	0 0 0 0
//	0 5 0 0
//	0 0 0 0
//输出样例2：
//	Not Unique
//
//输入样例3：
//	3 3 5
//	1 2 3
//	3 4 5
//	5 6 7
//输出样例3：
//	Not Exist

#include <iostream>
using namespace std;

int anColors[1 << 24] = { 0 }; // 栈不够
int main() {
	int nRows = 0, nColumn = 0, nTOL = 0;
	cin >> nColumn >> nRows >> nTOL;
	int** anImage = new int*[nRows];
	for (int i = 0; i < nRows; ++i) {
		anImage[i] = new int[nColumn];
		for (int j = 0; j < nColumn; ++j) {
			cin >> anImage[i][j];
			anColors[anImage[i][j]] += 1;
		}
	}

	bool bRight = false;
	const int anOffset[8][2] = {
		{ -1, -1 }, { 0, -1 }, { 1, -1 }
		, { -1, 0 }, { 1, 0 }
		, { -1, 1 }, { 0, 1 }, { 1, 1 }
	};
	int nTagX = 0, nTagY = 0;
	int nTOLCount = 0;
	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nColumn; ++j) {
			if (anColors[anImage[i][j]] > 1){
				continue;
			}
			bRight = false;
			for (int k = 0; k < 8; ++k) {
				if (((j + anOffset[k][0] >= 0) && (j + anOffset[k][0] < nColumn))
					&& ((i + anOffset[k][1] >= 0) && (i + anOffset[k][1] < nRows))){
					if ((anImage[i][j] - anImage[i + anOffset[k][1]][j + anOffset[k][0]] <= nTOL)
						&& (anImage[i + anOffset[k][1]][j + anOffset[k][0]] - anImage[i][j] <= nTOL)){
						bRight = true;
						break;
					}
				}
			}
			if (!bRight) {
				if (nTOLCount == 0){
					nTagX = j; nTagY = i;
					nTOLCount = 1;
				}
				else{
					nTOLCount = 2;
					break;
				}
			}
		}
		if (nTOLCount > 1) {
			break;
		}
	}
	if (nTOLCount == 0) {
		cout << "Not Exist" << endl;
	}
	else if (nTOLCount == 1) {
		cout << '(' << nTagX + 1 << ", " << nTagY + 1 << "): " << anImage[nTagY][nTagX] << endl;
	}
	else{
		cout << "Not Unique" << endl;
	}

	for (int i = 0; i < nRows; ++i) {
		delete[] anImage[i];
	}
	delete[] anImage;

	return 0;
}
