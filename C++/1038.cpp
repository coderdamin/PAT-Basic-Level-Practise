//����������
//	����Ҫ�����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������
//�����ʽ��
//	�����ڵ�1�и���������105��������N����ѧ�������������1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ������1�и���Ҫ��ѯ�ķ�������K��������N������������
//	�����K���������м��Կո�ָ���
//�����ʽ��
//	��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�
//����������
//	10
//	60 75 90 55 75 99 82 90 75 50
//	3 75 90 88
//���������
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
