//问题描述：
//	科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1 - 9]"."[0 - 9] + E[+-][0 - 9] + ，
//	即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
//	现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
//输入格式：
//	每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
//输出格式：
//	对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
//输入样例1：
//	+1.23400E-03
//输出样例1：
//	0.00123400
//
//输入样例2：
//	-1.2E+10
//输出样例2：
//	-12000000000

#include <iostream>
#include <stdio.h>
//#include <memory.h>
using namespace std;

void Solution_1();
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	char cSingal = '\0';
	char acInput[10000] = { 0 };
	int nExp = 0;
	//memset(acInput, 0, 10000);
	scanf_s("%c%c.%[0-9]E%d", &cSingal, 1, &acInput[0], 1, &acInput[1], 9998, &nExp);
	if (cSingal == '-') {
		printf("-");
	}

	if (nExp >= 0) {
		int index = 0;
		bool bZero = false;
		for (; index <= nExp; ++index) {
			if (acInput[index] == '\0') {
				bZero = true;
			}
			printf("%c", (bZero) ? '0' : acInput[index]);
		}
		if (!bZero && acInput[index] != '\0') {
			printf(".%s", &acInput[index]);
		}
	}
	else {
		printf("0.");
		for (int index = 1; index < -nExp; ++index) {
			printf("0");
		}
		printf("%s", acInput);
	}
	printf("\n");
}
