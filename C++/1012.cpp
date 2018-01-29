//����������
//	����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�
//	A1 = �ܱ�5����������������ż���ĺͣ�
//	A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1 - n2 + n3 - n4...��
//	A3 = ��5������2�����ֵĸ�����
//	A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
//	A5 = ��5������4��������������֡�
//�����ʽ��
//	ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���
//�����ʽ��
//	�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�
//	������ĳһ�����ֲ����ڣ�������Ӧλ�������N����
//��������1��
//	13 1 2 3 4 5 6 7 8 9 10 20 16 18
//�������1��
//	30 11 2 9.7 9
//
//��������2��
//	8 1 2 4 5 6 7 9 16
//�������2��
//	N 11 2 N 9

#include <iostream>
#include <iomanip>
using namespace std;

//#define FORMAT_OUT(val1, val2) \
//	(val1 == val2) ? 'N' : val1

int main() {
	int nCount = 0;
	cin >> nCount;
	int nNumber = 0;
	//int* anNumber = new int[nCount];
	int nMod = 0;
	int nA1 = 0;
	int nA2 = -1000000;
	int nA2Signal = 1;
	int nA3 = 0;
	int nA4 = 0;
	int nA4Count = 0;
	int nA5 = 0;
	for (int i = 0; i < nCount; ++i) {
		//cin >> anNumber[i];
		cin >> nNumber;
		nMod = nNumber % 5;
		switch (nMod) {
		case 0:
			if (!(nNumber & 0x00000001)) {
				nA1 += nNumber;
			}
			break;
		case 1:
			if (nA2 == -1000000) {
				nA2 = 0;
			}
			nA2 += (nA2Signal * nNumber);
			nA2Signal *= -1;
			break;
		case 2:
			nA3 += 1;
			break;
		case 3:
			nA4 += nNumber;
			nA4Count += 1;
			break;
		case 4:
			if (nNumber > nA5) {
				nA5 = nNumber;
			}
			break;
		}
	}
	cout.setf(ios::fixed);
	//cout << nA1 << ' ' << nA2 << ' ' << nA3 << ' ' << setprecision(1) << nA4 / (float)nA4Count << setprecision(0) << ' ' << nA5 << endl;
	((nA1 == 0) ? cout << 'N' : cout << nA1) << ' ';
	((nA2 == -1000000) ? cout << 'N' : cout << nA2) << ' ';
	((nA3 == 0) ? cout << 'N' : cout << nA3) << ' ';
	((nA4Count == 0) ? cout << 'N' : cout << setprecision(1) << (float)(nA4 / (float)nA4Count) << setprecision(0)) << ' ';
	((nA5 == 0) ? cout << 'N' : cout << nA5) << endl;

	return 0;
}
