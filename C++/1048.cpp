//����������
//	����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺������λ��
//	��Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��
//�����ʽ��
//	������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���
//�����ʽ��
//	��һ����������ܺ�Ľ����
//����������
//	1234567 368782971
//���������
//	3695Q8118

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char acSecretKey[101] = { 0 };
	char acNumber[101] = { 0 };
	cin >> acSecretKey >> acNumber;
	int nKeyIndex = strlen(acSecretKey);
	int nNumberIndex = strlen(acNumber);
	char nKey = 0;
	for (int i = nNumberIndex; i >= 0; --i){
		if (nKeyIndex < i) {
			nKey = 0;
		}
		else{
			nKey = acSecretKey[nKeyIndex - i];
		}
		if (nKey == 0) {
			cout << acNumber[nNumberIndex - i];
			continue;
		}
		if ((nNumberIndex - i + 1) & 0x00000001) {
			nKey = (nKey + acNumber[nNumberIndex - i] - '0' * 2) % 13;
			switch (nKey) {
			case 10:
				cout << 'J'; break;
			case 11:
				cout << 'Q'; break;
			case 12:
				cout << 'K'; break;
			default:
				cout << (int)nKey; break;
			}
		}
		else{
			nKey = acNumber[nNumberIndex - i] - nKey;
			cout << (int)((nKey > 0) ? nKey : 10 + nKey);
		}
	}
	cout << endl;
	return 0;
}
