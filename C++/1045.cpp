//����������
//	�����Ŀ��������㷨����һ������Ļ��ֹ��̣�����ͨ������ĳ�ַ���ȡһ��Ԫ����Ϊ��Ԫ��ͨ���������ѱ���ԪС��Ԫ�طŵ�������ߣ�����Ԫ���Ԫ�طŵ������ұߡ�
//	�������ֺ��N��������ͬ�������������У������ж��ٸ�Ԫ�ؿ����ǻ���ǰѡȡ����Ԫ��
//	�������N = 5, ������1��3��2��4��5����
//	1�����û��Ԫ�أ��ұߵ�Ԫ�ض���������������������Ԫ��
//	����3�����Ԫ�ض�����С���������ұߵ�2��С����������������Ԫ��
//	����2���ұ�Ԫ�ض������󣬵�����ߵ�3��������������������Ԫ��
//	����ԭ��4��5����������Ԫ��
//	��ˣ���3��Ԫ�ؿ�������Ԫ��
//�����ʽ��
//	�����ڵ�1���и���һ��������N�� <= 105���� ��2���ǿո�ָ���N����ͬ����������ÿ����������109��
//�����ʽ��
//	�ڵ�1��������п�������Ԫ��Ԫ�ظ������ڵ�2���а�����˳�������ЩԪ�أ������1���ո�ָ�����ĩ�����ж���ո�
//����������
//	5
//	1 3 2 4 5
//���������
//	3
//	1 4 5

#include <iostream>
using namespace std;

int main() {
	int nCount = 0;
	cin >> nCount;
	int* anNumber = new int[nCount];
	int nMin = 110;
	for (int i = 0; i < nCount; ++i){
		cin >> anNumber[i];
		if (i > 0 && nMin > anNumber[i]) {
			nMin = anNumber[i];
		}
	}

	int nResultCount = 1;
	int nMax = anNumber[0];
	for (int i = 1; i < nCount; ++i){
		if (nMax <= anNumber[i]) {
			nMax = anNumber[i];
			if (anNumber[i] <= nMin) {
				anNumber[nResultCount] = anNumber[i];
				nResultCount += 1;
			}
		}
		if (anNumber[i] == nMin) {
			nMin = 110;
			for (int j = i + 1; j < nCount; ++j){
				if (nMin > anNumber[j]) {
					nMin = anNumber[j];
				}
			}
		}
	}
	cout << nResultCount << '\n' << anNumber[0];
	for (int i = 1; i < nResultCount; ++i) {
		cout << ' ' << anNumber[i];
	}
	cout << endl;
	delete[] anNumber;
	return 0;
}
