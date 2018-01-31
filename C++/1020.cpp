//����������
//	�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�
//	ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣�
//	��ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45 / 2 = 94.5����Ԫ����
//�����ʽ��
//	ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾ
//	ÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���
//�����ʽ��
//	��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��
//����������
//	3 20
//	18 15 10
//	75 72 45
//���������
//	94.50

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class MoonClick {
public:
	MoonClick() {
		m_nStock = 0;
		m_nTotal = 0;
	}
	~MoonClick() {
	}
public:
	int m_nStock;
	int m_nTotal;
};

bool StockSortFunc(MoonClick& click1, MoonClick& click2);
int main() {
	int nMounts = 0;
	int nDemand = 0;
	cin >> nMounts >> nDemand;
	MoonClick* aClickList = new MoonClick[nMounts];
	for (int i = 0; i < nMounts; ++i) {
		cin >> aClickList[i].m_nStock;
	}
	for (int i = 0; i < nMounts; ++i) {
		cin >> aClickList[i].m_nTotal;
	}
	sort(aClickList, &aClickList[nMounts], StockSortFunc);
	float fTotal = 0;
	for (int i = 0; i < nMounts; ++i) {
		if (aClickList[i].m_nStock <= nDemand) {
			fTotal += aClickList[i].m_nTotal;
			nDemand -= aClickList[i].m_nStock;
		}
		else {
			fTotal += ((aClickList[i].m_nTotal / (float)aClickList[i].m_nStock) * nDemand);
			nDemand = 0;
		}
		if (nDemand == 0) {
			break;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << fTotal;
	delete[] aClickList;
	return 0;
}

bool StockSortFunc(MoonClick& click1, MoonClick& click2) {
	float fPrice1 = click1.m_nTotal / (float)click1.m_nStock;
	float fPrice2 = click2.m_nTotal / (float)click2.m_nStock;
	return (fPrice1 > fPrice2);
}

