//����������
//	����һ�� k + 1 λ�������� N��д�� ak...a1a0 ����ʽ�����ж����� i �� 0 <= ai < 10 �� ak > 0��N ����Ϊһ�������������ҽ��������� i �� ai = ak - i����Ҳ������Ϊһ����������
//	�ǻ�����Ҳ����ͨ��һϵ�в�����������������Ƚ���������ת���ٽ���ת���������ӣ�����ͻ�����һ�������������ظ������ת����ӵĲ�����ֱ��һ�����������֡����һ���ǻ��������Ա����������
//	�ͳ������Ϊ�ӳٵĻ������������巭���� https ://en.wikipedia.org/wiki/Palindromic_number��
//	��������һ��������������Ҫ�����ҵ��������Ǹ���������
//�����ʽ��
//	������һ���и���һ��������1000λ����������
//�����ʽ��
//	�Ը�����������һ��һ����������������Ĺ��̡�ÿ�и�ʽ����
//	A + B = C
//	����A��ԭʼ�����֣�B��A����ת����C�����ǵĺ͡�A�������������ʼ���ظ�����ֱ��C��10�����ڱ�ɻ���������ʱ��һ���������C is a palindromic number.����
//	�������10����û�ܵõ���������������һ���������Not found in 10 iterations.����
//�������� 1��
//	97152
//������� 1��
//	97152 + 25179 = 122331
//	122331 + 133221 = 255552
//	255552 is a palindromic number.
//
//�������� 2��
//	196
//������� 2��
//	196 + 691 = 887
//	887 + 788 = 1675
//	1675 + 5761 = 7436
//	7436 + 6347 = 13783
//	13783 + 38731 = 52514
//	52514 + 41525 = 94039
//	94039 + 93049 = 187088
//	187088 + 880781 = 1067869
//	1067869 + 9687601 = 10755470
//	10755470 + 07455701 = 18211171
//	Not found in 10 iterations.

#include <iostream>
#include <stdio.h>
using namespace std;

#define SWAP_VALUE(val1, val2) { \
	val1 ^= val2;				\
	val2 ^= val1;				\
	val1 ^= val2;				\
}

void ReverseCout(char* pNumber);
void ReverseString(char* pNumber);
bool CheckKaibun(char* pNumber);
bool ReverseAdd(char* pNumber, char* pOutbuf);
int main() {
	char acNumber[2][101] = { 0 };
	cin >> acNumber[0];
	int nLeftTimes = 10;
	int nAddend = 0, nResult = 1;
	bool bFounded = true;
	while (!CheckKaibun(acNumber[nAddend])) {
		if (nLeftTimes <= 0) {
			bFounded = false;
			break;
		}
		ReverseAdd(acNumber[nAddend], acNumber[nResult]);
		cout << acNumber[nAddend] << " + ";
		ReverseCout(acNumber[nAddend]);
		cout << " = " << acNumber[nResult] << '\n';
		SWAP_VALUE(nAddend, nResult)
			nLeftTimes -= 1;
	}
	if (bFounded) {
		cout << acNumber[nAddend] << " is a palindromic number." << endl;
	}
	else{
		cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}

void ReverseCout(char* pNumber) {
	if (pNumber == nullptr) {
		return;
	}
	int nLen = strlen(pNumber);
	for (int i = nLen - 1; i >= 0; --i){
		cout << pNumber[i];
	}
}

bool CheckKaibun(char* pNumber) {
	if (pNumber == nullptr) {
		return false;
	}
	int nLen = strlen(pNumber);
	bool bRight = true;
	for (int i = 0; i < (nLen >> 1); ++i){
		if (pNumber[i] != pNumber[nLen - 1 - i]) {
			bRight = false;
			break;
		}
	}
	return bRight;
}

bool ReverseAdd(char* pNumber, char* pOutbuf) {
	if (pNumber == nullptr || pOutbuf == nullptr) {
		return false;
	}
	int nLen = strlen(pNumber);
	int nCarry = 0;
	for (int i = 0; i < nLen; ++i){
		pOutbuf[i] = pNumber[i] + pNumber[nLen - 1 - i] - '0' + nCarry;
		if (pOutbuf[i] > '9') {
			pOutbuf[i] -= 10;
			nCarry = 1;
		}
		else{
			nCarry = 0;
		}
	}
	if (nCarry > 0) {
		pOutbuf[nLen] = '0' + nCarry;
	}
	ReverseString(pOutbuf);
}

void ReverseString(char* pNumber) {
	if (pNumber == nullptr) {
		return;
	}
	int nLen = strlen(pNumber);
	for (int i = 0; i < (nLen >> 1); ++i){
		SWAP_VALUE(pNumber[i], pNumber[nLen - 1 - i])
	}
}
