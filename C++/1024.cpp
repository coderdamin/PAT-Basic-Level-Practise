//����������
//	��ѧ�������ǿ�ѧ��������ʾ�ܴ���С�����ֵ�һ�ַ���ķ�����������������ʽ[+-][1 - 9]"."[0 - 9] + E[+-][0 - 9] + ��
//	�����ֵ���������ֻ��1λ��С������������1λ�������ּ���ָ�����ֵ������ż�ʹ������Ҳ�ض���ȷ������
//	���Կ�ѧ�������ĸ�ʽ����ʵ��A�����д������ͨ���ֱ�ʾ�����A������֤������Чλ����������
//�����ʽ��
//	ÿ���������1��������������һ���Կ�ѧ��������ʾ��ʵ��A�������ֵĴ洢���Ȳ�����9999�ֽڣ�����ָ���ľ���ֵ������9999��
//�����ʽ��
//	��ÿ��������������һ���а���ͨ���ֱ�ʾ�����A������֤������Чλ��������������ĩβ��0��
//��������1��
//	+1.23400E-03
//�������1��
//	0.00123400
//
//��������2��
//	-1.2E+10
//�������2��
//	-12000000000

#include <iostream>
#include <stdio.h>
//#include <memory.h>
using namespace std;

void Solution_1();
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	char cSingal = '\0';
	char acInput[10000] = { 0 };
	int nExp = 0;
	//memset(acInput, 0, 10000);
	scanf_s("%c%c.%[0-9]E%d", &cSingal, 1, &acInput[0], 1, &acInput[1], 9998, &nExp);
	if (cSingal == '-') {
		printf("-");
	}

	if (nExp >= 0) {
		int index = 0;
		bool bZero = false;
		for (; index <= nExp; ++index) {
			if (acInput[index] == '\0') {
				bZero = true;
			}
			printf("%c", (bZero) ? '0' : acInput[index]);
		}
		if (!bZero && acInput[index] != '\0') {
			printf(".%s", &acInput[index]);
		}
	}
	else {
		printf("0.");
		for (int index = 1; index < -nExp; ++index) {
			printf("0");
		}
		printf("%s", acInput);
	}
	printf("\n");
}
