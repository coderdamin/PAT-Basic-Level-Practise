//����������
//	����������Ĺ���Ϊ��ÿ�������������ɶ�Ա��ɣ����ж�Ա���������������ӵĳɼ�Ϊ���ж�Ա�ĳɼ��ͣ��ɼ���ߵĶӻ�ʤ��
//	�ָ������ж�Ա�ı����ɼ��������д�����ҳ��ھ��ӡ�
//�����ʽ��
//	�����һ�и���һ��������N�� <= 10000���������в�����Ա���������N�У�ÿ�и���һλ��Ա�ĳɼ�����ʽΪ���������� - ��Ա��� �ɼ�����
//	���С������š�Ϊ1��1000��������������Ա��š�Ϊ1��10�������������ɼ���Ϊ0��100��������
//�����ʽ��
//	��һ��������ھ��ӵı�ź��ܳɼ��������һ���ո�ָ���ע�⣺��Ŀ��֤�ھ�����Ψһ�ġ�
//����������
//	6
//	3-10 99
//	11-5 87
//	102-1 0
//	102-3 100
//	11-9 89
//	3-2 61
//���������
//	11 176

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int nTeamScore[1000] = { 0 };
	int nCount = 0;
	cin >> nCount;
	int nMaxNumber = 0;
	int nMaxScore = 0;
	int nTeamNumber, nMemberNumber, nScore;
	for (int i = 0; i < nCount; ++i) {
		scanf_s("%d-%d %d", &nTeamNumber, &nMemberNumber, &nScore);
		nTeamScore[nTeamNumber - 1] += nScore;
		if (nTeamScore[nTeamNumber - 1] > nMaxScore) {
			nMaxScore = nTeamScore[nTeamNumber - 1];
			nMaxNumber = nTeamNumber;
		}
	}
	cout << nMaxNumber << ' ' << nMaxScore << endl;
	return 0;
}
