//问题描述：
//	给定一个 k + 1 位的正整数 N，写成 ak...a1a0 的形式，其中对所有 i 有 0 <= ai < 10 且 ak > 0。N 被称为一个回文数，当且仅当对所有 i 有 ai = ak - i。零也被定义为一个回文数。
//	非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，
//	就称这个数为延迟的回文数。（定义翻译自 https ://en.wikipedia.org/wiki/Palindromic_number）
//	给定任意一个正整数，本题要求你找到其变出的那个回文数。
//输入格式：
//	输入在一行中给出一个不超过1000位的正整数。
//输出格式：
//	对给定的整数，一行一行输出其变出回文数的过程。每行格式如下
//	A + B = C
//	其中A是原始的数字，B是A的逆转数，C是它们的和。A从输入的整数开始。重复操作直到C在10步以内变成回文数，这时在一行中输出“C is a palindromic number.”；
//	或者如果10步都没能得到回文数，最后就在一行中输出“Not found in 10 iterations.”。
//输入样例 1：
//	97152
//输出样例 1：
//	97152 + 25179 = 122331
//	122331 + 133221 = 255552
//	255552 is a palindromic number.
//
//输入样例 2：
//	196
//输出样例 2：
//	196 + 691 = 887
//	887 + 788 = 1675
//	1675 + 5761 = 7436
//	7436 + 6347 = 13783
//	13783 + 38731 = 52514
//	52514 + 41525 = 94039
//	94039 + 93049 = 187088
//	187088 + 880781 = 1067869
//	1067869 + 9687601 = 10755470
//	10755470 + 07455701 = 18211171
//	Not found in 10 iterations.

#include <iostream>
#include <stdio.h>
using namespace std;

#define SWAP_VALUE(val1, val2) { \
	val1 ^= val2;				\
	val2 ^= val1;				\
	val1 ^= val2;				\
}

void ReverseCout(char* pNumber);
void ReverseString(char* pNumber);
bool CheckKaibun(char* pNumber);
bool ReverseAdd(char* pNumber, char* pOutbuf);
int main() {
	char acNumber[2][101] = { 0 };
	cin >> acNumber[0];
	int nLeftTimes = 10;
	int nAddend = 0, nResult = 1;
	bool bFounded = true;
	while (!CheckKaibun(acNumber[nAddend])) {
		if (nLeftTimes <= 0) {
			bFounded = false;
			break;
		}
		ReverseAdd(acNumber[nAddend], acNumber[nResult]);
		cout << acNumber[nAddend] << " + ";
		ReverseCout(acNumber[nAddend]);
		cout << " = " << acNumber[nResult] << '\n';
		SWAP_VALUE(nAddend, nResult)
			nLeftTimes -= 1;
	}
	if (bFounded) {
		cout << acNumber[nAddend] << " is a palindromic number." << endl;
	}
	else{
		cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}

void ReverseCout(char* pNumber) {
	if (pNumber == nullptr) {
		return;
	}
	int nLen = strlen(pNumber);
	for (int i = nLen - 1; i >= 0; --i){
		cout << pNumber[i];
	}
}

bool CheckKaibun(char* pNumber) {
	if (pNumber == nullptr) {
		return false;
	}
	int nLen = strlen(pNumber);
	bool bRight = true;
	for (int i = 0; i < (nLen >> 1); ++i){
		if (pNumber[i] != pNumber[nLen - 1 - i]) {
			bRight = false;
			break;
		}
	}
	return bRight;
}

bool ReverseAdd(char* pNumber, char* pOutbuf) {
	if (pNumber == nullptr || pOutbuf == nullptr) {
		return false;
	}
	int nLen = strlen(pNumber);
	int nCarry = 0;
	for (int i = 0; i < nLen; ++i){
		pOutbuf[i] = pNumber[i] + pNumber[nLen - 1 - i] - '0' + nCarry;
		if (pOutbuf[i] > '9') {
			pOutbuf[i] -= 10;
			nCarry = 1;
		}
		else{
			nCarry = 0;
		}
	}
	if (nCarry > 0) {
		pOutbuf[nLen] = '0' + nCarry;
	}
	ReverseString(pOutbuf);
}

void ReverseString(char* pNumber) {
	if (pNumber == nullptr) {
		return;
	}
	int nLen = strlen(pNumber);
	for (int i = 0; i < (nLen >> 1); ++i){
		SWAP_VALUE(pNumber[i], pNumber[nLen - 1 - i])
	}
}
