//问题描述：
//	本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，
//	并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。
//输入格式：
//	输入第一行给出正整数N（ <= 100）。随后一行给出N个实数，数字间以一个空格分隔。
//输出格式：
//	对每个非法输入，在一行中输出“ERROR : X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，
//	其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。
//输入样例1：
//	7
//	5 -3.2 aaa 9999 2.3.4 7.123 2.35
//输出样例1：
//	ERROR : aaa is not a legal number
//	ERROR : 9999 is not a legal number
//	ERROR : 2.3.4 is not a legal number
//	ERROR : 7.123 is not a legal number
//	The average of 3 numbers is 1.38
//输入样例2：
//	2
//	aaa - 9999
//输出样例2：
//	ERROR : aaa is not a legal number
//	ERROR : -9999 is not a legal number
//	The average of 0 numbers is Undefined

#include <iostream>
#include <iomanip>
using namespace std;

bool StringToFloat(char* pStr, float& fResult);
int main() {
	int nCount = 0;
	cin >> nCount;
	char(*acNumber)[16] = new char[nCount][16];
	for (int i = 0; i < nCount; ++i) {
		cin >> acNumber[i];
	}
	int nValidCount = 0;
	float fSum = 0.0f;
	float fValue = 0.0f;
	bool bValid = true;
	for (int i = 0; i < nCount; ++i) {
		bValid = false;
		if (StringToFloat(acNumber[i], fValue)) {
			if (fValue >= -1000 && fValue <= 1000) {
				nValidCount += 1;
				fSum += fValue;
				bValid = true;
			}
		}
		if (!bValid) {
			cout << "ERROR : " << acNumber[i] << " is not a legal number\n";
		}
	}
	cout << "The average of " << nValidCount;
	cout.setf(ios::fixed);
	if (nValidCount == 0) {
		cout << " number is Undefined" << endl;
	}
	else if (nValidCount == 1) {
		cout << " number is " << setprecision(2) << fSum << endl;
	}
	else {
		cout << " numbers is " << setprecision(2) << fSum / (float)nValidCount << endl;
	}
	delete[] acNumber;
	return 0;
}

bool StringToFloat(char* pStr, float& fResult) {
	fResult = 0.0f;
	if (pStr == nullptr) {
		return false;
	}
	// 去空格
	while (*pStr == ' ') { ++pStr; }
	if (*pStr != '+' && *pStr != '-'
		&& (*pStr < '0' || *pStr > '9')) {
		return false;
	}

	// 符号
	int nSign = (*pStr == '-') ? -1 : 1;
	if (*pStr == '+' || *pStr == '-') {
		pStr += 1;
	}
	// 整数
	bool bInvalid = true;
	int nIntegerPart = 0;
	while (*pStr != '\0') {
		if (*pStr == ' ') {
			pStr += 1;
			continue;
		}
		else if (*pStr == '.') {
			pStr += 1;
			break;
		}
		else if (*pStr >= '0' && *pStr <= '9') {
			bInvalid = false;
			nIntegerPart = nIntegerPart * 10 + (*pStr - '0');
			pStr += 1;
		}
		else {
			bInvalid = true;
			goto END_CONVERT;
		}
	}
	// 小数
	float fFractionalPart = 0.0f;
	float fBase = 0.1f;
	while (*pStr != '\0') {
		if (*pStr == ' ') {
			pStr += 1;
			continue;
		}
		else if (*pStr >= '0' && *pStr <= '9') {
			fFractionalPart = fFractionalPart + (*pStr - '0') * fBase;
			fBase /= 10.0f;
			pStr += 1;
		}
		else {
			bInvalid = true;
			goto END_CONVERT;
		}
	}
	if (fBase < 0.0005) {
		bInvalid = true;
	}
END_CONVERT:
	if (bInvalid) {
		return false;
	}
	else {
		fResult = (nIntegerPart + fFractionalPart)*nSign;
		return true;
	}
}
