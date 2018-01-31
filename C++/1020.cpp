//问题描述：
//	月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
//	注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，
//	那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45 / 2 = 94.5（亿元）。
//输入格式：
//	每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示
//	每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
//输出格式：
//	对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
//输入样例：
//	3 20
//	18 15 10
//	75 72 45
//输出样例：
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

