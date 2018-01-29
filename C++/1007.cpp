//问题描述：
//	让我们定义 dn 为：d(n) = p(n + 1) - p(n)，其中 p(i) 是第i个素数。显然有 d1 = 1 且对于n>1有 d(n) 是偶数。
//	“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。现给定任意正整数N(< 105)，请计算不超过N的满足猜想的素数对的个数。
//输入格式：
//	每个测试输入包含1个测试用例，给出正整数N。
//输出格式：
//	每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
//
//输入样例：
//20
//输出样例：
//4

#include <iostream>
#include <math.h>
using namespace std;

int GetNextPrimeNumber(int nPrimeNumber);
int main() {
	int nMaxNumber = 0;
	cin >> nMaxNumber;
	int nRightCount = 0;
	int nPrimeNumber = 3;
	int nNext = GetNextPrimeNumber(nPrimeNumber);
	while (nNext < nMaxNumber) {
		if (nNext - nPrimeNumber == 2) {
			++nRightCount;
		}
		nPrimeNumber = nNext;
		nNext = GetNextPrimeNumber(nPrimeNumber);
	}
	cout << nRightCount << endl;
	return 0;
}

// nPrimeNumber >= 5
int GetNextPrimeNumber(int nPrimeNumber) {
	int nNext = nPrimeNumber;
	while (true) {
		nNext = ((nNext % 6) == 1) ? nNext + 4 : nNext + 2;
		for (int i = 5; i <= sqrt(nNext); i += 6){
			if (nNext%i == 0 || nNext % (i + 2) == 0){
				goto CONTINUE_TAG;
			}
		}
		break;
	CONTINUE_TAG:
	}
	return nNext;
}
