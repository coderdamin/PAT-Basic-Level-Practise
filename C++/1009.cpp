//����������
//	����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
//�����ʽ��
//	�����������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ�����
//	����֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
//�����ʽ��
//	ÿ���������������ռһ�У���������ľ��ӡ�
//����������
//	Hello World Here I Come
//���������
//	Come I Here World Hello

#include <iostream>
using namespace std;

#define SWAP(val1, val2) \
{\
	val1 ^= val2; \
	val2 ^= val1; \
	val1 ^= val2; \
}

void Solution_1();
void Solution_2();
int main() {
	Solution_1();
}

void Solution_1() {
	char acInput[81] = { 0 };
	cin.getline(acInput, 80);
	unsigned char uLen = strlen(acInput);
	for (int i = 0; i < (uLen >> 1); ++i) {
		SWAP(acInput[i], acInput[uLen - 1 - i]);
	}
	unsigned char uPosBegin = 0;
	for (int i = 0; i < uLen; ++i) {
		if (acInput[i] == ' ' || (i == (uLen - 1) && ++i)) {
			for (int j = uPosBegin; j < ((uPosBegin + i - 1) >> 1); ++j) {
				SWAP(acInput[j], acInput[uPosBegin + i - 1 - j]);
			}
			uPosBegin = i + 1;
		}
	}
	cout << acInput << endl;
	return 0;
}

void Solution_2() {
	// �������ʴ���б�Ȼ������
}
