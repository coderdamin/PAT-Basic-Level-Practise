//����������
//	����Ҫ���д���򣬼���2���������ĺ͡�������̡�
//�����ʽ��
//	������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��
//�����ʽ��
//	�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ��k a/b����
//	����k���������֣�a/b�����������֣���Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������
//��������1��
//	2/3 -4/2
//�������1��
//	2/3 + (-2) = (-1 1/3)
//	2/3 - (-2) = 2 2/3
//	2/3 * (-2) = (-1 1/3)
//	2/3 / (-2) = (-1/3)
//
//��������2��
//	5/3 0/6
//�������2��
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
