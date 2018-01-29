//����������
//	�����Ƕ��� dn Ϊ��d(n) = p(n + 1) - p(n)������ p(i) �ǵ�i����������Ȼ�� d1 = 1 �Ҷ���n>1�� d(n) ��ż����
//	�������Բ��롱��Ϊ�����������������Ҳ�Ϊ2�����������ָ�������������N(< 105)������㲻����N���������������Եĸ�����
//�����ʽ��
//	ÿ�������������1����������������������N��
//�����ʽ��
//	ÿ���������������ռһ�У�������N���������������Եĸ�����
//
//����������
//20
//���������
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
