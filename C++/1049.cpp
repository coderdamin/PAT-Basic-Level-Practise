//问题描述：
//	给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列{ 0.1, 0.2, 0.3, 0.4 }，我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。
//	给定正整数数列，求出全部片段包含的所有的数之和。如本例中10个片段总和是0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。
//
//输入格式：
//	输入第一行给出一个不超过105的正整数N，表示数列中数的个数，第二行给出N个不超过1.0的正数，是数列中的数，其间以空格分隔。
//输出格式：
//	在一行中输出该序列所有片段包含的数之和，精确到小数点后2位。
//输入样例：
//4
//0.1 0.2 0.3 0.4
//输出样例：
//5.00

#include <iostream>
#include <iomanip>
using namespace std;

float Solution_1(float* pNumberList, int nLen);
float Solution_2(float* pNumberList, int nLen);
int main() {
	int nCount = 0;
	cin >> nCount;
	float* pNumberList = new float[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> pNumberList[i];
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << Solution_1(pNumberList, nCount) << endl;
	return 0;
}

// 往前递归方法
//5.00 = 
//0.1 +
//0.1 + 0.2 +
//0.1 + 0.2 + 0.3 +
//0.1 + 0.2 + 0.3 + 0.4 +
//	  0.2 +
//	  0.2 + 0.3 +
//	  0.2 + 0.3 + 0.4 +
//			0.3 +
//			0.3 + 0.4 +
//				  0.4
float Solution_1(float* pNumberList, int nLen) {
	float nSum = 0.0f;
	float nLastBlockSum = 0.0f;
	for (int i = 1; i <= nLen; ++i) {
		nLastBlockSum += i * pNumberList[nLen - i];
		nSum += nLastBlockSum;
	}
	return nSum;
}

float Solution_2(float* pNumberList, int nLen) {
	// 0.1 * nLen + 0.2 * 2 * (nLen - 1) + 0.3 * (2 * (nLen - 2) + (nLen - 3)) + 0.4 * (nLen - 4)
	return 0.0f;
}