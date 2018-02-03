//问题描述：
//	某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
//	这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
//输入格式：
//	输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy / mm / dd”（即年 / 月 / 日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
//输出格式：
//	在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
//输入样例：
//	5
//	John 2001/05/12
//	Tom 1814/09/06
//	Ann 2121/01/30
//	James 1814/09/05
//	Steve 1967/11/20
//输出样例：
//	3 Tom John

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//typedef struct PEOPLE {
//	char acName[6];
//	int nBirthday;
//} People;

int main() {
	int nCount = 0;
	cin >> nCount;
	char acNameOldest[6] = { 0 };
	int nOldest = 2014 * 365 + 9 * 30 + 6 + 1;
	char acNameYoungest[6] = { 0 };
	int nYoungest = 0;
	char acName[6] = { 0 };
	int nYear, nMonth, nDay;
	int nValidCount = nCount;
	for (int i = 0; i < nCount; ++i) {
		scanf_s("%s %d/%d/%d", &acName, 6, &nYear, &nMonth, &nDay);
		nDay = nYear * 365 + nMonth * 30 + nDay;
		if (nDay > 735386 || nDay < 662386) {
			nValidCount -= 1;
			continue;
		}
		if (nOldest > nDay) {
			nOldest = nDay;
			strcpy_s(acNameOldest, 6, acName);
		}
		if (nYoungest < nDay) {
			nYoungest = nDay;
			strcpy_s(acNameYoungest, 6, acName);
		}
	}
	cout << nValidCount << ' ' << acNameOldest << ' ' << acNameYoungest << endl;
	return 0;
}
