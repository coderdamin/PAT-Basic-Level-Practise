//����������
//	�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P), ��4λ(A), ��6λ(T)���ڶ���PAT�ǵ�3λ(P), ��4λ(A), ��6λ(T)��
//	�ָ����ַ�������һ�������γɶ��ٸ�PAT��
//�����ʽ��
//	����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ��
//�����ʽ��
//	��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����
//����������
//	APPAPT
//���������
//	2

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char acInput[106] = { 0 };
	cin >> acInput;
	int nPATCount = 0;
	int nATCount = 0;
	int nTCount = 0;
	int nIndex = strlen(acInput);
	while (nIndex >= 0) {
		switch (acInput[nIndex]) {
		case 'P':
			nPATCount += nATCount;
			break;
		case 'A':
			nATCount += nTCount;
			break;
		case 'T':
			nTCount += 1;
			break;
		}
		nIndex -= 1;
	}
	cout << nPATCount << endl;
	return 0;
}
