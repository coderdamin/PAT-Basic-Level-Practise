//����������
//	���������Ǹ�10��������A��B(<= 230 - 1)�����A + B��D(1 < D <= 10)��������
//�����ʽ��
//	������һ�������θ���3������A��B��D��
//�����ʽ��
//	���A + B��D��������
//����������
//	123 456 8
//���������
//	1103

#include <iostream>
using namespace std;

#define SWAP(val1, val2)	\
	(val1) ^= (val2);		\
	(val2) ^= (val1);		\
	(val1) ^= (val2)

void NumberToString(int uNumber, int uRadix, char* pOut);
int main() {
	int nNumberA = 0;
	int nNumberB = 0;
	int nScale = 0;
	cin >> nNumberA >> nNumberB >> nScale;
	nNumberA += nNumberB;
	char acBuff[16] = { 0 };
	NumberToString(nNumberA, nScale, acBuff);
	cout << acBuff << endl;
	return 0;
}

void NumberToString(int uNumber, int uRadix, char* pOut) {
	if (uNumber == 0 || uRadix == 0){
		pOut[0] = '0';
		pOut[1] = '\0';
		return;
	}
	char* pIterator = pOut;
	while (uNumber != 0) {
		*pIterator++ = (uNumber % uRadix) + '0';
		uNumber /= uRadix;
	}
	int nLen = strlen(pOut) - 1;
	for (int index = 0; index <= (nLen >> 1); ++index) {
		SWAP(pOut[index], pOut[nLen - index]);
	}
}