//����������
//	Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��
//�����ʽ��
//	�����ڵ�1�и���������105��������N�����������������N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ���
//	��������ɼ����ٷ��ƣ����м��Կո�ָ���
//�����ʽ��
//	��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�
//����������
//	6
//	3 65
//	2 80
//	1 100
//	2 70
//	3 40
//	3 0
//���������
//	2 150

#include <iostream>
using namespace std;

int main() {
	int anScore[105] = { 0 };
	int nCount = 0;
	cin >> nCount;
	int nNumber, nScore;
	int nMaxScore = -1, nMaxIndex = -1;
	for (int i = 0; i < nCount; ++i) {
		cin >> nNumber >> nScore;
		anScore[nNumber - 1] += nScore;
		if (nMaxScore < anScore[nNumber - 1]) {
			nMaxScore = anScore[nNumber - 1];
			nMaxIndex = nNumber - 1;
		}
	}
	cout << nMaxIndex + 1 << ' ' << nMaxScore << endl;
	return 0;
}
