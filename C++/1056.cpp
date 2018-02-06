//问题描述：
//	给定N个非0的个位数字，用其中任意2个数字都可以组合成1个2位的数字。要求所有可能组合出来的2位数字的和。
//	例如给定2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。
//输入格式：
//	输入在一行中先给出N（1<N<10），随后是N个不同的非0个位数字。数字间以空格分隔。
//输出格式：
//	输出所有可能组合出来的2位数字的和。
//输入样例：
//	3 2 8 5
//输出样例：
//	330

#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned char UINT8;
typedef unsigned int UINT32;

void Solution_1();
void Solution_2();
int main() {
	//Solution_1();
	Solution_2();
	return 0;
}

void Solution_1() {
	UINT8 acNumber[8] = { 0 };
	char cTemp = '\0';
	UINT8 uCount = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp == ' ') {
			continue;
		}
		acNumber[uCount++] = cTemp - '0';
	}
	UINT32 uSum = 0;
	for (int i = 0; i < uCount; i++) {
		for (int j = 0; j < uCount; j++) {
			if (i != j) {
				uSum += (acNumber[i] * 10 + acNumber[j]);
			}
		}
	}
	cout << uSum << endl;
}

void Solution_2() {
	UINT8 acNumber[8] = { 0 };
	char cTemp = '\0';
	UINT8 uCount = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp == ' ') {
			continue;
		}
		acNumber[uCount++] = cTemp - '0';
	}
	UINT32 uSum = 0;
	for (int i = 0; i < uCount - 1; i++) {
		for (int j = i + 1; j < uCount; j++) {
			uSum += (acNumber[i] * 10 + acNumber[j]);
			uSum += (acNumber[j] * 10 + acNumber[i]);
		}
	}
	cout << uSum << endl;
}
