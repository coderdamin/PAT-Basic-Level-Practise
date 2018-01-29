//问题描述：
//	给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
//	A1 = 能被5整除的数字中所有偶数的和；
//	A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1 - n2 + n3 - n4...；
//	A3 = 被5除后余2的数字的个数；
//	A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
//	A5 = 被5除后余4的数字中最大数字。
//输入格式：
//	每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
//输出格式：
//	对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
//	若其中某一类数字不存在，则在相应位置输出“N”。
//输入样例1：
//	13 1 2 3 4 5 6 7 8 9 10 20 16 18
//输出样例1：
//	30 11 2 9.7 9
//
//输入样例2：
//	8 1 2 4 5 6 7 9 16
//输出样例2：
//	N 11 2 N 9

#include <iostream>
#include <iomanip>
using namespace std;

//#define FORMAT_OUT(val1, val2) \
//	(val1 == val2) ? 'N' : val1

int main() {
	int nCount = 0;
	cin >> nCount;
	int nNumber = 0;
	//int* anNumber = new int[nCount];
	int nMod = 0;
	int nA1 = 0;
	int nA2 = -1000000;
	int nA2Signal = 1;
	int nA3 = 0;
	int nA4 = 0;
	int nA4Count = 0;
	int nA5 = 0;
	for (int i = 0; i < nCount; ++i) {
		//cin >> anNumber[i];
		cin >> nNumber;
		nMod = nNumber % 5;
		switch (nMod) {
		case 0:
			if (!(nNumber & 0x00000001)) {
				nA1 += nNumber;
			}
			break;
		case 1:
			if (nA2 == -1000000) {
				nA2 = 0;
			}
			nA2 += (nA2Signal * nNumber);
			nA2Signal *= -1;
			break;
		case 2:
			nA3 += 1;
			break;
		case 3:
			nA4 += nNumber;
			nA4Count += 1;
			break;
		case 4:
			if (nNumber > nA5) {
				nA5 = nNumber;
			}
			break;
		}
	}
	cout.setf(ios::fixed);
	//cout << nA1 << ' ' << nA2 << ' ' << nA3 << ' ' << setprecision(1) << nA4 / (float)nA4Count << setprecision(0) << ' ' << nA5 << endl;
	((nA1 == 0) ? cout << 'N' : cout << nA1) << ' ';
	((nA2 == -1000000) ? cout << 'N' : cout << nA2) << ' ';
	((nA3 == 0) ? cout << 'N' : cout << nA3) << ' ';
	((nA4Count == 0) ? cout << 'N' : cout << setprecision(1) << (float)(nA4 / (float)nA4Count) << setprecision(0)) << ' ';
	((nA5 == 0) ? cout << 'N' : cout << nA5) << endl;

	return 0;
}
