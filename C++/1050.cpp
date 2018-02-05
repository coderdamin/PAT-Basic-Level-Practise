//问题描述：
//	本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。
//	要求矩阵的规模为m行n列，满足条件：m*n等于N；m >= n；且m - n取所有可能值中的最小值。
//输入格式：
//	输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
//输出格式：
//	输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
//输入样例：
//	12
//	37 76 20 98 76 42 53 95 60 81 58 93
//输出样例：
//	98 95 93
//	42 37 81
//	53 20 76
//	58 60 76

#include <iostream>
#include <algonrithm>
#include <math.h>
using namespace std;

void Solution_1(int* anNumber, int nCount);
void Solution_2(int* anNumber, int nCount);
void Solution_3(int* anNumber, int nCount);
bool NumberSortFunc(int number1, int number2);
void CalcRowAndColumn(int nCount, int& nRow, int& nColumn);
int main() {
	int nCount = 0;
	cin >> nCount;
	int* anNumber = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> anNumber[i];
	}
	sort(anNumber, &anNumber[nCount]);

	return 0;
}

bool NumberSortFunc(int number1, int number2) {
	return number1 > number2;
}

void CalcRowAndColumn(int nCount, int& nRow, int& nColumn) {
	nRow = sqrt(nCount);
	if (nRow *  nRow < nCount) {
		nRow += 1;
	}
	for (int i = nRow; i <= nCount; ++i) {
		if (nCount % nRow == 0) {
			nColumn = nCount / nRow;
			break;
		}
	}
}

void Solution_1(int* anNumber, int nCount) {
	// 按行输出
}

void Solution_2(int* anNumber, int nCount) {
	// 按圈插入到一维数组
	int nRow = 0;
	int nColumn = 0;
	CalcRowAndColumn(nCount, &nRow, &nColumn);
	int nLoop = (nColumn + 1) >> 1;
	int* anOutbuf = new int[nCount];
	int nRowBase = 0;
	for (int i = 0; i < nLoop; ++i) {
		for (int j = 0; j < nColumn - 2 * i; ++j) {
			anOutbuf[nRowBase + j] = anNumber[index++];
		}
	}
	delete[] anOutbuf;
}

void Solution_3(int* anNumber, int nCount) {
	// 二维数组
}
