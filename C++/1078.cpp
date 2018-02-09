//����������
//	�ı�ѹ���кܶ��ַ�������������ֻ������򵥵�һ�֣�������ͬ�ַ���ɵ�һ��������Ƭ��������ַ���Ƭ���к�������ַ��ĸ�������ʾ��
//	���� ccccc ���� 5c ����ʾ������ַ�û���ظ�����ԭ����������� aba ѹ������Ȼ�� aba��
//	��ѹ�������Ƿ������������� 5c �����ı�ʾ�ָ�Ϊ ccccc��
//	������Ҫ�����ѹ�����ѹ��Ҫ�󣬶Ը����ַ������д����������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ��Ӣ����ĸ�Ϳո���ɵķǿ��ַ�����
//�����ʽ��
//	�����һ�и���һ���ַ�������� C �ͱ�ʾ������ַ�����Ҫ��ѹ��������� D �ͱ�ʾ������ַ�����Ҫ����ѹ���ڶ��и�����Ҫ��ѹ�����ѹ�Ĳ�����1000���ַ����ַ�����
//	�Իس���β����Ŀ��֤�ַ��ظ����������ͷ�Χ�ڣ�������ļ�������1MB��
//�����ʽ��
//	����Ҫ��ѹ�����ѹ�ַ���������һ������������
//�������� 1��
//	C
//	TTTTThhiiiis isssss a   tesssst CAaaa as
//������� 1��
//	5T2h4is i5s a3 te4st CA3a as
//
//�������� 2��
//	D
//	5T2h4is i5s a3 te4st CA3a as10Z
//������� 2��
//	TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

#include <iostream>
using namespace std;

void Compress(char* acInput);
void Decompress(char* acInput);
int main() {
	char cOption = '\0';
	char acInput[1001] = { 0 };
	cin >> cOption;
	cin.ignore();
	cin.getline(acInput, 1001);
	if (cOption == 'C') {
		Compress(acInput);
	}
	else{
		Decompress(acInput);
	}

	return 0;
}

void Compress(char* acInput) {
	if (acInput == nullptr || *acInput == '\0') {
		return;
	}

	char cCurChar = *acInput++;
	int nCount = 1;
	while (*acInput != '\0') {
		if (*acInput != cCurChar) {
			if (nCount > 1) {
				cout << nCount;
			}
			cout << cCurChar;
			cCurChar = *acInput;
			nCount = 1;
		}
		else{
			nCount += 1;
		}
		acInput += 1;
	}
	if (nCount > 1) {
		cout << nCount;
	}
	cout << cCurChar << endl;
}

void Decompress(char* acInput) {
	if (acInput == nullptr || *acInput == '\0') {
		return;
	}

	int nCount = 0;
	while (*acInput != '\0') {
		if (*acInput >= '0' && *acInput <= '9') {
			nCount = nCount * 10 + (*acInput - '0');
		}
		else if (nCount == 0){
			cout << *acInput;
		}
		else{
			for (int i = 0; i < nCount; ++i) {
				cout << *acInput;
			}
			nCount = 0;
		}
		acInput += 1;
	}
	cout << endl;
}
