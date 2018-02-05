//问题描述：
//	给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。
//	当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。
//输入格式：
//	输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
//输出格式：
//	在一行中按题目要求输出排序后的字符串。题目保证输出非空。
//输入样例：
//	redlesPayBestPATTopTeePHPereatitAPPT
//输出样例：
//	PATestPATestPTetPTePePee

#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned int UINT32;

#define GET_ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

const char aLetterIndex[] = { 'P', 'A', 'T', 'e', 's', 't' };

int LetterToIndex(char cLetter);
int main() {
	UINT32 auCount[6] = { 0 };
	char cLetter = '\0';
	int nIndex = 0;
	while ((cLetter = getchar()) != '\n') {
		nIndex = LetterToIndex(cLetter);
		if (nIndex != -1) {
			auCount[nIndex] += 1;
		}
	}
	bool bCompleted = false;
	while (true) {
		bCompleted = true;
		for (int i = 0; i < GET_ARRAY_LEN(auCount); ++i) {
			if (auCount[i] > 0) {
				cout << aLetterIndex[i];
				auCount[i] -= 1;
				bCompleted = false;
			}
		}
		if (bCompleted) {
			cout << endl;
			break;
		}
	}
	return 0;
}

int LetterToIndex(char cLetter) {
	int nIndex = -1;
	for (int i = 0; i < GET_ARRAY_LEN(aLetterIndex); ++i) {
		if (aLetterIndex[i] == cLetter) {
			nIndex = i;
			break;
		}
	}
	return nIndex;
}
