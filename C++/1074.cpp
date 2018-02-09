//����������
//	������ϰ��ʹ��ʮ������������Ĭ��һ�����ֵ�ÿһλ����ʮ���Ƶġ�����PAT���˿��ҵ������ÿ�����ֵ�ÿһλ���ǲ�ͬ���Ƶģ�������������ֳ�Ϊ��PAT������
//	ÿ��PAT���˶�������Ǹ�λ���ֵĽ��Ʊ����硰����0527���ͱ�ʾ���λ��7����������2λ��2����������3λ��5����������4λ��10���������ȵȡ�
//	ÿһλ�Ľ���d������0����ʾʮ���ƣ���������[2��9]�����ڵ�������������������Ʊ�Ӧ�ð��������λ���֣�����ʵ��Ӧ�ó�����PAT����ͨ��ֻ��Ҫ��סǰ20λ�͹����ˣ��Ժ��λĬ��Ϊ10���ơ�
//	������������ϵͳ�У���ʹ�Ǽ򵥵ļӷ�����Ҳ��ò��򵥡������Ӧ���Ʊ�0527��������μ��㡰6203 + 415���أ����ǵ����ȼ������λ��3 + 5 = 8��
//	��Ϊ���λ��7���Ƶģ��������ǵõ�1��1����λ����2λ�ǣ�0 + 1 + 1����λ�� = 2����Ϊ��λ��2���Ƶģ��������ǵõ�0��1����λ����3λ�ǣ�2 + 4 + 1����λ�� = 7��
//	��Ϊ��λ��5���Ƶģ��������ǵõ�2��1����λ����4λ�ǣ�6 + 1����λ�� = 7����Ϊ��λ��10���Ƶģ��������Ǿ͵õ�7��������ǵõ���6203 + 415 = 7201��
//�����ʽ��
//	���������ڵ�һ�и���һ��Nλ�Ľ��Ʊ�0 < N <= 20�����Իس������� ������У�ÿ�и���һ��������Nλ������PAT����
//�����ʽ��
//	��һ�����������PAT��֮�͡�
//����������
//	30527
//	06203
//	415
//���������
//	7201

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_VALUE(val1, val2) ((val1) >= (val2) ? (val1) : (val2))

int main() {
	char anBaseTable[21] = { 0 };
	char anNumber1[21] = { 0 };
	char anNumber2[21] = { 0 };
	cin >> anBaseTable >> anNumber1 >> anNumber2;
	char anSum[21] = { 0 };
	int nNumber1Len = strlen(anNumber1);
	int nNumber2Len = strlen(anNumber2);
	int nLoop = MAX_VALUE(nNumber1Len, nNumber2Len);
	int nBaseLen = strlen(anBaseTable);
	int nSumTmp = 0;
	int nCarry = 0;
	int nBase = 0;
	for (int i = 0; i < nLoop; ++i) {
		nSumTmp = (nNumber1Len - i > 0 ? anNumber1[nNumber1Len - 1 - i] - '0' : 0)
			+ (nNumber2Len - i > 0 ? anNumber2[nNumber2Len - 1 - i] - '0' : 0) + nCarry;
		nBase = (nBaseLen - i > 0) ? (anBaseTable[nBaseLen - i - 1] - '0') : 10;
		if (nBase == 0) { nBase = 10; }
		anSum[nLoop - 1 - i] = (nSumTmp % nBase) + '0';
		nCarry = nSumTmp / nBase;
	}
	if (nCarry > 0) {
		cout << nCarry;
	}
	for (int i = 0; i < nLoop; ++i) {
		if (anSum[i] == '0') {
			continue;
		}
		cout << &anSum[i] << endl;
		break;
	}
	return 0;
}
