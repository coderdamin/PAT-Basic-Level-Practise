//问题描述：
//	旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？
//输入格式：
//	输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。
//	可用的字符包括字母[a - z, A - Z]、数字0 - 9、以及下划线“_”（代表空格）、“, ”、“.”、“ - ”、“ + ”（代表上档键）。题目保证第2行输入的文字串非空。
//	注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
//输出格式：
//	在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
//输入样例：
//	7+IE.
//	7_This_is_a_test.
//输出样例：
//	_hs_s_a_tst

#include <iostream>
#include <algorithm> 
using namespace std;

char UPPER(char acChar);
int main() {
	char acBadKey[68] = { 0 };// 26 + 26 + 10 + 5 = 67
	char acString[106] = { 0 };
	cin >> acBadKey >> acString;
	int nIndex = 0;
	bool bUpper = true;
	if (find(acBadKey, acBadKey + 68, '+') != acBadKey + 68) {
		bUpper = false;
	}

	while (acString[nIndex] != '\0') {
		if (!bUpper && (acString[nIndex] >= 'A' && acString[nIndex] <= 'Z')) {
			//}else if ((bUpper || (acString[nIndex] < 'A' || acString[nIndex] > 'Z'))
			//	&& (find(acBadKey, acBadKey + 68, UPPER(acString[nIndex])) == acBadKey + 68)) {
		}
		else if (find(acBadKey, acBadKey + 68, UPPER(acString[nIndex])) == acBadKey + 68) {
			cout << acString[nIndex];
		}
		nIndex += 1;
	}
	cout << endl;
	return 0;
}

char UPPER(char acChar) {
	if ('a' <= acChar && acChar <= 'z') {
		return acChar - 'a' + 'A';
	}
	return acChar;
}