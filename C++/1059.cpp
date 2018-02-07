//问题描述：
//	C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
//	0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
//	1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
//	2. 其他人将得到巧克力。
//	给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。
//输入格式：
//	输入第一行给出一个正整数N（ <= 10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。
//输出格式：
//	对每个要查询的ID，在一行中输出“ID : 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。
//	如果所查ID根本不在排名里，打印“Are you kidding ? ”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID : Checked”（不能多吃多占）。
//输入样例：
//	6
//	1111
//	6666
//	8888
//	1234
//	5555
//	0001
//	6
//	8888
//	0001
//	1111
//	2222
//	8888
//	2222
//输出样例：
//	8888: Minion
//	0001 : Chocolate
//	1111 : Mystery Award
//	2222 : Are you kidding ?
//	8888 : Checked
//	2222 : Are you kidding ?

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bitset>
using namespace std;

bool CheckPrimeNumber(int nNumber);
int main() {
	int nCount = 0;
	cin >> nCount;
	int* pRankList = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> pRankList[i];
	}
	int nSearchCount = 0;
	cin >> nSearchCount;
	int* pSearchList = new int[nSearchCount];
	for (int i = 0; i < nSearchCount; ++i) {
		cin >> pSearchList[i];
	}
	int* pItertor = nullptr;
	int nRank = 0;
	bitset<10001> setSearched;
	for (int i = 0; i < nSearchCount; ++i) {
		cout << setfill('0') << setw(4) << pSearchList[i];
		if (setSearched[pSearchList[i]]) {
			cout << ": Checked";
		}
		else{
			pItertor = find(pRankList, &pRankList[nCount], pSearchList[i]);
			if (pItertor == &pRankList[nCount]) {
				cout << ": Are you kidding?";
			}
			else {
				setSearched.set(pSearchList[i]);
				if (pItertor == pRankList) {
					cout << ": Mystery Award";
				}
				else{
					nRank = (pItertor - pRankList) + 1;
					if (CheckPrimeNumber(nRank)) {
						cout << ": Minion";
					}
					else {
						cout << ": Chocolate";
					}
				}
			}
		}
		if (i < nSearchCount - 1){
			cout << '\n';
		}
	}
	cout << endl;
	delete[] pSearchList;
	delete[] pRankList;
	return 0;
}

bool CheckPrimeNumber(int nNumber) {
	if (nNumber == 2 || nNumber == 3) {
		return true;
	}
	int nIntTmp = nNumber % 6;
	if (nIntTmp != 5 && nIntTmp != 1) {
		return false;
	}
	bool bRight = true;
	for (int i = 2; i < sqrt(nNumber); ++i) {
		if (nNumber % i == 0) {
			bRight = false;
			break;
		}
	}
	return bRight;
}
