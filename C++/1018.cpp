//����������
//	���Ӧ�ö����桰���Ӽ�����������Ϸ������ͬʱ�������ƣ�ʤ��������ͼ��ʾ��
//	�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����
//�����ʽ��
//	�����1�и���������N�� <= 105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�
//	C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�
//�����ʽ��
//	�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣
//����������
//	10
//	C J
//	J B
//	C B
//	B B
//	B C
//	C C
//	C B
//	J B
//	B C
//	J J
//���������
//	5 3 2
//	2 3 5
//	B B

#include <iostream>
using namespace std;

int MoraToIndex(char cMora);
int main() {
	int nCount = 0;
	char cMora1 = '\0';
	char cMora2 = '\0';
	int anStat1[2] = { 0 };
	int anStat2[2] = { 0 };
	int anStatMora[2][3] = { 0 };
	cin >> nCount;
	for (int i = 0; i < nCount; ++i){
		cin >> cMora1 >> cMora2;
		if (cMora1 == cMora2) {
			anStat1[1] += 1;
			anStat2[1] += 1;
		}
		// B�������� C�������ӡ� J����������
		else if ((cMora1 == 'J' && cMora2 == 'B')
			|| (cMora1 < cMora2)){
			anStat1[0] += 1;
			anStatMora[0][MoraToIndex(cMora1)] += 1;
		}
		else{
			anStat2[0] += 1;
			anStatMora[1][MoraToIndex(cMora2)] += 1;
		}
	}
	cout << anStat1[0] << ' ' << anStat1[1] << ' ' << nCount - anStat1[0] - anStat1[1] << '\n';
	cout << anStat2[0] << ' ' << anStat2[1] << ' ' << nCount - anStat2[0] - anStat2[1] << '\n';
	char aMora[] = { 'B', 'C', 'J' };
	int nWinIndex1 = anStatMora[0][0] >= anStatMora[0][1] ? 0 : (anStatMora[0][1] >= anStatMora[0][2] ? 1 : 2);
	int nWinIndex2 = anStatMora[1][0] >= anStatMora[1][1] ? 0 : (anStatMora[1][1] >= anStatMora[1][2] ? 1 : 2);
	cout << aMora[nWinIndex1] << ' ' << aMora[nWinIndex2] << endl;
	return 0;
}

int MoraToIndex(char cMora) {
	if (cMora == 'B') {
		return 0;
	}
	else if (cMora == 'C') {
		return 1;
	}
	else {
		return 2;
	}
}