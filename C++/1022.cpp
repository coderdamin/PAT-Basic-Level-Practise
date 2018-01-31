//问题描述：
//	输入两个非负10进制整数A和B(<= 230 - 1)，输出A + B的D(1 < D <= 10)进制数。
//输入格式：
//	输入在一行中依次给出3个整数A、B和D。
//输出格式：
//	输出A + B的D进制数。
//输入样例：
//	123 456 8
//输出样例：
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