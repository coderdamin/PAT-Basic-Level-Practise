//����������
//	һ������һ��д�����������������ʽ��N/M������M��Ϊ0����������ָ���Ӻͷ�ĸû�й�Լ���ķ�����ʾ��ʽ��
//	�ָ�����������ȵ������� N1/M1 �� N2/M2��Ҫ���㰴��С�����˳���г�����֮���ĸΪK����������
//�����ʽ��
//	������һ���а�N/M�ĸ�ʽ���������������������һ����������ĸK������Կո�ָ�����Ŀ��֤����������������������1000��
//�����ʽ��
//	��һ���а�N/M�ĸ�ʽ�г�������������֮���ĸΪK������������������С�����˳�������1���ո�ָ�������β�����ж���ո���Ŀ��֤������1�������
//����������
//	7/18 13/20 12
//���������
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
