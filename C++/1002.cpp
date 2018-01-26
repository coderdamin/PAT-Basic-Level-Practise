//题目描述：
//	读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//输入格式：
//	每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。
//输出格式：
//	在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
//输入样例：
//	1234567890987654321123456789
//输出样例：
//	yi san wu

#include <iostream>
#include <math.h>

using namespace std;

void Solution_1();
void Solution_2();
const char* aPinyin[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int main() {
	//Solution_1();
	Solution_2();
	return 0;
}

//unsigned int GetLowestOrder(nNumber);
void GetLowestOrder(unsigned int nNumber, char cPrefix);
void Solution_1() {
	char* aInput = new char[101];
	cin >> aInput;
	unsigned int uSum = 0;
	while (*aInput != '\0') {
		uSum += (*aInput - '0');
		aInput += 1;
	}
	if (uSum != 0) {
		GetLowestOrder(uSum, ' ');
	}
	else{
		cout << aPinyin[0];
	}
	cout << endl;
	delete[] aInput;
	return;
}

void GetLowestOrder(unsigned int nNumber, char cPrefix) {
	if (nNumber / 10 > 0) {
		GetLowestOrder(nNumber / 10, ' ');
		cout << cPrefix << aPinyin[nNumber % 10];
	}
	else{
		cout << aPinyin[nNumber % 10];
	}
}

void Solution_2() {
	char* aInput = new char[101];
	cin >> aInput;
	unsigned int uSum = 0;
	while (*aInput != '\0') {
		uSum += (*aInput - '0');
		aInput += 1;
	}
	if (uSum != 0) {
		unsigned int uLen = 0;
		unsigned int uNumberTmp = uSum;
		while (uNumberTmp != 0) {
			uNumberTmp /= 10;
			uLen += 1;
		}
		// 或者参考stdlib的itoa实现
		cout << aPinyin[uSum / ((int)pow(10, uLen - 1))];
		uSum = uSum % ((int)pow(10, uLen - 1));
		for (int i = 1; i < uLen; ++i){
			cout << ' ' << aPinyin[uSum / ((int)pow(10, uLen - i - 1))];
			uSum = uSum % ((int)pow(10, uLen - i - 1));
		}
	}
	else{
		cout << aPinyin[0];
	}
	cout << endl;
	delete[] aInput;
	return;
}