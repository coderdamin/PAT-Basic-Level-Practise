//����������
//	�����ļ����רҵ���У������л������鱨��������ڡ�һ������̨�����Լ��Ĺ�������������̨��Ϊ��������֡���������Ļ����ɼ�����������ģ�����������������У�
//	ȥ��һ����߷ֺ�һ����ͷ֣�ʣ�µķ���ȡƽ���ּ�Ϊ G1����ʦ�����������ּ�Ϊ G2������÷�Ϊ(G1 + G2) / 2�����������������������֡�
//	�����Ҫ����д�����������ʦ����ÿ����Ļ����ɼ���
//�����ʽ��
//	�����һ�и�������������N��> 3����M���ֱ��Ƿ����������֣���������100�����N�У�ÿ�и�������õ���N������������֤Ϊ���ͷ�Χ�ڵ������������е�1������ʦ���������֣�
//	���� N - 1 ����������������֡��Ϸ�������Ӧ����[0, M]�����ڵ������������ںϷ������ڣ���÷����뱻���ԡ���Ŀ��֤��ʦ�����ֶ��ǺϷ��ģ�����ÿ�������ٻ���3������ͬѧ�ĺϷ����֡�
//�����ʽ��
//	Ϊÿ������������յ÷֡�ÿ���÷�ռһ�С�
//����������
//	6 50
//	42 49 49 35 38 41
//	36 51 50 28 -1 30
//	40 36 41 33 47 49
//	30 250 -25 27 45 31
//	48 0 0 50 50 1234
//	43 41 36 29 42 29
//���������
//	42
//	33
//	41
//	31
//	37
//	39

#include <iostream>
using namespace std;

int main() {
	int nCount = 0, nTotalScore = 0;
	cin >> nCount >> nTotalScore;
	int* anScore = new int[nCount];
	int nTemp = 0;
	int nScoreTeacher = 0;
	int nRightScoreCount = 0;
	int nScoreMin = nTotalScore + 1, nScoreMax = -1;
	for (int i = 0; i < nCount; ++i) {
		anScore[i] = 0;
		nRightScoreCount = 0;
		nScoreMin = nTotalScore + 1;
		nScoreMax = -1;
		cin >> nScoreTeacher;
		for (int j = 1; j < nCount; ++j) {
			cin >> nTemp;
			if (nTemp <= nTotalScore && nTemp >= 0) {
				anScore[i] += nTemp;
				nRightScoreCount += 1;
				if (nScoreMin > nTemp) {
					nScoreMin = nTemp;
				}
				if (nScoreMax < nTemp) {
					nScoreMax = nTemp;
				}
			}
		}
		anScore[i] -= (nScoreMin + nScoreMax);
		anScore[i] = ((anScore[i] / (nRightScoreCount - 2)) + nScoreTeacher + 1) / 2;
	}
	cout << anScore[0];
	for (int i = 1; i < nCount; ++i) {
		cout << '\n' << anScore[i];
	}
	cout << endl;
	delete[] anScore;
	return 0;
}
