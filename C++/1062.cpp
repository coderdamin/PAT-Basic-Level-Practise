//问题描述：
//	一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
//	现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
//输入格式：
//	输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
//输出格式：
//	在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。
//输入样例：
//	7/18 13/20 12
//输出样例：
//	5/12 7/12

#include <iostream>
#include <stdio.h>
using namespace std;

#define SWAP_VALUE(val1, val2) { \
	val1 ^= val2;				\
	val1 ^= val1;				\
	val1 ^= val2;				\
}

class Fraction{
public:
	Fraction() {};
	~Fraction() {};
public:
	bool operator<(Fraction& number) {
		if (nDenominator == number.nDenominator) {
			return (nNumerator < number.nNumerator);
		}
		return (nNumerator * number.nDenominator < nDenominator * number.nNumerator);
	}
	void Swap(Fraction& number) {
		SWAP_VALUE(nNumerator, number.nNumerator)
			SWAP_VALUE(nDenominator, number.nDenominator)
	}
public:
	int nNumerator;
	int nDenominator;
};

int GetGCD(int nNumber1, int nNumber2);
int main() {
	Fraction number1, number2;
	int nDenominator;
	scanf_s("%d/%d %d/%d %d", &number1.nNumerator, &number1.nDenominator, &number2.nNumerator, &number2.nDenominator, &nDenominator);
	if (number2 < number1) {
		number1.Swap(number2);
	}
	bool bFirst = true;
	int nCD = (number1.nDenominator * number2.nDenominator) / nDenominator;
	for (int i = number1.nNumerator * number2.nDenominator / nCD; i <= (number2.nNumerator * number1.nDenominator) / nCD; ++i) {
		if (GetGCD(i, nDenominator) == 1) {
			if (bFirst) {
				bFirst = false;
			}
			else{
				cout << ' ';
			}
			cout << i << '/' << nDenominator;
		}
	}
	return 0;
}

int GetGCD(int nNumber1, int nNumber2) {
	if (nNumber1 % nNumber2 == 0) {
		return nNumber2;
	}
	int nTmp = nNumber1 % nNumber2;
	while (nTmp != 0) {
		nNumber1 = nNumber2 % nTmp;
		nNumber2 = nTmp;
		nTmp = nNumber1;
	}
	return nNumber2;
}
