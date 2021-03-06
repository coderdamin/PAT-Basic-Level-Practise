//问题描述：
//	大侦探福尔摩斯接到一张奇怪的字条：
//	“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
//	大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中
//	第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；
//	第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
//	后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
//输入格式：
//	输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
//输出格式：
//	在一行中输出约会的时间，格式为“DAY HH : MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
//输入样例：
//	3485djDkxh4hhGE
//	2984akDfkkkkggEdsb
//	s&hgsfdk
//	d&Hyscvnm
//输出样例：
//	THU 14:04

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char acInput[4][61] = { 0 };
	cin >> acInput[0] >> acInput[1] >> acInput[2] >> acInput[3];
	int index = 0;
	char cWeek = '\0';
	char cHour = '\0';
	char cMM = '\0';
	while (acInput[0][index] != '\0') {
		if (acInput[0][index] == acInput[1][index]) {
			if (cWeek == '\0') {
				if (acInput[0][index] >= 'A'
					&& acInput[0][index] <= 'Z') {
					cWeek = acInput[0][index];
				}
			}
			else {
				cHour = acInput[0][index];
				break;
			}
		}
		index += 1;
	}
	index = 0;
	while (acInput[2][index] != '\0') {
		if ((acInput[2][index] >= 'A' && acInput[2][index] <= 'Z')
			|| (acInput[2][index] >= 'a' && acInput[2][index] <= 'z')) {
			if (acInput[2][index] == acInput[3][index]) {
				cMM = index;
				break;
			}
		}
		index += 1;
	}

	char *aDay[] = {
		"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
	};
	cout << aDay[cWeek - 'A'] << " ";
	cout << setfill('0') << setw(2);
	cout << (unsigned int)((cHour >= 'A') ? cHour - 'A' + 10 : cHour - '0') << ':';
	cout << setfill('0') << setw(2);
	cout << (unsigned int)cMM;
	cout << endl;
	return 0;
}
