//问题描述：
//	请编写程序，找出一段给定文字中出现最频繁的那个英文字母。
//输入格式：
//	输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。
//输出格式：
//	在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
//输入样例：
//	This is a simple TEST.There ARE numbers and other symbols 1 & 2 & 3...........
//输出样例：
//	e 7

#include <iostream>
using namespace std;

typedef unsigned int UINT32;

void Solution_1();
//void Solution_2();
int LetterToIndex(char cLetter);
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	char cTemp = '\0';
	UINT32 uLetterCount[26] = { 0 };
	int nIndex = 0;
	while ((cTemp = getchar()) != '\n') {
		nIndex = LetterToIndex(cTemp);
		if (nIndex != -1) {
			uLetterCount[nIndex] += 1;
		}
	}
	int nMaxCount = 0;
	int nIndexMaxCount = 0;
	for (int i = 0; i < 26; ++i) {
		if (nMaxCount < uLetterCount[i]) {
			nMaxCount = uLetterCount[i];
			nIndexMaxCount = i;
		}
	}
	cout << char('a' + nIndexMaxCount) << ' ' << nMaxCount << endl;
}

int LetterToIndex(char cLetter) {
	if (cLetter >= 'a' && cLetter <= 'z'){
		return cLetter - 'a';
	}
	else if (cLetter >= 'A' && cLetter <= 'Z'){
		return cLetter - 'A';
	}
	return -1;
}
