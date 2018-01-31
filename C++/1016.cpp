//����������
//	������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��
//	�ָ���A��DA��B��DB�����д�������PA + PB��
//�����ʽ��
//	������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 10^10��
//�����ʽ��
//	��һ�������PA + PB��ֵ��
//��������1��
//	3862767 6 13530293 3
//�������1��
//	399
//
//��������2��
//	3862767 1 13530293 8
//�������2��
//	0

#include <iostream>
using namespace std;

typedef unsigned char UINT8;

int GetDPart(int nNumber, UINT8 nD);
int main() {
	int nA = 0;
	int nDA = 0;
	int nB = 0;
	int nDB = 0;
	cin >> nA >> nDA >> nB >> nDB;
	cout << GetDPart(nA, nDA) + GetDPart(nB, nDB) << endl;
	return 0;
}

int GetDPart(int nNumber, UINT8 nD) {
	if (nNumber == 0 || nD == 0) {
		return 0;
	}
	if (nD >= 10) {
		return 0;
	}
	int nRetNumber = 0;
	UINT8 uRemainder = 0;
	while (nNumber != 0) {
		uRemainder = nNumber % 10;
		nNumber /= 10;
		if (uRemainder == nD) {
			nRetNumber = nRetNumber * 10 + uRemainder;
		}
	}
	return nRetNumber;
}
