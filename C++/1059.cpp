//����������
//	C���Ծ������㽭��ѧ�����ѧԺ���ֵ�һ�����ֵľ�������Ȼ������ּ��Ϊ�˺��棬�佱����Ҳ���ƶ��úܻ�����
//	0. �ھ���Ӯ��һ�ݡ����ش󽱡�������ܾ޴��һ��ѧ���о����ļ���������
//	1. ����Ϊ������ѧ����Ӯ����õĽ�Ʒ ���� С������ż��
//	2. �����˽��õ��ɿ�����
//	�������������������Լ�һϵ�в����ߵ�ID����Ҫ������Щ������Ӧ�û�õĽ�Ʒ��
//�����ʽ��
//	�����һ�и���һ��������N�� <= 10000�����ǲ��������������N�и�������������ÿ�а�����˳�����һλ�����ߵ�ID��4λ������ɣ�������������һ��������K�Լ�K����Ҫ��ѯ��ID��
//�����ʽ��
//	��ÿ��Ҫ��ѯ��ID����һ���������ID : ��Ʒ�������н�Ʒ�����ǡ�Mystery Award�������ش󽱣��������ǡ�Minion����С���ˣ��������ǡ�Chocolate�����ɿ�������
//	�������ID���������������ӡ��Are you kidding ? ����ˣ���أ����������ID�Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ�����ӡ��ID : Checked�������ܶ�Զ�ռ����
//����������
//	6
//	1111
//	6666
//	8888
//	1234
//	5555
//	0001
//	6
//	8888
//	0001
//	1111
//	2222
//	8888
//	2222
//���������
//	8888: Minion
//	0001 : Chocolate
//	1111 : Mystery Award
//	2222 : Are you kidding ?
//	8888 : Checked
//	2222 : Are you kidding ?

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bitset>
using namespace std;

bool CheckPrimeNumber(int nNumber);
int main() {
	int nCount = 0;
	cin >> nCount;
	int* pRankList = new int[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> pRankList[i];
	}
	int nSearchCount = 0;
	cin >> nSearchCount;
	int* pSearchList = new int[nSearchCount];
	for (int i = 0; i < nSearchCount; ++i) {
		cin >> pSearchList[i];
	}
	int* pItertor = nullptr;
	int nRank = 0;
	bitset<10001> setSearched;
	for (int i = 0; i < nSearchCount; ++i) {
		cout << setfill('0') << setw(4) << pSearchList[i];
		if (setSearched[pSearchList[i]]) {
			cout << ": Checked";
		}
		else{
			pItertor = find(pRankList, &pRankList[nCount], pSearchList[i]);
			if (pItertor == &pRankList[nCount]) {
				cout << ": Are you kidding?";
			}
			else {
				setSearched.set(pSearchList[i]);
				if (pItertor == pRankList) {
					cout << ": Mystery Award";
				}
				else{
					nRank = (pItertor - pRankList) + 1;
					if (CheckPrimeNumber(nRank)) {
						cout << ": Minion";
					}
					else {
						cout << ": Chocolate";
					}
				}
			}
		}
		if (i < nSearchCount - 1){
			cout << '\n';
		}
	}
	cout << endl;
	delete[] pSearchList;
	delete[] pRankList;
	return 0;
}

bool CheckPrimeNumber(int nNumber) {
	if (nNumber == 2 || nNumber == 3) {
		return true;
	}
	int nIntTmp = nNumber % 6;
	if (nIntTmp != 5 && nIntTmp != 1) {
		return false;
	}
	bool bRight = true;
	for (int i = 2; i < sqrt(nNumber); ++i) {
		if (nNumber % i == 0) {
			bRight = false;
			break;
		}
	}
	return bRight;
}
