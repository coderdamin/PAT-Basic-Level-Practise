//����������
//	����һ�����Ȳ�����105���ַ���������Ҫ���㽫��������Ӣ����ĸ����ţ���ĸa - z��Ӧ���1 - 26�����ִ�Сд����ӣ��õ�����N��
//	Ȼ���ٷ���һ��N�Ķ����Ʊ�ʾ���ж���0������1����������ַ�����PAT(Basic)��������ĸ���֮��Ϊ��16 + 1 + 20 + 2 + 1 + 19 + 9 + 3 = 71����71�Ķ�������1000111������3��0��4��1��
//�����ʽ��
//	������һ���и������Ȳ�����105���Իس��������ַ�����
//�����ʽ��
//	��һ�����Ⱥ����0�ĸ�����1�ĸ���������Կո�ָ���
//����������
//	PAT(Basic)
//���������
//	3 4

#include <iostream>
using namespace std;

int main() {
	char cTemp = '\0';
	unsigned int uNumber = 0;
	while ((cTemp = getchar()) != '\n') {
		if (cTemp >= 'a' && cTemp <= 'z') {
			uNumber += (cTemp - 'a' + 1);
		}
		else if (cTemp >= 'A' && cTemp <= 'Z') {
			uNumber += (cTemp - 'A' + 1);
		}
	}
	unsigned int uZeroCount = 0;
	unsigned int uOneCount = 0;
	while (uNumber != 0) {
		if (uNumber & 0x00000001) {
			uOneCount += 1;
		}
		else {
			uZeroCount += 1;
		}
		uNumber = uNumber >> 1;
	}
	cout << uZeroCount << ' ' << uOneCount << endl;
	return 0;
}
