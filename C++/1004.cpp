//����������
//	����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
//�����ʽ��
//	ÿ�������������1��������������ʽΪ
//	��1�У�������n
//	��2�У���1��ѧ�������� ѧ�� �ɼ�
//	��3�У���2��ѧ�������� ѧ�� �ɼ�
//	... ... ...
//	��n + 1�У���n��ѧ�������� ѧ�� �ɼ�
//	����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
//�����ʽ��
//	��ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�
//����������
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//
//���������
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