//����������
//	Ӣ������ѧ�Ұ����ٺ�ϲ���ﳵ����˵��Ϊ����ҫ�Լ����ﳵ��������������һ��������������E����������E���ﳵ����EӢ����������E����˵�������Լ���E����87��
//	�ָ���ĳ��N����ﳵ���룬���������Ӧ�İ�������E�� <= N����
//�����ʽ��
//	�����һ�и���һ��������N�� <= 105�����������ﳵ���������ڶ��и���N���Ǹ�����������ÿ����ﳵ���롣
//�����ʽ��
//	��һ���и���N��İ���������
//����������
//	10
//	6 7 6 9 3 10 8 2 7 8
//���������
//	6

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nCount = 0;
	cin >> nCount;
	int* anDistance = new int[nCount];
	for (int i = 0; i < nCount; i++) {
		cin >> anDistance[i];
	}
	sort(anDistance, &anDistance[nCount]);
	int nResult = anDistance[nCount - 1];
	for (int i = nCount - 2; i >= 0; --i) {
		if (nResult >= anDistance[i]) {
			if (nResult <= nCount - i - 2) {
				break;
			}
			else{
				nResult = anDistance[i];
			}
		}
	}
	cout << nResult << endl;
	delete[] anDistance;
	return 0;
}
