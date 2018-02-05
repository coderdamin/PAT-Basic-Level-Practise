//����������
//	С������Щ������һ���Լ�ϲ�����鴮�������ӵ�̯���кܶമ������ɫ���鴮�����ǲ��ϰ��κ�һ����ɢ����������С��Ҫ���æ�ж�һ�£�ĳ���������Ƿ������ȫ���Լ���Ҫ�����ӣ�
//	����ǣ���ô�������ж��ٶ�������ӣ�������ǣ���ô������ȱ�˶������ӡ�
//	Ϊ���������������[0 - 9]��[a - z]��[A - Z]��Χ�ڵ��ַ�����ʾ��ɫ��������ͼ1�У���3����С���������鴮����ô��1����������Ϊ������ȫ������Ҫ�����ӣ�
//	������8�Ų���Ҫ�����ӣ���2����������Ϊû�к�ɫ���ӣ���������һ�ź�ɫ�����ӡ�
//�����ʽ��
//	ÿ���������1������������ÿ�����������ֱ���2�����Ⱥ����̯�����鴮��С���������鴮��������������1000�����ӡ�
//�����ʽ��
//	�������������һ���������Yes���Լ��ж��ٶ�������ӣ����������������һ���������No���Լ�ȱ�˶������ӡ������1���ո�ָ���
//��������1��
//	ppRYYGrrYBR2258
//	YrR8RrY
//�������1��
//	Yes 8
//��������2��
//	ppRYYGrrYB225
//	YrR8RrY
//�������2��
//	No 2

#include <iostream>
using namespace std;

typedef unsigned char UINT8;
typedef unsigned int UINT32;

UINT32 GetColorToIndex(UINT8 uColor);
int main() {
	UINT8 auColor[62] = { 0 };
	char cTemp = '\0';
	UINT32 uIndex = 0;
	while ((cTemp = getchar()) != '\n') {
		uIndex = GetColorToIndex(cTemp);
		if (uIndex != -1) {
			auColor[uIndex] += 1;
		}
	}
	UINT32 uLackCount = 0;
	while ((cTemp = getchar()) != '\n') {
		uIndex = GetColorToIndex(cTemp);
		if (uIndex == -1) {
			continue;
		}
		if (auColor[uIndex] > 0) {
			auColor[uIndex] -= 1;
		}
		else{
			uLackCount += 1;
		}
	}
	if (uLackCount == 0) {
		UINT32 uLeftCount = 0;
		for (int i = 0; i < 62; ++i) {
			uLeftCount += auColor[i];
		}
		cout << "Yes " << uLeftCount << endl;
	}
	else{
		cout << "No " << uLackCount << endl;
	}
	return 0;
}

UINT32 GetColorToIndex(UINT8 uColor) {
	//[0 - 9]
	if (uColor >= '0' && uColor <= '9') {
		return uColor - '0';
	}
	//[a - z]
	else if (uColor >= 'a' && uColor <= 'z'){
		return uColor - 'a' + 10;
	}
	//[A - Z]
	else if (uColor >= 'A' && uColor <= 'Z'){
		return uColor - 'A' + 36;
	}
	return -1;
}
