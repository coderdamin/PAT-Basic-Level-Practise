//问题描述：
//	本题要求编写程序，计算2个有理数的和、差、积、商。
//输入格式：
//	输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。
//输出格式：
//	分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，
//	其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。
//输入样例1：
//	2/3 -4/2
//输出样例1：
//	2/3 + (-2) = (-1 1/3)
//	2/3 - (-2) = 2 2/3
//	2/3 * (-2) = (-1 1/3)
//	2/3 / (-2) = (-1/3)
//
//输入样例2：
//	5/3 0/6
//输出样例2：
//	1 2/3 + 0 = 1 2/3
//	1 2/3 - 0 = 1 2/3
//	1 2/3 * 0 = 0
//	1 2/3 / 0 = Inf

#include <iostream>
#include <stdio.h>
using namespace std;

int GetGCD(int number1, int number2);

class Fractions {
public:
	Fractions() {
		m_nNumerator = 0;
		m_nDenominator = 1;
	}
	~Fractions() {}
public:
	Fractions operator+(Fractions& number) {
		Fractions result;
		if (m_nDenominator == number.m_nDenominator) {
			result.m_nDenominator = m_nDenominator;
			result.m_nNumerator = m_nNumerator + number.m_nNumerator;
		}
		else {
			result.m_nDenominator = m_nDenominator * number.m_nDenominator;
			result.m_nNumerator = m_nNumerator * number.m_nDenominator + number.m_nNumerator * m_nDenominator;
		}
		return result;
	}
	Fractions operator-(Fractions& number) {
		Fractions result;
		if (m_nDenominator == number.m_nDenominator) {
			result.m_nDenominator = m_nDenominator;
			result.m_nNumerator = m_nNumerator - number.m_nNumerator;
		}
		else {
			result.m_nDenominator = m_nDenominator * number.m_nDenominator;
			result.m_nNumerator = m_nNumerator * number.m_nDenominator - number.m_nNumerator * m_nDenominator;
		}
		return result;
	}
	Fractions operator*(Fractions& number) {
		Fractions result;
		result.m_nDenominator = m_nDenominator * number.m_nDenominator;
		result.m_nNumerator = m_nNumerator * number.m_nNumerator;
		return result;
	}
	Fractions operator/(Fractions& number) {
		Fractions result;
		int nSingal = (number.m_nNumerator >= 0) ? 1 : -1;
		result.m_nDenominator = m_nDenominator * number.m_nNumerator * nSingal;
		result.m_nNumerator = m_nNumerator * number.m_nDenominator * nSingal;
		return result;
	}
	void FormatCOut() {
		if (m_nDenominator == 0) {
			cout << "Inf";
			return;
		}
		if (m_nNumerator < 0) {
			cout << '(';
		}
		int nGDC = GetGCD(m_nNumerator, m_nDenominator);
		if (nGDC == m_nDenominator) {
			cout << m_nNumerator / m_nDenominator;
		}
		else {
			int nSingal = 1;
			//if (m_nNumerator * nSingal > m_nDenominator) {
			if (m_nNumerator / m_nDenominator != 0) {
				cout << m_nNumerator / m_nDenominator << ' ';
				nSingal = (m_nNumerator >= 0) ? 1 : -1;
			}
			cout << (nSingal * m_nNumerator % m_nDenominator) / nGDC << '/' << m_nDenominator / nGDC;
		}
		if (m_nNumerator < 0) {
			cout << ')';
		}
	}

public:
	int m_nNumerator;
	int m_nDenominator;
};

int main() {
	Fractions number1, number2;
	scanf_s("%d/%d %d/%d", &number1.m_nNumerator, &number1.m_nDenominator
		, &number2.m_nNumerator, &number2.m_nDenominator);
	number1.FormatCOut(); cout << " + "; number2.FormatCOut(); cout << " = "; (number1 + number2).FormatCOut(); cout << '\n';
	number1.FormatCOut(); cout << " - "; number2.FormatCOut(); cout << " = "; (number1 - number2).FormatCOut(); cout << '\n';
	number1.FormatCOut(); cout << " * "; number2.FormatCOut(); cout << " = "; (number1 * number2).FormatCOut(); cout << '\n';
	number1.FormatCOut(); cout << " / "; number2.FormatCOut(); cout << " = "; (number1 / number2).FormatCOut(); cout << endl;
	return 0;
}

int GetGCD(int number1, int number2) {
	int nMod = number1 % number2;
	while (nMod != 0) {
		number1 = number2 % nMod;
		number2 = nMod;
		nMod = number1;
	}
	return (number2 == 0) ? 1 : (number2 < 0) ? -1 * number2 : number2;
}
