//����������
//	����һ���������У����ǿ��Դ��н�ȡ����������ļ���������ΪƬ�Ρ����磬��������{ 0.1, 0.2, 0.3, 0.4 }��������(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) ��10��Ƭ�Ρ�
//	�������������У����ȫ��Ƭ�ΰ��������е���֮�͡��籾����10��Ƭ���ܺ���0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0��
//
//�����ʽ��
//	�����һ�и���һ��������105��������N����ʾ���������ĸ������ڶ��и���N��������1.0���������������е���������Կո�ָ���
//�����ʽ��
//	��һ�����������������Ƭ�ΰ�������֮�ͣ���ȷ��С�����2λ��
//����������
//4
//0.1 0.2 0.3 0.4
//���������
//5.00

#include <iostream>
#include <iomanip>
using namespace std;

float Solution_1(float* pNumberList, int nLen);
float Solution_2(float* pNumberList, int nLen);
int main() {
	int nCount = 0;
	cin >> nCount;
	float* pNumberList = new float[nCount];
	for (int i = 0; i < nCount; ++i) {
		cin >> pNumberList[i];
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << Solution_1(pNumberList, nCount) << endl;
	return 0;
}

// ��ǰ�ݹ鷽��
//5.00 = 
//0.1 +
//0.1 + 0.2 +
//0.1 + 0.2 + 0.3 +
//0.1 + 0.2 + 0.3 + 0.4 +
//	  0.2 +
//	  0.2 + 0.3 +
//	  0.2 + 0.3 + 0.4 +
//			0.3 +
//			0.3 + 0.4 +
//				  0.4
float Solution_1(float* pNumberList, int nLen) {
	float nSum = 0.0f;
	float nLastBlockSum = 0.0f;
	for (int i = 1; i <= nLen; ++i) {
		nLastBlockSum += i * pNumberList[nLen - i];
		nSum += nLastBlockSum;
	}
	return nSum;
}

float Solution_2(float* pNumberList, int nLen) {
	// 0.1 * nLen + 0.2 * 2 * (nLen - 1) + 0.3 * (2 * (nLen - 2) + (nLen - 3)) + 0.4 * (nLen - 4)
	return 0.0f;
}