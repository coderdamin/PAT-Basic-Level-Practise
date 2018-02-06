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
#include <algorithm>
#include <math.h>
using namespace std;

#define MATH_MIN(val1, val2) (val1) < (val2) ? (val1) : (val2)

void Solution_1(int* anNumber, int nCount);
void Solution_2(int* anNumber, int nCount);
void Solution_3(int* anNumber, int nCount);
bool NumberSortFunc(int nNumber1, int nNumber2);
void CalcRowAndColumn(int nCount, int& nRow, int& nColumn);
int GetValueFromMatrix(int nX, int nY, int nRow, int nColumn);
int main() {
	int nCount = 0;
	cin >> nCount;
	int* anNumber = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> anNumber[i];
	}
	sort(anNumber, &anNumber[nCount], NumberSortFunc);

	Solution_1(anNumber, nCount);
	return 0;
}

bool NumberSortFunc(int nNumber1, int nNumber2) {
	return nNumber1 > nNumber2;
}

void CalcRowAndColumn(int nCount, int& nRow, int& nColumn) {
	nRow = sqrt(nCount);
	if (nRow *  nRow < nCount) {
		nRow += 1;
	}
	for (int i = nRow; i <= nCount; ++i) {
		if (nCount % i == 0) {
			nRow = i;
			nColumn = nCount / i;
			break;
		}
	}
}

int GetValueFromMatrix(int nX, int nY, int nRow, int nColumn) {
	int nLapIndex = MATH_MIN(MATH_MIN(nX, nY), MATH_MIN(nColumn - 1 - nX, nRow - 1 - nY));
	int nDistance = nX + nY - 2 * nLapIndex;
	if ((nY == nLapIndex || nX == nColumn - 1 - nLapIndex) // ����\����
		|| ((nLapIndex * 2 + 1) == nColumn)){
		int nLapBegin = 2 * nLapIndex * (nRow + nColumn - 2 * nLapIndex) + 1;
		return nLapBegin + nDistance;
	}
	else{
		int nNextLapBegin = 2 * (nLapIndex + 1) * (nRow + nColumn - 2 * (nLapIndex + 1)) + 1;
		return nNextLapBegin - nDistance;
	}
}

void Solution_1(int* anNumber, int nCount) {
	// �������
	int nRow = 0;
	int nColumn = 0;
	CalcRowAndColumn(nCount, nRow, nColumn);
	for (int y = 0; y < nRow; ++y) {
		for (int x = 0; x < nColumn; ++x){
			cout << anNumber[GetValueFromMatrix(x, y, nRow, nColumn) - 1];
			//cout << GetValueFromMatrix(x, y, nRow, nColumn);
			if (x < nColumn - 1) {
				cout << ' ';
			}
		}
		if (y < nRow - 1) {
			cout << '\n';
		}
	}
	cout << endl;
}

void Solution_2(int* anNumber, int nCount) {
	// ��Ȧ���뵽һά����
	int nRow = 0;
	int nColumn = 0;
	CalcRowAndColumn(nCount, nRow, nColumn);
	int nLoop = (nColumn + 1) >> 1;
	int* anOutbuf = new int[nCount];
	int nRowBase = 0;
	for (int i = 0; i < nLoop; ++i) {
		for (int j = 0; j < nColumn - 2 * i; ++j) {
			//anOutbuf[nRowBase + j] = anNumber[index++];
		}
	}
	delete[] anOutbuf;
}

void Solution_3(int* anNumber, int nCount) {
	// ��ά����
}
