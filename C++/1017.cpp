//����������
//	����Ҫ�����A / B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������
//�����ʽ��
//	������1�������θ���A��B���м���1�ո�ָ���
//�����ʽ��
//	��1�����������Q��R���м���1�ո�ָ���
//����������
//	123456789050987654321 7
//���������
//	17636684150141093474 3

#include <iostream>
using namespace std;

int main() {
	char acNumber[1001] = { 0 };
	int nDivisor = 0; // nDivisor > 0
	cin >> acNumber >> nDivisor;
	int nPrevNumber = 0;
	int nIndex = 0;
	while (acNumber[nIndex] != '\0') {
		if (nPrevNumber > 0 || (acNumber[nIndex] - '0') >= nDivisor) {
			cout << ((acNumber[nIndex] - '0' + nPrevNumber * 10) / nDivisor);
			nPrevNumber = ((acNumber[nIndex] - '0' + nPrevNumber * 10) % nDivisor);
		}
		else{
			nPrevNumber = (acNumber[nIndex] - '0');
		}
		++nIndex;
	}
	if (nIndex > 1 || (nPrevNumber != acNumber[0] - '0')) {
		cout << ' ' << nPrevNumber << endl;
	}
	else{
		cout << "0 " << nPrevNumber << endl;
	}
	return 0;
}
