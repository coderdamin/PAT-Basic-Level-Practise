//问题描述：
//	读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
//输入格式：
//	每个测试输入包含1个测试用例，格式为
//	第1行：正整数n
//	第2行：第1个学生的姓名 学号 成绩
//	第3行：第2个学生的姓名 学号 成绩
//	... ... ...
//	第n + 1行：第n个学生的姓名 学号 成绩
//	其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
//输出格式：
//	对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
//输入样例：
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//
//输出样例：
//Mike CS991301
//Joe Math990112

#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;
class Student {
public:
	Student() {
		nScore = 0;
		memset(acName, 0, sizeof(acName));
		memset(acStudentid, 0, sizeof(acStudentid));
	}
	~Student() {}

public:
	int nScore;
	char acName[11];
	char acStudentid[11];
};

int main() {
	int nCount = 0;
	cin >> nCount;
	int nScore = 0;
	char acName[11] = { 0 };
	char acStudentid[11] = { 0 };
	Student scoreMax;
	Student scoreMin;
	scoreMax.nScore = -1;
	scoreMin.nScore = 101;
	for (int i = 0; i < nCount; ++i) {
		cin >> acName >> acStudentid >> nScore;
		if (nScore > scoreMax.nScore) {
			scoreMax.nScore = nScore;
			strcpy(scoreMax.acName, acName);
			strcpy(scoreMax.acStudentid, acStudentid);
		}
		if (nScore < scoreMin.nScore) {
			scoreMin.nScore = nScore;
			strcpy(scoreMin.acName, acName);
			strcpy(scoreMin.acStudentid, acStudentid);
		}
	}
	cout << scoreMax.acName << ' ' << scoreMax.acStudentid << '\n';
	cout << scoreMin.acName << ' ' << scoreMin.acStudentid << endl;
	return 0;
}