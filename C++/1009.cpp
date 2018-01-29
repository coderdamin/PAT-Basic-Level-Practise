//问题描述：
//	给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
//输入格式：
//	测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，
//	单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
//输出格式：
//	每个测试用例的输出占一行，输出倒序后的句子。
//输入样例：
//	Hello World Here I Come
//输出样例：
//	Come I Here World Hello

#include <iostream>
using namespace std;

#define SWAP(val1, val2) \
{\
	val1 ^= val2; \
	val2 ^= val1; \
	val1 ^= val2; \
}

void Solution_1();
void Solution_2();
int main() {
	Solution_1();
}

void Solution_1() {
	char acInput[81] = { 0 };
	cin.getline(acInput, 80);
	unsigned char uLen = strlen(acInput);
	for (int i = 0; i < (uLen >> 1); ++i) {
		SWAP(acInput[i], acInput[uLen - 1 - i]);
	}
	unsigned char uPosBegin = 0;
	for (int i = 0; i < uLen; ++i) {
		if (acInput[i] == ' ' || (i == (uLen - 1) && ++i)) {
			for (int j = uPosBegin; j < ((uPosBegin + i - 1) >> 1); ++j) {
				SWAP(acInput[j], acInput[uPosBegin + i - 1 - j]);
			}
			uPosBegin = i + 1;
		}
	}
	cout << acInput << endl;
	return 0;
}

void Solution_2() {
	// 按单个词存成列表，然后逆序
}
