//问题描述：
//	在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：
//	在观察期内，若存在超过一半的日子用电量低于某给定的阈值e，则该住房为“可能空置”；
//	若观察期超过某给定阈值D天，且满足上一个条件，则该住房为“空置”。
//	现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。
//输入格式：
//	输入第一行给出正整数N（ <= 1000），为居民区住房总套数；正实数e，即低电量阈值；正整数D，即观察期阈值。随后N行，每行按以下格式给出一套住房的用电量数据：
//	K E1 E2 ... EK
//	其中K为观察的天数，Ei为第i天的用电量。
//输出格式：
//	在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后1位。
//输入样例：
//	5 0.5 10
//	6 0.3 0.4 0.5 0.2 0.8 0.6
//	10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
//	5 0.4 0.3 0.5 0.1 0.7
//	11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
//	11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
//输出样例：
//	40.0% 20.0%
//	（样例解释：第2、3户为“可能空置”，第4户为“空置”，其他户不是空置。）

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void Solution_1();
void Solution_2();
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	int nCount = 0;
	float fMinValue = 0.0f;
	int nDays = 0;
	cin >> nCount >> fMinValue >> nDays;
	int nDataCount = 0;
	int nIdle = 0, nMayIdle = 0;
	int nLessCount = 0;
	float fDataTmp = 0.0f;
	for (int i = 0; i < nCount; ++i){
		nLessCount = 0;
		cin >> nDataCount;
		for (int j = 0; j < nDataCount; ++j){
			cin >> fDataTmp;
			if (fDataTmp < fMinValue) {
				nLessCount += 1;
			}
		}
		if (nLessCount > nDays) {
			nIdle += 1;
		}
		else if (nLessCount >(nDataCount >> 1)) {
			nMayIdle += 1;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(1) << (100 * nMayIdle) / (float)nCount << "% ";
	cout << setprecision(1) << (100 * nIdle) / (float)nCount << '%' << endl;
}

void Solution_2() {
	vector<vector<float>> vElectricityMeterInfo;
	int nCount = 0;
	float fMinValue = 0.0f;
	int nDays = 0;
	cin >> nCount >> fMinValue >> nDays;
	int nDataCount = 0;
	for (int i = 0; i < nCount; ++i){
		cin >> nDataCount;
		for (int j = 0; j < nDataCount; ++j){
			cin >> vElectricityMeterInfo[i][j];
		}
	}
}
