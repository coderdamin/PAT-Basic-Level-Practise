//����������
//	����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ���
//	��Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������
//�����ʽ��
//	������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����
//�����ʽ��
//	��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�
//����������
//	redlesPayBestPATTopTeePHPereatitAPPT
//���������
//	PATestPATestPTetPTePePee

#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned int UINT32;

#define GET_ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

const char aLetterIndex[] = { 'P', 'A', 'T', 'e', 's', 't' };

int LetterToIndex(char cLetter);
int main() {
	UINT32 auCount[6] = { 0 };
	char cLetter = '\0';
	int nIndex = 0;
	while ((cLetter = getchar()) != '\n') {
		nIndex = LetterToIndex(cLetter);
		if (nIndex != -1) {
			auCount[nIndex] += 1;
		}
	}
	bool bCompleted = false;
	while (true) {
		bCompleted = true;
		for (int i = 0; i < GET_ARRAY_LEN(auCount); ++i) {
			if (auCount[i] > 0) {
				cout << aLetterIndex[i];
				auCount[i] -= 1;
				bCompleted = false;
			}
		}
		if (bCompleted) {
			cout << endl;
			break;
		}
	}
	return 0;
}

int LetterToIndex(char cLetter) {
	int nIndex = -1;
	for (int i = 0; i < GET_ARRAY_LEN(aLetterIndex); ++i) {
		if (aLetterIndex[i] == cLetter) {
			nIndex = i;
			break;
		}
	}
	return nIndex;
}
