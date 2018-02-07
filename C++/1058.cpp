//����������
//	���Ķ�ѡ���ǱȽ��鷳�����飬���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ���������ࡣ
//�����ʽ��
//	�����ڵ�һ�и�������������N�� <= 1000����M�� <= 100�����ֱ���ѧ�������Ͷ�ѡ��ĸ��������M�У�ÿ��˳�θ���һ���������ֵ��������5������������
//	ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ���
//	���N�У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������
//�����ʽ��
//	���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ��������һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳���1��ʼ��ţ���
//	����в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո����������Ŀ��û���˴��������һ�������Too simple����
//����������
//	3 4
//	3 4 2 a c
//	2 5 1 b
//	5 3 2 b c
//	1 5 4 a b d e
//	(2 a c) (2 b d) (2 a c) (3 a b e)
//	(2 a c) (1 b) (2 a b) (4 a b d e)
//	(2 b d) (1 e) (2 b c) (4 a b c d)
//���������
//	3
//	6
//	5
//	2 2 3 4

#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

typedef unsigned char UINT8;
typedef struct{
	char acResult[5];
	UINT8 uScore;
	UINT8 uOptionCount;
	UINT8 uResultCount;
} ExamQuestion;
//typedef struct{
//	char acAnswer[5];
//	UINT8 uAnswerCount;
//} ExamAnswer;

void CollectResult(int nCount, char*pResult);
int CheckResult(ExamQuestion& question, char*pAnswer, int nCount);
int main() {
	int nQuestionCount = 0, nExamineeCount = 0;
	cin >> nExamineeCount >> nQuestionCount;
	ExamQuestion* pExamQuestions = new ExamQuestion[nQuestionCount];
	int nTemp = 0;
	for (int i = 0; i < nQuestionCount; ++i) {
		cin >> nTemp; pExamQuestions[i].uScore = nTemp;
		cin >> nTemp; pExamQuestions[i].uOptionCount = nTemp;
		cin >> nTemp; pExamQuestions[i].uResultCount = nTemp;
		CollectResult(nTemp, pExamQuestions[i].acResult);
	}
	int nIndex = 0;
	int* pScores = new int[nExamineeCount];
	memset(pScores, 0, sizeof(int)*nExamineeCount);
	int* pDifficultyInfo = new int[nQuestionCount];
	memset(pDifficultyInfo, 0, sizeof(int)*nQuestionCount);
	//ExamAnswer* pExamAnswers = new ExamAnswer[nExamineeCount * nQuestionCount];
	int nAnswerCount = 0;
	int nMaxWrongTimes = 0;
	char acAnswer[5] = { 0 };
	char cTemp = '\0';
	for (int i = 0; i < nExamineeCount; ++i) {
		for (int j = 0; j < nQuestionCount; ++j) {
			//cin >> nTemp; pExamAnswers[nIndex].uAnswerCount = nTemp;
			//CollectResult(nTemp, pExamAnswers[nIndex].acAnswer);
			while ((cTemp = getchar()) != '(');
			cin >> nAnswerCount;
			CollectResult(nAnswerCount, acAnswer);
			if (nAnswerCount == pExamQuestions[j].uResultCount) {
				if (CheckResult(pExamQuestions[j], acAnswer, nAnswerCount) > 0){
					pScores[i] += pExamQuestions[j].uScore;
					continue;
				}
			}
			pDifficultyInfo[j] += 1;
			if (nMaxWrongTimes < pDifficultyInfo[j]){
				nMaxWrongTimes = pDifficultyInfo[j];
			}
		}
	}
	for (int i = 0; i < nExamineeCount; ++i) {
		cout << pScores[i] << '\n';
	}
	if (nMaxWrongTimes == 0) {
		cout << "Too simple";
	}
	else{
		cout << nMaxWrongTimes;
		for (int i = 0; i < nQuestionCount; ++i) {
			if (nMaxWrongTimes == pDifficultyInfo[i]) {
				cout << ' ' << i + 1;
			}
		}
	}
	cout << endl;
	delete[] pDifficultyInfo;
	delete[] pScores;
	//delete[] pExamAnswers;
	delete[] pExamQuestions;
	return 0;
}

void CollectResult(int nCount, char*pResult) {
	if (pResult == nullptr) {
		return;
	}
	int nIndex = 0;
	char cTemp = '\0';
	while ((cTemp = getchar()) != '\n'){
		if (cTemp != ' ') {
			pResult[nIndex++] = cTemp;
			if (nCount == nIndex) {
				break;
			}
		}
	}
}

int CheckResult(ExamQuestion& question, char*pAnswer, int nCount) {
	bool bRight = false;
	for (int i = 0; i < nCount; ++i) {
		bRight = false;
		for (int j = 0; j < question.uResultCount; ++j) {
			if (question.acResult[j] == pAnswer[i]) {
				bRight = true;
				break;
			}
		}
		if (!bRight) {
			break;
		}
	}
	return bRight ? nCount : 0;
}
