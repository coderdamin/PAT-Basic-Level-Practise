//问题描述：
//	给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。
//	一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
//	例如，我们从6767开始，将得到
//	7766 - 6677 = 1089
//	9810 - 0189 = 9621
//	9621 - 1269 = 8352
//	8532 - 2358 = 6174
//	7641 - 1467 = 6174
//	... ...
//	现给定任意4位正整数，请编写程序演示到达黑洞的过程。
//输入格式：
//	输入给出一个(0, 10000)区间内的正整数N。
//输出格式：
//	如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
//输入样例1：
//6767
//输出样例1：
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//
//输入样例2：
//2222
//输出样例2：
//2222 - 2222 = 0000

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void NumberToArray(int nNumber, char* acBuf);
int ArrayToNumber(char* acBuf, bool bDaoxu);
int main() {
	int nNumber = 0;
	char acNumber[5] = { 0 };
	cin >> nNumber;
	int nNumber2 = 0;
	while (true) {
		NumberToArray(nNumber, acNumber);
		//补0
		for (int i = strlen(acNumber); i < 4; ++i) {
			acNumber[i] = '0';
		}
		acNumber[4] = '\0';
		sort(acNumber, &acNumber[4]);
		nNumber = ArrayToNumber(acNumber, true);
		nNumber2 = ArrayToNumber(acNumber, false);
		cout << setfill('0') << setw(4) << nNumber << " - " << setfill('0') << setw(4) << nNumber2 << " = ";
		nNumber -= nNumber2;
		if (nNumber != 6174
			&& nNumber != 0) {
			cout << setfill('0') << setw(4) << nNumber << '\n';
		}
		else{
			cout << setfill('0') << setw(4) << nNumber;
			break;
		}
	}
	cout << endl;
	return 0;
}

// 倒序
void NumberToArray(int nNumber, char* acBuf) {
	while (nNumber != 0) {
		*(acBuf++) = '0' + (nNumber % 10);
		nNumber /= 10;
	}
}

int ArrayToNumber(char* acBuf, bool bDaoxu) {
	int nNumber = 0;
	int nIndex = (bDaoxu) ? strlen(acBuf) - 1 : 0;
	while (nIndex >= 0 && acBuf[nIndex] != '\0') {
		//while (nIndex >= 0 && nIndex < strlen(acBuf)) {
		nNumber = nNumber * 10 + (acBuf[nIndex] - '0');
		nIndex += (bDaoxu) ? -1 : 1;
	}

	return nNumber;
}
