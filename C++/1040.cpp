//问题描述：
//	字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P), 第4位(A), 第6位(T)；第二个PAT是第3位(P), 第4位(A), 第6位(T)。
//	现给定字符串，问一共可以形成多少个PAT？
//输入格式：
//	输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。
//输出格式：
//	在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
//输入样例：
//	APPAPT
//输出样例：
//	2

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char acInput[106] = { 0 };
	cin >> acInput;
	int nPATCount = 0;
	int nATCount = 0;
	int nTCount = 0;
	int nIndex = strlen(acInput);
	while (nIndex >= 0) {
		switch (acInput[nIndex]) {
		case 'P':
			nPATCount += nATCount;
			break;
		case 'A':
			nATCount += nTCount;
			break;
		case 'T':
			nTCount += 1;
			break;
		}
		nIndex -= 1;
	}
	cout << nPATCount << endl;
	return 0;
}
