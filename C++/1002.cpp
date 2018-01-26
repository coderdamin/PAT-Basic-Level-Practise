//��Ŀ������
//	����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
//�����ʽ��
//	ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��
//�����ʽ��
//	��һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
//����������
//	1234567890987654321123456789
//���������
//	yi san wu

#include <iostream>
#include <math.h>

using namespace std;

void Solution_1();
void Solution_2();
const char* aPinyin[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int main() {
	//Solution_1();
	Solution_2();
	return 0;
}

//unsigned int GetLowestOrder(nNumber);
void GetLowestOrder(unsigned int nNumber, char cPrefix);
void Solution_1() {
	char* aInput = new char[101];
	cin >> aInput;
	unsigned int uSum = 0;
	while (*aInput != '\0') {
		uSum += (*aInput - '0');
		aInput += 1;
	}
	if (uSum != 0) {
		GetLowestOrder(uSum, ' ');
	}
	else{
		cout << aPinyin[0];
	}
	cout << endl;
	delete[] aInput;
	return;
}

void GetLowestOrder(unsigned int nNumber, char cPrefix) {
	if (nNumber / 10 > 0) {
		GetLowestOrder(nNumber / 10, ' ');
		cout << cPrefix << aPinyin[nNumber % 10];
	}
	else{
		cout << aPinyin[nNumber % 10];
	}
}

void Solution_2() {
	char* aInput = new char[101];
	cin >> aInput;
	unsigned int uSum = 0;
	while (*aInput != '\0') {
		uSum += (*aInput - '0');
		aInput += 1;
	}
	if (uSum != 0) {
		unsigned int uLen = 0;
		unsigned int uNumberTmp = uSum;
		while (uNumberTmp != 0) {
			uNumberTmp /= 10;
			uLen += 1;
		}
		// ���߲ο�stdlib��itoaʵ��
		cout << aPinyin[uSum / ((int)pow(10, uLen - 1))];
		uSum = uSum % ((int)pow(10, uLen - 1));
		for (int i = 1; i < uLen; ++i){
			cout << ' ' << aPinyin[uSum / ((int)pow(10, uLen - i - 1))];
			uSum = uSum % ((int)pow(10, uLen - i - 1));
		}
	}
	else{
		cout << aPinyin[0];
	}
	cout << endl;
	delete[] aInput;
	return;
}