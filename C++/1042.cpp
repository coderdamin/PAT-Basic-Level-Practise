//����������
//	���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��
//�����ʽ��
//	������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���
//�����ʽ��
//	��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��
//����������
//	This is a simple TEST.There ARE numbers and other symbols 1 & 2 & 3...........
//���������
//	e 7

#include <iostream>
using namespace std;

typedef unsigned int UINT32;

void Solution_1();
//void Solution_2();
int LetterToIndex(char cLetter);
int main() {
	Solution_1();
	return 0;
}

void Solution_1() {
	char cTemp = '\0';
	UINT32 uLetterCount[26] = { 0 };
	int nIndex = 0;
	while ((cTemp = getchar()) != '\n') {
		nIndex = LetterToIndex(cTemp);
		if (nIndex != -1) {
			uLetterCount[nIndex] += 1;
		}
	}
	int nMaxCount = 0;
	int nIndexMaxCount = 0;
	for (int i = 0; i < 26; ++i) {
		if (nMaxCount < uLetterCount[i]) {
			nMaxCount = uLetterCount[i];
			nIndexMaxCount = i;
		}
	}
	cout << char('a' + nIndexMaxCount) << ' ' << nMaxCount << endl;
}

int LetterToIndex(char cLetter) {
	if (cLetter >= 'a' && cLetter <= 'z'){
		return cLetter - 'a';
	}
	else if (cLetter >= 'A' && cLetter <= 'Z'){
		return cLetter - 'A';
	}
	return -1;
}
