//问题描述：
//	划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。如果谁比划出的数字正好等于两人喊出的数字之和，
//	谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。
//	下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。
//输入格式：
//	输入第一行先给出一个正整数N（ <= 100），随后N行，每行给出一轮划拳的记录，格式为：
//	甲喊 甲划 乙喊 乙划
//	其中“喊”是喊出的数字，“划”是划出的数字，均为不超过100的正整数（两只手一起划）。
//输出格式：
//	在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。
//输入样例：
//	5
//	8 10 9 12
//	5 10 5 10
//	3 8 5 12
//	12 18 1 13
//	4 16 12 15
//输出样例：
//	1 2

#include <iostream>
using namespace std;

int main() {
	int nCount = 0;
	cin >> nCount;
	//int(*anMorraInfo)[4] = new int[nCount][4];
	//for (int i = 0; i < nCount; ++i) {
	//	cin >> anMorraInfo[i][0] >> anMorraInfo[i][1] >> anMorraInfo[i][2] >> anMorraInfo[i][3];
	//}
	//int nWinCountA = 0;
	//int nWinCountB = 0;
	//for (int i = 0; i < nCount; ++i) {
	//}
	//delete[] anMorraInfo;
	int nWinCountA = 0;
	int nWinCountB = 0;
	int nMorraA_1, nMorraA_2;
	int nMorraB_1, nMorraB_2;
	for (int i = 0; i < nCount; ++i) {
		cin >> nMorraA_1 >> nMorraA_2 >> nMorraB_1 >> nMorraB_2;
		if (nMorraA_2 != nMorraB_2) {
			if (nMorraA_2 == nMorraA_1 + nMorraB_1) {
				nWinCountA += 1;
			}
			else if (nMorraB_2 == nMorraA_1 + nMorraB_1){
				nWinCountB += 1;
			}
		}
	}
	cout << nWinCountB << ' ' << nWinCountA << endl;
	return 0;
}
