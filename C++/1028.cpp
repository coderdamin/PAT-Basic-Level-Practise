//����������
//	ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�
//	����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���
//�����ʽ��
//	�����ڵ�һ�и���������N��ȡֵ��(0, 105]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ��������Լ�����yyyy / mm / dd�������� / �� / �գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�
//�����ʽ��
//	��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���
//����������
//	5
//	John 2001/05/12
//	Tom 1814/09/06
//	Ann 2121/01/30
//	James 1814/09/05
//	Steve 1967/11/20
//���������
//	3 Tom John

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//typedef struct PEOPLE {
//	char acName[6];
//	int nBirthday;
//} People;

int main() {
	int nCount = 0;
	cin >> nCount;
	char acNameOldest[6] = { 0 };
	int nOldest = 2014 * 365 + 9 * 30 + 6 + 1;
	char acNameYoungest[6] = { 0 };
	int nYoungest = 0;
	char acName[6] = { 0 };
	int nYear, nMonth, nDay;
	int nValidCount = nCount;
	for (int i = 0; i < nCount; ++i) {
		scanf_s("%s %d/%d/%d", &acName, 6, &nYear, &nMonth, &nDay);
		nDay = nYear * 365 + nMonth * 30 + nDay;
		if (nDay > 735386 || nDay < 662386) {
			nValidCount -= 1;
			continue;
		}
		if (nOldest > nDay) {
			nOldest = nDay;
			strcpy_s(acNameOldest, 6, acName);
		}
		if (nYoungest < nDay) {
			nYoungest = nDay;
			strcpy_s(acNameYoungest, 6, acName);
		}
	}
	cout << nValidCount << ' ' << acNameOldest << ' ' << acNameYoungest << endl;
	return 0;
}
