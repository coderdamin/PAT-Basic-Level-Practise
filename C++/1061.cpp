//����������
//	�ж�������кܼ򵥣������Ҫ����д���򵥵ĳ��������ʦ���Ⲣͳ��ѧ�����ж���ĵ÷֡�
//�����ʽ��
//	�����ڵ�һ�и�������������100��������N��M���ֱ���ѧ���������ж����������ڶ��и���M��������5������������ÿ���������ֵ��
//	�����и���ÿ�����Ӧ����ȷ�𰸣�0�����ǡ���1�����ǡ������N�У�ÿ�и���һ��ѧ���Ľ�����ּ���Կո�ָ���
//�����ʽ��
//	���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�
//����������
//	3 6
//	2 1 3 3 4 5
//	0 0 1 0 1 1
//	0 1 1 0 0 1
//	1 0 1 0 1 0
//	1 1 0 0 1 1
//���������
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
