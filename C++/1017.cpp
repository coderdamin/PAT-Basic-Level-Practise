//问题描述：
//	本题要求计算A / B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
//输入格式：
//	输入在1行中依次给出A和B，中间以1空格分隔。
//输出格式：
//	在1行中依次输出Q和R，中间以1空格分隔。
//输入样例：
//	123456789050987654321 7
//输出样例：
//	17636684150141093474 3

#include <iostream>
using namespace std;

int main() {
	char acNumber[1001] = { 0 };
	int nDivisor = 0; // nDivisor > 0
	cin >> acNumber >> nDivisor;
	int nPrevNumber = 0;
	int nIndex = 0;
	while (acNumber[nIndex] != '\0') {
		if (nPrevNumber > 0 || (acNumber[nIndex] - '0') >= nDivisor) {
			cout << ((acNumber[nIndex] - '0' + nPrevNumber * 10) / nDivisor);
			nPrevNumber = ((acNumber[nIndex] - '0' + nPrevNumber * 10) % nDivisor);
		}
		else{
			nPrevNumber = (acNumber[nIndex] - '0');
		}
		++nIndex;
	}
	if (nIndex > 1 || (nPrevNumber != acNumber[0] - '0')) {
		cout << ' ' << nPrevNumber << endl;
	}
	else{
		cout << "0 " << nPrevNumber << endl;
	}
	return 0;
}
