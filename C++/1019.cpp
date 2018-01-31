//����������
//	������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����Ȼ���õ�1�����ּ���2�����֣����õ�һ���µ����֡�
//	һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������
//	���磬���Ǵ�6767��ʼ�����õ�
//	7766 - 6677 = 1089
//	9810 - 0189 = 9621
//	9621 - 1269 = 8352
//	8532 - 2358 = 6174
//	7641 - 1467 = 6174
//	... ...
//	�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�
//�����ʽ��
//	�������һ��(0, 10000)�����ڵ�������N��
//�����ʽ��
//	���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ���������ֱ��6174��Ϊ����֣������ʽ��������ע��ÿ�����ְ�4λ����ʽ�����
//��������1��
//6767
//�������1��
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//
//��������2��
//2222
//�������2��
//2222 - 2222 = 0000

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void NumberToArray(int nNumber, char* acBuf);
int ArrayToNumber(char* acBuf, bool bDaoxu);
int main() {
	int nNumber = 0;
	char acNumber[5] = { 0 };
	cin >> nNumber;
	int nNumber2 = 0;
	while (true) {
		NumberToArray(nNumber, acNumber);
		//��0
		for (int i = strlen(acNumber); i < 4; ++i) {
			acNumber[i] = '0';
		}
		acNumber[4] = '\0';
		sort(acNumber, &acNumber[4]);
		nNumber = ArrayToNumber(acNumber, true);
		nNumber2 = ArrayToNumber(acNumber, false);
		cout << setfill('0') << setw(4) << nNumber << " - " << setfill('0') << setw(4) << nNumber2 << " = ";
		nNumber -= nNumber2;
		if (nNumber != 6174
			&& nNumber != 0) {
			cout << setfill('0') << setw(4) << nNumber << '\n';
		}
		else{
			cout << setfill('0') << setw(4) << nNumber;
			break;
		}
	}
	cout << endl;
	return 0;
}

// ����
void NumberToArray(int nNumber, char* acBuf) {
	while (nNumber != 0) {
		*(acBuf++) = '0' + (nNumber % 10);
		nNumber /= 10;
	}
}

int ArrayToNumber(char* acBuf, bool bDaoxu) {
	int nNumber = 0;
	int nIndex = (bDaoxu) ? strlen(acBuf) - 1 : 0;
	while (nIndex >= 0 && acBuf[nIndex] != '\0') {
		//while (nIndex >= 0 && nIndex < strlen(acBuf)) {
		nNumber = nNumber * 10 + (acBuf[nIndex] - '0');
		nIndex += (bDaoxu) ? -1 : 1;
	}

	return nNumber;
}
