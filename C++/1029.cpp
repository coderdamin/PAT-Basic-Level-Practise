//问题描述：
//	旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。
//输入格式：
//	输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A - Z（包括大、小写）、数字0 - 9、
//	以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。
//输出格式：
//	按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。
//输入样例：
//	7_This_is_a_test
//	_hs_s_a_es
//输出样例：
//	7TI

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char UPPER(char acKey);
int main() {
	char acRight[81] = { 0 };
	char acInput[81] = { 0 };
	cin >> acRight >> acInput;
	int nIndex1 = 0;
	int nIndex2 = 0;
	vector<char> vOutList;
	char cTemp = '\0';
	while (acRight[nIndex1] != '\0') {
		if (acInput[nIndex2] == '\0' || acRight[nIndex1] != acInput[nIndex2]) {
			cTemp = UPPER(acRight[nIndex1]);
			if (find(vOutList.begin(), vOutList.end(), cTemp) == vOutList.end()) {
				vOutList.push_back(cTemp);
			}
			nIndex1 += 1;
		}
		else {
			nIndex1 += 1;
			nIndex2 += 1;
		}
	}
	for (auto badKey : vOutList) {
		cout << badKey;
	}
	cout << endl;
	vOutList.clear();
	return 0;
}

char UPPER(char acKey) {
	return ('a' <= acKey && acKey <= 'z') ? acKey + 'A' - 'a' : acKey;
}