//����������
//	ÿ��PAT�����ڲμӿ���ʱ���ᱻ����������λ�ţ�һ�����Ի���λ��һ���ǿ�����λ����������£��������볡ʱ�ȵõ��Ի���λ���룬���������Ի�״̬��ϵͳ����ʾ
//	�ÿ����Ŀ�����λ���룬����ʱ������Ҫ����������λ����������Щ�����ٵ��ˣ��Ի��Ѿ�����������ֻ�������쵽���Ի���λ�����������㣬�Ӻ�̨������ǵĿ�����λ���롣
//�����ʽ��
//	�����һ�и���һ��������N�� <= 1000�������N�У�ÿ�и���һ����������Ϣ����׼��֤�� �Ի���λ�� ������λ�š�������׼��֤����14λ������ɣ���λ��1��N��š�
//	���뱣֤ÿ���˵�׼��֤�Ŷ���ͬ�������κ�ʱ�򶼲���������˷��䵽ͬһ����λ�ϡ�
//	������Ϣ֮�󣬸���һ��������M�� <= N�������һ���и���M������ѯ���Ի���λ���룬�Կո�ָ���
//�����ʽ��
//	��Ӧÿ����Ҫ��ѯ���Ի���λ���룬��һ���������Ӧ������׼��֤�źͿ�����λ���룬�м���1���ո�ָ���
//����������
//	4
//	10120150912233 2 4
//	10120150912119 4 1
//	10120150912126 1 3
//	10120150912002 3 2
//	2
//	3 4
//���������
//	10120150912002 2
//	10120150912119 1

#include <iostream>
#include <map>
using namespace std;

typedef struct {
	char acNumber[15];
	int nTestPos;
	int nExamPos;
} Examinee;

void Solution_1();
void Solution_2();
int main() {
	//Solution_1();
	Solution_2();
	return 0;
}

void Solution_1() {
	int nCount = 0;
	cin >> nCount;
	Examinee* aExamineeList = new Examinee[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> aExamineeList[i].acNumber >> aExamineeList[i].nTestPos >> aExamineeList[i].nExamPos;
	}
	int nSearchCount = 0;
	cin >> nSearchCount;
	int* anSearchList = new int[nSearchCount];
	for (int i = 0; i < nSearchCount; ++i) {
		cin >> anSearchList[i];
	}
	bool bFirst = true;
	for (int i = 0; i < nSearchCount; ++i) {
		for (int j = 0; i < nCount; ++j) {
			if (aExamineeList[j].nTestPos == anSearchList[i]) {
				if (bFirst) {
					cout << aExamineeList[j].acNumber << ' ' << aExamineeList[j].nExamPos;
					bFirst = false;
				}
				else{
					cout << '\n' << aExamineeList[j].acNumber << ' ' << aExamineeList[j].nExamPos;
				}
				break;
			}
		}
	}
	delete[] anSearchList;
	delete[] aExamineeList;
}

void Solution_2() {
	int nCount = 0;
	cin >> nCount;
	map<int, Examinee*> mapExaminees;
	Examinee* pExaminee = nullptr;
	for (int i = 0; i < nCount; ++i) {
		pExaminee = new Examinee();
		cin >> pExaminee->acNumber >> pExaminee->nTestPos >> pExaminee->nExamPos;
		mapExaminees[pExaminee->nTestPos] = pExaminee;
	}
	int nSearchCount = 0;
	cin >> nSearchCount;
	int* anSearchList = new int[nSearchCount];
	for (int i = 0; i < nSearchCount; ++i) {
		cin >> anSearchList[i];
	}
	bool bFirst = true;
	map<int, Examinee*>::iterator iter;
	for (int i = 0; i < nSearchCount; ++i) {
		iter = mapExaminees.find(anSearchList[i]);
		if (iter != mapExaminees.end()) {
			if (bFirst) {
				cout << iter->second->acNumber << ' ' << iter->second->nExamPos;
				bFirst = false;
			}
			else{
				cout << '\n' << iter->second->acNumber << ' ' << iter->second->nExamPos;
			}
		}
	}
	delete[] anSearchList;
	for (auto iter : mapExaminees) {
		delete iter.second;
	}
	mapExaminees.clear();
}
