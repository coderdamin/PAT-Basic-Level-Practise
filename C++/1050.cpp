//����������
//	����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣
//	Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m >= n����m - nȡ���п���ֵ�е���Сֵ��
//�����ʽ��
//	�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����104�����������Կո�ָ���
//�����ʽ��
//	�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�
//����������
//	12
//	37 76 20 98 76 42 53 95 60 81 58 93
//���������
//	98 95 93
//	42 37 81
//	53 20 76
//	58 60 76

#include <iostream>
#include <algonrithm>
#include <math.h>
using namespace std;

void Solution_1(int* anNumber, int nCount);
void Solution_2(int* anNumber, int nCount);
void Solution_3(int* anNumber, int nCount);
bool NumberSortFunc(int number1, int number2);
void CalcRowAndColumn(int nCount, int& nRow, int& nColumn);
int main() {
	int nCount = 0;
	cin >> nCount;
	int* anNumber = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> anNumber[i];
	}
	sort(anNumber, &anNumber[nCount]);

	return 0;
}

bool NumberSortFunc(int number1, int number2) {
	return number1 > number2;
}

void CalcRowAndColumn(int nCount, int& nRow, int& nColumn) {
	nRow = sqrt(nCount);
	if (nRow *  nRow < nCount) {
		nRow += 1;
	}
	for (int i = nRow; i <= nCount; ++i) {
		if (nCount % nRow == 0) {
			nColumn = nCount / nRow;
			break;
		}
	}
}

void Solution_1(int* anNumber, int nCount) {
	// �������
	int nRow = 0;
	int nColumn = 0;
	CalcRowAndColumn(nCount, &nRow, &nColumn);
	int nRowBase = 0;
	
	// ��һ��
	for (int i = 0; i < nColumn; ++i) {
		cout << anNumber[i];
	}
	// �м� nRow - 2 ��
	for (int i = 1; i < nColumn - 2; ++i) {
		// ǰi��
		for (int j = 0; j < i; ++j) {
			//cout << 2 * (nRow + nColumn) - 3 - i;
		}
		for () {

		}
		// ��i��
		for () {

		}
	}
	// ���һ��
	nRowBase = nColumn + nRow - 2;
	for (int i = nColumn; i >= 0; --i) {
		cout << anNumber[nRowBase + i];
	}
}

void Solution_2(int* anNumber, int nCount) {
	// ��Ȧ���뵽һά����
	int nRow = 0;
	int nColumn = 0;
	CalcRowAndColumn(nCount, &nRow, &nColumn);
	int nLoop = (nColumn + 1) >> 1;
	int* anOutbuf = new int[nCount];
	int nRowBase = 0;
	for (int i = 0; i < nLoop; ++i) {
		for (int j = 0; j < nColumn - 2 * i; ++j) {
			anOutbuf[nRowBase + j] = anNumber[index++];
		}
	}
	delete[] anOutbuf;
}

void Solution_3(int* anNumber, int nCount) {
	// ��ά����
}