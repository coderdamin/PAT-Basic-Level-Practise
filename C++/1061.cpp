//问题描述：
//	判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。
//输入格式：
//	输入在第一行给出两个不超过100的正整数N和M，分别是学生人数和判断题数量。第二行给出M个不超过5的正整数，是每道题的满分值。
//	第三行给出每道题对应的正确答案，0代表“非”，1代表“是”。随后N行，每行给出一个学生的解答。数字间均以空格分隔。
//输出格式：
//	按照输入的顺序输出每个学生的得分，每个分数占一行。
//输入样例：
//	3 6
//	2 1 3 3 4 5
//	0 0 1 0 1 1
//	0 1 1 0 0 1
//	1 0 1 0 1 0
//	1 1 0 0 1 1
//输出样例：
//	13
//	11
//	12

#include <iostream>
using namespace std;

typedef struct{
	int nScore;
	int nResult;
} ExamQuestion;
int main() {
	int nStudentCount = 0, nQuestionCount = 0;
	cin >> nStudentCount >> nQuestionCount;
	ExamQuestion* aQueationList = new ExamQuestion[nQuestionCount];
	for (int i = 0; i < nQuestionCount; ++i) {
		cin >> aQueationList[i].nScore;
	}
	int nIntTmp = 0;
	for (int i = 0; i < nQuestionCount; ++i) {
		cin >> aQueationList[i].nResult;
	}
	int* anScoreList = new int[nStudentCount];
	for (int i = 0; i < nStudentCount; ++i) {
		anScoreList[i] = 0;
		for (int j = 0; j < nQuestionCount; ++j) {
			cin >> nIntTmp;
			if (nIntTmp == aQueationList[j].nResult) {
				anScoreList[i] += aQueationList[j].nScore;
			}
		}
	}
	cout << anScoreList[0];
	for (int i = 1; i < nStudentCount; ++i) {
		cout << '\n' << anScoreList[i];
	}
	cout << endl;
	delete[] anScoreList;
	delete[] aQueationList;
	return 0;
}
