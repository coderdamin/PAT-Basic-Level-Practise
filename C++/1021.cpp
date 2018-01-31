//����������
//	����һ��kλ����N = d(k - 1) * 10^(k - 1) + ... + d(1) * 10^1 + d(0) (0 <= di <= 9, i = 0, ..., k - 1, dk - 1>0)��
//	���д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺����N = 100311������2��0��3��1����1��3��
//�����ʽ��
//	ÿ���������1��������������һ��������1000λ��������N��
//�����ʽ��
//	��N��ÿһ�ֲ�ͬ�ĸ�λ���֣���D : M�ĸ�ʽ��һ���������λ����D������N�г��ֵĴ���M��Ҫ��D�����������
//����������
//	100311
//���������
//	0 : 2
//	1 : 3
//	3 : 1
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef unsigned short UINT16;

int main() {
	char acInput[1001] = { 0 };
	UINT16 auStatInfo[10] = { 0 };
	cin >> acInput;
	int nIndex = strlen(acInput);
	while (nIndex >= 0) {
		auStatInfo[acInput[nIndex] - '0'] += 1;
		nIndex -= 1;
	}
	int nSum = strlen(acInput);
	for (int i = 0; i <= 9; ++i){
		if (auStatInfo[i] > 0) {
			cout << i << " : " << auStatInfo[i];
			nSum -= auStatInfo[i];
			if (nSum > 0) {
				cout << '\n';
			}
		}
	}
	cout << endl;
	return 0;
}
