//����������
//	������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� ���纣����߹����ģ���ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ������ס�
//	�����ڣ���������Ӧ���ļ�ǮP����ʵ����ǮA�����������дһ��������������Ӧ�ñ��ҵ���Ǯ��
//�����ʽ��
//	������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut���������1���ո�ָ�������Galleon��[0, 107]�����ڵ�������Sickle��[0, 17)�����ڵ�������Knut��[0, 29)�����ڵ�������
//�����ʽ��
//	��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ�������û����Ǯ����ô�����Ӧ���Ǹ�����
//��������1��
//	10.16.27 14.1.28
//�������1��
//	3.2.1
//
//��������2��
//	14.1.28 10.16.27
//�������2��
//	-3.2.1

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct {
	int nGalleon;
	int nSickle;
	int nKnut;
} HWMoney;

void Solution_1(HWMoney& p, HWMoney& a);
void Solution_2(HWMoney& p, HWMoney& a);
int main() {
	HWMoney p, a;
	scanf_s("%d.%d.%d %d.%d.%d", &p.nGalleon, &p.nSickle, &p.nKnut
		, &a.nGalleon, &a.nSickle, &a.nKnut);
	Solution_1(p, a);
	return 0;
}

void Solution_1(HWMoney& p, HWMoney& a) {
	a.nKnut -= p.nKnut;
	if (a.nKnut < 0) {
		a.nKnut += 29;
		a.nSickle -= 1;
	}
	a.nSickle -= p.nSickle;
	if (a.nSickle < 0) {
		a.nSickle += 17;
		a.nGalleon -= 1;
	}
	a.nGalleon -= p.nGalleon;
	if (a.nGalleon < 0) {
		a.nGalleon += 1;
		a.nSickle = 16 - a.nSickle;
		a.nKnut = 29 - a.nKnut;
	}
	cout << a.nGalleon << '.' << a.nSickle << '.' << a.nKnut << endl;
}

// �����nKnut����ڻ������
void Solution_2(HWMoney& p, HWMoney& a) {

}
