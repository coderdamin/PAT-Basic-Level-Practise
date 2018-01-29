//问题描述：
//	令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。
//输入格式：
//	输入在一行中给出M和N，其间以空格分隔。
//输出格式：
//	输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
//输入样例：
//	5 27
//输出样例：
//	11 13 17 19 23 29 31 37 41 43
//	47 53 59 61 67 71 73 79 83 89
//	97 101 103

#include <iostream>
#include <set>
using namespace std;

int main() {
	int nM = 0;
	int nN = 0;
	cin >> nM >> nN;
	set<int> setPrimeNumber;
	int index = 1;
	while (true) {
	}

	return 0;
}

// nPrimeNumber >= 5
//int GetNextPrimeNumber(int nPrimeNumber) {
//	int nNext = nPrimeNumber;
//	while (true) {
//		nNext = ((nNext % 6) == 1) ? nNext + 4 : nNext + 2;
//		for (int i = 5; i <= sqrt(nNext); i += 6) {
//			if (nNext%i == 0 || nNext % (i + 2) == 0) {
//				goto CONTINUE_TAG;
//			}
//		}
//		break;
//	CONTINUE_TAG:
//	}
//	return nNext;
//}

