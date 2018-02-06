//����������
//	�ڲ����ž����ǰ���£�ͳ��ס�������ʵ�һ�ַ����Ǹ���ÿ���õ����������仯���ɽ����жϡ��жϷ������£�
//	�ڹ۲����ڣ������ڳ���һ��������õ�������ĳ��������ֵe�����ס��Ϊ�����ܿ��á���
//	���۲��ڳ���ĳ������ֵD�죬��������һ�����������ס��Ϊ�����á���
//	�ָ���ĳ��������ס���õ������ݣ�����ͳ�ơ����ܿ��á��ı��ʺ͡����á����ʣ�����������״̬��ס��ռ������ס���������İٷֱȡ�
//�����ʽ��
//	�����һ�и���������N�� <= 1000����Ϊ������ס������������ʵ��e�����͵�����ֵ��������D�����۲�����ֵ�����N�У�ÿ�а����¸�ʽ����һ��ס�����õ������ݣ�
//	K E1 E2 ... EK
//	����KΪ�۲��������EiΪ��i����õ�����
//�����ʽ��
//	��һ������������ܿ��á��ı��ʺ͡����á����ʵİٷֱ�ֵ�������һ���ո�ָ�������С�����1λ��
//����������
//	5 0.5 10
//	6 0.3 0.4 0.5 0.2 0.8 0.6
//	10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
//	5 0.4 0.3 0.5 0.1 0.7
//	11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
//	11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
//���������
//	40.0% 20.0%
//	���������ͣ���2��3��Ϊ�����ܿ��á�����4��Ϊ�����á������������ǿ��á���

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
