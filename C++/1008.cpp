//����������
//	һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M >= 0����λ�ã�����A�е������ɣ�A0 A1����AN - 1��
//	�任Ϊ��AN - M ���� AN - 1 A0 A1����AN - M - 1�������M����ѭ��������ǰ���M��λ�ã��������Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����
//�����ʽ��
//	ÿ���������һ��������������1������N(1 <= N <= 100)��M��M >= 0������2������N��������֮���ÿո�ָ���
//�����ʽ��
//	��һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�
//����������
//	6 2
//	1 2 3 4 5 6
//���������
//	5 6 1 2 3 4

#include <iostream>
using namespace std;

#define SWAP(val1, val2) \
	val1 ^= val2;	\
	val2 ^= val1;	\
	val1 ^= val2;

void Solution_1();
void Solution_2();
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	int nArrayLen = 0;
	int nShift = 0;
	cin >> nArrayLen >> nShift;
	int* anNumber = new int[nArrayLen];
	for (int i = 0; i < nArrayLen; ++i){
		cin >> anNumber[i];
	}
	for (int i = 0; i < ((nArrayLen - nShift) >> 1); ++i) {
		SWAP(anNumber[i], anNumber[nArrayLen - nShift - 1 - i]);
	}
	for (int i = 0; i < (nShift >> 1); ++i) {
		SWAP(anNumber[nArrayLen - nShift + i], anNumber[nArrayLen - 1 - i]);
	}
	for (int i = 0; i < (nArrayLen >> 1); ++i) {
		SWAP(anNumber[i], anNumber[nArrayLen - 1 - i]);
	}
	cout << anNumber[0];
	for (int i = 1; i < nArrayLen; ++i) {
		cout << ' ' << anNumber[i];
	}
	delete[] anNumber;
}

void Solution_2() {
	// ǿ��������״̬Ų
}
