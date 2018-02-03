//����������
//	����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�
//	���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�
//�����ʽ��
//	�����һ�и�������������N��p������N�� <= 105����������������ĸ�����p�� <= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109��
//�����ʽ��
//	��һ�������������ѡ����ٸ����������������һ���������С�
//����������
//	10 8
//	2 3 20 4 5 1 6 7 8 9
//���������
//	8

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nCount, nParams;
	cin >> nCount >> nParams;
	int* anNumber = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> anNumber[i];
	}
	sort(anNumber, &anNumber[nCount]);
	int nResult = 0;
	for (int i = nCount - 1; i >= 0; --i) {
		for (int j = 0; j < nCount; ++j) {
			if (anNumber[i] <= anNumber[j] * nParams) {
				if (nResult < i - j + 1) {
					nResult = i - j + 1;
					break;
				}
			}
		}
		if (i < nResult) {
			break;
		}
	}
	cout << nResult << endl;
	delete[] anNumber;
	return 0;
}