//问题描述：
//	火星人是以13进制计数的：
//	地球人的0被火星人称为tret。
//	地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
//	火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
//	例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。
//输入格式：
//	输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。
//输出格式：
//	对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
//输入样例：
//	4
//	29
//	5
//	elo nov
//	tam
//输出样例：
//	hel mar
//	may
//	115
//	13

#include <iostream>
using namespace std;

#define ARRAY_LEN(array) sizeof(array) / sizeof(array[0])

char* acTextspeakL[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char* acTextspeakH[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int StringToInt(char* pStr);
int main() {
	int nCount = 0;
	cin >> nCount;
	char(*acNumber)[10] = new char[nCount][10];
	cin.ignore();
	for (int i = 0; i < nCount; ++i) {
		cin.getline(acNumber[i], 10);
	}
	int nNumber = 0;
	int nNumberH = 0;
	for (int i = 0; i < nCount; ++i) {
		acNumber[i];
		// If the converted value would be out of the range of representable values by an int, 
		// it causes undefined behavior. 
		//nNumber = atoi(); 
		nNumber = StringToInt(acNumber[i]);
		if (nNumber != -1) {
			nNumberH = nNumber / 13;
			if (nNumberH > 0) {
				cout << acTextspeakH[nNumberH - 1] << ' ';
			}
			cout << acTextspeakL[nNumber % 13];
		}
		else{
			int nBeganPos = 0;
			int nEndPos = 0;
			nNumberH = 0;
			nNumber = 0;
			while (acNumber[i][nEndPos] != '\0') {
				if ((acNumber[i][nEndPos] == ' ' || acNumber[i][nEndPos + 1] == '\0')
					&& (nEndPos > nBeganPos)) {
					//if (acNumber[nEndPos] == ' ' && nEndPos > nBeganPos) {
					if (nNumberH == 0) {
						for (int j = 0; j < ARRAY_LEN(acTextspeakH); ++j) {
							if (strncmp(&acNumber[i][nBeganPos], acTextspeakH[j], nEndPos - nBeganPos) == 0) {
								nNumberH = j + 1;
								break;
							}
						}
					}
					else{
						for (int j = 0; j < ARRAY_LEN(acTextspeakL); ++j) {
							if (strncmp(&acNumber[i][nBeganPos], acTextspeakL[j], nEndPos - nBeganPos) == 0) {
								nNumber = j;
								break;
							}
						}
					}
					nBeganPos = nEndPos + 1;
				}
				nEndPos += 1;
			}
			cout << nNumberH * 13 + nNumber;
		}
		if (i != nCount - 1) {
			cout << '\n';
		}
	}
	cout << endl;
	delete[] acNumber;
	return 0;
}

int StringToInt(char* pStr) {
	int nNumber = 0;
	while (*pStr != '\0' && *pStr != ' ') {
		if (*pStr < '0' || *pStr > '9') {
			nNumber = -1;
			break;
		}
		nNumber = nNumber * 10 + (*pStr - '0');
		pStr += 1;
	}
	return nNumber;
}
