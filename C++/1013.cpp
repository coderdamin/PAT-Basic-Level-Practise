//����������
//	��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������
//�����ʽ��
//	������һ���и���M��N������Կո�ָ���
//�����ʽ��
//	�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
//����������
//	5 27
//���������
//	11 13 17 19 23 29 31 37 41 43
//	47 53 59 61 67 71 73 79 83 89
//	97 101 103

#include <iostream>
#include <set>
using namespace std;

int main() {
	int nM = 0;
	int nN = 0;
	cin >> nM >> nN;
	set<int> setPrimeNumber;
	int index = 1;
	while (true) {
	}

	return 0;
}

// nPrimeNumber >= 5
//int GetNextPrimeNumber(int nPrimeNumber) {
//	int nNext = nPrimeNumber;
//	while (true) {
//		nNext = ((nNext % 6) == 1) ? nNext + 4 : nNext + 2;
//		for (int i = 5; i <= sqrt(nNext); i += 6) {
//			if (nNext%i == 0 || nNext % (i + 2) == 0) {
//				goto CONTINUE_TAG;
//			}
//		}
//		break;
//	CONTINUE_TAG:
//	}
//	return nNext;
//}

