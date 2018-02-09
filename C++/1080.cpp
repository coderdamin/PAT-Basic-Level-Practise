//����������
//	�������й���ѧMOOC��http://www.icourse163.org/��ѧϰ�����ݽṹ���γ̵�ѧ������Ҫ���һ�źϸ�֤�飬�������Ȼ�ò�����200�ֵ����߱����ҵ�֣�Ȼ��������ò�����60�֣�����100����
//	�����ɼ��ļ��㹫ʽΪ G = (G����x 40% + G��ĩx 60%)����� G���� > G��ĩ���������� G ���� G��ĩ������ G���� �� G��ĩ �ֱ�Ϊѧ�������к���ĩ�ɼ���
//	���ڵ������ǣ�ÿ�ο��Զ�����һ�Ŷ����ĳɼ���������������д���򣬰Ѳ�ͬ�ĳɼ�����Ϊһ�š�
//�����ʽ��
//	�����ڵ�һ�и���3���������ֱ��� P���������߱����ҵ��ѧ��������M���μ������п��Ե�ѧ��������N���μ�����ĩ���Ե�ѧ��������ÿ������������10000��
//	���������������롣��һ����� P �����߱�̳ɼ� G��̣��ڶ������ M �����п��Գɼ� G���У���������� N ����ĩ���Գɼ� G��ĩ��
//	ÿ���ɼ�ռһ�У���ʽΪ��ѧ��ѧ�� ����������ѧ��ѧ��Ϊ������20���ַ���Ӣ����ĸ�����֣������ǷǸ�����������ܷ����Ϊ900�֣����к���ĩ����߷�Ϊ100�֣���
//�����ʽ��
//	��ӡ����úϸ�֤���ѧ��������ÿ��ѧ��ռһ�У���ʽΪ��
//	ѧ��ѧ�� G��� G���� G��ĩ G
//	����еĳɼ������ڣ�����ĳ��û�μ����п��ԣ���������Ӧ��λ������� - 1�������˳��Ϊ���������������������뾫ȷ���������ݼ������в��У���ѧ�ŵ�����
//	��Ŀ��֤ѧ��û���ظ��������ٴ���1���ϸ��ѧ����
//����������
//	6 6 7
//	01234 880
//	a1903 199
//	ydjh2 200
//	wehu8 300
//	dx86w 220
//	missing 400
//	ydhfu77 99
//	wehu8 55
//	ydjh2 98
//	dx86w 88
//	a1903 86
//	01234 39
//	ydhfu77 88
//	a1903 66
//	01234 58
//	wehu8 84
//	ydjh2 82
//	missing 99
//	dx86w 81
//���������
//	missing 400 - 1 99 99
//	ydjh2 200 98 82 88
//	dx86w 220 88 81 84
//	wehu8 300 55 84 84

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct {
	int nExerScore;
	int nMidScore;
	int nEndScore;
} StudentScore;

typedef struct {
	char acName[21];
	int nFinalScore;
	StudentScore* pScoreInfo;
} StudentScore2;

bool ScoreSortFunc(StudentScore2* score1, StudentScore2* score2);
int main() {
	map<string, StudentScore*> mapScore;
	int nCountExer = 0, nCountMid = 0, nCountEnd = 0;
	cin >> nCountExer >> nCountMid >> nCountEnd;
	char acName[21] = { 0 };
	int nScore = 0;
	for (int i = 0; i < nCountExer; ++i) {
		cin >> acName >> nScore;
		if (nScore >= 200) {
			mapScore[acName] = new StudentScore;
			mapScore[acName]->nExerScore = nScore;
			mapScore[acName]->nMidScore = -1;
			mapScore[acName]->nMidScore = -1;
		}
	}
	for (int i = 0; i < nCountMid; ++i) {
		cin >> acName >> nScore;
		if (mapScore.find(acName) != mapScore.end()) {
			mapScore[acName]->nMidScore = nScore;
		}
	}
	vector<StudentScore2*> vScore;
	StudentScore2* pScore = nullptr;
	int nScoreFinal = 0;
	for (int i = 0; i < nCountEnd; ++i) {
		cin >> acName >> nScore;
		if (mapScore.find(acName) != mapScore.end()) {
			if (nScore > mapScore[acName]->nMidScore) {
				nScoreFinal = nScore;
			}
			else{
				nScoreFinal = int(nScore * 0.6 + mapScore[acName]->nMidScore*0.4 + 0.5);
			}
			if (nScoreFinal >= 60) {
				pScore = new StudentScore2;
				strcpy(pScore->acName, acName);
				mapScore[acName]->nEndScore = nScore;
				pScore->nFinalScore = nScoreFinal;
				pScore->pScoreInfo = mapScore[acName];
				vScore.push_back(pScore);
			}
		}
	}
	sort(vScore.begin(), vScore.end(), ScoreSortFunc);
	bool bFirst = true;
	for (auto scoreInfo : vScore) {
		if (bFirst) {
			bFirst = false;
		}
		else{
			cout << '\n';
		}
		cout << scoreInfo->acName << ' ' << scoreInfo->pScoreInfo->nExerScore << ' ';
		//cout << (scoreInfo->pScoreInfo->nMidScore > 0) ? scoreInfo->pScoreInfo->nMidScore : -1 << ' ';
		cout << scoreInfo->pScoreInfo->nMidScore << ' ';
		cout << scoreInfo->pScoreInfo->nEndScore << ' ' << scoreInfo->nFinalScore;
		delete scoreInfo;
	}
	cout << endl;
	vScore.clear();
	for (auto iter : mapScore) {
		delete iter.second;
	}
	mapScore.clear();
	return 0;
}

bool ScoreSortFunc(StudentScore2* score1, StudentScore2* score2) {
	if (score1->nFinalScore == score2->nFinalScore) {
		return (strcmp(score1->acName, score2->acName) < 0);
	}
	return (score1->nFinalScore > score2->nFinalScore);
}
