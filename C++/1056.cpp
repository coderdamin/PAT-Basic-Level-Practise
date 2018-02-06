//����������
//	����N����0�ĸ�λ���֣�����������2�����ֶ�������ϳ�1��2λ�����֡�Ҫ�����п�����ϳ�����2λ���ֵĺ͡�
//	�������2��5��8���������ϳ���25��28��52��58��82��85�����ǵĺ�Ϊ330��
//�����ʽ��
//	������һ�����ȸ���N��1<N<10���������N����ͬ�ķ�0��λ���֡����ּ��Կո�ָ���
//�����ʽ��
//	������п�����ϳ�����2λ���ֵĺ͡�
//����������
//	3 2 8 5
//���������
//	330

#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned char UINT8;
typedef unsigned int UINT32;

void Solution_1();
void Solution_2();
int main() {
	//Solution_1();
	Solution_2();
	return 0;
}

void Solution_1() {
	UINT8 acNumber[8] = { 0 };
	char cTemp = '\0';
	UINT8 uCount = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp == ' ') {
			continue;
		}
		acNumber[uCount++] = cTemp - '0';
	}
	UINT32 uSum = 0;
	for (int i = 0; i < uCount; i++) {
		for (int j = 0; j < uCount; j++) {
			if (i != j) {
				uSum += (acNumber[i] * 10 + acNumber[j]);
			}
		}
	}
	cout << uSum << endl;
}

void Solution_2() {
	UINT8 acNumber[8] = { 0 };
	char cTemp = '\0';
	UINT8 uCount = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp == ' ') {
			continue;
		}
		acNumber[uCount++] = cTemp - '0';
	}
	UINT32 uSum = 0;
	for (int i = 0; i < uCount - 1; i++) {
		for (int j = i + 1; j < uCount; j++) {
			uSum += (acNumber[i] * 10 + acNumber[j]);
			uSum += (acNumber[j] * 10 + acNumber[i]);
		}
	}
	cout << uSum << endl;
}
