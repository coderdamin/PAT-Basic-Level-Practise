//问题描述：
//	本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。
//输入格式：
//	输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），
//	随后是K个分数，中间以空格分隔。
//输出格式：
//	在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
//输入样例：
//	10
//	60 75 90 55 75 99 82 90 75 50
//	3 75 90 88
//输出样例：
//	3 2 0

#include <iostream>
using namespace std;

void Solution_1();
void Solution_2();
int main() {
	Solution_1();
	//Solution_2();
	return 0;
}

void Solution_1() {
	int nCount = 0;
	cin >> nCount;
	int* anSocre = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> anSocre[i];
	}
	int nSearchCount = 0;
	cin >> nSearchCount;
	int(*anSearch)[2] = new int[nCount][2];
	for (int i = 0; i < nSearchCount; ++i) {
		cin >> anSearch[i][0];
		anSearch[i][1] = 0;
	}
	for (int i = 0; i < nCount; ++i) {
		for (int j = 0; j < nSearchCount; ++j) {
			if (anSearch[j][0] == anSocre[i]) {
				anSearch[j][1] += 1;
				break;
			}
		}
	}
	cout << anSearch[0][1];
	for (int j = 1; j < nSearchCount; ++j) {
		cout << ' ' << anSearch[j][1];
	}
	cout << endl;
	delete[] anSearch;
	delete[] anSocre;
}

void Solution_2() {
	int anSocre[105] = { 0 };
	int nCount = 0;
	cin >> nCount;
	int nScore = 0;
	for (int i = 0; i < nCount; ++i) {
		cin >> nScore;
		anSocre[nScore] += 1;
	}
	cin >> nCount;
	cin >> nScore;
	cout << anSocre[nScore];
	for (int i = 1; i < nCount; ++i) {
		cin >> nScore;
		cout << ' ' << anSocre[nScore];
	}
	cout << endl;
}
