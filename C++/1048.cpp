//问题描述：
//	本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，
//	对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。
//输入格式：
//	输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
//输出格式：
//	在一行中输出加密后的结果。
//输入样例：
//	1234567 368782971
//输出样例：
//	3695Q8118

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char acSecretKey[101] = { 0 };
	char acNumber[101] = { 0 };
	cin >> acSecretKey >> acNumber;
	int nKeyIndex = strlen(acSecretKey);
	int nNumberIndex = strlen(acNumber);
	char nKey = 0;
	for (int i = nNumberIndex; i >= 0; --i){
		if (nKeyIndex < i) {
			nKey = 0;
		}
		else{
			nKey = acSecretKey[nKeyIndex - i];
		}
		if (nKey == 0) {
			cout << acNumber[nNumberIndex - i];
			continue;
		}
		if ((nNumberIndex - i + 1) & 0x00000001) {
			nKey = (nKey + acNumber[nNumberIndex - i] - '0' * 2) % 13;
			switch (nKey) {
			case 10:
				cout << 'J'; break;
			case 11:
				cout << 'Q'; break;
			case 12:
				cout << 'K'; break;
			default:
				cout << (int)nKey; break;
			}
		}
		else{
			nKey = acNumber[nNumberIndex - i] - nKey;
			cout << (int)((nKey > 0) ? nKey : 10 + nKey);
		}
	}
	cout << endl;
	return 0;
}
